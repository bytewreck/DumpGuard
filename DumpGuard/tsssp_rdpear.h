#ifndef __TSSSP_RDPEAR_H__
#define __TSSSP_RDPEAR_H__

#include "tsssp_server.h"
#include "tsssp_client.h"

typedef struct _RDPEAR_PAYLOAD
{
	LONG ProtocolMagic;			// A 32-bit integer that MUST be equal to the value 0x4eacc3c8.
	ULONG Length;				// A 32-bit unsigned integer value that contains the overall length of the message.
	ULONG Version;				// A 32-bit unsigned integer value describing the RDPEAR Protocol version. This MUST be 0x00000000.
	ULONG Reserved;				// Reserved for future use.
	ULONG_PTR TsPkgContext;		// Used by the RDPEAR virtual channel ([MSDN-TSVC]) to maintain internal consistency across messages. This field MUST be zero in all network messages.
	char Payload[0];			// The encrypted portion of the RDPEAR Outer Layer. The plaintext data consists of an Abstract Syntax Notation One (ASN.1) structure, as specified in [X680], and is encoded using Distinguished Encoding Rules (DER), as specified in [X690] section 10. The plaintext data is encrypted using the negotiated security context between the client and server as part of [MS-CSSP].
} RDPEAR_PAYLOAD, *PRDPEAR_PAYLOAD;

typedef struct _CredIsoRemoteHeader
{
	unsigned short AlwaysOne;	// Must be 1
	unsigned short Sequence;	// Mirrored in output
	unsigned char padding[12];	// idk?
} CredIsoRemoteHeader;

BOOL tsssp_rdpear_send_ntlm_request_v1(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context);
BOOL tsssp_rdpear_send_ntlm_request_v2(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context);

BOOL tsssp_rdpear_send_kerb_request_service_ticket(TSSSP_SERVER_CONTEXT* server_context, TSSSP_CLIENT_CONTEXT* client_context, LPCSTR domain, LPCSTR spn);

#endif