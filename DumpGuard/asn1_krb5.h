// Copyright (C) 2024 Evan McBroom
//
// Kerberos protocol asn.1
//
#ifndef __ASN1_KRB5_H__
#define __ASN1_KRB5_H__

#include "asn1_base.h"

#undef ERROR

#define KERBEROS_VERSION  5
#define KERBEROS_REVISION 6

#define KERB_AP_OPTIONS_reserved        0x80000000
#define KERB_AP_OPTIONS_use_session_key 0x40000000
#define KERB_AP_OPTIONS_mutual_required 0x20000000
#define KERB_AP_OPTIONS_reserved1       0x00000001

#define KERB_KDC_OPTIONS_reserved          0x80000000
#define KERB_KDC_OPTIONS_forwardable       0x40000000
#define KERB_KDC_OPTIONS_forwarded         0x20000000
#define KERB_KDC_OPTIONS_proxiable         0x10000000
#define KERB_KDC_OPTIONS_proxy             0x08000000
#define KERB_KDC_OPTIONS_postdated         0x02000000
#define KERB_KDC_OPTIONS_allow_postdate    0x04000000
#define KERB_KDC_OPTIONS_unused7           0x01000000
#define KERB_KDC_OPTIONS_renewable         0x00800000
#define KERB_KDC_OPTIONS_unused9           0x00400000
#define KERB_KDC_OPTIONS_name_canonicalize 0x00010000
#define KERB_KDC_OPTIONS_cname_in_addl_tkt 0x00020000
#define KERB_KDC_OPTIONS_cname_in_pa_data  0x00040000
#define KERB_KDC_OPTIONS_renewable_ok      0x00000010
#define KERB_KDC_OPTIONS_enc_tkt_in_skey   0x00000008
#define KERB_KDC_OPTIONS_renew             0x00000002
#define KERB_KDC_OPTIONS_validate          0x00000001

#define KERB_TICKET_FLAGS_reserved          0x80000000
#define KERB_TICKET_FLAGS_forwardable       0x40000000
#define KERB_TICKET_FLAGS_forwarded         0x20000000
#define KERB_TICKET_FLAGS_proxiable         0x10000000
#define KERB_TICKET_FLAGS_proxy             0x08000000
#define KERB_TICKET_FLAGS_may_postdate      0x04000000
#define KERB_TICKET_FLAGS_postdated         0x02000000
#define KERB_TICKET_FLAGS_invalid           0x01000000
#define KERB_TICKET_FLAGS_renewable         0x00800000
#define KERB_TICKET_FLAGS_initial           0x00400000
#define KERB_TICKET_FLAGS_pre_authent       0x00200000
#define KERB_TICKET_FLAGS_hw_authent        0x00100000
#define KERB_TICKET_FLAGS_ok_as_delegate    0x00040000
#define KERB_TICKET_FLAGS_name_canonicalize 0x00010000
#define KERB_TICKET_FLAGS_reserved1         0x00000001

#define TD_INVALID_CERTIFICATES_Seq_PDU     0
#define TD_TRUSTED_CERTIFIERS_Seq_PDU       1
#define KERB_KEY_LIST_REQ_Seq_PDU           2
#define EtypeList_Seq_PDU                   3
#define PKERB_AUTHORIZATION_DATA_LIST_PDU   4
#define PKERB_IF_RELEVANT_AUTH_DATA_PDU     5
#define PKERB_TICKET_EXTENSIONS_Seq_PDU     6
#define PKERB_LAST_REQUEST_Seq_PDU          7
#define PKERB_AUTHORIZATION_DATA_Seq_PDU    8
#define PKERB_HOST_ADDRESSES_Seq_PDU        9
#define KERB_REALM_CACHE_PDU                10
#define KERB_PRINCIPAL_NAME_PDU             11
#define PKERB_PREAUTH_DATA_LIST_PDU         12
#define KERB_ENCRYPTED_TIMESTAMP_PDU        13
#define PKERB_ETYPE_INFO_PDU                14
#define ETYPE_INFO2_PDU                     15
#define KERB_ENCRYPTED_DATA_PDU             16
#define KERB_ENCRYPTION_KEY_ASN1_PDU        17
#define KERB_CHECKSUM_PDU                   18
#define KERB_TICKET_PDU                     19
#define KERB_KDC_REQUEST_BODY_PDU           20
#define KERB_KDC_REPLY_PDU                  21
#define KERB_ENCRYPTED_KDC_REPLY_PDU        22
#define KERB_AP_REQUEST_PDU                 23
#define KERB_AUTHENTICATOR_PDU              24
#define KERB_AP_REPLY_PDU                   25
#define KERB_ENCRYPTED_AP_REPLY_PDU         26
#define KERB_SAFE_BODY_PDU                  27
#define KERB_PRIV_MESSAGE_PDU               28
#define KERB_ENCRYPTED_PRIV_PDU             29
#define KERB_CRED_PDU                       30
#define KERB_ENCRYPTED_CRED_PDU             31
#define KERB_CRED_INFO_PDU                  32
#define KERB_ERROR_PDU                      33
#define KERB_ERROR_METHOD_DATA_PDU          34
#define TYPED_DATA_PDU                      35
#define EtypeList_PDU                       36
#define KERB_EXT_ERROR_PDU                  37
#define KERB_ERROR_DATA_PDU                 38
#define KERB_PA_PAC_REQUEST_PDU             39
#define KERB_AD_RESTRICTION_ENTRY_PDU       40
#define PKERB_AD_RESTRICTION_PDU            41
#define KERB_PA_PAC_OPTIONS_PDU             42
#define KERB_KEY_LIST_REQ_PDU               43
#define KERB_KEY_LIST_REP_PDU               44
#define KERB_CHANGE_PASSWORD_DATA_PDU       45
#define KDC_PROXY_MESSAGE_PDU               46
#define KERB_PA_FOR_USER_PDU                47
#define S4UUserID_PDU                       48
#define KrbFastArmoredReq_PDU               49
#define KrbFastReq_PDU                      50
#define KrbFastFinished_PDU                 51
#define EncryptedChallenge_PDU              52
#define KERB_PA_SERV_REFERRAL_PDU           53
#define KERB_PA_PK_AS_REQ_PDU               54
#define TrustedCA_PDU                       55
#define TD_TRUSTED_CERTIFIERS_PDU           56
#define TD_INVALID_CERTIFICATES_PDU         57
#define KRB5PrincipalName_PDU               58
#define AD_INITIAL_VERIFIED_CAS_PDU         59
#define DHRepInfo_PDU                       60
#define KDCDHKeyInfo_PDU                    61
#define PKOcspData_PDU                      62
#define PKAuthenticator_PDU                 63
#define KERB_ALGORITHM_IDENTIFIER_PDU       64
#define KERB_SUBJECT_PUBLIC_KEY_INFO_PDU    65
#define KERB_DH_PARAMTER_PDU                66
#define KERB_SIGNATURE_PDU                  67
#define KERB_SALTED_ENCRYPTED_TIMESTAMP_PDU 68
#define KERB_ENVELOPED_KEY_PACKAGE_PDU      69
#define KERB_PKCS_SIGNATURE_PDU             70
#define KERB_KDC_DH_KEY_INFO_PDU            71
#define KERB_REPLY_KEY_PACKAGE2_PDU         72
#define KERB_REPLY_KEY_PACKAGE3_PDU         73
#define KERB_KERBEROS_NAME_PDU              74
#define KERB_REPLY_KEY_PACKAGE_PDU          75
#define KERB_TGT_REQUEST_PDU                76
#define KERB_TGT_REPLY_PDU                  77
#define KERB_KDC_ISSUED_AUTH_DATA_PDU       78
#define KERB_ENCRYPTED_TICKET_PDU           79
#define KERB_KDC_REQUEST_PDU                80
#define KERB_MARSHALLED_REQUEST_BODY_PDU    81
#define KERB_AS_REPLY_PDU                   82
#define KERB_TGS_REPLY_PDU                  83
#define KERB_ENCRYPTED_AS_REPLY_PDU         84
#define KERB_ENCRYPTED_TGS_REPLY_PDU        85
#define KERB_SAFE_MESSAGE_PDU               86
#define PA_S4U_X509_USER_PDU                87
#define PA_FX_FAST_REQUEST_PDU              88
#define PA_FX_FAST_REPLY_PDU                89
#define KrbFastResponse_PDU                 90
#define KERB_AUTH_PACKAGE_PDU               91
#define KERB_AUTH_PACKAGE2_PDU              92
#define TD_DH_PARAMETERS_PDU                93
#define KERB_PA_PK_AS_REP_PDU               94
#define KERB_SIGNED_REPLY_KEY_PACKAGE_PDU   95
#define KERB_TRUSTED_CAS_PDU                96
#define KERB_AS_REQUEST_PDU                 97
#define KERB_TGS_REQUEST_PDU                98
#define KERB_PA_PK_AS_REP2_PDU              99
#define KERB_PA_PK_AS_REQ2_PDU              100

