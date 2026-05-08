#ifndef __KERB_BASE_H__
#define __KERB_BASE_H__

#include <Windows.h>

typedef enum _KERB_GSS_TOKEN_ID
{
    kerb_gss_KerbApReq               = 0x0001,
    kerb_gss_KerbApRep               = 0x0002,
    kerb_gss_KerbError               = 0x0003,
    kerb_gss_KerbTgtReq              = 0x0004,
    kerb_gss_KerbTgtRep              = 0x0005,
    kerb_gss_KerbGssMic              = 0x0101,
    kerb_gss_KerbGssWrap             = 0x0102,
    kerb_gss_KerbExportedNameToken   = 0x0104,
    kerb_gss_KerbGssMicToken         = 0x0404,
    kerb_gss_KerbGssWrapToken        = 0x0405,
} KERB_GSS_TOKEN_ID;

typedef enum _KERB_GSS_TOKEN_FLAGS
{
    kerb_gss_flag_SentByAcceptor  = 0b00000001,
    kerb_gss_flag_Sealed          = 0b00000010,
    kerb_gss_flag_AcceptorSubKey  = 0b00000100,
} KERB_GSS_TOKEN_FLAGS;

typedef enum _KERB_MESSAGE_TYPE
{
    kerb_mt_KrbAsReq        = 10,
    kerb_mt_KrbAsRep,
    kerb_mt_KrbTgsReq,
    kerb_mt_KrbTgsRep,
    kerb_mt_KrbApReq,
    kerb_mt_KrbApRep,
    kerb_mt_KrbTgtReqU2U,
    kerb_mt_KrbTgtRepU2U,
    kerb_mt_KrbSafe         = 20,
    kerb_mt_KrbPriv,
    kerb_mt_KrbCred,
    kerb_mt_KrbError        = 30,
} KERB_MESSAGE_TYPE;

typedef enum _KERB_KEY_USAGE
{
    kerb_ku_AsReqPaEncTimestamp = 1,                // Encrypted with the client key (AS-REQ PA-ENC-TIMESTAMP padata timestamp)
    kerb_ku_AsRepTgsRep = 2,                        // Encrypted with the service key (AS-REP Ticket and TGS-REP Ticket - includes TGS session key or application session key)
    kerb_ku_AsRepEncryptedPart = 3,                 // Encrypted with the client key (AS-REP encrypted part - includes TGS session key or application session key)
    kerb_ku_TgsReqEncAuthorizationData = 4,         // Encrypted with the TGS session key (TGS-REQ KDC-REQ-BODY AuthorizationData)
    kerb_ku_TgsReqEncAuthorizationDataSubKey = 5,   // Encrypted with the TGS authenticator subkey (TGS-REQ KDC-REQ-BODY AuthorizationData)
    kerb_ku_TgsReqPaAuthenticatorChecksum = 6,      // Keyed with the TGS session key (TGS-REQ PA-TGS-REQ padata AP-REQ Authenticator cksum)
    kerb_ku_TgsReqPaAuthenticator = 7,              // Encrypted with the TGS session key (TGS-REQ PA-TGS-REQ padata AP-REQ Authenticator - includes TGS authenticator subkey)
    kerb_ku_TgsRepEncryptedPart = 8,                // Encrypted with the TGS session key (TGS-REP encrypted part - includes application session key)
    kerb_ku_TgsRepEncryptedPartSubkey = 9,          // Encrypted with the TGS authenticator subkey (TGS-REP encrypted part - includes application session key)
    kerb_ku_ApReqAuthenticatorChecksum = 10,        // Keyed with the application session key (AP-REQ Authenticator cksum)
    kerb_ku_ApReqAuthenticator = 11,                // Encrypted with the application session key (AP-REQ Authenticator - includes application authenticator subkey)
    kerb_ku_ApRepEncryptedPart = 12,                // Encrypted with the application session key (AP-REP encrypted part - includes application session subkey)
    kerb_ku_KrbPrivEncryptedPart = 13,              // Encrypted with a key chosen by the application (KRB-PRIV encrypted part)
    kerb_ku_KrbCredEncryptedPart = 14,              // Encrypted with a key chosen by the application (KRB-CRED encrypted part)
    kerb_ku_KrbSafeChecksum = 15,                   // Keyed with a key chosen by the application (KRB-SAFE cksum)
    kerb_ku_KrbNonKerbSalt = 16,                    // 
    kerb_ku_KrbNonKeyChecksumSalt = 17,             // 
    kerb_ku_KgUsageAcceptorSeal = 22,               // Used for Kerberos v5 GSS-API Wrap tokens (server)
    kerb_ku_KgUsageAcceptorSign = 23,               // Used for Kerberos v5 GSS-API MIC tokens (server)
    kerb_ku_KgUsageInitiatorSeal = 24,              // Used for Kerberos v5 GSS-API Wrap tokens (client)
    kerb_ku_KgUsageInitiatorSign = 25,              // Used for Kerberos v5 GSS-API MIC tokens (client)
} KERB_KEY_USAGE;

