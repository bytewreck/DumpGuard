#include "spnego_server.h"
#include "kerb_server.h"

#include "asn1_spnego.h"

#include <stdio.h>

BOOL spnego_init_context(SPNEGO_CONTEXT* context, LPCSTR domain, LPCSTR username, LPCSTR password)
{
	memset(context, 0, sizeof(SPNEGO_CONTEXT));

	return kerb_init_context(&context->kerb, domain, username, password);
}

void spnego_free_context(SPNEGO_CONTEXT* context)
{
	if (context->pvSavedMechTypeList != NULL)
		free(context->pvSavedMechTypeList);

	kerb_free_context(&context->kerb);
}

BOOL spnego_encrypt(SPNEGO_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	return kerb_seal_message_old(&context->kerb, pvData, cbData, ppvOutput, pcbOutput);
}

BOOL spnego_decrypt(SPNEGO_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	return kerb_unseal_message_old(&context->kerb, pvData, cbData, ppvOutput, pcbOutput);
}

BOOL spnego_oid_compare(ASN1objectidentifier_t path, ULONG* ids, ULONG length)
{
	ULONG i = 0;

	while (path != NULL)
	{
		if (i >= length)
			return FALSE;

		if (path->value != ids[i++])
			return FALSE;

		path = path->next;
	}

	return TRUE;
}

BOOL spnego_mech_list_contains(PMechTypeList mech_list, ULONG* ids, ULONG length)
{
	while (mech_list != NULL)
	{
		if (spnego_oid_compare(mech_list->value, ids, length))
			return TRUE;

		mech_list = mech_list->next;
	}

	return FALSE;
}

BOOL spnego_handle_token(SPNEGO_CONTEXT* context, LPCVOID pvToken, ULONG cbToken, PVOID* ppvResponse, ULONG* pcbResponse)
{
	BOOL result = FALSE;

	ULONG cbKerbResponse = 0;
	PVOID pvKerbResponse = NULL;

	if (kerb_accept_token(&context->kerb, pvToken, cbToken, &pvKerbResponse, &cbKerbResponse))
	{
		NegotiationToken token;
		memset(&token, 0, sizeof(token));

		token.choice = negTokenTarg_chosen;

		token.u.negTokenTarg.bit_mask |= negResult_present;
		token.u.negTokenTarg.negResult = accept_incomplete;

		token.u.negTokenTarg.bit_mask |= responseToken_present;
		token.u.negTokenTarg.responseToken.value = pvKerbResponse;
		token.u.negTokenTarg.responseToken.length = cbKerbResponse;

		struct ASN1objectidentifier_s mech_type[7];
		mech_type[0].value = 1;
		mech_type[0].next = &mech_type[1];
		mech_type[1].value = 2;
		mech_type[1].next = &mech_type[2];
		mech_type[2].value = 840;
		mech_type[2].next = &mech_type[3];
		mech_type[3].value = 48018;
		mech_type[3].next = &mech_type[4];
		mech_type[4].value = 1;
		mech_type[4].next = &mech_type[5];
		mech_type[5].value = 2;
		mech_type[5].next = &mech_type[6];
		mech_type[6].value = 2;
		mech_type[6].next = NULL;

		ULONG cbMechListMic = 0;
		PVOID pvMechListMic = NULL;

		if (context->kerb.state == kerb_st_ApReplySent || context->kerb.state == kerb_st_ApRequestReceived)
		{
			if (kerb_make_signature_old(&context->kerb, context->pvSavedMechTypeList, context->cbSavedMechTypeList, &pvMechListMic, &cbMechListMic))
			{
				token.u.negTokenTarg.bit_mask |= NegTokenTarg_mechListMIC_present;
				token.u.negTokenTarg.mechListMIC.value = pvMechListMic;
				token.u.negTokenTarg.mechListMIC.length = cbMechListMic;
			}
		}
		else
		{
			token.u.negTokenTarg.bit_mask |= supportedMech_present;
			token.u.negTokenTarg.supportedMech = mech_type; // 1.2.840.48018.1.2.2
		}

		ULONG cbResponseToken = 0;
		PVOID pvResponseToken = NULL;

		if (asn1_encode_spnego(&token, NegotiationToken_PDU, &pvResponseToken, &cbResponseToken))
		{
			*ppvResponse = pvResponseToken;
			*pcbResponse = cbResponseToken;

			result = TRUE;
		}

		if (pvMechListMic != NULL)
			free(pvMechListMic);

		free(pvKerbResponse);
	}

	return result;
}

