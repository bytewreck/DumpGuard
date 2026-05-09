#include "kerb_server.h"
#include "kerb_network.h"

#include "asn1_krb5.h"
#include "asn1_gssapi.h"

#include <stdio.h>

typedef struct _KERB_GSS_InitialContextToken
{
	ASN1objectidentifier_t MechType;
	KERB_GSS_TOKEN_ID TokenId;
	ASN1open_t InnerToken;
} KERB_GSS_InitialContextToken;

BOOL kerb_init_context(KERB_CONTEXT* context, LPCSTR domain, LPCSTR username, LPCSTR password)
{
	memset(context, 0, sizeof(KERB_CONTEXT));
	
	strcpy_s(context->domain, sizeof(context->domain), domain);
	strcpy_s(context->username, sizeof(context->username), username);
	strcpy_s(context->password, sizeof(context->password), password);

	if (!kerb_build_longterm_keys(context, NULL))
		return FALSE;

	BYTE acceptor_subkey[] = 
	{ 
		0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,
		0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20 
	};

	context->acceptor_subkey_type = kerb_etype_aes256;
	memcpy(context->acceptor_subkey, acceptor_subkey, sizeof(acceptor_subkey));
	context->acceptor_subkey_length = sizeof(acceptor_subkey);

	context->acceptor_seq = 0x12345678;
	return TRUE;
}

void kerb_free_context(KERB_CONTEXT* context)
{

}

BOOL kerb_build_longterm_keys(KERB_CONTEXT* context, LPCSTR salt)
{
	if (context->username[0] == 0)
		return FALSE;

	char realm_upper[256];
	memset(realm_upper, 0, sizeof(realm_upper));

	char realm_lower[256];
	memset(realm_lower, 0, sizeof(realm_lower));

	for (int i = 0; i < sizeof(context->domain) && context->domain[i] != 0; i++)
	{
		realm_upper[i] = toupper(context->domain[i]);
		realm_lower[i] = tolower(context->domain[i]);
	}

	char username_lower[256];
	memset(username_lower, 0, sizeof(username_lower));

	for (int i = 0; i < sizeof(context->username) && context->username[i] != 0; i++)
		username_lower[i] = tolower(context->username[i]);

	if (username_lower[strlen(username_lower) - 1] == '$')
		username_lower[strlen(username_lower) - 1] = 0;

	wchar_t final_password[256];
	memset(final_password, 0, sizeof(final_password));

	swprintf_s(final_password, sizeof(final_password) / sizeof(wchar_t), L"%S", context->password);

	wchar_t final_salt[1024];
	memset(final_salt, 0, sizeof(final_salt));

	if (salt != NULL)
		swprintf_s(final_salt, sizeof(final_salt) / sizeof(wchar_t), L"%S", salt);
	else
	{
		if (context->username[strlen(context->username) - 1] == '$')
			swprintf_s(final_salt, sizeof(final_salt) / sizeof(wchar_t), L"%Shost%S.%S", realm_upper, username_lower, realm_lower);
		else
			swprintf_s(final_salt, sizeof(final_salt) / sizeof(wchar_t), L"%S%S", realm_upper, username_lower);
	}

	KERB_ETYPE types[] = { kerb_etype_rc4_hmac, kerb_etype_aes128, kerb_etype_aes256 };
	
	for (int i = 0; i < _countof(types); i++)
	{
		ULONG cbHash = 0;
		PVOID pvHash = NULL;

		if (!kerb_hash_password(types[i], final_password, final_salt, 4096, &pvHash, &cbHash))
			return FALSE;

		if (types[i] == kerb_etype_rc4_hmac)
			memcpy(context->longterm_key_rc4, pvHash, cbHash);
		else if (types[i] == kerb_etype_aes128)
			memcpy(context->longterm_key_aes128, pvHash, cbHash);
		else if (types[i] == kerb_etype_aes256)
			memcpy(context->longterm_key_aes256, pvHash, cbHash);

		free(pvHash);
	}

	return TRUE;
}

ULONG kerb_get_key_length(KERB_ETYPE type)
{
	switch (type)
	{
	case kerb_etype_rc4_hmac:
		return 16;
	case kerb_etype_aes128:
		return 16;
	case kerb_etype_aes256:
		return 32;
	}
	return 0;
}

PVOID kerb_get_key_buffer(KERB_CONTEXT* context, KERB_ETYPE type)
{
	switch (type)
	{
	case kerb_etype_rc4_hmac:
		return context->longterm_key_rc4;
	case kerb_etype_aes128:
		return context->longterm_key_aes128;
	case kerb_etype_aes256:
		return context->longterm_key_aes256;
	}
	return NULL;
}

