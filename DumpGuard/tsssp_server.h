#ifndef __TSSSP_SERVER_H__
#define __TSSSP_SERVER_H__

#include "spnego_server.h"

typedef struct _TSSSP_SERVER_CONTEXT
{
	SPNEGO_CONTEXT spnego;

	BOOL authenticated;

	ULONG cbPrimaryCreds;
	PVOID pvPrimaryCreds;

	ULONG cbSupplementalCreds;
	PVOID pvSupplementalCreds;

} TSSSP_SERVER_CONTEXT;

BOOL tsssp_server_init_context(TSSSP_SERVER_CONTEXT* context, LPCSTR domain, LPCSTR username, LPCSTR password);
void tsssp_server_free_context(TSSSP_SERVER_CONTEXT* context);

BOOL tsssp_server_encrypt(TSSSP_SERVER_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL tsssp_server_decrypt(TSSSP_SERVER_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);

BOOL tsssp_server_accept_security_context(TSSSP_SERVER_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, LPCVOID pvCert, ULONG cbCert, PVOID* ppvResponse, ULONG* pcbResponse);

#endif