BOOL spnego_accept_token(SPNEGO_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, PVOID* ppvResponse, ULONG* pcbResponse)
{
	BOOL result = FALSE;

	if (cbRequest >= 7 && strncmp(pvRequest, "NTLMSSP", 7) == 0)
		puts("[-] The client attempted to negotiate NTLM (target SPN is probably malformed)");
	else if (cbRequest > 0 && ((BYTE*)pvRequest)[0] == 0x60)
	{
		InitialNegToken* init_token = NULL;

		if (asn1_decode_spnego(pvRequest, cbRequest, InitialNegToken_PDU, &init_token))
		{
			ULONG krb5_gss_api_mech[] = { 1, 2, 840, 113554, 1, 2, 2 };

			if ((init_token->negToken.u.negTokenInit.bit_mask & NegTokenInit_mechToken_present) == 0)
				puts("[-] NegTokenInit does not contain a token for the underlying protocol");
			else if (!spnego_mech_list_contains(init_token->negToken.u.negTokenInit.mechTypes, krb5_gss_api_mech, _countof(krb5_gss_api_mech)))
				puts("[-] MechTypeList does not contain Kerberoes 5 GSS-API Mechanism (1.2.840.113554.1.2.2)");
			else
			{
				ULONG cbSavedMechTypeList = 0;
				PVOID pvSavedMechTypeList = NULL;

				if (asn1_encode_spnego(&init_token->negToken.u.negTokenInit.mechTypes, SavedMechTypeList_PDU, &pvSavedMechTypeList, &cbSavedMechTypeList))
				{
					context->pvSavedMechTypeList = pvSavedMechTypeList;
					context->cbSavedMechTypeList = cbSavedMechTypeList;
				}

				ULONG cbResponse = 0;
				PVOID pvResponse = NULL;

				if (spnego_handle_token(context, init_token->negToken.u.negTokenInit.mechToken.value, init_token->negToken.u.negTokenInit.mechToken.length, &pvResponse, &cbResponse))
				{
					*ppvResponse = pvResponse;
					*pcbResponse = cbResponse;

					result = TRUE;
				}
			}

			asn1_free_spnego(init_token, InitialNegToken_PDU);
		}
	}
	else
	{
		NegotiationToken* neg_token = NULL;

		if (asn1_decode_spnego(pvRequest, cbRequest, NegotiationToken_PDU, &neg_token))
		{
			if ((neg_token->u.negTokenTarg.bit_mask & negResult_present) == 0)
				puts("[-] NegToken does not contain a result");
			else if (neg_token->u.negTokenTarg.negResult == accept_completed)
				context->kerb.state = kerb_st_Authenticated;
			else if (neg_token->u.negTokenTarg.negResult == accept_incomplete)
			{
				ULONG cbResponse = 0;
				PVOID pvResponse = NULL;

				if (spnego_handle_token(context, neg_token->u.negTokenTarg.responseToken.value, neg_token->u.negTokenTarg.responseToken.length, &pvResponse, &cbResponse))
				{
					*ppvResponse = pvResponse;
					*pcbResponse = cbResponse;

					result = TRUE;
				}
			}
			else
			{
				printf("[-] NegToken contains unsupported result: %d\n", neg_token->u.negTokenTarg.negResult);
			}

			asn1_free_spnego(neg_token, NegotiationToken_PDU);
		}
	}

	return result;
}