BOOL kerb_make_signature_old(KERB_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	KERB_CTYPE checksum_type = kerb_ctype_none;

	if (context->acceptor_subkey_type != kerb_etype_aes128 && context->acceptor_subkey_type != kerb_etype_aes256)
	{
		printf("[-] Attempted to make kerberos signature with unspported key type: '%d'\n", context->acceptor_subkey_type);
		return FALSE;
	}
	else if (context->acceptor_subkey_type == kerb_etype_aes128)
		checksum_type = kerb_ctype_hmac_sha_96_aes128;
	else if (context->acceptor_subkey_type == kerb_etype_aes256)
		checksum_type = kerb_ctype_hmac_sha_96_aes256;

	BOOL result = FALSE;

	KERB_MIC_TOKEN_HEADER mic_header;
	memset(&mic_header, 0, sizeof(mic_header));

	mic_header.token_id = kerb_gss_KerbGssMicToken;
	mic_header.flags = kerb_gss_flag_SentByAcceptor | kerb_gss_flag_AcceptorSubKey;
	mic_header.filler1 = 0xff;
	mic_header.filler2 = 0xffffffff;
	mic_header.sequence_number = _byteswap_uint64(context->acceptor_seq++);

	ULONG cbDataBuffer = cbData + sizeof(mic_header);
	BYTE* pbDataBuffer = (BYTE*)malloc(cbDataBuffer);

	if (pbDataBuffer != NULL)
	{
		memcpy(pbDataBuffer, pvData, cbData);
		memcpy(pbDataBuffer + cbData, &mic_header, sizeof(mic_header));

		ULONG cbKey = kerb_get_key_length(context->acceptor_subkey_type);
		PVOID pvKey = context->acceptor_subkey;

		ULONG cbChecksum = 0;
		PVOID pvChecksum = NULL;

		if (kerb_checksum(checksum_type, kerb_ku_KgUsageAcceptorSign, pvKey, cbKey, pbDataBuffer, cbDataBuffer, &pvChecksum, &cbChecksum))
		{
			ULONG cbOutput = sizeof(mic_header) + cbChecksum;
			BYTE* pbOutput = (BYTE*)malloc(cbOutput);

			if (pbOutput != NULL)
			{
				memcpy(pbOutput, &mic_header, sizeof(mic_header));
				memcpy(pbOutput + sizeof(mic_header), pvChecksum, cbChecksum);

				*ppvOutput = pbOutput;
				*pcbOutput = cbOutput;

				result = TRUE;
			}

			free(pvChecksum);
		}

		free(pbDataBuffer);
	}

	return result;
}

BOOL kerb_seal_message_old(KERB_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	KERB_ETYPE etype = kerb_etype_none;
	KERB_CTYPE ctype = kerb_ctype_none;

	if (context->acceptor_subkey_type != kerb_etype_aes128 && context->acceptor_subkey_type != kerb_etype_aes256)
	{
		printf("[-] Attempted to seal kerberos message with unsupported key type: '%d'\n", context->acceptor_subkey_type);
		return FALSE;
	}
	else if (context->acceptor_subkey_type == kerb_etype_aes128)
	{
		etype = kerb_etype_aes128_plain;
		ctype = kerb_ctype_hmac_sha_96_aes128_ki;
	}
	else if (context->acceptor_subkey_type == kerb_etype_aes256)
	{
		etype = kerb_etype_aes256_plain;
		ctype = kerb_ctype_hmac_sha_96_aes256_ki;
	}
	
	KERB_GSS_SEAL_SIGNATURE signature;
	memset(&signature, 0, sizeof(signature));

	signature.header.token_id = kerb_gss_KerbGssWrapToken;
	signature.header.flags = kerb_gss_flag_SentByAcceptor | kerb_gss_flag_AcceptorSubKey | kerb_gss_flag_Sealed;
	signature.header.filler = 0xff;
	signature.header.sequence_number = _byteswap_uint64(context->acceptor_seq++);

	BYTE confounder[] = { 0xbc, 0xc8, 0x02, 0xe5, 0x6a, 0x70, 0xe3, 0xca, 0xd7, 0x2b, 0xc5, 0x8a, 0xf9, 0x84, 0x7e, 0xb9 };

	BOOL result = FALSE;

	ULONG cbTemp = sizeof(confounder) + cbData + sizeof(signature.header);
	PBYTE pvTemp = (BYTE*)malloc(cbTemp);

	if (pvTemp != NULL)
	{
		memcpy(&pvTemp[0], confounder, sizeof(confounder));
		memcpy(&pvTemp[sizeof(confounder)], pvData, cbData);
		memcpy(&pvTemp[sizeof(confounder) + cbData], &signature.header, sizeof(signature.header));

		ULONG cbChecksum = 0;
		PVOID pvChecksum = NULL;

		if (kerb_checksum(ctype, kerb_ku_KgUsageAcceptorSeal, context->acceptor_subkey, context->acceptor_subkey_length, pvTemp, cbTemp, &pvChecksum, &cbChecksum))
		{
			if (kerb_seal_transform(etype, kerb_ku_KgUsageAcceptorSeal, context->acceptor_subkey, context->acceptor_subkey_length, pvTemp, cbTemp, TRUE))
			{
				signature.header.right_rotation_count = _byteswap_ushort(0x1c);

				memcpy(signature.encrypted_header, &pvTemp[cbTemp - sizeof(signature.encrypted_header)], sizeof(signature.encrypted_header));
				memcpy(signature.checksum, pvChecksum, cbChecksum);
				memcpy(signature.confounder, &pvTemp[0], sizeof(signature.confounder));

				ULONG cbResult = sizeof(signature) + cbData;
				PBYTE pvResult = (BYTE*)malloc(cbResult);

				if (pvResult != NULL)
				{
					memcpy(&pvResult[0], &signature, sizeof(signature));
					memcpy(&pvResult[sizeof(signature)], &pvTemp[sizeof(confounder)], cbData);

					*ppvOutput = pvResult;
					*pcbOutput = cbResult;

					result = TRUE;
				}
			}

			free(pvChecksum);
		}

		free(pvTemp);
	}

	return result;
}

