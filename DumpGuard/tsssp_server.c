#include "tsssp_server.h"

#include "asn1_tsssp.h"

#include <credssp.h>
#include <stdio.h>

BOOL tsssp_server_init_context(TSSSP_SERVER_CONTEXT* context, LPCSTR domain, LPCSTR username, LPCSTR password)
{
	memset(context, 0, sizeof(TSSSP_SERVER_CONTEXT));

	context->authenticated = FALSE;

	return spnego_init_context(&context->spnego, domain, username, password);
}

void tsssp_server_free_context(TSSSP_SERVER_CONTEXT* context)
{
	spnego_free_context(&context->spnego);

	if (context->pvPrimaryCreds != NULL)
		free(context->pvPrimaryCreds);

	if (context->pvSupplementalCreds != NULL)
		free(context->pvSupplementalCreds);
}

BOOL tsssp_server_encrypt(TSSSP_SERVER_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	return spnego_encrypt(&context->spnego, pvData, cbData, ppvOutput, pcbOutput);
}

BOOL tsssp_server_decrypt(TSSSP_SERVER_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	return spnego_decrypt(&context->spnego, pvData, cbData, ppvOutput, pcbOutput);
}

BOOL tsssp_get_cert_public_key(LPCVOID pvCert, ULONG cbCert, PVOID* ppvPublicKey, ULONG* pcbPublicKey)
{
	BOOL result = FALSE;

	PCCERT_CONTEXT cert = CertCreateCertificateContext(X509_ASN_ENCODING, (LPCBYTE)pvCert, cbCert);

	if (cert != NULL)
	{
		CRYPT_BIT_BLOB* public_key = &cert->pCertInfo->SubjectPublicKeyInfo.PublicKey;

		ULONG cbData = public_key->cbData;
		PVOID pvData = malloc(cbData);

		if (pvData != NULL)
		{
			memcpy(pvData, public_key->pbData, cbData);

			*ppvPublicKey = pvData;
			*pcbPublicKey = cbData;

			result = TRUE;
		}

		CertFreeCertificateContext(cert);
	}

	return result;
}

BOOL tsssp_calculate_binding_hash(BOOL fClient, PVOID pvNonce, ULONG cbNonce, PVOID pvPublicKey, ULONG cbPublicKey, BYTE pbHash[32])
{
	static char client_binding[] = "CredSSP Client-To-Server Binding Hash";
	static char server_binding[] = "CredSSP Server-To-Client Binding Hash";

	BOOL result = FALSE;

	BCRYPT_ALG_HANDLE hAlgorithm = NULL;

	if (BCryptOpenAlgorithmProvider(&hAlgorithm, L"SHA256", NULL, 0) >= 0)
	{
		DWORD dwObjectLength = 0;
		DWORD dwResultLength = 0;

		if (BCryptGetProperty(hAlgorithm, L"ObjectLength", (PUCHAR)&dwObjectLength, sizeof(DWORD), &dwResultLength, 0) >= 0)
		{
			DWORD dwHashDigestLength = 0;

			if (BCryptGetProperty(hAlgorithm, L"HashDigestLength", (PUCHAR)&dwHashDigestLength, sizeof(DWORD), &dwResultLength, 0) >= 0 && dwHashDigestLength == 32)
			{
				PVOID pvHashObject = malloc(dwObjectLength);

				if (pvHashObject != NULL)
				{
					BCRYPT_HASH_HANDLE hHash = NULL;

					if (BCryptCreateHash(hAlgorithm, &hHash, pvHashObject, dwObjectLength, NULL, 0, 0) >= 0)
					{
						ULONG cbBinding = fClient ? sizeof(client_binding) : sizeof(server_binding);
						PVOID pbBinding = fClient ? client_binding : server_binding;

						if (BCryptHashData(hHash, pbBinding, cbBinding, 0) >= 0)
						{
							if (BCryptHashData(hHash, pvNonce, cbNonce, 0) >= 0)
							{
								if (BCryptHashData(hHash, pvPublicKey, cbPublicKey, 0) >= 0)
								{
									if (BCryptFinishHash(hHash, pbHash, 32, 0) >= 0)
										result = TRUE;
								}
							}
						}

						BCryptDestroyHash(hHash);
					}

					free(pvHashObject);
				}
			}
		}

		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
	}

	return result;
}

