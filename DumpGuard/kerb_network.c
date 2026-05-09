#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#include "kerb_crypto.h"
#include "kerb_network.h"
#include "asn1_krb5.h"

#include <DsGetDC.h>
#include <LM.h>
#include <stdio.h>

typedef struct {
	const char* name;
	const char* desc;
} krb_err_entry;

static const krb_err_entry krb_err_table[] =
{
	[KDC_ERR_NONE] = {"KDC_ERR_NONE", "No error"},
	[KDC_ERR_NAME_EXP] = {"KDC_ERR_NAME_EXP", "Client's entry in database has expired"},
	[KDC_ERR_SERVICE_EXP] = {"KDC_ERR_SERVICE_EXP", "Server's entry in database has expired"},
	[KDC_ERR_BAD_PVNO] = {"KDC_ERR_BAD_PVNO", "Requested protocol version number not supported"},
	[KDC_ERR_C_OLD_MAST_KVNO] = {"KDC_ERR_C_OLD_MAST_KVNO", "Client's key encrypted in old master key"},
	[KDC_ERR_S_OLD_MAST_KVNO] = {"KDC_ERR_S_OLD_MAST_KVNO", "Server's key encrypted in old master key"},
	[KDC_ERR_C_PRINCIPAL_UNKNOWN] = {"KDC_ERR_C_PRINCIPAL_UNKNOWN", "Client not found in Kerberos database"},
	[KDC_ERR_S_PRINCIPAL_UNKNOWN] = {"KDC_ERR_S_PRINCIPAL_UNKNOWN", "Server not found in Kerberos database"},
	[KDC_ERR_PRINCIPAL_NOT_UNIQUE] = {"KDC_ERR_PRINCIPAL_NOT_UNIQUE", "Multiple principal entries in database"},
	[KDC_ERR_NULL_KEY] = {"KDC_ERR_NULL_KEY", "The client or server has a null key"},
	[KDC_ERR_CANNOT_POSTDATE] = {"KDC_ERR_CANNOT_POSTDATE", "Ticket not eligible for postdating"},
	[KDC_ERR_NEVER_VALID] = {"KDC_ERR_NEVER_VALID", "Requested starttime is later than end time"},
	[KDC_ERR_POLICY] = {"KDC_ERR_POLICY", "KDC policy rejects request"},
	[KDC_ERR_BADOPTION] = {"KDC_ERR_BADOPTION", "KDC cannot accommodate requested option"},
	[KDC_ERR_ETYPE_NOSUPP] = {"KDC_ERR_ETYPE_NOSUPP", "KDC has no support for encryption type"},
	[KDC_ERR_SUMTYPE_NOSUPP] = {"KDC_ERR_SUMTYPE_NOSUPP", "KDC has no support for checksum type"},
	[KDC_ERR_PADATA_TYPE_NOSUPP] = {"KDC_ERR_PADATA_TYPE_NOSUPP", "KDC has no support for padata type"},
	[KDC_ERR_TRTYPE_NOSUPP] = {"KDC_ERR_TRTYPE_NOSUPP", "KDC has no support for transited type"},
	[KDC_ERR_CLIENT_REVOKED] = {"KDC_ERR_CLIENT_REVOKED", "Clients credentials have been revoked"},
	[KDC_ERR_SERVICE_REVOKED] = {"KDC_ERR_SERVICE_REVOKED", "Credentials for server have been revoked"},
	[KDC_ERR_TGT_REVOKED] = {"KDC_ERR_TGT_REVOKED", "TGT has been revoked"},
	[KDC_ERR_CLIENT_NOTYET] = {"KDC_ERR_CLIENT_NOTYET", "Client not yet valid; try again later"},
	[KDC_ERR_SERVICE_NOTYET] = {"KDC_ERR_SERVICE_NOTYET", "Server not yet valid; try again later"},
	[KDC_ERR_KEY_EXPIRED] = {"KDC_ERR_KEY_EXPIRED", "Password has expired; change password to reset"},
	[KDC_ERR_PREAUTH_FAILED] = {"KDC_ERR_PREAUTH_FAILED", "Pre-authentication information was invalid"},
	[KDC_ERR_PREAUTH_REQUIRED] = {"KDC_ERR_PREAUTH_REQUIRED", "Additional pre-authentication required"},
	[KDC_ERR_SERVER_NOMATCH] = {"KDC_ERR_SERVER_NOMATCH", "Requested server and ticket don't match"},
	[KDC_ERR_MUST_USE_USER2USER] = {"KDC_ERR_MUST_USE_USER2USER", "Server principal valid for user2user only"},
	[KDC_ERR_PATH_NOT_ACCEPTED] = {"KDC_ERR_PATH_NOT_ACCEPTED", "KDC Policy rejects transited path"},
	[KDC_ERR_SVC_UNAVAILABLE] = {"KDC_ERR_SVC_UNAVAILABLE", "A service is not available"},

	[KRB_AP_ERR_BAD_INTEGRITY] = {"KRB_AP_ERR_BAD_INTEGRITY", "Integrity check on decrypted field failed"},
	[KRB_AP_ERR_TKT_EXPIRED] = {"KRB_AP_ERR_TKT_EXPIRED", "Ticket expired"},
	[KRB_AP_ERR_TKT_NYV] = {"KRB_AP_ERR_TKT_NYV", "Ticket not yet valid"},
	[KRB_AP_ERR_REPEAT] = {"KRB_AP_ERR_REPEAT", "Request is a replay"},
	[KRB_AP_ERR_NOT_US] = {"KRB_AP_ERR_NOT_US", "The ticket isn't for us"},
	[KRB_AP_ERR_BADMATCH] = {"KRB_AP_ERR_BADMATCH", "Ticket and authenticator don't match"},
	[KRB_AP_ERR_SKEW] = {"KRB_AP_ERR_SKEW", "Clock skew too great"},
	[KRB_AP_ERR_BADADDR] = {"KRB_AP_ERR_BADADDR", "Incorrect net address"},
	[KRB_AP_ERR_BADVERSION] = {"KRB_AP_ERR_BADVERSION", "Protocol version mismatch"},
	[KRB_AP_ERR_MSG_TYPE] = {"KRB_AP_ERR_MSG_TYPE", "Invalid msg type"},
	[KRB_AP_ERR_MODIFIED] = {"KRB_AP_ERR_MODIFIED", "Message stream modified"},
	[KRB_AP_ERR_BADORDER] = {"KRB_AP_ERR_BADORDER", "Message out of order"},
	[KRB_AP_ERR_BADKEYVER] = {"KRB_AP_ERR_BADKEYVER", "Specified version of key is not available"},
	[KRB_AP_ERR_NOKEY] = {"KRB_AP_ERR_NOKEY", "Service key not available"},
	[KRB_AP_ERR_MUT_FAIL] = {"KRB_AP_ERR_MUT_FAIL", "Mutual authentication failed"},
	[KRB_AP_ERR_BADDIRECTION] = {"KRB_AP_ERR_BADDIRECTION", "Incorrect message direction"},
	[KRB_AP_ERR_METHOD] = {"KRB_AP_ERR_METHOD", "Alternative authentication method required"},
	[KRB_AP_ERR_BADSEQ] = {"KRB_AP_ERR_BADSEQ", "Incorrect sequence number in message"},
	[KRB_AP_ERR_INAPP_CKSUM] = {"KRB_AP_ERR_INAPP_CKSUM", "Inappropriate type of checksum in message"},
	[KRB_AP_PATH_NOT_ACCEPTED] = {"KRB_AP_PATH_NOT_ACCEPTED", "Policy rejects transited path"},
	[KRB_ERR_RESPONSE_TOO_BIG] = {"KRB_ERR_RESPONSE_TOO_BIG", "Response too big for UDP; retry with TCP"},
	// Missing entry?
	[KRB_ERR_GENERIC] = {"KRB_ERR_GENERIC", "Generic error (description in e-text)"},
	[KRB_ERR_FIELD_TOOLONG] = {"KRB_ERR_FIELD_TOOLONG", "Field is too long for this implementation"},
	[KDC_ERROR_CLIENT_NOT_TRUSTED] = {"KDC_ERROR_CLIENT_NOT_TRUSTED", "Reserved for PKINIT"},
	[KDC_ERROR_KDC_NOT_TRUSTED] = {"KDC_ERROR_KDC_NOT_TRUSTED", "Reserved for PKINIT"},
	[KDC_ERROR_INVALID_SIG] = {"KDC_ERROR_INVALID_SIG", "Reserved for PKINIT"},
	[KDC_ERR_KEY_TOO_WEAK] = {"KDC_ERR_KEY_TOO_WEAK", "Reserved for PKINIT"},
	[KDC_ERR_CERTIFICATE_MISMATCH] = {"KDC_ERR_CERTIFICATE_MISMATCH", "Reserved for PKINIT"},
	[KRB_AP_ERR_NO_TGT] = {"KRB_AP_ERR_NO_TGT", "No TGT available to validate USER-TO-USER"},
	[KDC_ERR_WRONG_REALM] = {"KDC_ERR_WRONG_REALM", "Reserved for future use"},
	[KRB_AP_ERR_USER_TO_USER_REQUIRED] = {"KRB_AP_ERR_USER_TO_USER_REQUIRED", "Ticket must be for USER-TO-USER"},
	[KDC_ERR_CANT_VERIFY_CERTIFICATE] = {"KDC_ERR_CANT_VERIFY_CERTIFICATE", "Reserved for PKINIT"},
	[KDC_ERR_INVALID_CERTIFICATE] = {"KDC_ERR_INVALID_CERTIFICATE", "Reserved for PKINIT"},
	[KDC_ERR_REVOKED_CERTIFICATE] = {"KDC_ERR_REVOKED_CERTIFICATE", "Reserved for PKINIT"},
	[KDC_ERR_REVOCATION_STATUS_UNKNOWN] = {"KDC_ERR_REVOCATION_STATUS_UNKNOWN", "Reserved for PKINIT"},
	[KDC_ERR_REVOCATION_STATUS_UNAVAILABLE] = {"KDC_ERR_REVOCATION_STATUS_UNAVAILABLE", "Reserved for PKINIT"},
	[KDC_ERR_CLIENT_NAME_MISMATCH] = {"KDC_ERR_CLIENT_NAME_MISMATCH", "Reserved for PKINIT"},
	[KDC_ERR_KDC_NAME_MISMATCH] = {"KDC_ERR_KDC_NAME_MISMATCH", "Reserved for PKINIT"},
};