BOOL kerb_unseal_message_old(KERB_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	KERB_ETYPE etype = kerb_etype_none;
	KERB_CTYPE ctype = kerb_ctype_none;

	if (context->acceptor_subkey_type != kerb_etype_aes128 && context->acceptor_subkey_type != kerb_etype_aes256)
	{
		printf("[-] Attempted to unseal kerberos message with unsupported key type: '%d'\n", context->acceptor_subkey_type);
		return FALSE;
	}
	else if (context->acceptor_subkey_type == kerb_etype_aes128)
	{
		etype = kerb_etype_aes128_plain;
		ctype = kerb_ctype_hmac_sha_96_aes128_ki;
	}
	else if (context->acceptor_subkey_type == kerb_etype_aes256)
	{
		etype = kerb_etype_aes256_plain;
		ctype = kerb_ctype_hmac_sha_96_aes256_ki;
	}

	BOOL result = FALSE;

	if (cbData >= sizeof(KERB_GSS_SEAL_SIGNATURE))
	{
		KERB_GSS_SEAL_SIGNATURE* signature = (KERB_GSS_SEAL_SIGNATURE*)pvData;

		ULONG cbBuffer = cbData - sizeof(KERB_GSS_SEAL_SIGNATURE);
		PVOID pvBuffer = (BYTE*)pvData + sizeof(KERB_GSS_SEAL_SIGNATURE);

		ULONG extra_count = _byteswap_ushort(signature->header.extra_count) + 0x1c;
		ULONG right_rotation_count = _byteswap_ushort(signature->header.right_rotation_count) % (cbBuffer - sizeof(KERB_GSS_SIGNATURE_HEADER));

		if (right_rotation_count > extra_count)
		{
			puts("[-] Failed to unseal kerberos message due to data rotation which is currently not implemented");
			return FALSE;
		}

		ULONG cbTemp = sizeof(signature->confounder) + cbBuffer + sizeof(signature->encrypted_header);
		PBYTE pvTemp = (BYTE*)malloc(cbTemp);

		if (pvTemp != NULL)
		{
			memcpy(&pvTemp[0], signature->confounder, sizeof(signature->confounder));
			memcpy(&pvTemp[sizeof(signature->confounder)], pvBuffer, cbBuffer);
			memcpy(&pvTemp[sizeof(signature->confounder) + cbBuffer], signature->encrypted_header, sizeof(signature->encrypted_header));

			if (kerb_seal_transform(etype, kerb_ku_KgUsageInitiatorSeal, context->acceptor_subkey, context->acceptor_subkey_length, pvTemp, cbTemp, FALSE))
			{
				ULONG cbChecksum = 0;
				PVOID pvChecksum = NULL;

				if (kerb_checksum(ctype, kerb_ku_KgUsageInitiatorSeal, context->acceptor_subkey, context->acceptor_subkey_length, pvTemp, cbTemp, &pvChecksum, &cbChecksum))
				{
					if (memcmp(pvChecksum, signature->checksum, min(cbChecksum, sizeof(signature->checksum))) == 0)
					{
						ULONG cbResult = cbBuffer;
						PVOID pvResult = malloc(cbResult);

						if (pvResult != NULL)
						{
							memcpy(pvResult, &pvTemp[sizeof(signature->confounder)], cbBuffer);

							*ppvOutput = pvResult;
							*pcbOutput = cbResult;

							result = TRUE;
						}
					}

					free(pvChecksum);
				}
			}

			free(pvTemp);
		}
	}

	return result;
}