#define SIZE_KRB5_Module_PDU_0   sizeof(TD_INVALID_CERTIFICATES_Seq)
#define SIZE_KRB5_Module_PDU_1   sizeof(TD_TRUSTED_CERTIFIERS_Seq)
#define SIZE_KRB5_Module_PDU_2   sizeof(KERB_KEY_LIST_REQ_Seq)
#define SIZE_KRB5_Module_PDU_3   sizeof(EtypeList_Seq)
#define SIZE_KRB5_Module_PDU_4   sizeof(PKERB_AUTHORIZATION_DATA_LIST)
#define SIZE_KRB5_Module_PDU_5   sizeof(PKERB_IF_RELEVANT_AUTH_DATA)
#define SIZE_KRB5_Module_PDU_6   sizeof(PKERB_TICKET_EXTENSIONS_Seq)
#define SIZE_KRB5_Module_PDU_7   sizeof(PKERB_LAST_REQUEST_Seq)
#define SIZE_KRB5_Module_PDU_8   sizeof(PKERB_AUTHORIZATION_DATA_Seq)
#define SIZE_KRB5_Module_PDU_9   sizeof(PKERB_HOST_ADDRESSES_Seq)
#define SIZE_KRB5_Module_PDU_10  sizeof(KERB_REALM_CACHE_Element)
#define SIZE_KRB5_Module_PDU_11  sizeof(KERB_PRINCIPAL_NAME)
#define SIZE_KRB5_Module_PDU_12  sizeof(PKERB_PREAUTH_DATA_LIST_Element)
#define SIZE_KRB5_Module_PDU_13  sizeof(KERB_ENCRYPTED_TIMESTAMP)
#define SIZE_KRB5_Module_PDU_14  sizeof(PKERB_ETYPE_INFO_Element)
#define SIZE_KRB5_Module_PDU_15  sizeof(ETYPE_INFO2_Element)
#define SIZE_KRB5_Module_PDU_16  sizeof(KERB_ENCRYPTED_DATA)
#define SIZE_KRB5_Module_PDU_17  sizeof(KERB_ENCRYPTION_KEY_ASN1)
#define SIZE_KRB5_Module_PDU_18  sizeof(KERB_CHECKSUM)
#define SIZE_KRB5_Module_PDU_19  sizeof(KERB_TICKET)
#define SIZE_KRB5_Module_PDU_20  sizeof(KERB_KDC_REQUEST_BODY)
#define SIZE_KRB5_Module_PDU_21  sizeof(KERB_KDC_REPLY)
#define SIZE_KRB5_Module_PDU_22  sizeof(KERB_ENCRYPTED_KDC_REPLY)
#define SIZE_KRB5_Module_PDU_23  sizeof(KERB_AP_REQUEST)
#define SIZE_KRB5_Module_PDU_24  sizeof(KERB_AUTHENTICATOR)
#define SIZE_KRB5_Module_PDU_25  sizeof(KERB_AP_REPLY)
#define SIZE_KRB5_Module_PDU_26  sizeof(KERB_ENCRYPTED_AP_REPLY)
#define SIZE_KRB5_Module_PDU_27  sizeof(KERB_SAFE_BODY)
#define SIZE_KRB5_Module_PDU_28  sizeof(KERB_PRIV_MESSAGE)
#define SIZE_KRB5_Module_PDU_29  sizeof(KERB_ENCRYPTED_PRIV)
#define SIZE_KRB5_Module_PDU_30  sizeof(KERB_CRED)
#define SIZE_KRB5_Module_PDU_31  sizeof(KERB_ENCRYPTED_CRED)
#define SIZE_KRB5_Module_PDU_32  sizeof(KERB_CRED_INFO)
#define SIZE_KRB5_Module_PDU_33  sizeof(KERB_ERROR)
#define SIZE_KRB5_Module_PDU_34  sizeof(KERB_ERROR_METHOD_DATA)
#define SIZE_KRB5_Module_PDU_35  sizeof(TYPED_DATA_Element)
#define SIZE_KRB5_Module_PDU_36  sizeof(EtypeList_Element)
#define SIZE_KRB5_Module_PDU_37  sizeof(KERB_EXT_ERROR)
#define SIZE_KRB5_Module_PDU_38  sizeof(KERB_ERROR_DATA)
#define SIZE_KRB5_Module_PDU_39  sizeof(KERB_PA_PAC_REQUEST)
#define SIZE_KRB5_Module_PDU_40  sizeof(KERB_AD_RESTRICTION_ENTRY)
#define SIZE_KRB5_Module_PDU_41  sizeof(PKERB_AD_RESTRICTION_Element)
#define SIZE_KRB5_Module_PDU_42  sizeof(KERB_PA_PAC_OPTIONS)
#define SIZE_KRB5_Module_PDU_43  sizeof(KERB_KEY_LIST_REQ_Element)
#define SIZE_KRB5_Module_PDU_44  sizeof(KERB_KEY_LIST_REP_Element)
#define SIZE_KRB5_Module_PDU_45  sizeof(KERB_CHANGE_PASSWORD_DATA)
#define SIZE_KRB5_Module_PDU_46  sizeof(KDC_PROXY_MESSAGE)
#define SIZE_KRB5_Module_PDU_47  sizeof(KERB_PA_FOR_USER)
#define SIZE_KRB5_Module_PDU_48  sizeof(S4UUserID)
#define SIZE_KRB5_Module_PDU_49  sizeof(KrbFastArmoredReq)
#define SIZE_KRB5_Module_PDU_50  sizeof(KrbFastReq)
#define SIZE_KRB5_Module_PDU_51  sizeof(KrbFastFinished)
#define SIZE_KRB5_Module_PDU_52  sizeof(EncryptedChallenge)
#define SIZE_KRB5_Module_PDU_53  sizeof(KERB_PA_SERV_REFERRAL)
#define SIZE_KRB5_Module_PDU_54  sizeof(KERB_PA_PK_AS_REQ)
#define SIZE_KRB5_Module_PDU_55  sizeof(TrustedCA)
#define SIZE_KRB5_Module_PDU_56  sizeof(TD_TRUSTED_CERTIFIERS_Element)
#define SIZE_KRB5_Module_PDU_57  sizeof(TD_INVALID_CERTIFICATES_Element)
#define SIZE_KRB5_Module_PDU_58  sizeof(KRB5PrincipalName)
#define SIZE_KRB5_Module_PDU_59  sizeof(AD_INITIAL_VERIFIED_CAS_Element)
#define SIZE_KRB5_Module_PDU_60  sizeof(DHRepInfo)
#define SIZE_KRB5_Module_PDU_61  sizeof(KDCDHKeyInfo)
#define SIZE_KRB5_Module_PDU_62  sizeof(PKOcspData_Element)
#define SIZE_KRB5_Module_PDU_63  sizeof(PKAuthenticator)
#define SIZE_KRB5_Module_PDU_64  sizeof(KERB_ALGORITHM_IDENTIFIER)
#define SIZE_KRB5_Module_PDU_65  sizeof(KERB_SUBJECT_PUBLIC_KEY_INFO)
#define SIZE_KRB5_Module_PDU_66  sizeof(KERB_DH_PARAMTER)
#define SIZE_KRB5_Module_PDU_67  sizeof(KERB_SIGNATURE)
#define SIZE_KRB5_Module_PDU_68  sizeof(KERB_SALTED_ENCRYPTED_TIMESTAMP)
#define SIZE_KRB5_Module_PDU_69  sizeof(KERB_ENVELOPED_KEY_PACKAGE)
#define SIZE_KRB5_Module_PDU_70  sizeof(KERB_PKCS_SIGNATURE)
#define SIZE_KRB5_Module_PDU_71  sizeof(KERB_KDC_DH_KEY_INFO)
#define SIZE_KRB5_Module_PDU_72  sizeof(KERB_REPLY_KEY_PACKAGE2)
#define SIZE_KRB5_Module_PDU_73  sizeof(KERB_REPLY_KEY_PACKAGE3)
#define SIZE_KRB5_Module_PDU_74  sizeof(KERB_KERBEROS_NAME)
#define SIZE_KRB5_Module_PDU_75  sizeof(KERB_REPLY_KEY_PACKAGE)
#define SIZE_KRB5_Module_PDU_76  sizeof(KERB_TGT_REQUEST)
#define SIZE_KRB5_Module_PDU_77  sizeof(KERB_TGT_REPLY)
#define SIZE_KRB5_Module_PDU_78  sizeof(KERB_KDC_ISSUED_AUTH_DATA)
#define SIZE_KRB5_Module_PDU_79  sizeof(KERB_ENCRYPTED_TICKET)
#define SIZE_KRB5_Module_PDU_80  sizeof(KERB_KDC_REQUEST)
#define SIZE_KRB5_Module_PDU_81  sizeof(KERB_MARSHALLED_REQUEST_BODY)
#define SIZE_KRB5_Module_PDU_82  sizeof(KERB_AS_REPLY)
#define SIZE_KRB5_Module_PDU_83  sizeof(KERB_TGS_REPLY)
#define SIZE_KRB5_Module_PDU_84  sizeof(KERB_ENCRYPTED_AS_REPLY)
#define SIZE_KRB5_Module_PDU_85  sizeof(KERB_ENCRYPTED_TGS_REPLY)
#define SIZE_KRB5_Module_PDU_86  sizeof(KERB_SAFE_MESSAGE)
#define SIZE_KRB5_Module_PDU_87  sizeof(PA_S4U_X509_USER)
#define SIZE_KRB5_Module_PDU_88  sizeof(PA_FX_FAST_REQUEST)
#define SIZE_KRB5_Module_PDU_89  sizeof(PA_FX_FAST_REPLY)
#define SIZE_KRB5_Module_PDU_90  sizeof(KrbFastResponse)
#define SIZE_KRB5_Module_PDU_91  sizeof(KERB_AUTH_PACKAGE)
#define SIZE_KRB5_Module_PDU_92  sizeof(KERB_AUTH_PACKAGE2)
#define SIZE_KRB5_Module_PDU_93  sizeof(TD_DH_PARAMETERS_Element)
#define SIZE_KRB5_Module_PDU_94  sizeof(KERB_PA_PK_AS_REP)
#define SIZE_KRB5_Module_PDU_95  sizeof(KERB_SIGNED_REPLY_KEY_PACKAGE)
#define SIZE_KRB5_Module_PDU_96  sizeof(KERB_TRUSTED_CAS)
#define SIZE_KRB5_Module_PDU_97  sizeof(KERB_AS_REQUEST)
#define SIZE_KRB5_Module_PDU_98  sizeof(KERB_TGS_REQUEST)
#define SIZE_KRB5_Module_PDU_99  sizeof(KERB_PA_PK_AS_REP2)
#define SIZE_KRB5_Module_PDU_100 sizeof(KERB_PA_PK_AS_REQ2)