BOOL tsssp_server_accept_security_context(TSSSP_SERVER_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, LPCVOID pvCert, ULONG cbCert, PVOID* ppvResponse, ULONG* pcbResponse)
{
	BOOL result = FALSE;

	TSRequest ts_response;
	memset(&ts_response, 0, sizeof(ts_response));

	TSRequest* ts_request = NULL;

	if (asn1_decode_tsssp(pvRequest, cbRequest, ASN1_PDU_TSREQUEST, &ts_request))
	{
		if ((ts_request->Flags & TSREQUEST_HAS_NEGOTOKENS) != 0)
		{
			NegoData* current = ts_request->NegoTokens;

			while (current != NULL)
			{
				ULONG cbNegoResponse = 0;
				PVOID pvNegoResponse = NULL;

				if (spnego_accept_token(&context->spnego, current->NegoToken.value, current->NegoToken.length, &pvNegoResponse, &cbNegoResponse))
				{
					if (pvNegoResponse != NULL && cbNegoResponse != 0)
					{
						NegoData* response = malloc(sizeof(NegoData));

						if (response == NULL)
							free(pvNegoResponse);
						else
						{
							response->Next = ts_response.NegoTokens;
							response->NegoToken.value = pvNegoResponse;
							response->NegoToken.length = cbNegoResponse;

							ts_response.Flags |= TSREQUEST_HAS_NEGOTOKENS;
							ts_response.NegoTokens = response;
						}
					}
				}
				else if (context->spnego.kerb.state != kerb_st_Authenticated)
				{
					puts("Failed to generate SPNEGO token");
				}

				current = current->Next;
			}
		}

		if ((ts_request->Flags & TSREQUEST_HAS_PUBKEYAUTH) != 0)
		{
			ULONG cbDecrypted = 0;
			PVOID pvDecrypted = NULL;

			if (tsssp_server_decrypt(context, ts_request->PubKeyAuth.value, ts_request->PubKeyAuth.length, &pvDecrypted, &cbDecrypted))
			{
				ULONG cbPubKey = 0;
				PVOID pvPubKey = NULL;

				if (tsssp_get_cert_public_key(pvCert, cbCert, &pvPubKey, &cbPubKey))
				{
					ULONG cbData = 0;
					PVOID pvData = NULL;

					if (ts_request->Version <= 4)
					{
						if (cbDecrypted != cbPubKey || memcmp(pvDecrypted, pvPubKey, min(cbDecrypted, cbPubKey)) != 0)
							printf("The client pubkey auth contained an incorrect public key");
						else
						{
							ULONG cbAuth = cbPubKey;
							PVOID pvAuth = malloc(cbAuth);

							if (pvAuth != NULL)
							{
								memcpy(pvAuth, pvPubKey, cbAuth);

								if (ts_request->Version <= 1)
									*(DWORD*)pvAuth += 1;
								else
									*(BYTE*)pvAuth += 1;

								pvData = pvAuth;
								cbData = cbAuth;
							}
						}
					}
					else if ((ts_request->Flags & TSREQUEST_HAS_CLIENTNONCE) != 0 && ts_request->ClientNonce.value != NULL && ts_request->ClientNonce.length != 0)
					{
						ULONG cbHash = 32;
						PVOID pvHash = malloc(cbHash);

						if (pvHash != NULL)
						{
							if (!tsssp_calculate_binding_hash(TRUE, ts_request->ClientNonce.value, ts_request->ClientNonce.length, pvPubKey, cbPubKey, pvHash))
								puts("The client pubkey auth could not be verified");
							else if (cbDecrypted != cbHash || memcmp(pvDecrypted, pvHash, min(cbDecrypted, cbHash)) != 0)
								puts("The client pubkey auth contained a hash for an incorrect public key");
							else if (tsssp_calculate_binding_hash(FALSE, ts_request->ClientNonce.value, ts_request->ClientNonce.length, pvPubKey, cbPubKey, pvHash))
							{
								pvData = pvHash;
								cbData = cbHash;
							}
						}
					}

					if (pvData != NULL && cbData != 0)
					{
						ULONG cbEncrypted = 0;
						PVOID pvEncrypted = NULL;

						if (tsssp_server_encrypt(context, pvData, cbData, &pvEncrypted, &cbEncrypted))
						{
							ts_response.Flags |= TSREQUEST_HAS_PUBKEYAUTH;
							ts_response.PubKeyAuth.value = pvEncrypted;
							ts_response.PubKeyAuth.length = cbEncrypted;
						}

						free(pvData);
					}

					free(pvPubKey);
				}

				free(pvDecrypted);
			}
		}

		if ((ts_request->Flags & TSREQUEST_HAS_AUTHINFO) != 0)
		{
			ULONG cbDecrypted = 0;
			PVOID pvDecrypted = NULL;

			if (tsssp_server_decrypt(context, ts_request->AuthInfo.value, ts_request->AuthInfo.length, &pvDecrypted, &cbDecrypted))
			{
				TSCredentials* ts_creds = NULL;

				if (asn1_decode_tsssp(pvDecrypted, cbDecrypted, ASN1_PDU_TSCREDENTIALS, &ts_creds))
				{
					TSRemoteGuardCreds* ts_rg_creds = NULL;

					if (ts_creds->CredType != TsCredTypeRemoteGuard)
						printf("Obtained unusable credential type: %d\n", ts_creds->CredType);
					else if (asn1_decode_tsssp(ts_creds->Credentials.value, ts_creds->Credentials.length, ASN1_PDU_TSREMOTEGUARDCREDS, &ts_rg_creds))
					{
						context->cbPrimaryCreds = ts_rg_creds->LogonCred.CredBuffer.length;
						context->pvPrimaryCreds = malloc(context->cbPrimaryCreds);

						if (context->pvPrimaryCreds != NULL)
							memcpy(context->pvPrimaryCreds, ts_rg_creds->LogonCred.CredBuffer.value, context->cbPrimaryCreds);

						if ((ts_rg_creds->Flags & TSREMOTEGUARDCREDS_HAS_SUPPLEMENTAL_CREDS) != 0)
						{
							TSRemoteGuardCreds_supplementalCreds* current = ts_rg_creds->SupplementalCreds;

							while (current != NULL)
							{
								if (current->Value.PackageName.length >= 8 && wcsncmp((const wchar_t*)current->Value.PackageName.value, L"NTLM", 4) == 0)
								{
									context->cbSupplementalCreds = current->Value.CredBuffer.length;
									context->pvSupplementalCreds = malloc(context->cbSupplementalCreds);

									if (context->pvSupplementalCreds != NULL)
										memcpy(context->pvSupplementalCreds, current->Value.CredBuffer.value, context->cbSupplementalCreds);

									break;
								}

								current = current->Next;
							}
						}
						
						asn1_free_tsssp(ts_rg_creds, ASN1_PDU_TSREMOTEGUARDCREDS);
					}

					asn1_free_tsssp(ts_creds, ASN1_PDU_TSCREDENTIALS);
				}

				free(pvDecrypted);
			}
		}

		if (ts_response.Flags == 0)
			context->authenticated = result = TRUE;
		else
		{
			ts_response.Version = 6;

			ULONG cbResponse = 0;
			PVOID pvResponse = NULL;

			if (asn1_encode_tsssp(&ts_response, ASN1_PDU_TSREQUEST, &pvResponse, &cbResponse))
			{
				*ppvResponse = pvResponse;
				*pcbResponse = cbResponse;
			}

			if (ts_response.PubKeyAuth.value != NULL)
				free(ts_response.PubKeyAuth.value);

			NegoData* current = ts_response.NegoTokens;

			while (current != NULL)
			{
				NegoData* next = current->Next;

				free(current->NegoToken.value);
				free(current);

				current = next;
			}
		}

		asn1_free_tsssp(ts_request, ASN1_PDU_TSREQUEST);
	}

	return result;
}