typedef enum _KERB_PA_DATA_TYPE
{
    kerb_PA_TGS_REQ = 1,
    kerb_PA_ENC_TIMESTAMP = 2,
    kerb_PA_PW_SALT = 3,
    kerb_PA_ENC_UNIX_TIME = 5,
    kerb_PA_SANDIA_SECURE_ID = 6,
    kerb_PA_SESAME = 7,
    kerb_PA_OSF_DCE = 8,
    kerb_PA_CYBERSAFE_SECURE_ID = 9,
    kerb_PA_AFS3_SALT = 10,
    kerb_PA_ETYPE_INFO = 11,
    kerb_PA_SAM_CHALLENGE = 12,
    kerb_PA_SAM_RESPONSE = 13,
    kerb_PA_PK_AS_REQ_OLD = 14,
    kerb_PA_PK_AS_REP_OLD = 15,
    kerb_PA_PK_AS_REQ = 16,
    kerb_PA_PK_AS_REP = 17,
    kerb_PA_PK_OCSP_RESPONSE = 18,
    kerb_PA_ETYPE_INFO2 = 19,
    kerb_PA_USE_SPECIFIED_KVNO = 20,
    kerb_PA_SVR_REFERRALINFO = 20,
    kerb_PA_SAM_REDIRECT = 21,
    kerb_PA_GET_FROM_TYPED_DATA = 22,
    kerb_PA_SAM_ETYPE_INFO = 23,
    kerb_PA_ALT_PRINC = 24,
    kerb_PA_SERVER_REFERRAL_INFO = 25,
    kerb_PA_SAM_CHALLENGE2 = 30,
    kerb_PA_SAM_RESPONSE2 = 31,
    kerb_PA_EXTRA_TGT = 41,
    kerb_TD_PKINIT_CMS_CERTIFICATES = 101,
    kerb_TD_KRB_PRINCIPAL = 102,
    kerb_TD_KRB_REALM = 103,
    kerb_TD_TRUSTED_CERTIFIERS = 104,
    kerb_TD_CERTIFICATE_INDEX = 105,
    kerb_TD_APP_DEFINED_ERROR = 106,
    kerb_TD_REQ_NONCE = 106,
    kerb_TD_REQ_SEQ = 107,
    kerb_PA_PAC_REQUEST = 128,
    kerb_S4U_SELF = 129,
    kerb_PA_S4U_X509_USER = 130,
    kerb_PA_FX_COOKIE = 133,
    kerb_PA_FX_FAST = 136,
    kerb_PA_FX_ERROR = 137,
    kerb_PA_ENCRYPTED_CHALLENGE = 138,
    kerb_KERB_KEY_LIST_REQ = 161,
    kerb_KERB_KEY_LIST_REP = 162,
    kerb_PA_SUPPORTED_ENC_TYPES = 165,
    kerb_PA_PAC_OPTIONS = 167,
    kerb_SUPERSEDED_BY_USER = 170,
    kerb_DMSA_KEY_PACKAGE = 171,
} KERB_PA_DATA_TYPE;

typedef enum _KERB_PRINCIPAL_NAME_TYPE
{
    kerb_NT_UNKNOWN = 0,
    kerb_NT_PRINCIPAL = 1,
    kerb_NT_SRV_INST = 2,
    kerb_NT_SRV_HST = 3,
    kerb_NT_SRV_XHST = 4,
    kerb_NT_UID = 5,
    kerb_NT_X500_PRINCIPAL = 6,
    kerb_NT_SMTP_NAME = 7,
    kerb_NT_ENTERPRISE = 10,
} KERB_PRINCIPAL_NAME_TYPE;