#ifdef __cplusplus
extern "C" {
#endif
    
struct AD_INITIAL_VERIFIED_CAS;
struct DHRepInfo;
struct ETYPE_INFO2;
struct ETYPE_INFO2_ENTRY;
struct EtypeList;
struct KDC_PROXY_MESSAGE;
struct KDCDHKeyInfo;
struct KERB_AD_RESTRICTION_ENTRY;
struct KERB_ALGORITHM_IDENTIFIER;
struct KERB_AP_REPLY;
struct KERB_AP_REQUEST;
struct KERB_AUTH_PACKAGE;
struct KERB_AUTH_PACKAGE2;
struct KERB_AUTH_PACKAGE2_supportedCMSTypes;
struct KERB_AUTHENTICATOR;
struct KERB_CERTIFICATE;
struct KERB_CHANGE_PASSWORD_DATA;
struct KERB_CHECKSUM;
struct KERB_CRED;
struct KERB_CRED_INFO;
struct KERB_CRED_tickets;
struct KERB_DH_PARAMTER;
struct KERB_ENCRYPTED_AP_REPLY;
struct KERB_ENCRYPTED_CRED;
struct KERB_ENCRYPTED_CRED_ticket_info;
struct KERB_ENCRYPTED_DATA;
struct KERB_ENCRYPTED_KDC_REPLY;
struct KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data;
struct KERB_ENCRYPTED_PRIV;
struct KERB_ENCRYPTED_TICKET;
struct KERB_ENCRYPTED_TIMESTAMP;
struct KERB_ENCRYPTION_KEY_ASN1;
struct KERB_ENVELOPED_KEY_PACKAGE;
struct KERB_ERROR;
struct KERB_ERROR_METHOD_DATA;
struct KERB_ETYPE_INFO_ENTRY;
struct KERB_EXT_ERROR;
struct KERB_HOST_ADDRESS;
struct KERB_KDC_DH_KEY_INFO;
struct KERB_KDC_ISSUED_AUTH_DATA;
struct KERB_KDC_ISSUED_AUTH_DATA_elements;
struct KERB_KDC_REPLY;
struct KERB_KDC_REPLY_preauth_data;
struct KERB_KDC_REQUEST;
struct KERB_KDC_REQUEST_BODY;
struct KERB_KDC_REQUEST_BODY_additional_tickets;
struct KERB_KDC_REQUEST_BODY_encryption_type;
struct KERB_KDC_REQUEST_preauth_data;
struct KERB_KERBEROS_NAME;
struct KERB_KEY_LIST_REP;
struct KERB_KEY_LIST_REQ;
struct KERB_PA_DATA;
struct KERB_PA_FOR_USER;
struct KERB_PA_PAC_OPTIONS;
struct KERB_PA_PAC_REQUEST;
struct KERB_PA_PK_AS_REP;
struct KERB_PA_PK_AS_REP2;
struct KERB_PA_PK_AS_REP2_kdc_cert;
struct KERB_PA_PK_AS_REQ;
struct KERB_PA_PK_AS_REQ_trusted_certifiers;
struct KERB_PA_PK_AS_REQ2;
struct KERB_PA_PK_AS_REQ2_trusted_certifiers;
struct KERB_PA_PK_AS_REQ2_user_certs;
struct KERB_PA_SERV_REFERRAL;
struct KERB_PK_AUTHENTICATOR;
struct KERB_PKCS_SIGNATURE;
struct KERB_PRINCIPAL_NAME;
struct KERB_PRINCIPAL_NAME_name_string;
struct KERB_PRIV_MESSAGE;
struct KERB_REALM_CACHE;
struct KERB_REALM_CACHE_ENTRY;
struct KERB_REPLY_KEY_PACKAGE;
struct KERB_REPLY_KEY_PACKAGE2;
struct KERB_REPLY_KEY_PACKAGE3;
struct KERB_SAFE_BODY;
struct KERB_SAFE_MESSAGE;
struct KERB_SALTED_ENCRYPTED_TIMESTAMP;
struct KERB_SIGNATURE;
struct KERB_SIGNED_AUTH_PACKAGE;
struct KERB_SIGNED_KDC_PUBLIC_VALUE;
struct KERB_SIGNED_REPLY_KEY_PACKAGE;
struct KERB_SUBJECT_PUBLIC_KEY_INFO;
struct KERB_TGT_REPLY;
struct KERB_TGT_REQUEST;
struct KERB_TICKET;
struct KERB_TRANSITED_ENCODING;
struct KERB_TRUSTED_CAS;
struct KERB_TYPED_DATA;
struct KRB5PrincipalName;
struct KrbFastArmor;
struct KrbFastArmoredRep;
struct KrbFastArmoredReq;
struct KrbFastFinished;
struct KrbFastReq;
struct KrbFastReq_padata;
struct KrbFastResponse;
struct KrbFastResponse_padata;
struct PA_FX_FAST_REPLY;
struct PA_FX_FAST_REQUEST;
struct PA_S4U_X509_USER;
struct PKAuthenticator;
struct PKERB_AD_RESTRICTION;
struct PKERB_AUTHORIZATION_DATA;
struct PKERB_AUTHORIZATION_DATA_Seq;
struct PKERB_ETYPE_INFO;
struct PKERB_HOST_ADDRESSES;
struct PKERB_HOST_ADDRESSES_Seq;
struct PKERB_LAST_REQUEST;
struct PKERB_LAST_REQUEST_Seq;
struct PKERB_PREAUTH_DATA_LIST;
struct PKERB_TICKET_EXTENSIONS;
struct PKERB_TICKET_EXTENSIONS_Seq;
struct PKOcspData;
struct S4UUserID;
struct TD_DH_PARAMETERS;
struct TD_INVALID_CERTIFICATES;
struct TD_TRUSTED_CERTIFIERS;
struct TrustedCA;
struct TYPED_DATA;

typedef struct KERB_KDC_REQUEST_BODY_encryption_type* PKERB_KDC_REQUEST_BODY_encryption_type;
typedef struct KERB_PRINCIPAL_NAME_name_string* PKERB_PRINCIPAL_NAME_name_string;
typedef struct KERB_REALM_CACHE* PKERB_REALM_CACHE;
typedef struct PKERB_HOST_ADDRESSES* PPKERB_HOST_ADDRESSES;
typedef struct PKERB_AUTHORIZATION_DATA* PPKERB_AUTHORIZATION_DATA;
typedef struct PKERB_PREAUTH_DATA_LIST* PPKERB_PREAUTH_DATA_LIST;
typedef struct PKERB_ETYPE_INFO* PPKERB_ETYPE_INFO;
typedef struct PKERB_LAST_REQUEST* PPKERB_LAST_REQUEST;
typedef struct PKERB_TICKET_EXTENSIONS* PPKERB_TICKET_EXTENSIONS;
typedef struct TYPED_DATA* PTYPED_DATA;
typedef struct ETYPE_INFO2* PETYPE_INFO2;
typedef struct EtypeList* PEtypeList;
typedef struct PKERB_AD_RESTRICTION* PPKERB_AD_RESTRICTION;
typedef struct KERB_KEY_LIST_REQ* PKERB_KEY_LIST_REQ;
typedef struct KERB_KEY_LIST_REP* PKERB_KEY_LIST_REP;
typedef struct TD_TRUSTED_CERTIFIERS* PTD_TRUSTED_CERTIFIERS;
typedef struct TD_INVALID_CERTIFICATES* PTD_INVALID_CERTIFICATES;
typedef struct AD_INITIAL_VERIFIED_CAS* PAD_INITIAL_VERIFIED_CAS;
typedef struct PKOcspData* PPKOcspData;
typedef struct KERB_PA_PK_AS_REQ2_trusted_certifiers* PKERB_PA_PK_AS_REQ2_trusted_certifiers;
typedef struct KERB_PA_PK_AS_REQ2_user_certs* PKERB_PA_PK_AS_REQ2_user_certs;
typedef struct KERB_PA_PK_AS_REP2_kdc_cert* PKERB_PA_PK_AS_REP2_kdc_cert;
typedef struct KERB_AUTH_PACKAGE2_supportedCMSTypes* PKERB_AUTH_PACKAGE2_supportedCMSTypes;
typedef struct KrbFastResponse_padata* PKrbFastResponse_padata;
typedef struct KrbFastReq_padata* PKrbFastReq_padata;
typedef struct KERB_ENCRYPTED_CRED_ticket_info* PKERB_ENCRYPTED_CRED_ticket_info;
typedef struct KERB_CRED_tickets* PKERB_CRED_tickets;
typedef struct KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data* PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data;
typedef struct KERB_KDC_REPLY_preauth_data* PKERB_KDC_REPLY_preauth_data;
typedef struct KERB_KDC_REQUEST_BODY_additional_tickets* PKERB_KDC_REQUEST_BODY_additional_tickets;
typedef struct KERB_KDC_REQUEST_preauth_data* PKERB_KDC_REQUEST_preauth_data;
typedef struct KERB_KDC_ISSUED_AUTH_DATA_elements* PKERB_KDC_ISSUED_AUTH_DATA_elements;
typedef struct TD_DH_PARAMETERS* PTD_DH_PARAMETERS;
typedef struct KERB_PA_PK_AS_REQ_trusted_certifiers* PKERB_PA_PK_AS_REQ_trusted_certifiers;
typedef ASN1ztcharstring_t KERB_PRINCIPAL_NAME_name_string_Seq;
typedef ASN1int32_t KERB_KDC_REQUEST_BODY_encryption_type_Seq;
typedef ASN1octetstring_t TD_INVALID_CERTIFICATES_Seq;
typedef ASN1octetstring_t TD_TRUSTED_CERTIFIERS_Seq;
typedef ASN1int32_t KERB_KEY_LIST_REQ_Seq;
typedef ASN1int32_t EtypeList_Seq;
typedef ASN1ztcharstring_t KERB_REALM;
typedef ASN1generalizedtime_t KERB_TIME;
typedef ASN1intx_t KERB_SEQUENCE_NUMBER_LARGE;
typedef ASN1uint32_t KERB_SEQUENCE_NUMBER;
typedef PPKERB_AUTHORIZATION_DATA PKERB_AUTHORIZATION_DATA_LIST;
typedef PPKERB_AUTHORIZATION_DATA PKERB_IF_RELEVANT_AUTH_DATA;
typedef ASN1bitstring_t KERB_KDC_OPTIONS;
typedef ASN1bitstring_t KERB_TICKET_FLAGS;
typedef ASN1bitstring_t KERB_AP_OPTIONS;
typedef ASN1octetstring_t DHNonce;
typedef ASN1octetstring_t OcspResponse;
typedef ASN1int32_t KERB_CERTIFICATE_SERIAL_NUMBER;
typedef ASN1open_t NOCOPYANY;

typedef struct PKERB_TICKET_EXTENSIONS_Seq {
    ASN1int32_t te_type;
    ASN1octetstring_t te_data;
} PKERB_TICKET_EXTENSIONS_Seq;

typedef struct PKERB_LAST_REQUEST_Seq {
    ASN1int32_t last_request_type;
    KERB_TIME last_request_value;
} PKERB_LAST_REQUEST_Seq;

typedef struct KERB_KDC_REQUEST_BODY_encryption_type {
    PKERB_KDC_REQUEST_BODY_encryption_type next;
    KERB_KDC_REQUEST_BODY_encryption_type_Seq value;
} KERB_KDC_REQUEST_BODY_encryption_type_Element;

typedef struct PKERB_AUTHORIZATION_DATA_Seq {
    ASN1int32_t auth_data_type;
    ASN1octetstring_t auth_data;
} PKERB_AUTHORIZATION_DATA_Seq;

typedef struct PKERB_HOST_ADDRESSES_Seq {
    ASN1int32_t addr_type;
    ASN1octetstring_t address;
} PKERB_HOST_ADDRESSES_Seq;

typedef struct KERB_PRINCIPAL_NAME_name_string {
    PKERB_PRINCIPAL_NAME_name_string next;
    KERB_PRINCIPAL_NAME_name_string_Seq value;
} KERB_PRINCIPAL_NAME_name_string_Element;

typedef struct KERB_REALM_CACHE_ENTRY {
    ASN1ztcharstring_t realm;
    ASN1generalizedtime_t access_time;
} KERB_REALM_CACHE_ENTRY;

typedef struct KERB_REALM_CACHE {
    PKERB_REALM_CACHE next;
    KERB_REALM_CACHE_ENTRY value;
} KERB_REALM_CACHE_Element;

typedef struct KERB_PRINCIPAL_NAME {
    ASN1int32_t name_type;
    PKERB_PRINCIPAL_NAME_name_string name_string;
} KERB_PRINCIPAL_NAME;

typedef struct KERB_HOST_ADDRESS {
    ASN1int32_t addr_type;
    ASN1octetstring_t address;
} KERB_HOST_ADDRESS;

typedef struct PKERB_HOST_ADDRESSES {
    PPKERB_HOST_ADDRESSES next;
    PKERB_HOST_ADDRESSES_Seq value;
} PKERB_HOST_ADDRESSES_Element;

typedef struct PKERB_AUTHORIZATION_DATA {
    PPKERB_AUTHORIZATION_DATA next;
    PKERB_AUTHORIZATION_DATA_Seq value;
} PKERB_AUTHORIZATION_DATA_Element;

typedef struct KERB_PA_DATA {
    ASN1int32_t preauth_data_type;
    ASN1octetstring_t preauth_data;
} KERB_PA_DATA;

typedef struct PKERB_PREAUTH_DATA_LIST {
    PPKERB_PREAUTH_DATA_LIST next;
    KERB_PA_DATA value;
} PKERB_PREAUTH_DATA_LIST_Element;

typedef struct KERB_ENCRYPTED_TIMESTAMP {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_TIME timestamp;
#define KERB_ENCRYPTED_TIMESTAMP_usec_present 0x80
    ASN1int32_t usec;
} KERB_ENCRYPTED_TIMESTAMP;

typedef struct KERB_ETYPE_INFO_ENTRY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t encryption_type;
#define KERB_ETYPE_INFO_ENTRY_salt_present 0x80
    ASN1octetstring_t salt;
} KERB_ETYPE_INFO_ENTRY;

