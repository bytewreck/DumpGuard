#ifndef __KERB_SERVER_H__
#define __KERB_SERVER_H__

#include "kerb_base.h"
#include "kerb_crypto.h"

typedef enum _KERB_SERVER_STATE
{
	kerb_st_None = 0,
	kerb_st_TgtRequestReceived = 1,
	kerb_st_TgtReplySent = 2,
	kerb_st_ApRequestReceived = 3,
	kerb_st_ApReplySent = 4,
	kerb_st_Authenticated = 5,
	kerb_st_ErrorMessageSent = 6,
	kerb_st_InvalidState = 7,
} KERB_SERVER_STATE;

typedef struct _KERB_CONTEXT
{
	KERB_SERVER_STATE state;

	CHAR domain[256];
	CHAR username[256];
	CHAR password[256];
	CHAR spn[256];

	BYTE longterm_key_rc4[16];
	BYTE longterm_key_aes128[16];
	BYTE longterm_key_aes256[32];

	KERB_ETYPE session_key_type;
	BYTE session_key[256];

	KERB_ETYPE initiator_subkey_type;
	BYTE initiator_subkey[256];

	KERB_ETYPE acceptor_subkey_type;
	BYTE acceptor_subkey[32];
	ULONG acceptor_subkey_length;

	ULONG initiator_seq;
	ULONGLONG acceptor_seq;

} KERB_CONTEXT;

typedef struct _KERB_MIC_TOKEN_HEADER
{
	WORD token_id;
	BYTE flags;
	BYTE filler1;
	ULONG filler2;
	ULONGLONG sequence_number;
} KERB_MIC_TOKEN_HEADER;

typedef struct _KERB_GSS_SIGNATURE_HEADER
{
	WORD token_id;
	BYTE flags;
	BYTE filler;
	WORD extra_count;
	WORD right_rotation_count;
	ULONGLONG sequence_number;
} KERB_GSS_SIGNATURE_HEADER;

#pragma pack(push, 1)
typedef struct _KERB_GSS_SEAL_SIGNATURE
{
	KERB_GSS_SIGNATURE_HEADER header;
	BYTE encrypted_header[16];
	BYTE checksum[12];
	BYTE confounder[16];
} KERB_GSS_SEAL_SIGNATURE;
#pragma pack(pop)

BOOL kerb_init_context(KERB_CONTEXT* context, LPCSTR domain, LPCSTR username, LPCSTR password);
void kerb_free_context(KERB_CONTEXT* context);

BOOL kerb_build_longterm_keys(KERB_CONTEXT* context, LPCSTR salt);
BOOL kerb_make_signature_old(KERB_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL kerb_seal_message_old(KERB_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL kerb_unseal_message_old(KERB_CONTEXT* context, PVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);

BOOL kerb_accept_token(KERB_CONTEXT* context, LPCVOID pvRequest, ULONG cbRequest, PVOID* ppvResponse, ULONG* pcbResponse);

#endif