const char* kerb_err_name(int err_code)
{
	if (err_code < 0 || err_code >= _countof(krb_err_table) || !krb_err_table[err_code].name)
		return "KRB_ERR_UNKNOWN";
	else
		return krb_err_table[err_code].name;
}

const char* kerb_err_desc(int err_code)
{
	if (err_code < 0 || err_code >= _countof(krb_err_table) || !krb_err_table[err_code].desc)
		return "Unknown error code";
	else
		return krb_err_table[err_code].desc;
}

BOOL kerb_init_winsock()
{
	static BOOL initialized = FALSE;

	if (!initialized)
	{
		WSADATA wsa_data;
		memset(&wsa_data, 0, sizeof(wsa_data));

		if (WSAStartup(MAKEWORD(2, 2), &wsa_data) == 0)
			initialized = TRUE;
	}

	return initialized;
}

BOOL kerb_send_exact(SOCKET sock, LPCVOID pvBuffer, ULONG cbBuffer)
{
	ULONG offset = 0;

	while (offset < cbBuffer)
	{
		int sent = send(sock, (const char*)pvBuffer + offset, cbBuffer - offset, 0);

		if (sent == SOCKET_ERROR)
			return FALSE;

		offset += sent;
	}

	return TRUE;
}

BOOL kerb_recv_exact(SOCKET sock, LPVOID pvBuffer, ULONG cbBuffer)
{
	ULONG offset = 0;

	while (offset < cbBuffer)
	{
		int read = recv(sock, (char*)pvBuffer + offset, cbBuffer - offset, 0);

		if (read == SOCKET_ERROR)
			return FALSE;

		offset += read;
	}

	return TRUE;
}