typedef struct PKERB_ETYPE_INFO {
    PPKERB_ETYPE_INFO next;
    KERB_ETYPE_INFO_ENTRY value;
} PKERB_ETYPE_INFO_Element;

typedef struct ETYPE_INFO2_ENTRY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t etype;
#define ETYPE_INFO2_ENTRY_salt_present 0x80
    ASN1ztcharstring_t salt;
#define s2kparams_present 0x40
    ASN1octetstring_t s2kparams;
} ETYPE_INFO2_ENTRY;

typedef struct ETYPE_INFO2 {
    PETYPE_INFO2 next;
    ETYPE_INFO2_ENTRY value;
} ETYPE_INFO2_Element;

typedef struct KERB_ENCRYPTED_DATA {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t encryption_type;

#define version_present 0x80

    ASN1int32_t version;
    ASN1octetstring_t cipher_text;
} KERB_ENCRYPTED_DATA;

typedef KERB_ENCRYPTED_DATA EncryptedData;

typedef struct KERB_ENCRYPTION_KEY_ASN1 {
    ASN1int32_t keytype;
    ASN1octetstring_t keyvalue;
} KERB_ENCRYPTION_KEY_ASN1;

typedef KERB_ENCRYPTED_DATA EncryptionKey;

typedef struct KERB_CHECKSUM {
    ASN1int32_t checksum_type;
    ASN1octetstring_t checksum;
} KERB_CHECKSUM;

typedef struct KERB_TICKET {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t ticket_version;
    KERB_REALM realm;
    KERB_PRINCIPAL_NAME server_name;
    KERB_ENCRYPTED_DATA encrypted_part;
#define ticket_extensions_present 0x80
    PPKERB_TICKET_EXTENSIONS ticket_extensions;
} KERB_TICKET;

typedef struct KERB_TRANSITED_ENCODING {
    ASN1int32_t transited_type;
    ASN1octetstring_t contents;
} KERB_TRANSITED_ENCODING;

typedef struct KERB_KDC_REQUEST_BODY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_KDC_OPTIONS kdc_options;
#define KERB_KDC_REQUEST_BODY_client_name_present 0x80
    KERB_PRINCIPAL_NAME client_name;
    KERB_REALM realm;
#define KERB_KDC_REQUEST_BODY_server_name_present 0x40
    KERB_PRINCIPAL_NAME server_name;
#define KERB_KDC_REQUEST_BODY_starttime_present 0x20
    KERB_TIME starttime;
    KERB_TIME endtime;
#define KERB_KDC_REQUEST_BODY_renew_until_present 0x10
    KERB_TIME renew_until;
    ASN1int32_t nonce;
    PKERB_KDC_REQUEST_BODY_encryption_type encryption_type;
#define addresses_present 0x8
    PPKERB_HOST_ADDRESSES addresses;
#define enc_authorization_data_present 0x4
    KERB_ENCRYPTED_DATA enc_authorization_data;
#define additional_tickets_present 0x2
    PKERB_KDC_REQUEST_BODY_additional_tickets additional_tickets;
} KERB_KDC_REQUEST_BODY;

typedef struct KERB_KDC_REPLY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t version;
    ASN1int32_t message_type;
#define KERB_KDC_REPLY_preauth_data_present 0x80
    PKERB_KDC_REPLY_preauth_data preauth_data;
    KERB_REALM client_realm;
    KERB_PRINCIPAL_NAME client_name;
    KERB_TICKET ticket;
    KERB_ENCRYPTED_DATA encrypted_part;
} KERB_KDC_REPLY;

typedef struct KERB_ENCRYPTED_KDC_REPLY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_ENCRYPTION_KEY_ASN1 session_key;
    PPKERB_LAST_REQUEST last_request;
    ASN1int32_t nonce;
#define key_expiration_present 0x80
    KERB_TIME key_expiration;
    KERB_TICKET_FLAGS flags;
    KERB_TIME authtime;
#define KERB_ENCRYPTED_KDC_REPLY_starttime_present 0x40
    KERB_TIME starttime;
    KERB_TIME endtime;
#define KERB_ENCRYPTED_KDC_REPLY_renew_until_present 0x20
    KERB_TIME renew_until;
    KERB_REALM server_realm;
    KERB_PRINCIPAL_NAME server_name;
#define KERB_ENCRYPTED_KDC_REPLY_client_addresses_present 0x10
    PPKERB_HOST_ADDRESSES client_addresses;