void kerb_build_time(KERB_TIME* time)
{
	SYSTEMTIME system_time;
	GetSystemTime(&system_time);

	time->year = system_time.wYear;
	time->month = (BYTE)system_time.wMonth;
	time->day = (BYTE)system_time.wDay;
	time->hour = (BYTE)system_time.wHour;
	time->minute = (BYTE)system_time.wMinute;
	time->second = (BYTE)system_time.wSecond;
	time->millisecond = system_time.wMilliseconds;
	time->universal = 1;
	time->diff = 0;
}

BOOL kerb_build_pac_request(PVOID* ppvOutput, ULONG* pcbOutput)
{
	KERB_PA_PAC_REQUEST pac_request;
	memset(&pac_request, 0, sizeof(pac_request));

	pac_request.include_pac = 1;

	return asn1_encode_kerb(&pac_request, KERB_PA_PAC_REQUEST_PDU, ppvOutput, pcbOutput);
}

BOOL kerb_build_timestamp(PVOID* ppvOutput, ULONG* pcbOutput)
{
	KERB_ENCRYPTED_TIMESTAMP enc_timestamp;
	memset(&enc_timestamp, 0, sizeof(enc_timestamp));

	kerb_build_time(&enc_timestamp.timestamp);

	return asn1_encode_kerb(&enc_timestamp, KERB_ENCRYPTED_TIMESTAMP_PDU, ppvOutput, pcbOutput);
}

BOOL kerb_build_encrypted_timestamp(KERB_ETYPE etype, LPCVOID pbKey, ULONG cbKey, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	ULONG cbTimestamp = 0;
	PVOID pvTimestamp = NULL;

	if (kerb_build_timestamp(&pvTimestamp, &cbTimestamp))
	{
		ULONG cbEncrypted = 0;
		PVOID pvEncrypted = NULL;

		if (kerb_encrypt(etype, kerb_ku_AsReqPaEncTimestamp, pbKey, cbKey, pvTimestamp, cbTimestamp, &pvEncrypted, &cbEncrypted))
		{
			KERB_ENCRYPTED_DATA enc_data;
			memset(&enc_data, 0, sizeof(enc_data));

			enc_data.encryption_type = etype;
			enc_data.cipher_text.value = pvEncrypted;
			enc_data.cipher_text.length = cbEncrypted;
			
			result = asn1_encode_kerb(&enc_data, KERB_ENCRYPTED_DATA_PDU, ppvOutput, pcbOutput);

			free(pvEncrypted);
		}

		free(pvTimestamp);
	}

	return result;
}

