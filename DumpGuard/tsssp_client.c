#include "tsssp_client.h"

#include <credssp.h>
#include <stdio.h>

void tsssp_client_init_context(TSSSP_CLIENT_CONTEXT* context)
{
	memset(context, 0, sizeof(TSSSP_CLIENT_CONTEXT));

	context->authenticated = FALSE;

	context->cred.dwLower = -1LL;
	context->cred.dwUpper = -1LL;

	context->context.dwLower = -1LL;
	context->context.dwUpper = -1LL;
}

void tsssp_client_free_context(TSSSP_CLIENT_CONTEXT* context)
{
	if (context->context.dwLower != -1LL || context->context.dwUpper != -1LL)
		DeleteSecurityContext(&context->context);

	if (context->cred.dwLower != -1LL || context->cred.dwUpper != -1LL)
		FreeCredentialsHandle(&context->cred);
}

BOOL tsssp_client_acquire_credentials(TSSSP_CLIENT_CONTEXT* context)
{
	CREDSSP_CRED_EX cred_ex;
	memset(&cred_ex, 0, sizeof(cred_ex));
	
	cred_ex.Type = CredsspCredEx;
	cred_ex.Version = CREDSSP_CRED_EX_VERSION;
	cred_ex.Flags = CREDSSP_FLAG_REDIRECT;
	cred_ex.Cred.Type = CredsspSubmitBufferBoth;
	
	return (AcquireCredentialsHandleA(NULL, (LPSTR)TS_SSP_NAME_A, SECPKG_CRED_OUTBOUND, NULL, &cred_ex, NULL, NULL, &context->cred, NULL) == SEC_E_OK);
}

BOOL tsssp_client_initialize_security_context(TSSSP_CLIENT_CONTEXT* context, LPCSTR lpTarget, SecBufferDesc* pInput, SecBufferDesc* pOutput)
{
	TimeStamp ctx_expiry;
	memset(&ctx_expiry, 0, sizeof(ctx_expiry));

	ULONG ctx_attr = 0;

	SECURITY_STATUS status = 0;

	if (context->context.dwLower == -1LL && context->context.dwUpper == -1LL)
	{
		status = InitializeSecurityContextA(&context->cred, NULL, (LPSTR)lpTarget, ISC_REQ_ALLOCATE_MEMORY, 
			0, SECURITY_NATIVE_DREP, NULL, 0, &context->context, pOutput, &ctx_attr, &ctx_expiry);
	}
	else
	{
		status = InitializeSecurityContextA(&context->cred, &context->context, (LPSTR)lpTarget, ISC_REQ_ALLOCATE_MEMORY, 
			0, SECURITY_NATIVE_DREP, pInput, 0, &context->context, pOutput, &ctx_attr, &ctx_expiry);
	}

	if (status == SEC_I_CONTINUE_NEEDED)
		return TRUE;
	else if (status == SEC_E_OK)
		return (context->authenticated = TRUE);
	else
	{
		printf("InitializeSecurityContextA failed with error code: %08x\n", status);
		return FALSE;
	}
}