#define encrypted_pa_data_present 0x8
    PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data encrypted_pa_data;
} KERB_ENCRYPTED_KDC_REPLY;

typedef struct PKERB_LAST_REQUEST {
    PPKERB_LAST_REQUEST next;
    PKERB_LAST_REQUEST_Seq value;
} PKERB_LAST_REQUEST_Element;

typedef struct KERB_AP_REQUEST {
    ASN1int32_t version;
    ASN1int32_t message_type;
    KERB_AP_OPTIONS ap_options;
    KERB_TICKET ticket;
    KERB_ENCRYPTED_DATA authenticator;
} KERB_AP_REQUEST;

typedef struct KERB_AUTHENTICATOR {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t authenticator_version;
    KERB_REALM client_realm;
    KERB_PRINCIPAL_NAME client_name;
#define checksum_present 0x80
    KERB_CHECKSUM checksum;
    ASN1int32_t client_usec;
    KERB_TIME client_time;
#define KERB_AUTHENTICATOR_subkey_present 0x40
    KERB_ENCRYPTION_KEY_ASN1 subkey;
#define KERB_AUTHENTICATOR_sequence_number_present 0x20
    KERB_SEQUENCE_NUMBER_LARGE sequence_number;
#define KERB_AUTHENTICATOR_authorization_data_present 0x10
    PPKERB_AUTHORIZATION_DATA authorization_data;
} KERB_AUTHENTICATOR;

typedef struct KERB_AP_REPLY {
    ASN1int32_t version;
    ASN1int32_t message_type;
    KERB_ENCRYPTED_DATA encrypted_part;
} KERB_AP_REPLY;

typedef struct KERB_ENCRYPTED_AP_REPLY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_TIME client_time;
    ASN1int32_t client_usec;
#define KERB_ENCRYPTED_AP_REPLY_subkey_present 0x80
    KERB_ENCRYPTION_KEY_ASN1 subkey;
#define KERB_ENCRYPTED_AP_REPLY_sequence_number_present 0x40
    KERB_SEQUENCE_NUMBER sequence_number;
} KERB_ENCRYPTED_AP_REPLY;

typedef struct KERB_SAFE_BODY {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1octetstring_t user_data;
#define KERB_SAFE_BODY_timestamp_present 0x80
    KERB_TIME timestamp;
#define KERB_SAFE_BODY_usec_present 0x40
    ASN1int32_t usec;
#define KERB_SAFE_BODY_sequence_number_present 0x20
    KERB_SEQUENCE_NUMBER sequence_number;
    KERB_HOST_ADDRESS sender_address;
#define KERB_SAFE_BODY_recipient_address_present 0x10
    KERB_HOST_ADDRESS recipient_address;
} KERB_SAFE_BODY;

typedef struct KERB_PRIV_MESSAGE {
    ASN1int32_t version;
    ASN1int32_t message_type;
    KERB_ENCRYPTED_DATA encrypted_part;
} KERB_PRIV_MESSAGE;

typedef struct KERB_ENCRYPTED_PRIV {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1octetstring_t user_data;
#define KERB_ENCRYPTED_PRIV_timestamp_present 0x80
    KERB_TIME timestamp;
#define KERB_ENCRYPTED_PRIV_usec_present 0x40
    ASN1int32_t usec;
#define KERB_ENCRYPTED_PRIV_sequence_number_present 0x20
    KERB_SEQUENCE_NUMBER sequence_number;
    KERB_HOST_ADDRESS sender_address;
#define KERB_ENCRYPTED_PRIV_recipient_address_present 0x10
    KERB_HOST_ADDRESS recipient_address;
} KERB_ENCRYPTED_PRIV;

typedef struct PKERB_TICKET_EXTENSIONS {
    PPKERB_TICKET_EXTENSIONS next;
    PKERB_TICKET_EXTENSIONS_Seq value;
} PKERB_TICKET_EXTENSIONS_Element;

typedef struct KERB_CRED {
    ASN1int32_t version;
    ASN1int32_t message_type;
    PKERB_CRED_tickets tickets;
    KERB_ENCRYPTED_DATA encrypted_part;
} KERB_CRED;

typedef struct KERB_ENCRYPTED_CRED {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    PKERB_ENCRYPTED_CRED_ticket_info ticket_info;
#define nonce_present 0x80
    ASN1int32_t nonce;
#define KERB_ENCRYPTED_CRED_timestamp_present 0x40
    KERB_TIME timestamp;
#define KERB_ENCRYPTED_CRED_usec_present 0x20
    ASN1int32_t usec;
#define sender_address_present 0x10
    KERB_HOST_ADDRESS sender_address;
#define KERB_ENCRYPTED_CRED_recipient_address_present 0x8
    KERB_HOST_ADDRESS recipient_address;
} KERB_ENCRYPTED_CRED;

typedef struct KERB_CRED_INFO {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[2];
    };
    KERB_ENCRYPTION_KEY_ASN1 key;
#define principal_realm_present 0x80
    KERB_REALM principal_realm;
#define principal_name_present 0x40
    KERB_PRINCIPAL_NAME principal_name;
#define flags_present 0x20
    KERB_TICKET_FLAGS flags;
#define authtime_present 0x10
    KERB_TIME authtime;
#define KERB_CRED_INFO_starttime_present 0x8
    KERB_TIME starttime;
#define endtime_present 0x4
    KERB_TIME endtime;
#define KERB_CRED_INFO_renew_until_present 0x2
    KERB_TIME renew_until;
#define service_realm_present 0x1
    KERB_REALM service_realm;
#define service_name_present 0x8000
    KERB_PRINCIPAL_NAME service_name;
#define KERB_CRED_INFO_client_addresses_present 0x4000
    PPKERB_HOST_ADDRESSES client_addresses;
} KERB_CRED_INFO;

typedef struct KERB_ERROR {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t version;
    ASN1int32_t message_type;
#define client_time_present 0x80
    KERB_TIME client_time;
#define client_usec_present 0x40
    ASN1int32_t client_usec;
    KERB_TIME server_time;
    ASN1int32_t server_usec;
    ASN1int32_t error_code;
#define client_realm_present 0x20
    KERB_REALM client_realm;
#define KERB_ERROR_client_name_present 0x10
    KERB_PRINCIPAL_NAME client_name;
    KERB_REALM realm;
    KERB_PRINCIPAL_NAME server_name;
#define error_text_present 0x8
    ASN1charstring_t error_text;
#define error_data_present 0x4
    ASN1octetstring_t error_data;
} KERB_ERROR;

typedef struct KERB_ERROR_METHOD_DATA {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t data_type;
#define data_value_present 0x80
    ASN1octetstring_t data_value;
} KERB_ERROR_METHOD_DATA;

typedef struct KERB_TYPED_DATA {
    ASN1int32_t data_type;
    ASN1octetstring_t data_value;
} KERB_TYPED_DATA;

typedef struct TYPED_DATA {
    PTYPED_DATA next;
    KERB_TYPED_DATA value;
} TYPED_DATA_Element;

typedef struct EtypeList {
    PEtypeList next;
    EtypeList_Seq value;
} EtypeList_Element;

typedef struct KERB_EXT_ERROR {
    ASN1int32_t status;
    ASN1int32_t klininfo;
    ASN1int32_t flags;
} KERB_EXT_ERROR;

typedef KERB_ERROR_METHOD_DATA KERB_ERROR_DATA;

typedef struct KERB_PA_PAC_REQUEST {
    ASN1bool_t include_pac;
} KERB_PA_PAC_REQUEST;

typedef struct KERB_AD_RESTRICTION_ENTRY {
    ASN1int32_t restriction_type;
    ASN1octetstring_t restriction;
} KERB_AD_RESTRICTION_ENTRY;

typedef struct PKERB_AD_RESTRICTION {
    PPKERB_AD_RESTRICTION next;
    KERB_AD_RESTRICTION_ENTRY value;
} PKERB_AD_RESTRICTION_Element;

typedef struct KERB_PA_PAC_OPTIONS {
    KERB_KDC_OPTIONS pac_flags;
} KERB_PA_PAC_OPTIONS;

typedef struct KERB_KEY_LIST_REQ {
    PKERB_KEY_LIST_REQ next;
    KERB_KEY_LIST_REQ_Seq value;
} KERB_KEY_LIST_REQ_Element;

typedef struct KERB_KEY_LIST_REP {
    PKERB_KEY_LIST_REP next;
    KERB_ENCRYPTION_KEY_ASN1 value;
} KERB_KEY_LIST_REP_Element;

typedef struct KERB_CHANGE_PASSWORD_DATA {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1octetstring_t new_password;
#define target_name_present 0x80
    KERB_PRINCIPAL_NAME target_name;
#define target_realm_present 0x40
    KERB_REALM target_realm;
} KERB_CHANGE_PASSWORD_DATA;

typedef struct KDC_PROXY_MESSAGE {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1octetstring_t kerb_message;
#define target_domain_present 0x80
    KERB_REALM target_domain;
#define dclocator_hint_present 0x40
    ASN1int32_t dclocator_hint;
} KDC_PROXY_MESSAGE;

typedef struct KERB_PA_FOR_USER {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_PRINCIPAL_NAME userName;
    KERB_REALM userRealm;
    KERB_CHECKSUM cksum;
    ASN1ztcharstring_t authentication_package;
#define KERB_PA_FOR_USER_authorization_data_present 0x80
    ASN1octetstring_t authorization_data;
} KERB_PA_FOR_USER;

typedef struct S4UUserID {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t nonce;
#define cname_present 0x80
    KERB_PRINCIPAL_NAME cname;
    KERB_REALM crealm;
#define certificate_present 0x40
    ASN1octetstring_t certificate;
#define options_present 0x20
    ASN1bitstring_t options;
} S4UUserID;