BOOL kerb_find_kdc_host(LPCSTR domain, LPSTR pvOutput, DWORD cbOutput)
{
	DOMAIN_CONTROLLER_INFOA* dc = NULL;

	if (DsGetDcNameA(NULL, domain, NULL, NULL, DS_KDC_REQUIRED, &dc) != ERROR_SUCCESS)
	{
		if (DsGetDcNameA(NULL, NULL, NULL, NULL, DS_KDC_REQUIRED, &dc) != ERROR_SUCCESS)
			return FALSE;
	}

	if (dc == NULL)
		return FALSE;

	BOOL result = FALSE;

	if (dc->DomainControllerName != NULL)
	{
		LPCSTR DcName = dc->DomainControllerName;

		if (strncmp(DcName, "\\\\", 2) == 0)
			DcName += 2;

		strcpy_s(pvOutput, cbOutput, DcName);

		result = TRUE;
	}

	NetApiBufferFree(dc);
	return result;
}

BOOL kerb_send_kdc_data(LPCSTR domain, LPCBYTE pbRequest, ULONG cbRequest, PVOID* ppvResponse, ULONG* pcbResponse)
{
	BOOL result = FALSE;

	char host[256];

	if (kerb_init_winsock() && kerb_find_kdc_host(domain, host, sizeof(host)))
	{
		ADDRINFOA hints;
		memset(&hints, 0, sizeof(hints));

		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		ADDRINFOA* info = NULL;

		if (GetAddrInfoA(host, "88", &hints, &info) == 0)
		{
			SOCKET sock = socket(info->ai_family, info->ai_socktype, info->ai_protocol);

			if (sock != INVALID_SOCKET)
			{
				if (connect(sock, info->ai_addr, (int)info->ai_addrlen) != SOCKET_ERROR)
				{
					ULONG req_length = htonl(cbRequest);

					if (kerb_send_exact(sock, &req_length, sizeof(req_length)) &&
						kerb_send_exact(sock, pbRequest, cbRequest))
					{
						ULONG rep_length = 0;

						if (kerb_recv_exact(sock, &rep_length, sizeof(rep_length)))
						{
							ULONG cbTemp = ntohl(rep_length);

							if (cbTemp != 0)
							{
								PVOID pvTemp = malloc(cbTemp);

								if (pvTemp != NULL)
								{
									if (!kerb_recv_exact(sock, pvTemp, cbTemp))
										free(pvTemp);
									else
									{
										*ppvResponse = pvTemp;
										*pcbResponse = cbTemp;

										result = TRUE;
									}
								}
							}
						}
					}
				}

				closesocket(sock);
			}

			FreeAddrInfoA(info);
		}
	}

	return result;
}