BOOL kerb_build_as_request(KERB_ETYPE etype, LPCVOID pbKey, ULONG cbKey, LPSTR szUsername, LPSTR szRealm, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	ULONG cbEncTimestamp = 0;
	PVOID pvEncTimestamp = NULL;

	if (kerb_build_encrypted_timestamp(etype, pbKey, cbKey, &pvEncTimestamp, &cbEncTimestamp))
	{
		ULONG cbPacRequest = 0;
		PVOID pvPacRequest = NULL;

		if (kerb_build_pac_request(&pvPacRequest, &cbPacRequest))
		{
			KERB_KDC_REQUEST_preauth_data_Element preauth_data[2];
			preauth_data[0].value.preauth_data_type = kerb_PA_ENC_TIMESTAMP;
			preauth_data[0].value.preauth_data.value = pvEncTimestamp;
			preauth_data[0].value.preauth_data.length = cbEncTimestamp;
			preauth_data[0].next = &preauth_data[1];
			preauth_data[1].value.preauth_data_type = kerb_PA_PAC_REQUEST;
			preauth_data[1].value.preauth_data.value = pvPacRequest;
			preauth_data[1].value.preauth_data.length = cbPacRequest;
			preauth_data[1].next = NULL;

			KERB_KDC_REQUEST_BODY_encryption_type_Element encryption_types[1];
			encryption_types[0].value = kerb_etype_aes256;
			encryption_types[0].next = NULL;

			KERB_PRINCIPAL_NAME_name_string_Element client_name[1];
			client_name[0].value = szUsername;
			client_name[0].next = NULL;

			KERB_PRINCIPAL_NAME_name_string_Element server_name[2];
			server_name[0].value = "krbtgt";
			server_name[0].next = &server_name[1];
			server_name[1].value = szRealm;
			server_name[1].next = NULL;

			BYTE kdc_options[4];
			memset(kdc_options, 0, sizeof(kdc_options));

			kerb_set_bitstring32(kdc_options, kerb_kdc_opt_Forwardable | kerb_kdc_opt_Renewable | kerb_kdc_opt_RenewableOk);

			KERB_AS_REQUEST as_request;
			memset(&as_request, 0, sizeof(as_request));

			as_request.version = 5;
			as_request.message_type = kerb_mt_KrbAsReq;

			as_request.bit_mask |= KERB_KDC_REQUEST_preauth_data_present;
			as_request.preauth_data = preauth_data;

			as_request.request_body.kdc_options.value = kdc_options;
			as_request.request_body.kdc_options.length = sizeof(kdc_options) * 8;

			as_request.request_body.bit_mask |= KERB_KDC_REQUEST_BODY_client_name_present;
			as_request.request_body.client_name.name_type = kerb_NT_PRINCIPAL;
			as_request.request_body.client_name.name_string = client_name;

			as_request.request_body.realm = szRealm;

			as_request.request_body.bit_mask |= KERB_KDC_REQUEST_BODY_server_name_present;
			as_request.request_body.server_name.name_type = kerb_NT_SRV_INST;
			as_request.request_body.server_name.name_string = server_name;

			kerb_build_time(&as_request.request_body.endtime);
			as_request.request_body.endtime.year += 1;

			as_request.request_body.nonce = rand();
			as_request.request_body.encryption_type = encryption_types;
			
			result = asn1_encode_kerb(&as_request, KERB_AS_REQUEST_PDU, ppvOutput, pcbOutput);

			free(pvPacRequest);
		}

		free(pvEncTimestamp);
	}

	return result;
}