typedef struct KrbFastArmor {
    ASN1int32_t armor_type;
    ASN1octetstring_t armor_value;
} KrbFastArmor;

typedef struct KrbFastArmoredReq {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
#define armor_present 0x80
    KrbFastArmor armor;
    KERB_CHECKSUM req_checksum;
    EncryptedData enc_fast_req;
} KrbFastArmoredReq;

typedef struct KrbFastReq {
    ASN1bitstring_t fast_options;
    PKrbFastReq_padata padata;
    KERB_KDC_REQUEST_BODY req_body;
} KrbFastReq;

typedef struct KrbFastArmoredRep {
    EncryptedData enc_fast_rep;
} KrbFastArmoredRep;

typedef struct KrbFastFinished {
    KERB_TIME timestamp;
    ASN1int32_t usec;
    KERB_REALM crealm;
    KERB_PRINCIPAL_NAME cname;
    KERB_CHECKSUM ticket_checksum;
} KrbFastFinished;

typedef EncryptedData EncryptedChallenge;

typedef struct KERB_PA_SERV_REFERRAL {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
#define referred_server_name_present 0x80
    KERB_PRINCIPAL_NAME referred_server_name;
    KERB_REALM referred_server_realm;
} KERB_PA_SERV_REFERRAL;

typedef struct KERB_PA_PK_AS_REQ {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1octetstring_t signed_auth_pack;
#define KERB_PA_PK_AS_REQ_trusted_certifiers_present 0x80
    PKERB_PA_PK_AS_REQ_trusted_certifiers trusted_certifiers;
#define kdc_pk_id_present 0x40
    ASN1octetstring_t kdc_pk_id;
} KERB_PA_PK_AS_REQ;

typedef struct TrustedCA {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
#define subjectName_present 0x80
    ASN1octetstring_t subjectName;
#define issuerAndSerialNumber_present 0x40
    ASN1octetstring_t issuerAndSerialNumber;
#define subjectKeyIdentifier_present 0x20
    ASN1octetstring_t subjectKeyIdentifier;
} TrustedCA;

typedef struct KERB_PK_AUTHENTICATOR {
    KERB_PRINCIPAL_NAME kdc_name;
    KERB_REALM kdc_realm;
    ASN1int32_t cusec;
    KERB_TIME client_time;
    ASN1int32_t nonce;
} KERB_PK_AUTHENTICATOR;

typedef struct TD_TRUSTED_CERTIFIERS {
    PTD_TRUSTED_CERTIFIERS next;
    TD_TRUSTED_CERTIFIERS_Seq value;
} TD_TRUSTED_CERTIFIERS_Element;

typedef struct TD_INVALID_CERTIFICATES {
    PTD_INVALID_CERTIFICATES next;
    TD_INVALID_CERTIFICATES_Seq value;
} TD_INVALID_CERTIFICATES_Element;

typedef struct KRB5PrincipalName {
    KERB_REALM realm;
    KERB_PRINCIPAL_NAME principalName;
} KRB5PrincipalName;

typedef struct AD_INITIAL_VERIFIED_CAS {
    PAD_INITIAL_VERIFIED_CAS next;
    TrustedCA value;
} AD_INITIAL_VERIFIED_CAS_Element;

typedef struct DHRepInfo {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1octetstring_t dhSignedData;
#define serverDHNonce_present 0x80
    DHNonce serverDHNonce;
} DHRepInfo;

typedef struct KDCDHKeyInfo {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1bitstring_t subjectPublicKey;
    ASN1uint32_t nonce;
#define dhKeyExpiration_present 0x80
    KERB_TIME dhKeyExpiration;
} KDCDHKeyInfo;

typedef struct PKOcspData {
    PPKOcspData next;
    OcspResponse value;
} PKOcspData_Element;

typedef struct PKAuthenticator {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1uint32_t cusec;
    KERB_TIME client_time;
    ASN1uint32_t nonce;
#define paChecksum_present 0x80
    ASN1octetstring_t paChecksum;
#define freshnessToken_present 0x40
    ASN1octetstring_t freshnessToken;
} PKAuthenticator;

typedef struct KERB_ALGORITHM_IDENTIFIER {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1objectidentifier_t algorithm;
#define parameters_present 0x80
    NOCOPYANY parameters;
} KERB_ALGORITHM_IDENTIFIER;

typedef struct KERB_SUBJECT_PUBLIC_KEY_INFO {
    KERB_ALGORITHM_IDENTIFIER algorithm;
    ASN1bitstring_t subjectPublicKey;
} KERB_SUBJECT_PUBLIC_KEY_INFO;

typedef struct KERB_DH_PARAMTER {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t prime;
    ASN1int32_t base;
#define private_value_length_present 0x80
    ASN1int32_t private_value_length;
} KERB_DH_PARAMTER;

typedef struct KERB_CERTIFICATE {
    ASN1int32_t cert_type;
    ASN1octetstring_t cert_data;
} KERB_CERTIFICATE;

typedef struct KERB_SIGNATURE {
    KERB_ALGORITHM_IDENTIFIER signature_algorithm;
    ASN1bitstring_t pkcs_signature;
} KERB_SIGNATURE;

typedef struct KERB_SALTED_ENCRYPTED_TIMESTAMP {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_TIME timestamp;
#define KERB_SALTED_ENCRYPTED_TIMESTAMP_usec_present 0x80
    ASN1int32_t usec;
    ASN1octetstring_t salt;
} KERB_SALTED_ENCRYPTED_TIMESTAMP;

typedef struct KERB_ENVELOPED_KEY_PACKAGE {
    ASN1choice_t choice;
    union {
#define encrypted_data_chosen 1
        KERB_ENCRYPTED_DATA encrypted_data;
#define pkinit_enveloped_data_chosen 2
        ASN1octetstring_t pkinit_enveloped_data;
    } u;
} KERB_ENVELOPED_KEY_PACKAGE;

typedef struct KERB_PKCS_SIGNATURE {
    ASN1int32_t encryption_type;
    ASN1octetstring_t signature;
} KERB_PKCS_SIGNATURE;

typedef struct KERB_KDC_DH_KEY_INFO {
    ASN1int32_t nonce;
    ASN1bitstring_t subject_public_key;
} KERB_KDC_DH_KEY_INFO;

typedef struct KERB_REPLY_KEY_PACKAGE2 {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_ENCRYPTION_KEY_ASN1 reply_key;
    ASN1int32_t nonce;
#define subject_public_key_present 0x80
    ASN1bitstring_t subject_public_key;
} KERB_REPLY_KEY_PACKAGE2;

typedef struct KERB_REPLY_KEY_PACKAGE3 {
    KERB_ENCRYPTION_KEY_ASN1 reply_key;
    KERB_CHECKSUM as_checksum;
} KERB_REPLY_KEY_PACKAGE3;

typedef struct KERB_KERBEROS_NAME {
    KERB_REALM realm;
    KERB_PRINCIPAL_NAME principal_name;
} KERB_KERBEROS_NAME;

typedef struct KERB_REPLY_KEY_PACKAGE {
    KERB_ENCRYPTION_KEY_ASN1 reply_key;
    ASN1int32_t nonce;
} KERB_REPLY_KEY_PACKAGE;

typedef struct KERB_TGT_REQUEST {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t version;
    ASN1int32_t message_type;
#define KERB_TGT_REQUEST_server_name_present 0x80
    KERB_PRINCIPAL_NAME server_name;
#define server_realm_present 0x40
    KERB_REALM server_realm;
} KERB_TGT_REQUEST;

typedef struct KERB_TGT_REPLY {
    ASN1int32_t version;
    ASN1int32_t message_type;
    KERB_TICKET ticket;
} KERB_TGT_REPLY;

typedef struct KERB_PA_PK_AS_REQ2_trusted_certifiers {
    PKERB_PA_PK_AS_REQ2_trusted_certifiers next;
    KERB_PRINCIPAL_NAME value;
} KERB_PA_PK_AS_REQ2_trusted_certifiers_Element;

typedef struct KERB_PA_PK_AS_REQ2_user_certs {
    PKERB_PA_PK_AS_REQ2_user_certs next;
    KERB_CERTIFICATE value;
} KERB_PA_PK_AS_REQ2_user_certs_Element;

typedef struct KERB_PA_PK_AS_REP2_kdc_cert {
    PKERB_PA_PK_AS_REP2_kdc_cert next;
    KERB_CERTIFICATE value;
} KERB_PA_PK_AS_REP2_kdc_cert_Element;

typedef struct KERB_AUTH_PACKAGE2_supportedCMSTypes {
    PKERB_AUTH_PACKAGE2_supportedCMSTypes next;
    KERB_ALGORITHM_IDENTIFIER value;
} KERB_AUTH_PACKAGE2_supportedCMSTypes_Element;

typedef struct KrbFastResponse_padata {
    PKrbFastResponse_padata next;
    KERB_PA_DATA value;
} KrbFastResponse_padata_Element;

typedef struct KrbFastReq_padata {
    PKrbFastReq_padata next;
    KERB_PA_DATA value;
} KrbFastReq_padata_Element;

typedef struct KERB_ENCRYPTED_CRED_ticket_info {
    PKERB_ENCRYPTED_CRED_ticket_info next;
    KERB_CRED_INFO value;
} KERB_ENCRYPTED_CRED_ticket_info_Element;

typedef struct KERB_CRED_tickets {
    PKERB_CRED_tickets next;
    KERB_TICKET value;
} KERB_CRED_tickets_Element;