BOOL kerb_send_kdc_request(LPCSTR domain, LPCBYTE pbRequest, ULONG cbRequest, PVOID* ppvResponse, ULONG* pcbResponse)
{
	ULONG cbResponse = 0;
	PVOID pvResponse = NULL;

	if (kerb_send_kdc_data(domain, pbRequest, cbRequest, &pvResponse, &cbResponse))
	{
		if ((((BYTE*)pvResponse)[0] & 0b11111) != kerb_mt_KrbError)
		{
			*ppvResponse = pvResponse;
			*pcbResponse = cbResponse;

			return TRUE;
		}
		else
		{
			KERB_ERROR* kerb_error = NULL;

			if (asn1_decode_kerb(pvResponse, cbResponse, KERB_ERROR_PDU, &kerb_error))
			{
				printf("[-] The KDC returned error code 0x%08x (%s): %s\n", kerb_error->error_code, kerb_err_name(kerb_error->error_code), kerb_err_desc(kerb_error->error_code));

				if (kerb_error->error_code == KDC_ERR_PREAUTH_FAILED && (kerb_error->bit_mask & error_data_present) != 0)
				{
					PKERB_PREAUTH_DATA_LIST_Element* kerb_preauth_data_list = NULL;

					if (asn1_decode_kerb(kerb_error->error_data.value, kerb_error->error_data.length, PKERB_PREAUTH_DATA_LIST_PDU, &kerb_preauth_data_list))
					{
						PKERB_PREAUTH_DATA_LIST_Element* kerb_preauth_data_list_current = kerb_preauth_data_list;

						while (kerb_preauth_data_list_current != NULL)
						{
							if (kerb_preauth_data_list_current->value.preauth_data_type == kerb_PA_ETYPE_INFO2)
							{
								ETYPE_INFO2_Element* etype_info2 = NULL;

								if (asn1_decode_kerb(kerb_preauth_data_list_current->value.preauth_data.value, kerb_preauth_data_list_current->value.preauth_data.length, ETYPE_INFO2_PDU, &etype_info2))
								{
									ETYPE_INFO2_Element* etype_info2_current = etype_info2;

									while (etype_info2_current != NULL)
									{
										if (etype_info2_current->value.etype == kerb_etype_aes256 && (etype_info2_current->value.bit_mask & ETYPE_INFO2_ENTRY_salt_present) != 0 && etype_info2_current->value.salt != NULL)
										{
											ULONG cbTemp = (ULONG)(strlen(etype_info2_current->value.salt) + 1);
											PVOID pvTemp = malloc(cbTemp);

											if (pvTemp != NULL)
											{
												strcpy_s(pvTemp, cbTemp, etype_info2_current->value.salt);

												*ppvResponse = pvTemp;
												*pcbResponse = cbTemp;
											}
										}

										etype_info2_current = etype_info2_current->next;
									}

									asn1_free_kerb(etype_info2, ETYPE_INFO2_PDU);
								}
							}

							kerb_preauth_data_list_current = kerb_preauth_data_list_current->next;
						}

						asn1_free_kerb(kerb_preauth_data_list, PKERB_PREAUTH_DATA_LIST_PDU);
					}
				}

				asn1_free_kerb(kerb_error, KERB_ERROR_PDU);
			}

			free(pvResponse);
		}
	}

	return FALSE;
}