BOOL kerb_handle_tgt_request(KERB_CONTEXT* context, LPCVOID pvTgtRequest, ULONG cbTgtRequest, BOOL fGssApi, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;

	*ppvOutput = NULL;
	*pcbOutput = 0;

	KERB_TGT_REQUEST* tgt_request = NULL;

	if (asn1_decode_kerb(pvTgtRequest, cbTgtRequest, KERB_TGT_REQUEST_PDU, &tgt_request))
	{
		if (tgt_request->version != 5)
			printf("[-] Kerberos TGT-REQ must target version 5\n");
		else if (tgt_request->message_type != kerb_mt_KrbTgtReqU2U)
			printf("[-] Kerberos TGT-REQ handling for message type '%d' is currently not supported\n", tgt_request->message_type);
		else
		{
			ULONG cbAsRequest = 0;
			PVOID pvAsRequest = NULL;

			if (kerb_build_as_request(kerb_etype_aes256, context->longterm_key_aes256, 32, context->username, context->domain, &pvAsRequest, &cbAsRequest))
			{
				ULONG cbAsReply = 0;
				PVOID pvAsReply = NULL;

				BOOL as_req_ok = kerb_send_kdc_request(context->domain, pvAsRequest, cbAsRequest, &pvAsReply, &cbAsReply);

				free(pvAsRequest);

				if (!as_req_ok && pvAsReply != NULL)
				{
					printf("[*] Trying to rebuild longterm keys with KDC-provided salt: %s\n", (const char*)pvAsReply);
					kerb_build_longterm_keys(context, (const char*)pvAsReply);

					free(pvAsReply);
					pvAsReply = NULL;

					if (kerb_build_as_request(kerb_etype_aes256, context->longterm_key_aes256, 32, context->username, context->domain, &pvAsRequest, &cbAsRequest))
					{
						as_req_ok = kerb_send_kdc_request(context->domain, pvAsRequest, cbAsRequest, &pvAsReply, &cbAsReply);

						free(pvAsRequest);
					}
				}

				if (as_req_ok)
				{
					KERB_AS_REPLY* as_reply = NULL;

					if (asn1_decode_kerb(pvAsReply, cbAsReply, KERB_AS_REPLY_PDU, &as_reply))
					{
						ULONG cbKey = kerb_get_key_length(as_reply->encrypted_part.encryption_type);
						PVOID pvKey = kerb_get_key_buffer(context, as_reply->encrypted_part.encryption_type);

						ULONG cbDecrypted = 0;
						PVOID pvDecrypted = NULL;

						if (cbKey != 0 && pvKey != NULL && kerb_decrypt(as_reply->encrypted_part.encryption_type, kerb_ku_AsRepEncryptedPart, pvKey, cbKey, 
							as_reply->encrypted_part.cipher_text.value, as_reply->encrypted_part.cipher_text.length, &pvDecrypted, &cbDecrypted))
						{
							KERB_ENCRYPTED_AS_REPLY* enc_as_reply = NULL;

							if (asn1_decode_kerb(pvDecrypted, cbDecrypted, KERB_ENCRYPTED_AS_REPLY_PDU, &enc_as_reply))
							{
								if (enc_as_reply->session_key.keyvalue.length <= sizeof(context->session_key))
								{
									context->session_key_type = enc_as_reply->session_key.keytype;
									memset(context->session_key, 0, sizeof(context->session_key));
									memcpy(context->session_key, enc_as_reply->session_key.keyvalue.value, enc_as_reply->session_key.keyvalue.length);
								}

								KERB_TGT_REPLY tgt_reply;
								memset(&tgt_reply, 0, sizeof(tgt_reply));

								tgt_reply.version = 5;
								tgt_reply.message_type = kerb_mt_KrbTgtRepU2U;

								memcpy(&tgt_reply.ticket, &as_reply->ticket, sizeof(KERB_TICKET));

								ULONG cbTgtReply = 0;
								PVOID pvTgtReply = NULL;

								if (asn1_encode_kerb(&tgt_reply, KERB_TGT_REPLY_PDU, &pvTgtReply, &cbTgtReply))
								{
									if (fGssApi)
									{
										KERB_GSS_InitialContextToken gss_api_token;
										memset(&gss_api_token, 0, sizeof(gss_api_token));

										struct ASN1objectidentifier_s mech_type[8];
										mech_type[0].value = 1;
										mech_type[0].next = &mech_type[1];
										mech_type[1].value = 2;
										mech_type[1].next = &mech_type[2];
										mech_type[2].value = 840;
										mech_type[2].next = &mech_type[3];
										mech_type[3].value = 113554;
										mech_type[3].next = &mech_type[4];
										mech_type[4].value = 1;
										mech_type[4].next = &mech_type[5];
										mech_type[5].value = 2;
										mech_type[5].next = &mech_type[6];
										mech_type[6].value = 2;
										mech_type[6].next = &mech_type[7];
										mech_type[7].value = 3;
										mech_type[7].next = NULL;

										gss_api_token.MechType = mech_type; // 1.2.840.113554.1.2.2.3
										gss_api_token.TokenId = kerb_gss_KerbExportedNameToken;
										gss_api_token.InnerToken.value = pvTgtReply;
										gss_api_token.InnerToken.length = cbTgtReply;

										ULONG cbGssApiToken = 0;
										PVOID pvGssApiToken = NULL;

										if (asn1_encode_gssapi(&gss_api_token, InitialContextToken_PDU, &pvGssApiToken, &cbGssApiToken))
										{
											*ppvOutput = pvGssApiToken;
											*pcbOutput = cbGssApiToken;

											context->state = kerb_st_TgtReplySent;
											result = TRUE;
										}

										free(pvTgtReply);
									}
									else
									{
										*ppvOutput = pvTgtReply;
										*pcbOutput = cbTgtReply;

										context->state = kerb_st_TgtReplySent;
										result = TRUE;
									}
								}

								asn1_free_kerb(enc_as_reply, KERB_ENCRYPTED_AS_REPLY_PDU);
							}

							free(pvDecrypted);
						}

						asn1_free_kerb(as_reply, KERB_AS_REPLY_PDU);
					}

					free(pvAsReply);
				}
			}
		}

		asn1_free_kerb(tgt_request, KERB_TGT_REQUEST_PDU);
	}

	return result;
}