typedef struct KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data {
    PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data next;
    KERB_PA_DATA value;
} KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data_Element;

typedef struct KERB_KDC_REPLY_preauth_data {
    PKERB_KDC_REPLY_preauth_data next;
    KERB_PA_DATA value;
} KERB_KDC_REPLY_preauth_data_Element;

typedef struct KERB_KDC_REQUEST_BODY_additional_tickets {
    PKERB_KDC_REQUEST_BODY_additional_tickets next;
    KERB_TICKET value;
} KERB_KDC_REQUEST_BODY_additional_tickets_Element;

typedef struct KERB_KDC_REQUEST_preauth_data {
    PKERB_KDC_REQUEST_preauth_data next;
    KERB_PA_DATA value;
} KERB_KDC_REQUEST_preauth_data_Element;

typedef struct KERB_KDC_ISSUED_AUTH_DATA_elements {
    PKERB_KDC_ISSUED_AUTH_DATA_elements next;
    KERB_PA_DATA value;
} KERB_KDC_ISSUED_AUTH_DATA_elements_Element;

typedef struct KERB_KDC_ISSUED_AUTH_DATA {
    KERB_SIGNATURE checksum;
    PKERB_KDC_ISSUED_AUTH_DATA_elements elements;
} KERB_KDC_ISSUED_AUTH_DATA;

typedef struct KERB_ENCRYPTED_TICKET {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_TICKET_FLAGS flags;
    KERB_ENCRYPTION_KEY_ASN1 key;
    KERB_REALM client_realm;
    KERB_PRINCIPAL_NAME client_name;
    KERB_TRANSITED_ENCODING transited;
    KERB_TIME authtime;
#define KERB_ENCRYPTED_TICKET_starttime_present 0x80
    KERB_TIME starttime;
    KERB_TIME endtime;
#define KERB_ENCRYPTED_TICKET_renew_until_present 0x40
    KERB_TIME renew_until;
#define KERB_ENCRYPTED_TICKET_client_addresses_present 0x20
    PPKERB_HOST_ADDRESSES client_addresses;
#define KERB_ENCRYPTED_TICKET_authorization_data_present 0x10
    PPKERB_AUTHORIZATION_DATA authorization_data;
} KERB_ENCRYPTED_TICKET;

typedef struct KERB_KDC_REQUEST {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    ASN1int32_t version;
    ASN1int32_t message_type;

#define KERB_KDC_REQUEST_preauth_data_present 0x80

    PKERB_KDC_REQUEST_preauth_data preauth_data;
    KERB_KDC_REQUEST_BODY request_body;
} KERB_KDC_REQUEST;

typedef KERB_KDC_REQUEST_BODY KERB_MARSHALLED_REQUEST_BODY;
typedef KERB_KDC_REPLY KERB_AS_REPLY;
typedef KERB_KDC_REPLY KERB_TGS_REPLY;
typedef KERB_ENCRYPTED_KDC_REPLY KERB_ENCRYPTED_AS_REPLY;
typedef KERB_ENCRYPTED_KDC_REPLY KERB_ENCRYPTED_TGS_REPLY;

typedef struct KERB_SAFE_MESSAGE {
    ASN1int32_t version;
    ASN1int32_t message_type;
    KERB_SAFE_BODY safe_body;
    KERB_CHECKSUM checksum;
} KERB_SAFE_MESSAGE;

typedef struct PA_S4U_X509_USER {
    S4UUserID user_id;
    KERB_CHECKSUM checksum;
} PA_S4U_X509_USER;

typedef struct PA_FX_FAST_REQUEST {
    ASN1choice_t choice;
    union {
#define PA_FX_FAST_REQUEST_armored_data_chosen 1
        KrbFastArmoredReq armored_data;
    } u;
} PA_FX_FAST_REQUEST;

typedef struct PA_FX_FAST_REPLY {
    ASN1choice_t choice;
    union {
#define PA_FX_FAST_REPLY_armored_data_chosen 1
        KrbFastArmoredRep armored_data;
    } u;
} PA_FX_FAST_REPLY;

typedef struct KrbFastResponse {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    PKrbFastResponse_padata padata;
#define strengthen_key_present 0x80
    EncryptionKey strengthen_key;
#define finished_present 0x40
    KrbFastFinished finished;
    ASN1int32_t nonce;
} KrbFastResponse;

typedef struct KERB_AUTH_PACKAGE {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_PK_AUTHENTICATOR pk_authenticator;
#define client_public_value_present 0x80
    KERB_SUBJECT_PUBLIC_KEY_INFO client_public_value;
} KERB_AUTH_PACKAGE;

typedef struct KERB_AUTH_PACKAGE2 {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    PKAuthenticator pkAuthenticator;
#define clientPublicValue_present 0x80
    KERB_SUBJECT_PUBLIC_KEY_INFO clientPublicValue;
#define supportedCMSTypes_present 0x40
    PKERB_AUTH_PACKAGE2_supportedCMSTypes supportedCMSTypes;
#define clientDHNonce_present 0x20
    DHNonce clientDHNonce;
} KERB_AUTH_PACKAGE2;

typedef struct TD_DH_PARAMETERS {
    PTD_DH_PARAMETERS next;
    KERB_ALGORITHM_IDENTIFIER value;
} TD_DH_PARAMETERS_Element;

typedef struct KERB_PA_PK_AS_REP {
    ASN1choice_t choice;
    union {
#define dhInfo_chosen 1
        DHRepInfo dhInfo;
#define key_package_chosen 2
        ASN1octetstring_t key_package;
    } u;
} KERB_PA_PK_AS_REP;

typedef struct KERB_SIGNED_REPLY_KEY_PACKAGE {
    KERB_REPLY_KEY_PACKAGE2 reply_key_package;
    KERB_SIGNATURE reply_key_signature;
} KERB_SIGNED_REPLY_KEY_PACKAGE;

typedef struct KERB_SIGNED_KDC_PUBLIC_VALUE {
    KERB_SUBJECT_PUBLIC_KEY_INFO kdc_public_value;
    KERB_SIGNATURE kdc_public_value_sig;
} KERB_SIGNED_KDC_PUBLIC_VALUE;

typedef struct KERB_SIGNED_AUTH_PACKAGE {
    KERB_AUTH_PACKAGE auth_package;
    KERB_SIGNATURE auth_package_signature;
} KERB_SIGNED_AUTH_PACKAGE;

typedef struct KERB_TRUSTED_CAS {
    ASN1choice_t choice;
    union {
#define principal_name_chosen 1
        KERB_KERBEROS_NAME principal_name;
#define ca_name_chosen 2
        ASN1octetstring_t ca_name;
#define issuer_and_serial_chosen 3
        ASN1octetstring_t issuer_and_serial;
    } u;
} KERB_TRUSTED_CAS;

typedef struct KERB_PA_PK_AS_REQ_trusted_certifiers {
    PKERB_PA_PK_AS_REQ_trusted_certifiers next;
    KERB_TRUSTED_CAS value;
} KERB_PA_PK_AS_REQ_trusted_certifiers_Element;

typedef KERB_KDC_REQUEST KERB_AS_REQUEST;
typedef KERB_KDC_REQUEST KERB_TGS_REQUEST;

typedef struct KERB_PA_PK_AS_REP2 {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
#define key_package_present 0x80
    KERB_ENCRYPTED_DATA key_package;
    KERB_ENVELOPED_KEY_PACKAGE temp_key_package;
#define signed_kdc_public_value_present 0x40
    KERB_SIGNED_KDC_PUBLIC_VALUE signed_kdc_public_value;
#define kdc_cert_present 0x20
    PKERB_PA_PK_AS_REP2_kdc_cert kdc_cert;
} KERB_PA_PK_AS_REP2;

typedef struct KERB_PA_PK_AS_REQ2 {
    union {
        ASN1uint16_t bit_mask;
        ASN1octet_t o[1];
    };
    KERB_SIGNED_AUTH_PACKAGE signed_auth_pack;
#define user_certs_present 0x80
    PKERB_PA_PK_AS_REQ2_user_certs user_certs;
#define KERB_PA_PK_AS_REQ2_trusted_certifiers_present 0x40
    PKERB_PA_PK_AS_REQ2_trusted_certifiers trusted_certifiers;
#define serial_number_present 0x20
    KERB_CERTIFICATE_SERIAL_NUMBER serial_number;
} KERB_PA_PK_AS_REQ2;

extern ASN1module_t KRB5_Module;
extern BOOL ASN1CALL asn1_startup_krb5();
extern void ASN1CALL asn1_cleanup_krb5();

extern BOOL asn1_encode_kerb(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData);
extern BOOL asn1_decode_kerb(LPCVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct);
extern BOOL asn1_free_kerb(PVOID pDataStruct, DWORD dwPdu);

