#ifndef __SPNEGO_SERVER_H__
#define __SPNEGO_SERVER_H__

#include "kerb_server.h"

typedef struct _SPNEGO_CONTEXT
{
	KERB_CONTEXT kerb;

	ULONG cbSavedMechTypeList;
	PVOID pvSavedMechTypeList;

} SPNEGO_CONTEXT;

BOOL spnego_init_context(SPNEGO_CONTEXT* context, LPCSTR domain, LPCSTR username, LPCSTR password);
void spnego_free_context(SPNEGO_CONTEXT* context);

BOOL spnego_encrypt(SPNEGO_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL spnego_decrypt(SPNEGO_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);

BOOL spnego_accept_token(SPNEGO_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, PVOID* ppvResponse, ULONG* pcbResponse);

#endif