typedef enum _KERB_KDC_OPTIONS_FLAGS
{
    kerb_kdc_opt_Reserved0               = 0b00000000000000000000000000000001,
    kerb_kdc_opt_Forwardable             = 0b00000000000000000000000000000010,
    kerb_kdc_opt_Forwarded               = 0b00000000000000000000000000000100,
    kerb_kdc_opt_Proxiable               = 0b00000000000000000000000000001000,
    kerb_kdc_opt_Proxy                   = 0b00000000000000000000000000010000,
    kerb_kdc_opt_AllowPostDate           = 0b00000000000000000000000000100000,
    kerb_kdc_opt_PostDated               = 0b00000000000000000000000001000000,
    kerb_kdc_opt_Reserved7               = 0b00000000000000000000000010000000,
    kerb_kdc_opt_Renewable               = 0b00000000000000000000000100000000,
    kerb_kdc_opt_Reserved9               = 0b00000000000000000000001000000000,
    kerb_kdc_opt_Reserved10              = 0b00000000000000000000010000000000,
    kerb_kdc_opt_OptHardwareAuth         = 0b00000000000000000000100000000000,
    kerb_kdc_opt_Reserved12              = 0b00000000000000000001000000000000,
    kerb_kdc_opt_Reserved13              = 0b00000000000000000010000000000000,
    kerb_kdc_opt_ConstrainedDelegation   = 0b00000000000000000100000000000000,
    kerb_kdc_opt_Canonicalize            = 0b00000000000000001000000000000000,
    kerb_kdc_opt_RequestAnonymous        = 0b00000000000000010000000000000000,
    kerb_kdc_opt_Reserved17              = 0b00000000000000100000000000000000,
    kerb_kdc_opt_Reserved18              = 0b00000000000001000000000000000000,
    kerb_kdc_opt_Reserved19              = 0b00000000000010000000000000000000,
    kerb_kdc_opt_Reserved20              = 0b00000000000100000000000000000000,
    kerb_kdc_opt_Reserved21              = 0b00000000001000000000000000000000,
    kerb_kdc_opt_Reserved22              = 0b00000000010000000000000000000000,
    kerb_kdc_opt_Reserved23              = 0b00000000100000000000000000000000,
    kerb_kdc_opt_Reserved24              = 0b00000001000000000000000000000000,
    kerb_kdc_opt_Reserved25              = 0b00000010000000000000000000000000,
    kerb_kdc_opt_DisabledTransitedCheck  = 0b00000100000000000000000000000000,
    kerb_kdc_opt_RenewableOk             = 0b00001000000000000000000000000000,
    kerb_kdc_opt_EnctktInSkey            = 0b00010000000000000000000000000000,
    kerb_kdc_opt_Reserved29              = 0b00100000000000000000000000000000,
    kerb_kdc_opt_Renew                   = 0b01000000000000000000000000000000,
    kerb_kdc_opt_Validate                = 0b10000000000000000000000000000000,
} KERB_KDC_OPTIONS_FLAGS;

typedef enum _KERB_PAC_OPTIONS_FLAGS
{
    kerb_pac_opt_Claims                             = 0b00000000000000000000000000000001,
    kerb_pac_opt_BranchAware                        = 0b00000000000000000000000000000010,
    kerb_pac_opt_ForwardToFullDc                    = 0b00000000000000000000000000000100,
    kerb_pac_opt_ResourceBasedConstrainedDelegation = 0b00000000000000000000000000001000,
} KERB_PAC_OPTIONS_FLAGS;

typedef enum _KERB_AP_REQUEST_OPTIONS_FLAGS
{
    kerb_ap_req_opt_Reserved0               = 0b00000000000000000000000000000001,
    kerb_ap_req_opt_UseSessionKey           = 0b00000000000000000000000000000010,
    kerb_ap_req_opt_MutualRequired          = 0b00000000000000000000000000000100,
} KERB_AP_REQUEST_OPTIONS_FLAGS;

BYTE kerb_reverse_bits(BYTE value);

void kerb_set_bitstring32(BYTE* bitstring, ULONG value);
ULONG kerb_get_bitstring32(BYTE* bitstring, ULONG length);

#endif