#ifdef __cplusplus
} // Closes extern "C" above
namespace Asn1 {
    namespace Kerberos {
        using AD_INITIAL_VERIFIED_CAS = ::AD_INITIAL_VERIFIED_CAS;
        using AD_RESTRICTION_ENTRY = ::KERB_AD_RESTRICTION_ENTRY;
        using ALGORITHM_IDENTIFIER = ::KERB_ALGORITHM_IDENTIFIER;
        using AP_REPLY = ::KERB_AP_REPLY;
        using AP_REQUEST = ::KERB_AP_REQUEST;
        using AUTH_PACKAGE = ::KERB_AUTH_PACKAGE;
        using AUTH_PACKAGE2 = ::KERB_AUTH_PACKAGE2;
        using AUTH_PACKAGE2_supportedCMSTypes = ::KERB_AUTH_PACKAGE2_supportedCMSTypes;
        using AUTHENTICATOR = ::KERB_AUTHENTICATOR;
        using CERTIFICATE = ::KERB_CERTIFICATE;
        using CHANGE_PASSWORD_DATA = ::KERB_CHANGE_PASSWORD_DATA;
        using CHECKSUM = ::KERB_CHECKSUM;
        using CRED = ::KERB_CRED;
        using CRED_INFO = ::KERB_CRED_INFO;
        using CRED_tickets = ::KERB_CRED_tickets;
        using DH_PARAMTER = ::KERB_DH_PARAMTER;
        using DHRepInfo = ::DHRepInfo;
        using ENCRYPTED_AP_REPLY = ::KERB_ENCRYPTED_AP_REPLY;
        using ENCRYPTED_CRED = ::KERB_ENCRYPTED_CRED;
        using ENCRYPTED_CRED_ticket_info = ::KERB_ENCRYPTED_CRED_ticket_info;
        using ENCRYPTED_DATA = ::KERB_ENCRYPTED_DATA;
        using ENCRYPTED_KDC_REPLY = ::KERB_ENCRYPTED_KDC_REPLY;
        using ENCRYPTED_KDC_REPLY_encrypted_pa_data = ::KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data;
        using ENCRYPTED_PRIV = ::KERB_ENCRYPTED_PRIV;
        using ENCRYPTED_TICKET = ::KERB_ENCRYPTED_TICKET;
        using ENCRYPTED_TIMESTAMP = ::KERB_ENCRYPTED_TIMESTAMP;
        using ENCRYPTION_KEY_ASN1 = ::KERB_ENCRYPTION_KEY_ASN1;
        using ENVELOPED_KEY_PACKAGE = ::KERB_ENVELOPED_KEY_PACKAGE;
        using ERROR = ::KERB_ERROR;
        using ERROR_METHOD_DATA = ::KERB_ERROR_METHOD_DATA;
        using ETYPE_INFO_ENTRY = ::KERB_ETYPE_INFO_ENTRY;
        using ETYPE_INFO2 = ::ETYPE_INFO2;
        using ETYPE_INFO2_ENTRY = ::ETYPE_INFO2_ENTRY;
        using EtypeList = ::EtypeList;
        using EXT_ERROR = ::KERB_EXT_ERROR;
        using HOST_ADDRESS = ::KERB_HOST_ADDRESS;
        using KDC_DH_KEY_INFO = ::KERB_KDC_DH_KEY_INFO;
        using KDC_ISSUED_AUTH_DATA = ::KERB_KDC_ISSUED_AUTH_DATA;
        using KDC_ISSUED_AUTH_DATA_elements = ::KERB_KDC_ISSUED_AUTH_DATA_elements;
        using KDC_PROXY_MESSAGE = ::KDC_PROXY_MESSAGE;
        using KDC_REPLY = ::KERB_KDC_REPLY;
        using KDC_REPLY_preauth_data = ::KERB_KDC_REPLY_preauth_data;
        using KDC_REQUEST = ::KERB_KDC_REQUEST;
        using KDC_REQUEST_BODY = ::KERB_KDC_REQUEST_BODY;
        using KDC_REQUEST_BODY_additional_tickets = ::KERB_KDC_REQUEST_BODY_additional_tickets;
        using KDC_REQUEST_BODY_encryption_type = ::KERB_KDC_REQUEST_BODY_encryption_type;
        using KDC_REQUEST_preauth_data = ::KERB_KDC_REQUEST_preauth_data;
        using KDCDHKeyInfo = ::KDCDHKeyInfo;
        using KERBEROS_NAME = ::KERB_KERBEROS_NAME;
        using KEY_LIST_REP = ::KERB_KEY_LIST_REP;
        using KEY_LIST_REQ = ::KERB_KEY_LIST_REQ;
        using KRB5PrincipalName = ::KRB5PrincipalName;
        using KrbFastArmor = ::KrbFastArmor;
        using KrbFastArmoredRep = ::KrbFastArmoredRep;
        using KrbFastArmoredReq = ::KrbFastArmoredReq;
        using KrbFastFinished = ::KrbFastFinished;
        using KrbFastReq = ::KrbFastReq;
        using KrbFastReq_padata = ::KrbFastReq_padata;
        using KrbFastResponse = ::KrbFastResponse;
        using KrbFastResponse_padata = ::KrbFastResponse_padata;
        using PA_DATA = ::KERB_PA_DATA;
        using PA_FOR_USER = ::KERB_PA_FOR_USER;
        using PA_FX_FAST_REPLY = ::PA_FX_FAST_REPLY;
        using PA_FX_FAST_REQUEST = ::PA_FX_FAST_REQUEST;
        using PA_PAC_OPTIONS = ::KERB_PA_PAC_OPTIONS;
        using PA_PAC_REQUEST = ::KERB_PA_PAC_REQUEST;
        using PA_PK_AS_REP = ::KERB_PA_PK_AS_REP;
        using PA_PK_AS_REP2 = ::KERB_PA_PK_AS_REP2;
        using PA_PK_AS_REP2_kdc_cert = ::KERB_PA_PK_AS_REP2_kdc_cert;
        using PA_PK_AS_REQ = ::KERB_PA_PK_AS_REQ;
        using PA_PK_AS_REQ_trusted_certifiers = ::KERB_PA_PK_AS_REQ_trusted_certifiers;
        using PA_PK_AS_REQ2 = ::KERB_PA_PK_AS_REQ2;
        using PA_PK_AS_REQ2_trusted_certifiers = ::KERB_PA_PK_AS_REQ2_trusted_certifiers;
        using PA_PK_AS_REQ2_user_certs = ::KERB_PA_PK_AS_REQ2_user_certs;
        using PA_S4U_X509_USER = ::PA_S4U_X509_USER;
        using PA_SERV_REFERRAL = ::KERB_PA_SERV_REFERRAL;
        using PAD_RESTRICTION = ::PKERB_AD_RESTRICTION;
        using PAUTHORIZATION_DATA = ::PKERB_AUTHORIZATION_DATA;
        using PAUTHORIZATION_DATA_Seq = ::PKERB_AUTHORIZATION_DATA_Seq;
        using PETYPE_INFO = ::PKERB_ETYPE_INFO;
        using PHOST_ADDRESSES = ::PKERB_HOST_ADDRESSES;
        using PHOST_ADDRESSES_Seq = ::PKERB_HOST_ADDRESSES_Seq;
        using PK_AUTHENTICATOR = ::KERB_PK_AUTHENTICATOR;
        using PKAuthenticator = ::PKAuthenticator;
        using PKCS_SIGNATURE = ::KERB_PKCS_SIGNATURE;
        using PKOcspData = ::PKOcspData;
        using PLAST_REQUEST = ::PKERB_LAST_REQUEST;
        using PLAST_REQUEST_Seq = ::PKERB_LAST_REQUEST_Seq;
        using PPREAUTH_DATA_LIST = ::PKERB_PREAUTH_DATA_LIST;
        using PRINCIPAL_NAME = ::KERB_PRINCIPAL_NAME;
        using PRINCIPAL_NAME_name_string = ::KERB_PRINCIPAL_NAME_name_string;
        using PRIV_MESSAGE = ::KERB_PRIV_MESSAGE;
        using PTICKET_EXTENSIONS = ::PKERB_TICKET_EXTENSIONS;
        using PTICKET_EXTENSIONS_Seq = ::PKERB_TICKET_EXTENSIONS_Seq;
        using REALM_CACHE = ::KERB_REALM_CACHE;
        using REALM_CACHE_ENTRY = ::KERB_REALM_CACHE_ENTRY;
        using REPLY_KEY_PACKAGE = ::KERB_REPLY_KEY_PACKAGE;
        using REPLY_KEY_PACKAGE2 = ::KERB_REPLY_KEY_PACKAGE2;
        using REPLY_KEY_PACKAGE3 = ::KERB_REPLY_KEY_PACKAGE3;
        using S4UUserID = ::S4UUserID;
        using SAFE_BODY = ::KERB_SAFE_BODY;
        using SAFE_MESSAGE = ::KERB_SAFE_MESSAGE;
        using SALTED_ENCRYPTED_TIMESTAMP = ::KERB_SALTED_ENCRYPTED_TIMESTAMP;
        using SIGNATURE = ::KERB_SIGNATURE;
        using SIGNED_AUTH_PACKAGE = ::KERB_SIGNED_AUTH_PACKAGE;
        using SIGNED_KDC_PUBLIC_VALUE = ::KERB_SIGNED_KDC_PUBLIC_VALUE;
        using SIGNED_REPLY_KEY_PACKAGE = ::KERB_SIGNED_REPLY_KEY_PACKAGE;
        using SUBJECT_PUBLIC_KEY_INFO = ::KERB_SUBJECT_PUBLIC_KEY_INFO;
        using TD_DH_PARAMETERS = ::TD_DH_PARAMETERS;
        using TD_INVALID_CERTIFICATES = ::TD_INVALID_CERTIFICATES;
        using TD_TRUSTED_CERTIFIERS = ::TD_TRUSTED_CERTIFIERS;
        using TGT_REPLY = ::KERB_TGT_REPLY;
        using TGT_REQUEST = ::KERB_TGT_REQUEST;
        using TICKET = ::KERB_TICKET;
        using TRANSITED_ENCODING = ::KERB_TRANSITED_ENCODING;
        using TRUSTED_CAS = ::KERB_TRUSTED_CAS;
        using TrustedCA = ::TrustedCA;
        using TYPED_DATA = ::KERB_TYPED_DATA;
        using TYPED_DATA_Element = ::TYPED_DATA_Element;
    }
}
#endif

#endif