BOOL kerb_handle_ap_request(KERB_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, BOOL fGssApi, PVOID* ppvResponse, ULONG* pcbResponse)
{
	BOOL result = FALSE;

	KERB_AP_REQUEST* ap_request = NULL;

	if (asn1_decode_kerb(pvRequest, cbRequest, KERB_AP_REQUEST_PDU, &ap_request))
	{
		if (ap_request->version != 5)
			printf("[-] Kerberos AP-REQ must target version 5\n");
		else if (ap_request->message_type != kerb_mt_KrbApReq)
			printf("[-] Kerberos AP-REQ handling for message type '%d' is currently not supported\n", ap_request->message_type);
		else
		{
			ULONG ap_options = kerb_get_bitstring32(ap_request->ap_options.value, ap_request->ap_options.length);

			KERB_ETYPE key_type = kerb_etype_none;

			ULONG cbKey = 0;
			PVOID pvKey = NULL;

			if ((ap_options & kerb_ap_req_opt_UseSessionKey) != 0)
			{
				key_type = context->session_key_type;

				cbKey = kerb_get_key_length(key_type);
				pvKey = context->session_key;
			}
			else
			{
				key_type = ap_request->ticket.encrypted_part.encryption_type;

				cbKey = kerb_get_key_length(key_type);
				pvKey = kerb_get_key_buffer(context, key_type);
			}

			ULONG cbDecryptedTicket = 0;
			PVOID pvDecryptedTicket = NULL;

			if (key_type != kerb_etype_none && cbKey != 0 && pvKey != NULL && kerb_decrypt(key_type, kerb_ku_AsRepTgsRep, pvKey, cbKey, 
				ap_request->ticket.encrypted_part.cipher_text.value, ap_request->ticket.encrypted_part.cipher_text.length, &pvDecryptedTicket, &cbDecryptedTicket))
			{
				KERB_ENCRYPTED_TICKET* enc_ticket = NULL;

				if (asn1_decode_kerb(pvDecryptedTicket, cbDecryptedTicket, KERB_ENCRYPTED_TICKET_PDU, &enc_ticket))
				{
					ULONG cbDecryptedAuthenticator = 0;
					PVOID pvDecryptedAuthenticator = NULL;

					if (kerb_decrypt(enc_ticket->key.keytype, kerb_ku_ApReqAuthenticator, enc_ticket->key.keyvalue.value, enc_ticket->key.keyvalue.length,
						ap_request->authenticator.cipher_text.value, ap_request->authenticator.cipher_text.length, &pvDecryptedAuthenticator, &cbDecryptedAuthenticator))
					{
						KERB_AUTHENTICATOR* authenticator = NULL;

						if (asn1_decode_kerb(pvDecryptedAuthenticator, cbDecryptedAuthenticator, KERB_AUTHENTICATOR_PDU, &authenticator))
						{
							if ((authenticator->bit_mask & KERB_AUTHENTICATOR_subkey_present) != 0 && authenticator->subkey.keyvalue.length <= sizeof(context->initiator_subkey))
							{
								context->initiator_subkey_type = authenticator->subkey.keytype;
								memset(context->initiator_subkey, 0, sizeof(context->initiator_subkey));
								memcpy(context->initiator_subkey, authenticator->subkey.keyvalue.value, authenticator->subkey.keyvalue.length);
							}

							if ((authenticator->bit_mask & KERB_AUTHENTICATOR_sequence_number_present) != 0)
								context->initiator_seq = _byteswap_ulong(kerb_get_bitstring32(authenticator->sequence_number.value, authenticator->sequence_number.length));

							if ((ap_options & kerb_ap_req_opt_MutualRequired) == 0)
							{
								context->state = kerb_st_ApRequestReceived;
								result = TRUE;
							}
							else
							{
								KERB_ENCRYPTED_AP_REPLY enc_ap_reply;
								memset(&enc_ap_reply, 0, sizeof(enc_ap_reply));

								memcpy(&enc_ap_reply.client_time, &authenticator->client_time, sizeof(KERB_TIME));
								enc_ap_reply.client_usec = authenticator->client_usec;

								enc_ap_reply.bit_mask |= KERB_ENCRYPTED_AP_REPLY_subkey_present;
								enc_ap_reply.subkey.keytype = context->acceptor_subkey_type;
								enc_ap_reply.subkey.keyvalue.value = context->acceptor_subkey;
								enc_ap_reply.subkey.keyvalue.length = context->acceptor_subkey_length;

								enc_ap_reply.bit_mask |= KERB_ENCRYPTED_AP_REPLY_sequence_number_present;
								enc_ap_reply.sequence_number = context->acceptor_seq & 0xffffffff;

								ULONG cbEncApReply = 0;
								PVOID pvEncApReply = NULL;

								if (asn1_encode_kerb(&enc_ap_reply, KERB_ENCRYPTED_AP_REPLY_PDU, &pvEncApReply, &cbEncApReply))
								{
									ULONG cbEncryptedApReply = 0;
									PVOID pvEncryptedApReply = NULL;

									if (kerb_encrypt(enc_ticket->key.keytype, kerb_ku_ApRepEncryptedPart, enc_ticket->key.keyvalue.value, enc_ticket->key.keyvalue.length,
										pvEncApReply, cbEncApReply, &pvEncryptedApReply, &cbEncryptedApReply))
									{
										KERB_AP_REPLY ap_reply;
										memset(&ap_reply, 0, sizeof(ap_reply));

										ap_reply.version = 5;
										ap_reply.message_type = kerb_mt_KrbApRep;

										ap_reply.encrypted_part.encryption_type = enc_ticket->key.keytype;
										ap_reply.encrypted_part.cipher_text.value = pvEncryptedApReply;
										ap_reply.encrypted_part.cipher_text.length = cbEncryptedApReply;

										ULONG cbApReply = 0;
										PVOID pvApReply = NULL;

										if (asn1_encode_kerb(&ap_reply, KERB_AP_REPLY_PDU, &pvApReply, &cbApReply))
										{
											if (fGssApi)
											{
												KERB_GSS_InitialContextToken gss_api_token;
												memset(&gss_api_token, 0, sizeof(gss_api_token));

												struct ASN1objectidentifier_s mech_type[8];
												mech_type[0].value = 1;
												mech_type[0].next = &mech_type[1];
												mech_type[1].value = 2;
												mech_type[1].next = &mech_type[2];
												mech_type[2].value = 840;
												mech_type[2].next = &mech_type[3];
												mech_type[3].value = 113554;
												mech_type[3].next = &mech_type[4];
												mech_type[4].value = 1;
												mech_type[4].next = &mech_type[5];
												mech_type[5].value = 2;
												mech_type[5].next = &mech_type[6];
												mech_type[6].value = 2;
												mech_type[6].next = &mech_type[7];
												mech_type[7].value = 3;
												mech_type[7].next = NULL;

												gss_api_token.MechType = mech_type; // 1.2.840.113554.1.2.2.3
												gss_api_token.TokenId = kerb_gss_KerbApRep;
												gss_api_token.InnerToken.value = pvApReply;
												gss_api_token.InnerToken.length = cbApReply;

												ULONG cbGssApiToken = 0;
												PVOID pvGssApiToken = NULL;

												if (asn1_encode_gssapi(&gss_api_token, InitialContextToken_PDU, &pvGssApiToken, &cbGssApiToken))
												{
													*ppvResponse = pvGssApiToken;
													*pcbResponse = cbGssApiToken;

													context->state = kerb_st_ApReplySent;
													result = TRUE;
												}

												free(pvApReply);
											}
											else
											{
												*ppvResponse = pvApReply;
												*pcbResponse = cbApReply;

												context->state = kerb_st_ApReplySent;
												result = TRUE;
											}
										}

										free(pvEncryptedApReply);
									}

									free(pvEncApReply);
								}
							}

							asn1_free_kerb(authenticator, KERB_AUTHENTICATOR_PDU);
						}

						free(pvDecryptedAuthenticator);
					}

					asn1_free_kerb(enc_ticket, KERB_ENCRYPTED_TICKET_PDU);
				}

				free(pvDecryptedTicket);
			}
		}

		asn1_free_kerb(ap_request, KERB_AP_REQUEST_PDU);
	}

	return result;
}

