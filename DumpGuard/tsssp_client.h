#ifndef __TSSSP_CLIENT_H__
#define __TSSSP_CLIENT_H__

#include <Windows.h>

#ifndef SECURITY_WIN32
#define SECURITY_WIN32
#endif

#include <sspi.h>

typedef struct _TSSSP_CLIENT_CONTEXT
{
	BOOL authenticated;

	CredHandle cred;
	CtxtHandle context;
	
} TSSSP_CLIENT_CONTEXT;

void tsssp_client_init_context(TSSSP_CLIENT_CONTEXT* context);
void tsssp_client_free_context(TSSSP_CLIENT_CONTEXT* context);

NTSTATUS tsssp_client_acquire_credentials(TSSSP_CLIENT_CONTEXT* context);
NTSTATUS tsssp_client_initialize_security_context(TSSSP_CLIENT_CONTEXT* context, LPCSTR lpTarget, SecBufferDesc* pInput, SecBufferDesc* pOutput);

#endif