BOOL kerb_handle_token(KERB_CONTEXT* context, KERB_GSS_TOKEN_ID token_id, LPCVOID pvToken, ULONG cbToken, BOOL fGssApi, PVOID* ppvResponse, ULONG* pcbResponse)
{
	switch (token_id)
	{
	case kerb_gss_KerbTgtReq:
		return kerb_handle_tgt_request(context, pvToken, cbToken, fGssApi, ppvResponse, pcbResponse);

	case kerb_gss_KerbApReq:
		return kerb_handle_ap_request(context, pvToken, cbToken, fGssApi, ppvResponse, pcbResponse);

	default:
		printf("[-] Kerberos handling for token id '%d' is not currently supported\n", token_id);
		return FALSE;
	}
}

BOOL kerb_accept_token(KERB_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, PVOID* ppvResponse, ULONG* pcbResponse)
{
	BOOL result = FALSE;

	if (cbRequest > 0 && ((BYTE*)pvRequest)[0] == 0x60) // GSS-API pseudo ASN.1 frame
	{
		KERB_GSS_InitialContextToken* token = NULL;

		if (asn1_decode_gssapi(pvRequest, cbRequest, InitialContextToken_PDU, &token))
		{
			result = kerb_handle_token(context, token->TokenId, token->InnerToken.value, token->InnerToken.length, TRUE, ppvResponse, pcbResponse);

			asn1_free_gssapi(token, InitialContextToken_PDU);
		}
	}
	else if (cbRequest >= 2)
	{
		KERB_GSS_TOKEN_ID token_id = *(USHORT*)pvRequest;

		result = kerb_handle_token(context, token_id, (BYTE*)pvRequest + 2, cbRequest - 2, FALSE, ppvResponse, pcbResponse);
	}

	return result;
}