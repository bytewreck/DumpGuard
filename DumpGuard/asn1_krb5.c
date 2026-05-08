// Copyright (C) 2024 Evan McBroom
//
// Kerberos protocol asn.1
//
#include "asn1_krb5.h"

ASN1module_t KRB5_Module = NULL;

static int ASN1CALL ASN1Enc_TD_INVALID_CERTIFICATES_Seq(ASN1encoding_t enc, ASN1uint32_t tag, TD_INVALID_CERTIFICATES_Seq *val);
static int ASN1CALL ASN1Enc_TD_TRUSTED_CERTIFIERS_Seq(ASN1encoding_t enc, ASN1uint32_t tag, TD_TRUSTED_CERTIFIERS_Seq *val);
static int ASN1CALL ASN1Enc_KERB_KEY_LIST_REQ_Seq(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KEY_LIST_REQ_Seq *val);
static int ASN1CALL ASN1Enc_EtypeList_Seq(ASN1encoding_t enc, ASN1uint32_t tag, EtypeList_Seq *val);
static int ASN1CALL ASN1Enc_PKERB_AUTHORIZATION_DATA_LIST(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_LIST *val);
static int ASN1CALL ASN1Enc_PKERB_IF_RELEVANT_AUTH_DATA(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_IF_RELEVANT_AUTH_DATA *val);
static int ASN1CALL ASN1Enc_PKERB_TICKET_EXTENSIONS_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_TICKET_EXTENSIONS_Seq *val);
static int ASN1CALL ASN1Enc_PKERB_LAST_REQUEST_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_LAST_REQUEST_Seq *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_BODY_encryption_type(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_encryption_type *val);
static int ASN1CALL ASN1Enc_PKERB_AUTHORIZATION_DATA_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_Seq *val);
static int ASN1CALL ASN1Enc_PKERB_HOST_ADDRESSES_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_HOST_ADDRESSES_Seq *val);
static int ASN1CALL ASN1Enc_KERB_PRINCIPAL_NAME_name_string(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PRINCIPAL_NAME_name_string *val);
static int ASN1CALL ASN1Enc_KERB_REALM_CACHE_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REALM_CACHE_ENTRY *val);
static int ASN1CALL ASN1Enc_KERB_REALM_CACHE(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_REALM_CACHE *val);
static int ASN1CALL ASN1Enc_KERB_PRINCIPAL_NAME(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PRINCIPAL_NAME *val);
static int ASN1CALL ASN1Enc_KERB_HOST_ADDRESS(ASN1encoding_t enc, ASN1uint32_t tag, KERB_HOST_ADDRESS *val);
static int ASN1CALL ASN1Enc_PKERB_HOST_ADDRESSES(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_HOST_ADDRESSES *val);
static int ASN1CALL ASN1Enc_PKERB_AUTHORIZATION_DATA(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_AUTHORIZATION_DATA *val);
static int ASN1CALL ASN1Enc_KERB_PA_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_DATA *val);
static int ASN1CALL ASN1Enc_PKERB_PREAUTH_DATA_LIST(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_PREAUTH_DATA_LIST *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_TIMESTAMP(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_TIMESTAMP *val);
static int ASN1CALL ASN1Enc_KERB_ETYPE_INFO_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ETYPE_INFO_ENTRY *val);
static int ASN1CALL ASN1Enc_PKERB_ETYPE_INFO(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_ETYPE_INFO *val);
static int ASN1CALL ASN1Enc_ETYPE_INFO2_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, ETYPE_INFO2_ENTRY *val);
static int ASN1CALL ASN1Enc_ETYPE_INFO2(ASN1encoding_t enc, ASN1uint32_t tag, PETYPE_INFO2 *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_DATA *val);
static int ASN1CALL ASN1Enc_EncryptedData(ASN1encoding_t enc, ASN1uint32_t tag, EncryptedData *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTION_KEY_ASN1 *val);
static int ASN1CALL ASN1Enc_EncryptionKey(ASN1encoding_t enc, ASN1uint32_t tag, EncryptionKey *val);
static int ASN1CALL ASN1Enc_KERB_CHECKSUM(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CHECKSUM *val);
static int ASN1CALL ASN1Enc_KERB_TICKET(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TICKET *val);
static int ASN1CALL ASN1Enc_KERB_TRANSITED_ENCODING(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TRANSITED_ENCODING *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_BODY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_REQUEST_BODY *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_KDC_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_KDC_REPLY *val);
static int ASN1CALL ASN1Enc_PKERB_LAST_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_LAST_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_AP_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AP_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_AUTHENTICATOR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AUTHENTICATOR *val);
static int ASN1CALL ASN1Enc_KERB_AP_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AP_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_AP_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_AP_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_SAFE_BODY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SAFE_BODY *val);
static int ASN1CALL ASN1Enc_KERB_PRIV_MESSAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PRIV_MESSAGE *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_PRIV(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_PRIV *val);
static int ASN1CALL ASN1Enc_PKERB_TICKET_EXTENSIONS(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_TICKET_EXTENSIONS *val);
static int ASN1CALL ASN1Enc_KERB_CRED(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CRED *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_CRED(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_CRED *val);
static int ASN1CALL ASN1Enc_KERB_CRED_INFO(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CRED_INFO *val);
static int ASN1CALL ASN1Enc_KERB_ERROR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ERROR *val);
static int ASN1CALL ASN1Enc_KERB_ERROR_METHOD_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ERROR_METHOD_DATA *val);
static int ASN1CALL ASN1Enc_KERB_TYPED_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TYPED_DATA *val);
static int ASN1CALL ASN1Enc_TYPED_DATA(ASN1encoding_t enc, ASN1uint32_t tag, PTYPED_DATA *val);
static int ASN1CALL ASN1Enc_EtypeList(ASN1encoding_t enc, ASN1uint32_t tag, PEtypeList *val);
static int ASN1CALL ASN1Enc_KERB_EXT_ERROR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_EXT_ERROR *val);
static int ASN1CALL ASN1Enc_KERB_ERROR_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ERROR_DATA *val);
static int ASN1CALL ASN1Enc_KERB_PA_PAC_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PAC_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_AD_RESTRICTION_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AD_RESTRICTION_ENTRY *val);
static int ASN1CALL ASN1Enc_PKERB_AD_RESTRICTION(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_AD_RESTRICTION *val);
static int ASN1CALL ASN1Enc_KERB_PA_PAC_OPTIONS(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PAC_OPTIONS *val);
static int ASN1CALL ASN1Enc_KERB_KEY_LIST_REQ(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KEY_LIST_REQ *val);
static int ASN1CALL ASN1Enc_KERB_KEY_LIST_REP(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KEY_LIST_REP *val);
static int ASN1CALL ASN1Enc_KERB_CHANGE_PASSWORD_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CHANGE_PASSWORD_DATA *val);
static int ASN1CALL ASN1Enc_KDC_PROXY_MESSAGE(ASN1encoding_t enc, ASN1uint32_t tag, KDC_PROXY_MESSAGE *val);
static int ASN1CALL ASN1Enc_KERB_PA_FOR_USER(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_FOR_USER *val);
static int ASN1CALL ASN1Enc_S4UUserID(ASN1encoding_t enc, ASN1uint32_t tag, S4UUserID *val);
static int ASN1CALL ASN1Enc_KrbFastArmor(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastArmor *val);
static int ASN1CALL ASN1Enc_KrbFastArmoredReq(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastArmoredReq *val);
static int ASN1CALL ASN1Enc_KrbFastReq(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastReq *val);
static int ASN1CALL ASN1Enc_KrbFastArmoredRep(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastArmoredRep *val);
static int ASN1CALL ASN1Enc_KrbFastFinished(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastFinished *val);
static int ASN1CALL ASN1Enc_EncryptedChallenge(ASN1encoding_t enc, ASN1uint32_t tag, EncryptedChallenge *val);
static int ASN1CALL ASN1Enc_KERB_PA_SERV_REFERRAL(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_SERV_REFERRAL *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REQ *val);
static int ASN1CALL ASN1Enc_TrustedCA(ASN1encoding_t enc, ASN1uint32_t tag, TrustedCA *val);
static int ASN1CALL ASN1Enc_KERB_PK_AUTHENTICATOR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PK_AUTHENTICATOR *val);
static int ASN1CALL ASN1Enc_TD_TRUSTED_CERTIFIERS(ASN1encoding_t enc, ASN1uint32_t tag, PTD_TRUSTED_CERTIFIERS *val);
static int ASN1CALL ASN1Enc_TD_INVALID_CERTIFICATES(ASN1encoding_t enc, ASN1uint32_t tag, PTD_INVALID_CERTIFICATES *val);
static int ASN1CALL ASN1Enc_KRB5PrincipalName(ASN1encoding_t enc, ASN1uint32_t tag, KRB5PrincipalName *val);
static int ASN1CALL ASN1Enc_AD_INITIAL_VERIFIED_CAS(ASN1encoding_t enc, ASN1uint32_t tag, PAD_INITIAL_VERIFIED_CAS *val);
static int ASN1CALL ASN1Enc_DHRepInfo(ASN1encoding_t enc, ASN1uint32_t tag, DHRepInfo *val);
static int ASN1CALL ASN1Enc_KDCDHKeyInfo(ASN1encoding_t enc, ASN1uint32_t tag, KDCDHKeyInfo *val);
static int ASN1CALL ASN1Enc_PKOcspData(ASN1encoding_t enc, ASN1uint32_t tag, PPKOcspData *val);
static int ASN1CALL ASN1Enc_PKAuthenticator(ASN1encoding_t enc, ASN1uint32_t tag, PKAuthenticator *val);
static int ASN1CALL ASN1Enc_KERB_ALGORITHM_IDENTIFIER(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ALGORITHM_IDENTIFIER *val);
static int ASN1CALL ASN1Enc_KERB_SUBJECT_PUBLIC_KEY_INFO(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SUBJECT_PUBLIC_KEY_INFO *val);
static int ASN1CALL ASN1Enc_KERB_DH_PARAMTER(ASN1encoding_t enc, ASN1uint32_t tag, KERB_DH_PARAMTER *val);
static int ASN1CALL ASN1Enc_KERB_CERTIFICATE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CERTIFICATE *val);
static int ASN1CALL ASN1Enc_KERB_SIGNATURE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNATURE *val);
static int ASN1CALL ASN1Enc_KERB_SALTED_ENCRYPTED_TIMESTAMP(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SALTED_ENCRYPTED_TIMESTAMP *val);
static int ASN1CALL ASN1Enc_KERB_ENVELOPED_KEY_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENVELOPED_KEY_PACKAGE *val);
static int ASN1CALL ASN1Enc_KERB_PKCS_SIGNATURE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PKCS_SIGNATURE *val);
static int ASN1CALL ASN1Enc_KERB_KDC_DH_KEY_INFO(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_DH_KEY_INFO *val);
static int ASN1CALL ASN1Enc_KERB_REPLY_KEY_PACKAGE2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE2 *val);
static int ASN1CALL ASN1Enc_KERB_REPLY_KEY_PACKAGE3(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE3 *val);
static int ASN1CALL ASN1Enc_KERB_KERBEROS_NAME(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KERBEROS_NAME *val);
static int ASN1CALL ASN1Enc_KERB_REPLY_KEY_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE *val);
static int ASN1CALL ASN1Enc_KERB_TGT_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGT_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_TGT_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGT_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ2_trusted_certifiers(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_trusted_certifiers *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ2_user_certs(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_user_certs *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REP2_kdc_cert(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REP2_kdc_cert *val);
static int ASN1CALL ASN1Enc_KERB_AUTH_PACKAGE2_supportedCMSTypes(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_AUTH_PACKAGE2_supportedCMSTypes *val);
static int ASN1CALL ASN1Enc_KrbFastResponse_padata(ASN1encoding_t enc, ASN1uint32_t tag, PKrbFastResponse_padata *val);
static int ASN1CALL ASN1Enc_KrbFastReq_padata(ASN1encoding_t enc, ASN1uint32_t tag, PKrbFastReq_padata *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_CRED_ticket_info(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_ENCRYPTED_CRED_ticket_info *val);
static int ASN1CALL ASN1Enc_KERB_CRED_tickets(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_CRED_tickets *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REPLY_preauth_data(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REPLY_preauth_data *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_BODY_additional_tickets(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_additional_tickets *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_preauth_data(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REQUEST_preauth_data *val);
static int ASN1CALL ASN1Enc_KERB_KDC_ISSUED_AUTH_DATA_elements(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_ISSUED_AUTH_DATA_elements *val);
static int ASN1CALL ASN1Enc_KERB_KDC_ISSUED_AUTH_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_ISSUED_AUTH_DATA *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_TICKET(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_TICKET *val);
static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_MARSHALLED_REQUEST_BODY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_MARSHALLED_REQUEST_BODY *val);
static int ASN1CALL ASN1Enc_KERB_AS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AS_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_TGS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGS_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_AS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_AS_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_TGS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_TGS_REPLY *val);
static int ASN1CALL ASN1Enc_KERB_SAFE_MESSAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SAFE_MESSAGE *val);
static int ASN1CALL ASN1Enc_PA_S4U_X509_USER(ASN1encoding_t enc, ASN1uint32_t tag, PA_S4U_X509_USER *val);
static int ASN1CALL ASN1Enc_PA_FX_FAST_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, PA_FX_FAST_REQUEST *val);
static int ASN1CALL ASN1Enc_PA_FX_FAST_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, PA_FX_FAST_REPLY *val);
static int ASN1CALL ASN1Enc_KrbFastResponse(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastResponse *val);
static int ASN1CALL ASN1Enc_KERB_AUTH_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AUTH_PACKAGE *val);
static int ASN1CALL ASN1Enc_KERB_AUTH_PACKAGE2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AUTH_PACKAGE2 *val);
static int ASN1CALL ASN1Enc_TD_DH_PARAMETERS(ASN1encoding_t enc, ASN1uint32_t tag, PTD_DH_PARAMETERS *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REP(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REP *val);
static int ASN1CALL ASN1Enc_KERB_SIGNED_REPLY_KEY_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNED_REPLY_KEY_PACKAGE *val);
static int ASN1CALL ASN1Enc_KERB_SIGNED_KDC_PUBLIC_VALUE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNED_KDC_PUBLIC_VALUE *val);
static int ASN1CALL ASN1Enc_KERB_SIGNED_AUTH_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNED_AUTH_PACKAGE *val);
static int ASN1CALL ASN1Enc_KERB_TRUSTED_CAS(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TRUSTED_CAS *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ_trusted_certifiers(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ_trusted_certifiers *val);
static int ASN1CALL ASN1Enc_KERB_AS_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AS_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_TGS_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGS_REQUEST *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REP2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REP2 *val);
static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REQ2 *val);
static int ASN1CALL ASN1Dec_TD_INVALID_CERTIFICATES_Seq(ASN1decoding_t dec, ASN1uint32_t tag, TD_INVALID_CERTIFICATES_Seq *val);
static int ASN1CALL ASN1Dec_TD_TRUSTED_CERTIFIERS_Seq(ASN1decoding_t dec, ASN1uint32_t tag, TD_TRUSTED_CERTIFIERS_Seq *val);
static int ASN1CALL ASN1Dec_KERB_KEY_LIST_REQ_Seq(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KEY_LIST_REQ_Seq *val);
static int ASN1CALL ASN1Dec_EtypeList_Seq(ASN1decoding_t dec, ASN1uint32_t tag, EtypeList_Seq *val);
static int ASN1CALL ASN1Dec_PKERB_AUTHORIZATION_DATA_LIST(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_LIST *val);
static int ASN1CALL ASN1Dec_PKERB_IF_RELEVANT_AUTH_DATA(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_IF_RELEVANT_AUTH_DATA *val);
static int ASN1CALL ASN1Dec_PKERB_TICKET_EXTENSIONS_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_TICKET_EXTENSIONS_Seq *val);
static int ASN1CALL ASN1Dec_PKERB_LAST_REQUEST_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_LAST_REQUEST_Seq *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_BODY_encryption_type(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_encryption_type *val);
static int ASN1CALL ASN1Dec_PKERB_AUTHORIZATION_DATA_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_Seq *val);
static int ASN1CALL ASN1Dec_PKERB_HOST_ADDRESSES_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_HOST_ADDRESSES_Seq *val);
static int ASN1CALL ASN1Dec_KERB_PRINCIPAL_NAME_name_string(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PRINCIPAL_NAME_name_string *val);
static int ASN1CALL ASN1Dec_KERB_REALM_CACHE_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REALM_CACHE_ENTRY *val);
static int ASN1CALL ASN1Dec_KERB_REALM_CACHE(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_REALM_CACHE *val);
static int ASN1CALL ASN1Dec_KERB_PRINCIPAL_NAME(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PRINCIPAL_NAME *val);
static int ASN1CALL ASN1Dec_KERB_HOST_ADDRESS(ASN1decoding_t dec, ASN1uint32_t tag, KERB_HOST_ADDRESS *val);
static int ASN1CALL ASN1Dec_PKERB_HOST_ADDRESSES(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_HOST_ADDRESSES *val);
static int ASN1CALL ASN1Dec_PKERB_AUTHORIZATION_DATA(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_AUTHORIZATION_DATA *val);
static int ASN1CALL ASN1Dec_KERB_PA_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_DATA *val);
static int ASN1CALL ASN1Dec_PKERB_PREAUTH_DATA_LIST(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_PREAUTH_DATA_LIST *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_TIMESTAMP(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_TIMESTAMP *val);
static int ASN1CALL ASN1Dec_KERB_ETYPE_INFO_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ETYPE_INFO_ENTRY *val);
static int ASN1CALL ASN1Dec_PKERB_ETYPE_INFO(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_ETYPE_INFO *val);
static int ASN1CALL ASN1Dec_ETYPE_INFO2_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, ETYPE_INFO2_ENTRY *val);
static int ASN1CALL ASN1Dec_ETYPE_INFO2(ASN1decoding_t dec, ASN1uint32_t tag, PETYPE_INFO2 *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_DATA *val);
static int ASN1CALL ASN1Dec_EncryptedData(ASN1decoding_t dec, ASN1uint32_t tag, EncryptedData *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTION_KEY_ASN1 *val);
static int ASN1CALL ASN1Dec_EncryptionKey(ASN1decoding_t dec, ASN1uint32_t tag, EncryptionKey *val);
static int ASN1CALL ASN1Dec_KERB_CHECKSUM(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CHECKSUM *val);
static int ASN1CALL ASN1Dec_KERB_TICKET(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TICKET *val);
static int ASN1CALL ASN1Dec_KERB_TRANSITED_ENCODING(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TRANSITED_ENCODING *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_BODY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_REQUEST_BODY *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_KDC_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_KDC_REPLY *val);
static int ASN1CALL ASN1Dec_PKERB_LAST_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_LAST_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_AP_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AP_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_AUTHENTICATOR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AUTHENTICATOR *val);
static int ASN1CALL ASN1Dec_KERB_AP_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AP_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_AP_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_AP_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_SAFE_BODY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SAFE_BODY *val);
static int ASN1CALL ASN1Dec_KERB_PRIV_MESSAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PRIV_MESSAGE *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_PRIV(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_PRIV *val);
static int ASN1CALL ASN1Dec_PKERB_TICKET_EXTENSIONS(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_TICKET_EXTENSIONS *val);
static int ASN1CALL ASN1Dec_KERB_CRED(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CRED *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_CRED(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_CRED *val);
static int ASN1CALL ASN1Dec_KERB_CRED_INFO(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CRED_INFO *val);
static int ASN1CALL ASN1Dec_KERB_ERROR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ERROR *val);
static int ASN1CALL ASN1Dec_KERB_ERROR_METHOD_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ERROR_METHOD_DATA *val);
static int ASN1CALL ASN1Dec_KERB_TYPED_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TYPED_DATA *val);
static int ASN1CALL ASN1Dec_TYPED_DATA(ASN1decoding_t dec, ASN1uint32_t tag, PTYPED_DATA *val);
static int ASN1CALL ASN1Dec_EtypeList(ASN1decoding_t dec, ASN1uint32_t tag, PEtypeList *val);
static int ASN1CALL ASN1Dec_KERB_EXT_ERROR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_EXT_ERROR *val);
static int ASN1CALL ASN1Dec_KERB_ERROR_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ERROR_DATA *val);
static int ASN1CALL ASN1Dec_KERB_PA_PAC_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PAC_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_AD_RESTRICTION_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AD_RESTRICTION_ENTRY *val);
static int ASN1CALL ASN1Dec_PKERB_AD_RESTRICTION(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_AD_RESTRICTION *val);
static int ASN1CALL ASN1Dec_KERB_PA_PAC_OPTIONS(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PAC_OPTIONS *val);
static int ASN1CALL ASN1Dec_KERB_KEY_LIST_REQ(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KEY_LIST_REQ *val);
static int ASN1CALL ASN1Dec_KERB_KEY_LIST_REP(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KEY_LIST_REP *val);
static int ASN1CALL ASN1Dec_KERB_CHANGE_PASSWORD_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CHANGE_PASSWORD_DATA *val);
static int ASN1CALL ASN1Dec_KDC_PROXY_MESSAGE(ASN1decoding_t dec, ASN1uint32_t tag, KDC_PROXY_MESSAGE *val);
static int ASN1CALL ASN1Dec_KERB_PA_FOR_USER(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_FOR_USER *val);
static int ASN1CALL ASN1Dec_S4UUserID(ASN1decoding_t dec, ASN1uint32_t tag, S4UUserID *val);
static int ASN1CALL ASN1Dec_KrbFastArmor(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastArmor *val);
static int ASN1CALL ASN1Dec_KrbFastArmoredReq(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastArmoredReq *val);
static int ASN1CALL ASN1Dec_KrbFastReq(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastReq *val);
static int ASN1CALL ASN1Dec_KrbFastArmoredRep(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastArmoredRep *val);
static int ASN1CALL ASN1Dec_KrbFastFinished(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastFinished *val);
static int ASN1CALL ASN1Dec_EncryptedChallenge(ASN1decoding_t dec, ASN1uint32_t tag, EncryptedChallenge *val);
static int ASN1CALL ASN1Dec_KERB_PA_SERV_REFERRAL(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_SERV_REFERRAL *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REQ *val);
static int ASN1CALL ASN1Dec_TrustedCA(ASN1decoding_t dec, ASN1uint32_t tag, TrustedCA *val);
static int ASN1CALL ASN1Dec_KERB_PK_AUTHENTICATOR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PK_AUTHENTICATOR *val);
static int ASN1CALL ASN1Dec_TD_TRUSTED_CERTIFIERS(ASN1decoding_t dec, ASN1uint32_t tag, PTD_TRUSTED_CERTIFIERS *val);
static int ASN1CALL ASN1Dec_TD_INVALID_CERTIFICATES(ASN1decoding_t dec, ASN1uint32_t tag, PTD_INVALID_CERTIFICATES *val);
static int ASN1CALL ASN1Dec_KRB5PrincipalName(ASN1decoding_t dec, ASN1uint32_t tag, KRB5PrincipalName *val);
static int ASN1CALL ASN1Dec_AD_INITIAL_VERIFIED_CAS(ASN1decoding_t dec, ASN1uint32_t tag, PAD_INITIAL_VERIFIED_CAS *val);
static int ASN1CALL ASN1Dec_DHRepInfo(ASN1decoding_t dec, ASN1uint32_t tag, DHRepInfo *val);
static int ASN1CALL ASN1Dec_KDCDHKeyInfo(ASN1decoding_t dec, ASN1uint32_t tag, KDCDHKeyInfo *val);
static int ASN1CALL ASN1Dec_PKOcspData(ASN1decoding_t dec, ASN1uint32_t tag, PPKOcspData *val);
static int ASN1CALL ASN1Dec_PKAuthenticator(ASN1decoding_t dec, ASN1uint32_t tag, PKAuthenticator *val);
static int ASN1CALL ASN1Dec_KERB_ALGORITHM_IDENTIFIER(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ALGORITHM_IDENTIFIER *val);
static int ASN1CALL ASN1Dec_KERB_SUBJECT_PUBLIC_KEY_INFO(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SUBJECT_PUBLIC_KEY_INFO *val);
static int ASN1CALL ASN1Dec_KERB_DH_PARAMTER(ASN1decoding_t dec, ASN1uint32_t tag, KERB_DH_PARAMTER *val);
static int ASN1CALL ASN1Dec_KERB_CERTIFICATE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CERTIFICATE *val);
static int ASN1CALL ASN1Dec_KERB_SIGNATURE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNATURE *val);
static int ASN1CALL ASN1Dec_KERB_SALTED_ENCRYPTED_TIMESTAMP(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SALTED_ENCRYPTED_TIMESTAMP *val);
static int ASN1CALL ASN1Dec_KERB_ENVELOPED_KEY_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENVELOPED_KEY_PACKAGE *val);
static int ASN1CALL ASN1Dec_KERB_PKCS_SIGNATURE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PKCS_SIGNATURE *val);
static int ASN1CALL ASN1Dec_KERB_KDC_DH_KEY_INFO(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_DH_KEY_INFO *val);
static int ASN1CALL ASN1Dec_KERB_REPLY_KEY_PACKAGE2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE2 *val);
static int ASN1CALL ASN1Dec_KERB_REPLY_KEY_PACKAGE3(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE3 *val);
static int ASN1CALL ASN1Dec_KERB_KERBEROS_NAME(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KERBEROS_NAME *val);
static int ASN1CALL ASN1Dec_KERB_REPLY_KEY_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE *val);
static int ASN1CALL ASN1Dec_KERB_TGT_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGT_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_TGT_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGT_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ2_trusted_certifiers(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_trusted_certifiers *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ2_user_certs(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_user_certs *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REP2_kdc_cert(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REP2_kdc_cert *val);
static int ASN1CALL ASN1Dec_KERB_AUTH_PACKAGE2_supportedCMSTypes(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_AUTH_PACKAGE2_supportedCMSTypes *val);
static int ASN1CALL ASN1Dec_KrbFastResponse_padata(ASN1decoding_t dec, ASN1uint32_t tag, PKrbFastResponse_padata *val);
static int ASN1CALL ASN1Dec_KrbFastReq_padata(ASN1decoding_t dec, ASN1uint32_t tag, PKrbFastReq_padata *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_CRED_ticket_info(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_ENCRYPTED_CRED_ticket_info *val);
static int ASN1CALL ASN1Dec_KERB_CRED_tickets(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_CRED_tickets *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REPLY_preauth_data(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REPLY_preauth_data *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_BODY_additional_tickets(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_additional_tickets *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_preauth_data(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REQUEST_preauth_data *val);
static int ASN1CALL ASN1Dec_KERB_KDC_ISSUED_AUTH_DATA_elements(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_ISSUED_AUTH_DATA_elements *val);
static int ASN1CALL ASN1Dec_KERB_KDC_ISSUED_AUTH_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_ISSUED_AUTH_DATA *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_TICKET(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_TICKET *val);
static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_MARSHALLED_REQUEST_BODY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_MARSHALLED_REQUEST_BODY *val);
static int ASN1CALL ASN1Dec_KERB_AS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AS_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_TGS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGS_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_AS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_AS_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_TGS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_TGS_REPLY *val);
static int ASN1CALL ASN1Dec_KERB_SAFE_MESSAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SAFE_MESSAGE *val);
static int ASN1CALL ASN1Dec_PA_S4U_X509_USER(ASN1decoding_t dec, ASN1uint32_t tag, PA_S4U_X509_USER *val);
static int ASN1CALL ASN1Dec_PA_FX_FAST_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, PA_FX_FAST_REQUEST *val);
static int ASN1CALL ASN1Dec_PA_FX_FAST_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, PA_FX_FAST_REPLY *val);
static int ASN1CALL ASN1Dec_KrbFastResponse(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastResponse *val);
static int ASN1CALL ASN1Dec_KERB_AUTH_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AUTH_PACKAGE *val);
static int ASN1CALL ASN1Dec_KERB_AUTH_PACKAGE2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AUTH_PACKAGE2 *val);
static int ASN1CALL ASN1Dec_TD_DH_PARAMETERS(ASN1decoding_t dec, ASN1uint32_t tag, PTD_DH_PARAMETERS *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REP(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REP *val);
static int ASN1CALL ASN1Dec_KERB_SIGNED_REPLY_KEY_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNED_REPLY_KEY_PACKAGE *val);
static int ASN1CALL ASN1Dec_KERB_SIGNED_KDC_PUBLIC_VALUE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNED_KDC_PUBLIC_VALUE *val);
static int ASN1CALL ASN1Dec_KERB_SIGNED_AUTH_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNED_AUTH_PACKAGE *val);
static int ASN1CALL ASN1Dec_KERB_TRUSTED_CAS(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TRUSTED_CAS *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ_trusted_certifiers(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ_trusted_certifiers *val);
static int ASN1CALL ASN1Dec_KERB_AS_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AS_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_TGS_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGS_REQUEST *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REP2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REP2 *val);
static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REQ2 *val);
static void ASN1CALL ASN1Free_TD_INVALID_CERTIFICATES_Seq(TD_INVALID_CERTIFICATES_Seq *val);
static void ASN1CALL ASN1Free_TD_TRUSTED_CERTIFIERS_Seq(TD_TRUSTED_CERTIFIERS_Seq *val);
static void ASN1CALL ASN1Free_PKERB_AUTHORIZATION_DATA_LIST(PKERB_AUTHORIZATION_DATA_LIST *val);
static void ASN1CALL ASN1Free_PKERB_IF_RELEVANT_AUTH_DATA(PKERB_IF_RELEVANT_AUTH_DATA *val);
static void ASN1CALL ASN1Free_PKERB_TICKET_EXTENSIONS_Seq(PKERB_TICKET_EXTENSIONS_Seq *val);
static void ASN1CALL ASN1Free_PKERB_LAST_REQUEST_Seq(PKERB_LAST_REQUEST_Seq *val);
static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_BODY_encryption_type(PKERB_KDC_REQUEST_BODY_encryption_type *val);
static void ASN1CALL ASN1Free_PKERB_AUTHORIZATION_DATA_Seq(PKERB_AUTHORIZATION_DATA_Seq *val);
static void ASN1CALL ASN1Free_PKERB_HOST_ADDRESSES_Seq(PKERB_HOST_ADDRESSES_Seq *val);
static void ASN1CALL ASN1Free_KERB_PRINCIPAL_NAME_name_string(PKERB_PRINCIPAL_NAME_name_string *val);
static void ASN1CALL ASN1Free_KERB_REALM_CACHE_ENTRY(KERB_REALM_CACHE_ENTRY *val);
static void ASN1CALL ASN1Free_KERB_REALM_CACHE(PKERB_REALM_CACHE *val);
static void ASN1CALL ASN1Free_KERB_PRINCIPAL_NAME(KERB_PRINCIPAL_NAME *val);
static void ASN1CALL ASN1Free_KERB_HOST_ADDRESS(KERB_HOST_ADDRESS *val);
static void ASN1CALL ASN1Free_PKERB_HOST_ADDRESSES(PPKERB_HOST_ADDRESSES *val);
static void ASN1CALL ASN1Free_PKERB_AUTHORIZATION_DATA(PPKERB_AUTHORIZATION_DATA *val);
static void ASN1CALL ASN1Free_KERB_PA_DATA(KERB_PA_DATA *val);
static void ASN1CALL ASN1Free_PKERB_PREAUTH_DATA_LIST(PPKERB_PREAUTH_DATA_LIST *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_TIMESTAMP(KERB_ENCRYPTED_TIMESTAMP *val);
static void ASN1CALL ASN1Free_KERB_ETYPE_INFO_ENTRY(KERB_ETYPE_INFO_ENTRY *val);
static void ASN1CALL ASN1Free_PKERB_ETYPE_INFO(PPKERB_ETYPE_INFO *val);
static void ASN1CALL ASN1Free_ETYPE_INFO2_ENTRY(ETYPE_INFO2_ENTRY *val);
static void ASN1CALL ASN1Free_ETYPE_INFO2(PETYPE_INFO2 *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_DATA(KERB_ENCRYPTED_DATA *val);
static void ASN1CALL ASN1Free_EncryptedData(EncryptedData *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTION_KEY_ASN1(KERB_ENCRYPTION_KEY_ASN1 *val);
static void ASN1CALL ASN1Free_EncryptionKey(EncryptionKey *val);
static void ASN1CALL ASN1Free_KERB_CHECKSUM(KERB_CHECKSUM *val);
static void ASN1CALL ASN1Free_KERB_TICKET(KERB_TICKET *val);
static void ASN1CALL ASN1Free_KERB_TRANSITED_ENCODING(KERB_TRANSITED_ENCODING *val);
static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_BODY(KERB_KDC_REQUEST_BODY *val);
static void ASN1CALL ASN1Free_KERB_KDC_REPLY(KERB_KDC_REPLY *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_KDC_REPLY(KERB_ENCRYPTED_KDC_REPLY *val);
static void ASN1CALL ASN1Free_PKERB_LAST_REQUEST(PPKERB_LAST_REQUEST *val);
static void ASN1CALL ASN1Free_KERB_AP_REQUEST(KERB_AP_REQUEST *val);
static void ASN1CALL ASN1Free_KERB_AUTHENTICATOR(KERB_AUTHENTICATOR *val);
static void ASN1CALL ASN1Free_KERB_AP_REPLY(KERB_AP_REPLY *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_AP_REPLY(KERB_ENCRYPTED_AP_REPLY *val);
static void ASN1CALL ASN1Free_KERB_SAFE_BODY(KERB_SAFE_BODY *val);
static void ASN1CALL ASN1Free_KERB_PRIV_MESSAGE(KERB_PRIV_MESSAGE *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_PRIV(KERB_ENCRYPTED_PRIV *val);
static void ASN1CALL ASN1Free_PKERB_TICKET_EXTENSIONS(PPKERB_TICKET_EXTENSIONS *val);
static void ASN1CALL ASN1Free_KERB_CRED(KERB_CRED *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_CRED(KERB_ENCRYPTED_CRED *val);
static void ASN1CALL ASN1Free_KERB_CRED_INFO(KERB_CRED_INFO *val);
static void ASN1CALL ASN1Free_KERB_ERROR(KERB_ERROR *val);
static void ASN1CALL ASN1Free_KERB_ERROR_METHOD_DATA(KERB_ERROR_METHOD_DATA *val);
static void ASN1CALL ASN1Free_KERB_TYPED_DATA(KERB_TYPED_DATA *val);
static void ASN1CALL ASN1Free_TYPED_DATA(PTYPED_DATA *val);
static void ASN1CALL ASN1Free_EtypeList(PEtypeList *val);
static void ASN1CALL ASN1Free_KERB_ERROR_DATA(KERB_ERROR_DATA *val);
static void ASN1CALL ASN1Free_KERB_AD_RESTRICTION_ENTRY(KERB_AD_RESTRICTION_ENTRY *val);
static void ASN1CALL ASN1Free_PKERB_AD_RESTRICTION(PPKERB_AD_RESTRICTION *val);
static void ASN1CALL ASN1Free_KERB_PA_PAC_OPTIONS(KERB_PA_PAC_OPTIONS *val);
static void ASN1CALL ASN1Free_KERB_KEY_LIST_REQ(PKERB_KEY_LIST_REQ *val);
static void ASN1CALL ASN1Free_KERB_KEY_LIST_REP(PKERB_KEY_LIST_REP *val);
static void ASN1CALL ASN1Free_KERB_CHANGE_PASSWORD_DATA(KERB_CHANGE_PASSWORD_DATA *val);
static void ASN1CALL ASN1Free_KDC_PROXY_MESSAGE(KDC_PROXY_MESSAGE *val);
static void ASN1CALL ASN1Free_KERB_PA_FOR_USER(KERB_PA_FOR_USER *val);
static void ASN1CALL ASN1Free_S4UUserID(S4UUserID *val);
static void ASN1CALL ASN1Free_KrbFastArmor(KrbFastArmor *val);
static void ASN1CALL ASN1Free_KrbFastArmoredReq(KrbFastArmoredReq *val);
static void ASN1CALL ASN1Free_KrbFastReq(KrbFastReq *val);
static void ASN1CALL ASN1Free_KrbFastArmoredRep(KrbFastArmoredRep *val);
static void ASN1CALL ASN1Free_KrbFastFinished(KrbFastFinished *val);
static void ASN1CALL ASN1Free_EncryptedChallenge(EncryptedChallenge *val);
static void ASN1CALL ASN1Free_KERB_PA_SERV_REFERRAL(KERB_PA_SERV_REFERRAL *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ(KERB_PA_PK_AS_REQ *val);
static void ASN1CALL ASN1Free_TrustedCA(TrustedCA *val);
static void ASN1CALL ASN1Free_KERB_PK_AUTHENTICATOR(KERB_PK_AUTHENTICATOR *val);
static void ASN1CALL ASN1Free_TD_TRUSTED_CERTIFIERS(PTD_TRUSTED_CERTIFIERS *val);
static void ASN1CALL ASN1Free_TD_INVALID_CERTIFICATES(PTD_INVALID_CERTIFICATES *val);
static void ASN1CALL ASN1Free_KRB5PrincipalName(KRB5PrincipalName *val);
static void ASN1CALL ASN1Free_AD_INITIAL_VERIFIED_CAS(PAD_INITIAL_VERIFIED_CAS *val);
static void ASN1CALL ASN1Free_DHRepInfo(DHRepInfo *val);
static void ASN1CALL ASN1Free_KDCDHKeyInfo(KDCDHKeyInfo *val);
static void ASN1CALL ASN1Free_PKOcspData(PPKOcspData *val);
static void ASN1CALL ASN1Free_PKAuthenticator(PKAuthenticator *val);
static void ASN1CALL ASN1Free_KERB_ALGORITHM_IDENTIFIER(KERB_ALGORITHM_IDENTIFIER *val);
static void ASN1CALL ASN1Free_KERB_SUBJECT_PUBLIC_KEY_INFO(KERB_SUBJECT_PUBLIC_KEY_INFO *val);
static void ASN1CALL ASN1Free_KERB_CERTIFICATE(KERB_CERTIFICATE *val);
static void ASN1CALL ASN1Free_KERB_SIGNATURE(KERB_SIGNATURE *val);
static void ASN1CALL ASN1Free_KERB_SALTED_ENCRYPTED_TIMESTAMP(KERB_SALTED_ENCRYPTED_TIMESTAMP *val);
static void ASN1CALL ASN1Free_KERB_ENVELOPED_KEY_PACKAGE(KERB_ENVELOPED_KEY_PACKAGE *val);
static void ASN1CALL ASN1Free_KERB_PKCS_SIGNATURE(KERB_PKCS_SIGNATURE *val);
static void ASN1CALL ASN1Free_KERB_KDC_DH_KEY_INFO(KERB_KDC_DH_KEY_INFO *val);
static void ASN1CALL ASN1Free_KERB_REPLY_KEY_PACKAGE2(KERB_REPLY_KEY_PACKAGE2 *val);
static void ASN1CALL ASN1Free_KERB_REPLY_KEY_PACKAGE3(KERB_REPLY_KEY_PACKAGE3 *val);
static void ASN1CALL ASN1Free_KERB_KERBEROS_NAME(KERB_KERBEROS_NAME *val);
static void ASN1CALL ASN1Free_KERB_REPLY_KEY_PACKAGE(KERB_REPLY_KEY_PACKAGE *val);
static void ASN1CALL ASN1Free_KERB_TGT_REQUEST(KERB_TGT_REQUEST *val);
static void ASN1CALL ASN1Free_KERB_TGT_REPLY(KERB_TGT_REPLY *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ2_trusted_certifiers(PKERB_PA_PK_AS_REQ2_trusted_certifiers *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ2_user_certs(PKERB_PA_PK_AS_REQ2_user_certs *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REP2_kdc_cert(PKERB_PA_PK_AS_REP2_kdc_cert *val);
static void ASN1CALL ASN1Free_KERB_AUTH_PACKAGE2_supportedCMSTypes(PKERB_AUTH_PACKAGE2_supportedCMSTypes *val);
static void ASN1CALL ASN1Free_KrbFastResponse_padata(PKrbFastResponse_padata *val);
static void ASN1CALL ASN1Free_KrbFastReq_padata(PKrbFastReq_padata *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_CRED_ticket_info(PKERB_ENCRYPTED_CRED_ticket_info *val);
static void ASN1CALL ASN1Free_KERB_CRED_tickets(PKERB_CRED_tickets *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *val);
static void ASN1CALL ASN1Free_KERB_KDC_REPLY_preauth_data(PKERB_KDC_REPLY_preauth_data *val);
static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_BODY_additional_tickets(PKERB_KDC_REQUEST_BODY_additional_tickets *val);
static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_preauth_data(PKERB_KDC_REQUEST_preauth_data *val);
static void ASN1CALL ASN1Free_KERB_KDC_ISSUED_AUTH_DATA_elements(PKERB_KDC_ISSUED_AUTH_DATA_elements *val);
static void ASN1CALL ASN1Free_KERB_KDC_ISSUED_AUTH_DATA(KERB_KDC_ISSUED_AUTH_DATA *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_TICKET(KERB_ENCRYPTED_TICKET *val);
static void ASN1CALL ASN1Free_KERB_KDC_REQUEST(KERB_KDC_REQUEST *val);
static void ASN1CALL ASN1Free_KERB_MARSHALLED_REQUEST_BODY(KERB_MARSHALLED_REQUEST_BODY *val);
static void ASN1CALL ASN1Free_KERB_AS_REPLY(KERB_AS_REPLY *val);
static void ASN1CALL ASN1Free_KERB_TGS_REPLY(KERB_TGS_REPLY *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_AS_REPLY(KERB_ENCRYPTED_AS_REPLY *val);
static void ASN1CALL ASN1Free_KERB_ENCRYPTED_TGS_REPLY(KERB_ENCRYPTED_TGS_REPLY *val);
static void ASN1CALL ASN1Free_KERB_SAFE_MESSAGE(KERB_SAFE_MESSAGE *val);
static void ASN1CALL ASN1Free_PA_S4U_X509_USER(PA_S4U_X509_USER *val);
static void ASN1CALL ASN1Free_PA_FX_FAST_REQUEST(PA_FX_FAST_REQUEST *val);
static void ASN1CALL ASN1Free_PA_FX_FAST_REPLY(PA_FX_FAST_REPLY *val);
static void ASN1CALL ASN1Free_KrbFastResponse(KrbFastResponse *val);
static void ASN1CALL ASN1Free_KERB_AUTH_PACKAGE(KERB_AUTH_PACKAGE *val);
static void ASN1CALL ASN1Free_KERB_AUTH_PACKAGE2(KERB_AUTH_PACKAGE2 *val);
static void ASN1CALL ASN1Free_TD_DH_PARAMETERS(PTD_DH_PARAMETERS *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REP(KERB_PA_PK_AS_REP *val);
static void ASN1CALL ASN1Free_KERB_SIGNED_REPLY_KEY_PACKAGE(KERB_SIGNED_REPLY_KEY_PACKAGE *val);
static void ASN1CALL ASN1Free_KERB_SIGNED_KDC_PUBLIC_VALUE(KERB_SIGNED_KDC_PUBLIC_VALUE *val);
static void ASN1CALL ASN1Free_KERB_SIGNED_AUTH_PACKAGE(KERB_SIGNED_AUTH_PACKAGE *val);
static void ASN1CALL ASN1Free_KERB_TRUSTED_CAS(KERB_TRUSTED_CAS *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ_trusted_certifiers(PKERB_PA_PK_AS_REQ_trusted_certifiers *val);
static void ASN1CALL ASN1Free_KERB_AS_REQUEST(KERB_AS_REQUEST *val);
static void ASN1CALL ASN1Free_KERB_TGS_REQUEST(KERB_TGS_REQUEST *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REP2(KERB_PA_PK_AS_REP2 *val);
static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ2(KERB_PA_PK_AS_REQ2 *val);

typedef ASN1BerEncFun_t ASN1EncFun_t;
static const ASN1EncFun_t encfntab[] = {
    (ASN1EncFun_t) ASN1Enc_TD_INVALID_CERTIFICATES_Seq,
    (ASN1EncFun_t) ASN1Enc_TD_TRUSTED_CERTIFIERS_Seq,
    (ASN1EncFun_t) ASN1Enc_KERB_KEY_LIST_REQ_Seq,
    (ASN1EncFun_t) ASN1Enc_EtypeList_Seq,
    (ASN1EncFun_t) ASN1Enc_PKERB_AUTHORIZATION_DATA_LIST,
    (ASN1EncFun_t) ASN1Enc_PKERB_IF_RELEVANT_AUTH_DATA,
    (ASN1EncFun_t) ASN1Enc_PKERB_TICKET_EXTENSIONS_Seq,
    (ASN1EncFun_t) ASN1Enc_PKERB_LAST_REQUEST_Seq,
    (ASN1EncFun_t) ASN1Enc_PKERB_AUTHORIZATION_DATA_Seq,
    (ASN1EncFun_t) ASN1Enc_PKERB_HOST_ADDRESSES_Seq,
    (ASN1EncFun_t) ASN1Enc_KERB_REALM_CACHE,
    (ASN1EncFun_t) ASN1Enc_KERB_PRINCIPAL_NAME,
    (ASN1EncFun_t) ASN1Enc_PKERB_PREAUTH_DATA_LIST,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_TIMESTAMP,
    (ASN1EncFun_t) ASN1Enc_PKERB_ETYPE_INFO,
    (ASN1EncFun_t) ASN1Enc_ETYPE_INFO2,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_DATA,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTION_KEY_ASN1,
    (ASN1EncFun_t) ASN1Enc_KERB_CHECKSUM,
    (ASN1EncFun_t) ASN1Enc_KERB_TICKET,
    (ASN1EncFun_t) ASN1Enc_KERB_KDC_REQUEST_BODY,
    (ASN1EncFun_t) ASN1Enc_KERB_KDC_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_KDC_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_AP_REQUEST,
    (ASN1EncFun_t) ASN1Enc_KERB_AUTHENTICATOR,
    (ASN1EncFun_t) ASN1Enc_KERB_AP_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_AP_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_SAFE_BODY,
    (ASN1EncFun_t) ASN1Enc_KERB_PRIV_MESSAGE,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_PRIV,
    (ASN1EncFun_t) ASN1Enc_KERB_CRED,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_CRED,
    (ASN1EncFun_t) ASN1Enc_KERB_CRED_INFO,
    (ASN1EncFun_t) ASN1Enc_KERB_ERROR,
    (ASN1EncFun_t) ASN1Enc_KERB_ERROR_METHOD_DATA,
    (ASN1EncFun_t) ASN1Enc_TYPED_DATA,
    (ASN1EncFun_t) ASN1Enc_EtypeList,
    (ASN1EncFun_t) ASN1Enc_KERB_EXT_ERROR,
    (ASN1EncFun_t) ASN1Enc_KERB_ERROR_DATA,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_PAC_REQUEST,
    (ASN1EncFun_t) ASN1Enc_KERB_AD_RESTRICTION_ENTRY,
    (ASN1EncFun_t) ASN1Enc_PKERB_AD_RESTRICTION,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_PAC_OPTIONS,
    (ASN1EncFun_t) ASN1Enc_KERB_KEY_LIST_REQ,
    (ASN1EncFun_t) ASN1Enc_KERB_KEY_LIST_REP,
    (ASN1EncFun_t) ASN1Enc_KERB_CHANGE_PASSWORD_DATA,
    (ASN1EncFun_t) ASN1Enc_KDC_PROXY_MESSAGE,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_FOR_USER,
    (ASN1EncFun_t) ASN1Enc_S4UUserID,
    (ASN1EncFun_t) ASN1Enc_KrbFastArmoredReq,
    (ASN1EncFun_t) ASN1Enc_KrbFastReq,
    (ASN1EncFun_t) ASN1Enc_KrbFastFinished,
    (ASN1EncFun_t) ASN1Enc_EncryptedChallenge,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_SERV_REFERRAL,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_PK_AS_REQ,
    (ASN1EncFun_t) ASN1Enc_TrustedCA,
    (ASN1EncFun_t) ASN1Enc_TD_TRUSTED_CERTIFIERS,
    (ASN1EncFun_t) ASN1Enc_TD_INVALID_CERTIFICATES,
    (ASN1EncFun_t) ASN1Enc_KRB5PrincipalName,
    (ASN1EncFun_t) ASN1Enc_AD_INITIAL_VERIFIED_CAS,
    (ASN1EncFun_t) ASN1Enc_DHRepInfo,
    (ASN1EncFun_t) ASN1Enc_KDCDHKeyInfo,
    (ASN1EncFun_t) ASN1Enc_PKOcspData,
    (ASN1EncFun_t) ASN1Enc_PKAuthenticator,
    (ASN1EncFun_t) ASN1Enc_KERB_ALGORITHM_IDENTIFIER,
    (ASN1EncFun_t) ASN1Enc_KERB_SUBJECT_PUBLIC_KEY_INFO,
    (ASN1EncFun_t) ASN1Enc_KERB_DH_PARAMTER,
    (ASN1EncFun_t) ASN1Enc_KERB_SIGNATURE,
    (ASN1EncFun_t) ASN1Enc_KERB_SALTED_ENCRYPTED_TIMESTAMP,
    (ASN1EncFun_t) ASN1Enc_KERB_ENVELOPED_KEY_PACKAGE,
    (ASN1EncFun_t) ASN1Enc_KERB_PKCS_SIGNATURE,
    (ASN1EncFun_t) ASN1Enc_KERB_KDC_DH_KEY_INFO,
    (ASN1EncFun_t) ASN1Enc_KERB_REPLY_KEY_PACKAGE2,
    (ASN1EncFun_t) ASN1Enc_KERB_REPLY_KEY_PACKAGE3,
    (ASN1EncFun_t) ASN1Enc_KERB_KERBEROS_NAME,
    (ASN1EncFun_t) ASN1Enc_KERB_REPLY_KEY_PACKAGE,
    (ASN1EncFun_t) ASN1Enc_KERB_TGT_REQUEST,
    (ASN1EncFun_t) ASN1Enc_KERB_TGT_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_KDC_ISSUED_AUTH_DATA,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_TICKET,
    (ASN1EncFun_t) ASN1Enc_KERB_KDC_REQUEST,
    (ASN1EncFun_t) ASN1Enc_KERB_MARSHALLED_REQUEST_BODY,
    (ASN1EncFun_t) ASN1Enc_KERB_AS_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_TGS_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_AS_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_ENCRYPTED_TGS_REPLY,
    (ASN1EncFun_t) ASN1Enc_KERB_SAFE_MESSAGE,
    (ASN1EncFun_t) ASN1Enc_PA_S4U_X509_USER,
    (ASN1EncFun_t) ASN1Enc_PA_FX_FAST_REQUEST,
    (ASN1EncFun_t) ASN1Enc_PA_FX_FAST_REPLY,
    (ASN1EncFun_t) ASN1Enc_KrbFastResponse,
    (ASN1EncFun_t) ASN1Enc_KERB_AUTH_PACKAGE,
    (ASN1EncFun_t) ASN1Enc_KERB_AUTH_PACKAGE2,
    (ASN1EncFun_t) ASN1Enc_TD_DH_PARAMETERS,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_PK_AS_REP,
    (ASN1EncFun_t) ASN1Enc_KERB_SIGNED_REPLY_KEY_PACKAGE,
    (ASN1EncFun_t) ASN1Enc_KERB_TRUSTED_CAS,
    (ASN1EncFun_t) ASN1Enc_KERB_AS_REQUEST,
    (ASN1EncFun_t) ASN1Enc_KERB_TGS_REQUEST,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_PK_AS_REP2,
    (ASN1EncFun_t) ASN1Enc_KERB_PA_PK_AS_REQ2,
};
typedef ASN1BerDecFun_t ASN1DecFun_t;
static const ASN1DecFun_t decfntab[] = {
    (ASN1DecFun_t) ASN1Dec_TD_INVALID_CERTIFICATES_Seq,
    (ASN1DecFun_t) ASN1Dec_TD_TRUSTED_CERTIFIERS_Seq,
    (ASN1DecFun_t) ASN1Dec_KERB_KEY_LIST_REQ_Seq,
    (ASN1DecFun_t) ASN1Dec_EtypeList_Seq,
    (ASN1DecFun_t) ASN1Dec_PKERB_AUTHORIZATION_DATA_LIST,
    (ASN1DecFun_t) ASN1Dec_PKERB_IF_RELEVANT_AUTH_DATA,
    (ASN1DecFun_t) ASN1Dec_PKERB_TICKET_EXTENSIONS_Seq,
    (ASN1DecFun_t) ASN1Dec_PKERB_LAST_REQUEST_Seq,
    (ASN1DecFun_t) ASN1Dec_PKERB_AUTHORIZATION_DATA_Seq,
    (ASN1DecFun_t) ASN1Dec_PKERB_HOST_ADDRESSES_Seq,
    (ASN1DecFun_t) ASN1Dec_KERB_REALM_CACHE,
    (ASN1DecFun_t) ASN1Dec_KERB_PRINCIPAL_NAME,
    (ASN1DecFun_t) ASN1Dec_PKERB_PREAUTH_DATA_LIST,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_TIMESTAMP,
    (ASN1DecFun_t) ASN1Dec_PKERB_ETYPE_INFO,
    (ASN1DecFun_t) ASN1Dec_ETYPE_INFO2,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_DATA,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTION_KEY_ASN1,
    (ASN1DecFun_t) ASN1Dec_KERB_CHECKSUM,
    (ASN1DecFun_t) ASN1Dec_KERB_TICKET,
    (ASN1DecFun_t) ASN1Dec_KERB_KDC_REQUEST_BODY,
    (ASN1DecFun_t) ASN1Dec_KERB_KDC_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_KDC_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_AP_REQUEST,
    (ASN1DecFun_t) ASN1Dec_KERB_AUTHENTICATOR,
    (ASN1DecFun_t) ASN1Dec_KERB_AP_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_AP_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_SAFE_BODY,
    (ASN1DecFun_t) ASN1Dec_KERB_PRIV_MESSAGE,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_PRIV,
    (ASN1DecFun_t) ASN1Dec_KERB_CRED,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_CRED,
    (ASN1DecFun_t) ASN1Dec_KERB_CRED_INFO,
    (ASN1DecFun_t) ASN1Dec_KERB_ERROR,
    (ASN1DecFun_t) ASN1Dec_KERB_ERROR_METHOD_DATA,
    (ASN1DecFun_t) ASN1Dec_TYPED_DATA,
    (ASN1DecFun_t) ASN1Dec_EtypeList,
    (ASN1DecFun_t) ASN1Dec_KERB_EXT_ERROR,
    (ASN1DecFun_t) ASN1Dec_KERB_ERROR_DATA,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_PAC_REQUEST,
    (ASN1DecFun_t) ASN1Dec_KERB_AD_RESTRICTION_ENTRY,
    (ASN1DecFun_t) ASN1Dec_PKERB_AD_RESTRICTION,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_PAC_OPTIONS,
    (ASN1DecFun_t) ASN1Dec_KERB_KEY_LIST_REQ,
    (ASN1DecFun_t) ASN1Dec_KERB_KEY_LIST_REP,
    (ASN1DecFun_t) ASN1Dec_KERB_CHANGE_PASSWORD_DATA,
    (ASN1DecFun_t) ASN1Dec_KDC_PROXY_MESSAGE,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_FOR_USER,
    (ASN1DecFun_t) ASN1Dec_S4UUserID,
    (ASN1DecFun_t) ASN1Dec_KrbFastArmoredReq,
    (ASN1DecFun_t) ASN1Dec_KrbFastReq,
    (ASN1DecFun_t) ASN1Dec_KrbFastFinished,
    (ASN1DecFun_t) ASN1Dec_EncryptedChallenge,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_SERV_REFERRAL,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_PK_AS_REQ,
    (ASN1DecFun_t) ASN1Dec_TrustedCA,
    (ASN1DecFun_t) ASN1Dec_TD_TRUSTED_CERTIFIERS,
    (ASN1DecFun_t) ASN1Dec_TD_INVALID_CERTIFICATES,
    (ASN1DecFun_t) ASN1Dec_KRB5PrincipalName,
    (ASN1DecFun_t) ASN1Dec_AD_INITIAL_VERIFIED_CAS,
    (ASN1DecFun_t) ASN1Dec_DHRepInfo,
    (ASN1DecFun_t) ASN1Dec_KDCDHKeyInfo,
    (ASN1DecFun_t) ASN1Dec_PKOcspData,
    (ASN1DecFun_t) ASN1Dec_PKAuthenticator,
    (ASN1DecFun_t) ASN1Dec_KERB_ALGORITHM_IDENTIFIER,
    (ASN1DecFun_t) ASN1Dec_KERB_SUBJECT_PUBLIC_KEY_INFO,
    (ASN1DecFun_t) ASN1Dec_KERB_DH_PARAMTER,
    (ASN1DecFun_t) ASN1Dec_KERB_SIGNATURE,
    (ASN1DecFun_t) ASN1Dec_KERB_SALTED_ENCRYPTED_TIMESTAMP,
    (ASN1DecFun_t) ASN1Dec_KERB_ENVELOPED_KEY_PACKAGE,
    (ASN1DecFun_t) ASN1Dec_KERB_PKCS_SIGNATURE,
    (ASN1DecFun_t) ASN1Dec_KERB_KDC_DH_KEY_INFO,
    (ASN1DecFun_t) ASN1Dec_KERB_REPLY_KEY_PACKAGE2,
    (ASN1DecFun_t) ASN1Dec_KERB_REPLY_KEY_PACKAGE3,
    (ASN1DecFun_t) ASN1Dec_KERB_KERBEROS_NAME,
    (ASN1DecFun_t) ASN1Dec_KERB_REPLY_KEY_PACKAGE,
    (ASN1DecFun_t) ASN1Dec_KERB_TGT_REQUEST,
    (ASN1DecFun_t) ASN1Dec_KERB_TGT_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_KDC_ISSUED_AUTH_DATA,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_TICKET,
    (ASN1DecFun_t) ASN1Dec_KERB_KDC_REQUEST,
    (ASN1DecFun_t) ASN1Dec_KERB_MARSHALLED_REQUEST_BODY,
    (ASN1DecFun_t) ASN1Dec_KERB_AS_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_TGS_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_AS_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_ENCRYPTED_TGS_REPLY,
    (ASN1DecFun_t) ASN1Dec_KERB_SAFE_MESSAGE,
    (ASN1DecFun_t) ASN1Dec_PA_S4U_X509_USER,
    (ASN1DecFun_t) ASN1Dec_PA_FX_FAST_REQUEST,
    (ASN1DecFun_t) ASN1Dec_PA_FX_FAST_REPLY,
    (ASN1DecFun_t) ASN1Dec_KrbFastResponse,
    (ASN1DecFun_t) ASN1Dec_KERB_AUTH_PACKAGE,
    (ASN1DecFun_t) ASN1Dec_KERB_AUTH_PACKAGE2,
    (ASN1DecFun_t) ASN1Dec_TD_DH_PARAMETERS,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_PK_AS_REP,
    (ASN1DecFun_t) ASN1Dec_KERB_SIGNED_REPLY_KEY_PACKAGE,
    (ASN1DecFun_t) ASN1Dec_KERB_TRUSTED_CAS,
    (ASN1DecFun_t) ASN1Dec_KERB_AS_REQUEST,
    (ASN1DecFun_t) ASN1Dec_KERB_TGS_REQUEST,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_PK_AS_REP2,
    (ASN1DecFun_t) ASN1Dec_KERB_PA_PK_AS_REQ2,
};
static const ASN1FreeFun_t freefntab[] = {
    (ASN1FreeFun_t) ASN1Free_TD_INVALID_CERTIFICATES_Seq,
    (ASN1FreeFun_t) ASN1Free_TD_TRUSTED_CERTIFIERS_Seq,
    (ASN1FreeFun_t) NULL,
    (ASN1FreeFun_t) NULL,
    (ASN1FreeFun_t) ASN1Free_PKERB_AUTHORIZATION_DATA_LIST,
    (ASN1FreeFun_t) ASN1Free_PKERB_IF_RELEVANT_AUTH_DATA,
    (ASN1FreeFun_t) ASN1Free_PKERB_TICKET_EXTENSIONS_Seq,
    (ASN1FreeFun_t) ASN1Free_PKERB_LAST_REQUEST_Seq,
    (ASN1FreeFun_t) ASN1Free_PKERB_AUTHORIZATION_DATA_Seq,
    (ASN1FreeFun_t) ASN1Free_PKERB_HOST_ADDRESSES_Seq,
    (ASN1FreeFun_t) ASN1Free_KERB_REALM_CACHE,
    (ASN1FreeFun_t) ASN1Free_KERB_PRINCIPAL_NAME,
    (ASN1FreeFun_t) ASN1Free_PKERB_PREAUTH_DATA_LIST,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_TIMESTAMP,
    (ASN1FreeFun_t) ASN1Free_PKERB_ETYPE_INFO,
    (ASN1FreeFun_t) ASN1Free_ETYPE_INFO2,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_DATA,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTION_KEY_ASN1,
    (ASN1FreeFun_t) ASN1Free_KERB_CHECKSUM,
    (ASN1FreeFun_t) ASN1Free_KERB_TICKET,
    (ASN1FreeFun_t) ASN1Free_KERB_KDC_REQUEST_BODY,
    (ASN1FreeFun_t) ASN1Free_KERB_KDC_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_KDC_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_AP_REQUEST,
    (ASN1FreeFun_t) ASN1Free_KERB_AUTHENTICATOR,
    (ASN1FreeFun_t) ASN1Free_KERB_AP_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_AP_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_SAFE_BODY,
    (ASN1FreeFun_t) ASN1Free_KERB_PRIV_MESSAGE,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_PRIV,
    (ASN1FreeFun_t) ASN1Free_KERB_CRED,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_CRED,
    (ASN1FreeFun_t) ASN1Free_KERB_CRED_INFO,
    (ASN1FreeFun_t) ASN1Free_KERB_ERROR,
    (ASN1FreeFun_t) ASN1Free_KERB_ERROR_METHOD_DATA,
    (ASN1FreeFun_t) ASN1Free_TYPED_DATA,
    (ASN1FreeFun_t) ASN1Free_EtypeList,
    (ASN1FreeFun_t) NULL,
    (ASN1FreeFun_t) ASN1Free_KERB_ERROR_DATA,
    (ASN1FreeFun_t) NULL,
    (ASN1FreeFun_t) ASN1Free_KERB_AD_RESTRICTION_ENTRY,
    (ASN1FreeFun_t) ASN1Free_PKERB_AD_RESTRICTION,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_PAC_OPTIONS,
    (ASN1FreeFun_t) ASN1Free_KERB_KEY_LIST_REQ,
    (ASN1FreeFun_t) ASN1Free_KERB_KEY_LIST_REP,
    (ASN1FreeFun_t) ASN1Free_KERB_CHANGE_PASSWORD_DATA,
    (ASN1FreeFun_t) ASN1Free_KDC_PROXY_MESSAGE,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_FOR_USER,
    (ASN1FreeFun_t) ASN1Free_S4UUserID,
    (ASN1FreeFun_t) ASN1Free_KrbFastArmoredReq,
    (ASN1FreeFun_t) ASN1Free_KrbFastReq,
    (ASN1FreeFun_t) ASN1Free_KrbFastFinished,
    (ASN1FreeFun_t) ASN1Free_EncryptedChallenge,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_SERV_REFERRAL,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_PK_AS_REQ,
    (ASN1FreeFun_t) ASN1Free_TrustedCA,
    (ASN1FreeFun_t) ASN1Free_TD_TRUSTED_CERTIFIERS,
    (ASN1FreeFun_t) ASN1Free_TD_INVALID_CERTIFICATES,
    (ASN1FreeFun_t) ASN1Free_KRB5PrincipalName,
    (ASN1FreeFun_t) ASN1Free_AD_INITIAL_VERIFIED_CAS,
    (ASN1FreeFun_t) ASN1Free_DHRepInfo,
    (ASN1FreeFun_t) ASN1Free_KDCDHKeyInfo,
    (ASN1FreeFun_t) ASN1Free_PKOcspData,
    (ASN1FreeFun_t) ASN1Free_PKAuthenticator,
    (ASN1FreeFun_t) ASN1Free_KERB_ALGORITHM_IDENTIFIER,
    (ASN1FreeFun_t) ASN1Free_KERB_SUBJECT_PUBLIC_KEY_INFO,
    (ASN1FreeFun_t) NULL,
    (ASN1FreeFun_t) ASN1Free_KERB_SIGNATURE,
    (ASN1FreeFun_t) ASN1Free_KERB_SALTED_ENCRYPTED_TIMESTAMP,
    (ASN1FreeFun_t) ASN1Free_KERB_ENVELOPED_KEY_PACKAGE,
    (ASN1FreeFun_t) ASN1Free_KERB_PKCS_SIGNATURE,
    (ASN1FreeFun_t) ASN1Free_KERB_KDC_DH_KEY_INFO,
    (ASN1FreeFun_t) ASN1Free_KERB_REPLY_KEY_PACKAGE2,
    (ASN1FreeFun_t) ASN1Free_KERB_REPLY_KEY_PACKAGE3,
    (ASN1FreeFun_t) ASN1Free_KERB_KERBEROS_NAME,
    (ASN1FreeFun_t) ASN1Free_KERB_REPLY_KEY_PACKAGE,
    (ASN1FreeFun_t) ASN1Free_KERB_TGT_REQUEST,
    (ASN1FreeFun_t) ASN1Free_KERB_TGT_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_KDC_ISSUED_AUTH_DATA,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_TICKET,
    (ASN1FreeFun_t) ASN1Free_KERB_KDC_REQUEST,
    (ASN1FreeFun_t) ASN1Free_KERB_MARSHALLED_REQUEST_BODY,
    (ASN1FreeFun_t) ASN1Free_KERB_AS_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_TGS_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_AS_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_ENCRYPTED_TGS_REPLY,
    (ASN1FreeFun_t) ASN1Free_KERB_SAFE_MESSAGE,
    (ASN1FreeFun_t) ASN1Free_PA_S4U_X509_USER,
    (ASN1FreeFun_t) ASN1Free_PA_FX_FAST_REQUEST,
    (ASN1FreeFun_t) ASN1Free_PA_FX_FAST_REPLY,
    (ASN1FreeFun_t) ASN1Free_KrbFastResponse,
    (ASN1FreeFun_t) ASN1Free_KERB_AUTH_PACKAGE,
    (ASN1FreeFun_t) ASN1Free_KERB_AUTH_PACKAGE2,
    (ASN1FreeFun_t) ASN1Free_TD_DH_PARAMETERS,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_PK_AS_REP,
    (ASN1FreeFun_t) ASN1Free_KERB_SIGNED_REPLY_KEY_PACKAGE,
    (ASN1FreeFun_t) ASN1Free_KERB_TRUSTED_CAS,
    (ASN1FreeFun_t) ASN1Free_KERB_AS_REQUEST,
    (ASN1FreeFun_t) ASN1Free_KERB_TGS_REQUEST,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_PK_AS_REP2,
    (ASN1FreeFun_t) ASN1Free_KERB_PA_PK_AS_REQ2,
};
static const ULONG sizetab[] = {
    SIZE_KRB5_Module_PDU_0,
    SIZE_KRB5_Module_PDU_1,
    SIZE_KRB5_Module_PDU_2,
    SIZE_KRB5_Module_PDU_3,
    SIZE_KRB5_Module_PDU_4,
    SIZE_KRB5_Module_PDU_5,
    SIZE_KRB5_Module_PDU_6,
    SIZE_KRB5_Module_PDU_7,
    SIZE_KRB5_Module_PDU_8,
    SIZE_KRB5_Module_PDU_9,
    SIZE_KRB5_Module_PDU_10,
    SIZE_KRB5_Module_PDU_11,
    SIZE_KRB5_Module_PDU_12,
    SIZE_KRB5_Module_PDU_13,
    SIZE_KRB5_Module_PDU_14,
    SIZE_KRB5_Module_PDU_15,
    SIZE_KRB5_Module_PDU_16,
    SIZE_KRB5_Module_PDU_17,
    SIZE_KRB5_Module_PDU_18,
    SIZE_KRB5_Module_PDU_19,
    SIZE_KRB5_Module_PDU_20,
    SIZE_KRB5_Module_PDU_21,
    SIZE_KRB5_Module_PDU_22,
    SIZE_KRB5_Module_PDU_23,
    SIZE_KRB5_Module_PDU_24,
    SIZE_KRB5_Module_PDU_25,
    SIZE_KRB5_Module_PDU_26,
    SIZE_KRB5_Module_PDU_27,
    SIZE_KRB5_Module_PDU_28,
    SIZE_KRB5_Module_PDU_29,
    SIZE_KRB5_Module_PDU_30,
    SIZE_KRB5_Module_PDU_31,
    SIZE_KRB5_Module_PDU_32,
    SIZE_KRB5_Module_PDU_33,
    SIZE_KRB5_Module_PDU_34,
    SIZE_KRB5_Module_PDU_35,
    SIZE_KRB5_Module_PDU_36,
    SIZE_KRB5_Module_PDU_37,
    SIZE_KRB5_Module_PDU_38,
    SIZE_KRB5_Module_PDU_39,
    SIZE_KRB5_Module_PDU_40,
    SIZE_KRB5_Module_PDU_41,
    SIZE_KRB5_Module_PDU_42,
    SIZE_KRB5_Module_PDU_43,
    SIZE_KRB5_Module_PDU_44,
    SIZE_KRB5_Module_PDU_45,
    SIZE_KRB5_Module_PDU_46,
    SIZE_KRB5_Module_PDU_47,
    SIZE_KRB5_Module_PDU_48,
    SIZE_KRB5_Module_PDU_49,
    SIZE_KRB5_Module_PDU_50,
    SIZE_KRB5_Module_PDU_51,
    SIZE_KRB5_Module_PDU_52,
    SIZE_KRB5_Module_PDU_53,
    SIZE_KRB5_Module_PDU_54,
    SIZE_KRB5_Module_PDU_55,
    SIZE_KRB5_Module_PDU_56,
    SIZE_KRB5_Module_PDU_57,
    SIZE_KRB5_Module_PDU_58,
    SIZE_KRB5_Module_PDU_59,
    SIZE_KRB5_Module_PDU_60,
    SIZE_KRB5_Module_PDU_61,
    SIZE_KRB5_Module_PDU_62,
    SIZE_KRB5_Module_PDU_63,
    SIZE_KRB5_Module_PDU_64,
    SIZE_KRB5_Module_PDU_65,
    SIZE_KRB5_Module_PDU_66,
    SIZE_KRB5_Module_PDU_67,
    SIZE_KRB5_Module_PDU_68,
    SIZE_KRB5_Module_PDU_69,
    SIZE_KRB5_Module_PDU_70,
    SIZE_KRB5_Module_PDU_71,
    SIZE_KRB5_Module_PDU_72,
    SIZE_KRB5_Module_PDU_73,
    SIZE_KRB5_Module_PDU_74,
    SIZE_KRB5_Module_PDU_75,
    SIZE_KRB5_Module_PDU_76,
    SIZE_KRB5_Module_PDU_77,
    SIZE_KRB5_Module_PDU_78,
    SIZE_KRB5_Module_PDU_79,
    SIZE_KRB5_Module_PDU_80,
    SIZE_KRB5_Module_PDU_81,
    SIZE_KRB5_Module_PDU_82,
    SIZE_KRB5_Module_PDU_83,
    SIZE_KRB5_Module_PDU_84,
    SIZE_KRB5_Module_PDU_85,
    SIZE_KRB5_Module_PDU_86,
    SIZE_KRB5_Module_PDU_87,
    SIZE_KRB5_Module_PDU_88,
    SIZE_KRB5_Module_PDU_89,
    SIZE_KRB5_Module_PDU_90,
    SIZE_KRB5_Module_PDU_91,
    SIZE_KRB5_Module_PDU_92,
    SIZE_KRB5_Module_PDU_93,
    SIZE_KRB5_Module_PDU_94,
    SIZE_KRB5_Module_PDU_95,
    SIZE_KRB5_Module_PDU_96,
    SIZE_KRB5_Module_PDU_97,
    SIZE_KRB5_Module_PDU_98,
    SIZE_KRB5_Module_PDU_99,
    SIZE_KRB5_Module_PDU_100,
};

BOOL ASN1CALL asn1_startup_krb5()
{
    return (KRB5_Module = ASN1_CreateModule(0x10000, ASN1_BER_RULE_DER, ASN1FLAGS_NOASSERT, 101, (const ASN1GenericFun_t*)encfntab, (const ASN1GenericFun_t*)decfntab, freefntab, sizetab, 0x3562726b)) != 0;
}

void ASN1CALL asn1_cleanup_krb5()
{
    ASN1_CloseModule(KRB5_Module);
    KRB5_Module = NULL;
}

BOOL asn1_encode_kerb(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData)
{
    BOOL Result = FALSE;

    if (KRB5_Module != NULL)
    {
        ASN1encoding_t Encoder = NULL;

        if (ASN1_CreateEncoder(KRB5_Module, &Encoder, NULL, 0, NULL) == ASN1_SUCCESS && Encoder != NULL)
        {
            if (ASN1_Encode(Encoder, pDataStruct, dwPdu, ASN1ENCODE_ALLOCATEBUFFER, NULL, 0) >= 0)
            {
                ULONG cbResult = Encoder->len;
                PVOID pvResult = malloc(cbResult);

                if (pvResult != NULL)
                {
                    *ppvData = pvResult;
                    *pcbData = cbResult;
                    memcpy(pvResult, Encoder->buf, cbResult);

                    Result = TRUE;
                }

                ASN1_FreeEncoded(Encoder, Encoder->buf);
            }

            ASN1_CloseEncoder(Encoder);
        }
    }

    return Result;
}

BOOL asn1_decode_kerb(LPCVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct)
{
    BOOL Result = FALSE;

    if (KRB5_Module != NULL)
    {
        ASN1decoding_t Decoder = NULL;

        if (ASN1_CreateDecoder(KRB5_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
        {
            Result = ASN1_Decode(Decoder, ppDataStruct, dwPdu, ASN1DECODE_SETBUFFER, (ASN1octet_t*)pvData, (ASN1uint32_t)cbData) >= 0;
            ASN1_CloseDecoder(Decoder);
        }
    }

    return Result;
}

BOOL asn1_free_kerb(PVOID pDataStruct, DWORD dwPdu)
{
    BOOL Result = FALSE;

    if (KRB5_Module != NULL)
    {
        ASN1decoding_t Decoder = NULL;

        if (ASN1_CreateDecoder(KRB5_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
        {
            ASN1_FreeDecoded(Decoder, pDataStruct, dwPdu);
            ASN1_CloseDecoder(Decoder);
        }
    }

    return Result;
}

static int ASN1CALL ASN1Enc_TD_INVALID_CERTIFICATES_Seq(ASN1encoding_t enc, ASN1uint32_t tag, TD_INVALID_CERTIFICATES_Seq *val)
{
    if (!ASN1DEREncOctetString(enc, tag ? tag : 0x4, (val)->length, (val)->value))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TD_INVALID_CERTIFICATES_Seq(ASN1decoding_t dec, ASN1uint32_t tag, TD_INVALID_CERTIFICATES_Seq *val)
{
    if (!ASN1BERDecOctetString(dec, tag ? tag : 0x4, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TD_INVALID_CERTIFICATES_Seq(TD_INVALID_CERTIFICATES_Seq *val)
{
    if (val) {
        ASN1octetstring_free(val);
    }
}

static int ASN1CALL ASN1Enc_TD_TRUSTED_CERTIFIERS_Seq(ASN1encoding_t enc, ASN1uint32_t tag, TD_TRUSTED_CERTIFIERS_Seq *val)
{
    if (!ASN1DEREncOctetString(enc, tag ? tag : 0x4, (val)->length, (val)->value))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TD_TRUSTED_CERTIFIERS_Seq(ASN1decoding_t dec, ASN1uint32_t tag, TD_TRUSTED_CERTIFIERS_Seq *val)
{
    if (!ASN1BERDecOctetString(dec, tag ? tag : 0x4, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TD_TRUSTED_CERTIFIERS_Seq(TD_TRUSTED_CERTIFIERS_Seq *val)
{
    if (val) {
        ASN1octetstring_free(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_KEY_LIST_REQ_Seq(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KEY_LIST_REQ_Seq *val)
{
    if (!ASN1BEREncS32(enc, tag ? tag : 0x2, *val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KEY_LIST_REQ_Seq(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KEY_LIST_REQ_Seq *val)
{
    if (!ASN1BERDecS32Val(dec, tag ? tag : 0x2, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Enc_EtypeList_Seq(ASN1encoding_t enc, ASN1uint32_t tag, EtypeList_Seq *val)
{
    if (!ASN1BEREncS32(enc, tag ? tag : 0x2, *val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_EtypeList_Seq(ASN1decoding_t dec, ASN1uint32_t tag, EtypeList_Seq *val)
{
    if (!ASN1BERDecS32Val(dec, tag ? tag : 0x2, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Enc_PKERB_AUTHORIZATION_DATA_LIST(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_LIST *val)
{
    if (!ASN1Enc_PKERB_AUTHORIZATION_DATA(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_AUTHORIZATION_DATA_LIST(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_LIST *val)
{
    if (!ASN1Dec_PKERB_AUTHORIZATION_DATA(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_AUTHORIZATION_DATA_LIST(PKERB_AUTHORIZATION_DATA_LIST *val)
{
    if (val) {
        ASN1Free_PKERB_AUTHORIZATION_DATA(val);
    }
}

static int ASN1CALL ASN1Enc_PKERB_IF_RELEVANT_AUTH_DATA(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_IF_RELEVANT_AUTH_DATA *val)
{
    if (!ASN1Enc_PKERB_AUTHORIZATION_DATA(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_IF_RELEVANT_AUTH_DATA(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_IF_RELEVANT_AUTH_DATA *val)
{
    if (!ASN1Dec_PKERB_AUTHORIZATION_DATA(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_IF_RELEVANT_AUTH_DATA(PKERB_IF_RELEVANT_AUTH_DATA *val)
{
    if (val) {
        ASN1Free_PKERB_AUTHORIZATION_DATA(val);
    }
}

static int ASN1CALL ASN1Enc_PKERB_TICKET_EXTENSIONS_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_TICKET_EXTENSIONS_Seq *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->te_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->te_data).length, ((val)->te_data).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_TICKET_EXTENSIONS_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_TICKET_EXTENSIONS_Seq *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->te_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->te_data))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_TICKET_EXTENSIONS_Seq(PKERB_TICKET_EXTENSIONS_Seq *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->te_data);
    }
}

static int ASN1CALL ASN1Enc_PKERB_LAST_REQUEST_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_LAST_REQUEST_Seq *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->last_request_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->last_request_value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_LAST_REQUEST_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_LAST_REQUEST_Seq *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->last_request_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->last_request_value))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_LAST_REQUEST_Seq(PKERB_LAST_REQUEST_Seq *val)
{
    if (val) {
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_BODY_encryption_type(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_encryption_type *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_KDC_REQUEST_BODY_encryption_type f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000008, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1BEREncS32(enc, 0x2, f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_BODY_encryption_type(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_encryption_type *val)
{
    PKERB_KDC_REQUEST_BODY_encryption_type *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000008, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KDC_REQUEST_BODY_encryption_type)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecS32Val(dd, 0x2, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_BODY_encryption_type(PKERB_KDC_REQUEST_BODY_encryption_type *val)
{
    PKERB_KDC_REQUEST_BODY_encryption_type f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_PKERB_AUTHORIZATION_DATA_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_Seq *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->auth_data_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->auth_data).length, ((val)->auth_data).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_AUTHORIZATION_DATA_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_AUTHORIZATION_DATA_Seq *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->auth_data_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->auth_data))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_AUTHORIZATION_DATA_Seq(PKERB_AUTHORIZATION_DATA_Seq *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->auth_data);
    }
}

static int ASN1CALL ASN1Enc_PKERB_HOST_ADDRESSES_Seq(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_HOST_ADDRESSES_Seq *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->addr_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->address).length, ((val)->address).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_HOST_ADDRESSES_Seq(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_HOST_ADDRESSES_Seq *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->addr_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->address))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_HOST_ADDRESSES_Seq(PKERB_HOST_ADDRESSES_Seq *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->address);
    }
}

static int ASN1CALL ASN1Enc_KERB_PRINCIPAL_NAME_name_string(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PRINCIPAL_NAME_name_string *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_PRINCIPAL_NAME_name_string f;
    ASN1uint32_t nLenOff;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        t = lstrlenA(f->value);
        if (!ASN1DEREncCharString(enc, 0x1b, t, f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PRINCIPAL_NAME_name_string(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PRINCIPAL_NAME_name_string *val)
{
    PKERB_PRINCIPAL_NAME_name_string *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_PRINCIPAL_NAME_name_string)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecZeroCharString(dd, 0x1b, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PRINCIPAL_NAME_name_string(PKERB_PRINCIPAL_NAME_name_string *val)
{
    PKERB_PRINCIPAL_NAME_name_string f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1ztcharstring_free(f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_REALM_CACHE_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REALM_CACHE_ENTRY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t t = 0;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    t = lstrlenA((val)->realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->access_time))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_REALM_CACHE_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REALM_CACHE_ENTRY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->access_time))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_REALM_CACHE_ENTRY(KERB_REALM_CACHE_ENTRY *val)
{
    if (val) {
        ASN1ztcharstring_free((val)->realm);
    }
}

static int ASN1CALL ASN1Enc_KERB_REALM_CACHE(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_REALM_CACHE *val)
{
    PKERB_REALM_CACHE f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_REALM_CACHE_ENTRY(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_REALM_CACHE(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_REALM_CACHE *val)
{
    PKERB_REALM_CACHE *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_REALM_CACHE)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_REALM_CACHE_ENTRY(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_REALM_CACHE(PKERB_REALM_CACHE *val)
{
    PKERB_REALM_CACHE f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_REALM_CACHE_ENTRY(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PRINCIPAL_NAME(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PRINCIPAL_NAME *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->name_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME_name_string(enc, 0, &(val)->name_string))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PRINCIPAL_NAME(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PRINCIPAL_NAME *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->name_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME_name_string(dd, 0, &(val)->name_string))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PRINCIPAL_NAME(KERB_PRINCIPAL_NAME *val)
{
    if (val) {
        ASN1Free_KERB_PRINCIPAL_NAME_name_string(&(val)->name_string);
    }
}

static int ASN1CALL ASN1Enc_KERB_HOST_ADDRESS(ASN1encoding_t enc, ASN1uint32_t tag, KERB_HOST_ADDRESS *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->addr_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->address).length, ((val)->address).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_HOST_ADDRESS(ASN1decoding_t dec, ASN1uint32_t tag, KERB_HOST_ADDRESS *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->addr_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->address))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_HOST_ADDRESS(KERB_HOST_ADDRESS *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->address);
    }
}

static int ASN1CALL ASN1Enc_PKERB_HOST_ADDRESSES(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_HOST_ADDRESSES *val)
{
    PPKERB_HOST_ADDRESSES f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_PKERB_HOST_ADDRESSES_Seq(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_HOST_ADDRESSES(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_HOST_ADDRESSES *val)
{
    PPKERB_HOST_ADDRESSES *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_HOST_ADDRESSES)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_PKERB_HOST_ADDRESSES_Seq(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_HOST_ADDRESSES(PPKERB_HOST_ADDRESSES *val)
{
    PPKERB_HOST_ADDRESSES f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_PKERB_HOST_ADDRESSES_Seq(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_PKERB_AUTHORIZATION_DATA(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_AUTHORIZATION_DATA *val)
{
    PPKERB_AUTHORIZATION_DATA f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_PKERB_AUTHORIZATION_DATA_Seq(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_AUTHORIZATION_DATA(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_AUTHORIZATION_DATA *val)
{
    PPKERB_AUTHORIZATION_DATA *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_AUTHORIZATION_DATA)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_PKERB_AUTHORIZATION_DATA_Seq(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_AUTHORIZATION_DATA(PPKERB_AUTHORIZATION_DATA *val)
{
    PPKERB_AUTHORIZATION_DATA f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_PKERB_AUTHORIZATION_DATA_Seq(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_DATA *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->preauth_data_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->preauth_data).length, ((val)->preauth_data).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_DATA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->preauth_data_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->preauth_data))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_DATA(KERB_PA_DATA *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->preauth_data);
    }
}

static int ASN1CALL ASN1Enc_PKERB_PREAUTH_DATA_LIST(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_PREAUTH_DATA_LIST *val)
{
    PPKERB_PREAUTH_DATA_LIST f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_PREAUTH_DATA_LIST(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_PREAUTH_DATA_LIST *val)
{
    PPKERB_PREAUTH_DATA_LIST *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_PREAUTH_DATA_LIST)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_PREAUTH_DATA_LIST(PPKERB_PREAUTH_DATA_LIST *val)
{
    PPKERB_PREAUTH_DATA_LIST f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_TIMESTAMP(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_TIMESTAMP *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->timestamp))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->usec))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_TIMESTAMP(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_TIMESTAMP *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->timestamp))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->usec))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_TIMESTAMP(KERB_ENCRYPTED_TIMESTAMP *val)
{
    if (val) {
    }
}

static int ASN1CALL ASN1Enc_KERB_ETYPE_INFO_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ETYPE_INFO_ENTRY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->encryption_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->salt).length, ((val)->salt).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ETYPE_INFO_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ETYPE_INFO_ENTRY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->encryption_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->salt))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ETYPE_INFO_ENTRY(KERB_ETYPE_INFO_ENTRY *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1octetstring_free(&(val)->salt);
        }
    }
}

static int ASN1CALL ASN1Enc_PKERB_ETYPE_INFO(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_ETYPE_INFO *val)
{
    PPKERB_ETYPE_INFO f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_ETYPE_INFO_ENTRY(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_ETYPE_INFO(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_ETYPE_INFO *val)
{
    PPKERB_ETYPE_INFO *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_ETYPE_INFO)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_ETYPE_INFO_ENTRY(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_ETYPE_INFO(PPKERB_ETYPE_INFO *val)
{
    PPKERB_ETYPE_INFO f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_ETYPE_INFO_ENTRY(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_ETYPE_INFO2_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, ETYPE_INFO2_ENTRY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->etype))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        t = lstrlenA((val)->salt);
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->salt))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->s2kparams).length, ((val)->s2kparams).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_ETYPE_INFO2_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, ETYPE_INFO2_ENTRY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->etype))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->salt))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->s2kparams))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_ETYPE_INFO2_ENTRY(ETYPE_INFO2_ENTRY *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1ztcharstring_free((val)->salt);
        }
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->s2kparams);
        }
    }
}

static int ASN1CALL ASN1Enc_ETYPE_INFO2(ASN1encoding_t enc, ASN1uint32_t tag, PETYPE_INFO2 *val)
{
    PETYPE_INFO2 f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_ETYPE_INFO2_ENTRY(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_ETYPE_INFO2(ASN1decoding_t dec, ASN1uint32_t tag, PETYPE_INFO2 *val)
{
    PETYPE_INFO2 *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PETYPE_INFO2)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_ETYPE_INFO2_ENTRY(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_ETYPE_INFO2(PETYPE_INFO2 *val)
{
    PETYPE_INFO2 f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_ETYPE_INFO2_ENTRY(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_DATA *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->encryption_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->version))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->cipher_text).length, ((val)->cipher_text).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_DATA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->encryption_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->cipher_text))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_DATA(KERB_ENCRYPTED_DATA *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->cipher_text);
    }
}

static int ASN1CALL ASN1Enc_EncryptedData(ASN1encoding_t enc, ASN1uint32_t tag, EncryptedData *val)
{
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_EncryptedData(ASN1decoding_t dec, ASN1uint32_t tag, EncryptedData *val)
{
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_EncryptedData(EncryptedData *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_DATA(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTION_KEY_ASN1 *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->keytype))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->keyvalue).length, ((val)->keyvalue).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTION_KEY_ASN1 *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->keytype))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->keyvalue))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTION_KEY_ASN1(KERB_ENCRYPTION_KEY_ASN1 *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->keyvalue);
    }
}

static int ASN1CALL ASN1Enc_EncryptionKey(ASN1encoding_t enc, ASN1uint32_t tag, EncryptionKey *val)
{
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_EncryptionKey(ASN1decoding_t dec, ASN1uint32_t tag, EncryptionKey *val)
{
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_EncryptionKey(EncryptionKey *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_DATA(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_CHECKSUM(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CHECKSUM *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->checksum_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->checksum).length, ((val)->checksum).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_CHECKSUM(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CHECKSUM *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->checksum_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_CHECKSUM(KERB_CHECKSUM *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->checksum);
    }
}

static int ASN1CALL ASN1Enc_KERB_TICKET(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TICKET *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000001, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->ticket_version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->server_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_TICKET_EXTENSIONS(enc, 0, &(val)->ticket_extensions))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TICKET(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TICKET *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000001, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->ticket_version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->server_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_TICKET_EXTENSIONS(dd0, 0, &(val)->ticket_extensions))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TICKET(KERB_TICKET *val)
{
    if (val) {
        ASN1ztcharstring_free((val)->realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->server_name);
        ASN1Free_KERB_ENCRYPTED_DATA(&(val)->encrypted_part);
        if ((val)->o[0] & 0x80) {
            ASN1Free_PKERB_TICKET_EXTENSIONS(&(val)->ticket_extensions);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_TRANSITED_ENCODING(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TRANSITED_ENCODING *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->transited_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->contents).length, ((val)->contents).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TRANSITED_ENCODING(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TRANSITED_ENCODING *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->transited_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->contents))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TRANSITED_ENCODING(KERB_TRANSITED_ENCODING *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->contents);
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_BODY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_REQUEST_BODY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->kdc_options).length, ((val)->kdc_options).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->client_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    t = lstrlenA((val)->realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->server_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->endtime))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000007, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REQUEST_BODY_encryption_type(enc, 0, &(val)->encryption_type))
        return 0;
    if ((val)->o[0] & 0x8) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000009, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_HOST_ADDRESSES(enc, 0, &(val)->addresses))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x4) {
        if (!ASN1BEREncExplicitTag(enc, 0x8000000a, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->enc_authorization_data))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x2) {
        if (!ASN1Enc_KERB_KDC_REQUEST_BODY_additional_tickets(enc, 0, &(val)->additional_tickets))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_BODY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_REQUEST_BODY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->kdc_options))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->client_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->server_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->endtime))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000006) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000007, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REQUEST_BODY_encryption_type(dd, 0, &(val)->encryption_type))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000009) {
        (val)->o[0] |= 0x8;
        if (!ASN1BERDecExplicitTag(dd, 0x80000009, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_HOST_ADDRESSES(dd0, 0, &(val)->addresses))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000a) {
        (val)->o[0] |= 0x4;
        if (!ASN1BERDecExplicitTag(dd, 0x8000000a, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->enc_authorization_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000b) {
        (val)->o[0] |= 0x2;
        if (!ASN1Dec_KERB_KDC_REQUEST_BODY_additional_tickets(dd, 0, &(val)->additional_tickets))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_BODY(KERB_KDC_REQUEST_BODY *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->kdc_options);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->client_name);
        }
        ASN1ztcharstring_free((val)->realm);
        if ((val)->o[0] & 0x40) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->server_name);
        }
        if ((val)->o[0] & 0x20) {
        }
        if ((val)->o[0] & 0x10) {
        }
        ASN1Free_KERB_KDC_REQUEST_BODY_encryption_type(&(val)->encryption_type);
        if ((val)->o[0] & 0x8) {
            ASN1Free_PKERB_HOST_ADDRESSES(&(val)->addresses);
        }
        if ((val)->o[0] & 0x4) {
            ASN1Free_KERB_ENCRYPTED_DATA(&(val)->enc_authorization_data);
        }
        if ((val)->o[0] & 0x2) {
            ASN1Free_KERB_KDC_REQUEST_BODY_additional_tickets(&(val)->additional_tickets);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_REPLY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1Enc_KERB_KDC_REPLY_preauth_data(enc, 0, &(val)->preauth_data))
            return 0;
    }
    t = lstrlenA((val)->client_realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->client_realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->client_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_TICKET(enc, 0, &(val)->ticket))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_REPLY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1Dec_KERB_KDC_REPLY_preauth_data(dd, 0, &(val)->preauth_data))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->client_realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->client_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_TICKET(dd0, 0, &(val)->ticket))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REPLY(KERB_KDC_REPLY *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_KDC_REPLY_preauth_data(&(val)->preauth_data);
        }
        ASN1ztcharstring_free((val)->client_realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->client_name);
        ASN1Free_KERB_TICKET(&(val)->ticket);
        ASN1Free_KERB_ENCRYPTED_DATA(&(val)->encrypted_part);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_KDC_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_KDC_REPLY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->session_key))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_PKERB_LAST_REQUEST(enc, 0, &(val)->last_request))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->key_expiration))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->flags).length, ((val)->flags).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->authtime))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000007, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->endtime))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000008, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    t = lstrlenA((val)->server_realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000009, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->server_realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x8000000a, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->server_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x8000000b, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_HOST_ADDRESSES(enc, 0, &(val)->client_addresses))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x8) {
        if (!ASN1Enc_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(enc, 0, &(val)->encrypted_pa_data))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_KDC_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_KDC_REPLY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->session_key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_PKERB_LAST_REQUEST(dd0, 0, &(val)->last_request))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->key_expiration))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->flags))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->authtime))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000006) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000007, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->endtime))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000008) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000008, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000009, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->server_realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x8000000a, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->server_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000b) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x8000000b, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_HOST_ADDRESSES(dd0, 0, &(val)->client_addresses))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000c) {
        (val)->o[0] |= 0x8;
        if (!ASN1Dec_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(dd, 0, &(val)->encrypted_pa_data))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_KDC_REPLY(KERB_ENCRYPTED_KDC_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->session_key);
        ASN1Free_PKERB_LAST_REQUEST(&(val)->last_request);
        if ((val)->o[0] & 0x80) {
        }
        ASN1bitstring_free(&(val)->flags);
        if ((val)->o[0] & 0x40) {
        }
        if ((val)->o[0] & 0x20) {
        }
        ASN1ztcharstring_free((val)->server_realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->server_name);
        if ((val)->o[0] & 0x10) {
            ASN1Free_PKERB_HOST_ADDRESSES(&(val)->client_addresses);
        }
        if ((val)->o[0] & 0x8) {
            ASN1Free_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(&(val)->encrypted_pa_data);
        }
    }
}

static int ASN1CALL ASN1Enc_PKERB_LAST_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_LAST_REQUEST *val)
{
    PPKERB_LAST_REQUEST f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_PKERB_LAST_REQUEST_Seq(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_LAST_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_LAST_REQUEST *val)
{
    PPKERB_LAST_REQUEST *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_LAST_REQUEST)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_PKERB_LAST_REQUEST_Seq(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_LAST_REQUEST(PPKERB_LAST_REQUEST *val)
{
    PPKERB_LAST_REQUEST f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_PKERB_LAST_REQUEST_Seq(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_AP_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AP_REQUEST *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000000e, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->ap_options).length, ((val)->ap_options).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_TICKET(enc, 0, &(val)->ticket))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->authenticator))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AP_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AP_REQUEST *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000000e, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->ap_options))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_TICKET(dd0, 0, &(val)->ticket))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->authenticator))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AP_REQUEST(KERB_AP_REQUEST *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->ap_options);
        ASN1Free_KERB_TICKET(&(val)->ticket);
        ASN1Free_KERB_ENCRYPTED_DATA(&(val)->authenticator);
    }
}

static int ASN1CALL ASN1Enc_KERB_AUTHENTICATOR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AUTHENTICATOR *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000002, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->authenticator_version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->client_realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->client_realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->client_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->checksum))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->client_usec))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->subkey))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000007, &nLenOff0))
            return 0;
        if (!ASN1BEREncSX(enc, 0x2, &(val)->sequence_number))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000008, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_AUTHORIZATION_DATA(enc, 0, &(val)->authorization_data))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AUTHENTICATOR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AUTHENTICATOR *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000002, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->authenticator_version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->client_realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->client_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->checksum))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->client_usec))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000006) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->subkey))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000007) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000007, &dd0, &di0))
            return 0;
        if (!ASN1BERDecSXVal(dd0, 0x2, &(val)->sequence_number))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000008) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000008, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_AUTHORIZATION_DATA(dd0, 0, &(val)->authorization_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AUTHENTICATOR(KERB_AUTHENTICATOR *val)
{
    if (val) {
        ASN1ztcharstring_free((val)->client_realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->client_name);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_CHECKSUM(&(val)->checksum);
        }
        if ((val)->o[0] & 0x40) {
            ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->subkey);
        }
        if ((val)->o[0] & 0x20) {
            ASN1intx_free(&(val)->sequence_number);
        }
        if ((val)->o[0] & 0x10) {
            ASN1Free_PKERB_AUTHORIZATION_DATA(&(val)->authorization_data);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_AP_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AP_REPLY *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000000f, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AP_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AP_REPLY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000000f, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AP_REPLY(KERB_AP_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_DATA(&(val)->encrypted_part);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_AP_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_AP_REPLY *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000001b, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->client_usec))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->subkey))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1BEREncU32(enc, 0x2, (val)->sequence_number))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_AP_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_AP_REPLY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000001b, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->client_usec))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->subkey))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecU32Val(dd0, 0x2, (ASN1uint32_t *) &(val)->sequence_number))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_AP_REPLY(KERB_ENCRYPTED_AP_REPLY *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->subkey);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_SAFE_BODY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SAFE_BODY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->user_data).length, ((val)->user_data).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->timestamp))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->usec))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1BEREncU32(enc, 0x2, (val)->sequence_number))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_HOST_ADDRESS(enc, 0, &(val)->sender_address))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_HOST_ADDRESS(enc, 0, &(val)->recipient_address))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SAFE_BODY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SAFE_BODY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->user_data))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->timestamp))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->usec))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecU32Val(dd0, 0x2, (ASN1uint32_t *) &(val)->sequence_number))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_HOST_ADDRESS(dd0, 0, &(val)->sender_address))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000005) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_HOST_ADDRESS(dd0, 0, &(val)->recipient_address))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SAFE_BODY(KERB_SAFE_BODY *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->user_data);
        if ((val)->o[0] & 0x80) {
        }
        ASN1Free_KERB_HOST_ADDRESS(&(val)->sender_address);
        if ((val)->o[0] & 0x10) {
            ASN1Free_KERB_HOST_ADDRESS(&(val)->recipient_address);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PRIV_MESSAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PRIV_MESSAGE *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000015, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PRIV_MESSAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PRIV_MESSAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000015, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PRIV_MESSAGE(KERB_PRIV_MESSAGE *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_DATA(&(val)->encrypted_part);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_PRIV(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_PRIV *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000001c, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->user_data).length, ((val)->user_data).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->timestamp))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->usec))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1BEREncU32(enc, 0x2, (val)->sequence_number))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_HOST_ADDRESS(enc, 0, &(val)->sender_address))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_HOST_ADDRESS(enc, 0, &(val)->recipient_address))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_PRIV(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_PRIV *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000001c, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->user_data))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->timestamp))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->usec))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecU32Val(dd0, 0x2, (ASN1uint32_t *) &(val)->sequence_number))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_HOST_ADDRESS(dd0, 0, &(val)->sender_address))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000005) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_HOST_ADDRESS(dd0, 0, &(val)->recipient_address))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_PRIV(KERB_ENCRYPTED_PRIV *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->user_data);
        if ((val)->o[0] & 0x80) {
        }
        ASN1Free_KERB_HOST_ADDRESS(&(val)->sender_address);
        if ((val)->o[0] & 0x10) {
            ASN1Free_KERB_HOST_ADDRESS(&(val)->recipient_address);
        }
    }
}

static int ASN1CALL ASN1Enc_PKERB_TICKET_EXTENSIONS(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_TICKET_EXTENSIONS *val)
{
    PPKERB_TICKET_EXTENSIONS f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_PKERB_TICKET_EXTENSIONS_Seq(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_TICKET_EXTENSIONS(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_TICKET_EXTENSIONS *val)
{
    PPKERB_TICKET_EXTENSIONS *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_TICKET_EXTENSIONS)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_PKERB_TICKET_EXTENSIONS_Seq(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_TICKET_EXTENSIONS(PPKERB_TICKET_EXTENSIONS *val)
{
    PPKERB_TICKET_EXTENSIONS f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_PKERB_TICKET_EXTENSIONS_Seq(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_CRED(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CRED *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000016, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CRED_tickets(enc, 0, &(val)->tickets))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

#include <stdio.h>

static int ASN1CALL ASN1Dec_KERB_CRED(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CRED *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000016, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1Dec_KERB_CRED_tickets(dd, 0, &(val)->tickets))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->encrypted_part))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_CRED(KERB_CRED *val)
{
    if (val) {
        ASN1Free_KERB_CRED_tickets(&(val)->tickets);
        ASN1Free_KERB_ENCRYPTED_DATA(&(val)->encrypted_part);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_CRED(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_CRED *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000001d, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_CRED_ticket_info(enc, 0, &(val)->ticket_info))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->timestamp))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->usec))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_HOST_ADDRESS(enc, 0, &(val)->sender_address))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x8) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_HOST_ADDRESS(enc, 0, &(val)->recipient_address))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_CRED(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_CRED *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000001d, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1Dec_KERB_ENCRYPTED_CRED_ticket_info(dd, 0, &(val)->ticket_info))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->timestamp))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->usec))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_HOST_ADDRESS(dd0, 0, &(val)->sender_address))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000005) {
        (val)->o[0] |= 0x8;
        if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_HOST_ADDRESS(dd0, 0, &(val)->recipient_address))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_CRED(KERB_ENCRYPTED_CRED *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_CRED_ticket_info(&(val)->ticket_info);
        if ((val)->o[0] & 0x40) {
        }
        if ((val)->o[0] & 0x10) {
            ASN1Free_KERB_HOST_ADDRESS(&(val)->sender_address);
        }
        if ((val)->o[0] & 0x8) {
            ASN1Free_KERB_HOST_ADDRESS(&(val)->recipient_address);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_CRED_INFO(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CRED_INFO *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->key))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        t = lstrlenA((val)->principal_realm);
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->principal_realm))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->principal_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncBitString(enc, 0x3, ((val)->flags).length, ((val)->flags).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->authtime))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x8) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x4) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->endtime))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x2) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000007, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x1) {
        t = lstrlenA((val)->service_realm);
        if (!ASN1BEREncExplicitTag(enc, 0x80000008, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->service_realm))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[1] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000009, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->service_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[1] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x8000000a, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_HOST_ADDRESSES(enc, 0, &(val)->client_addresses))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_CRED_INFO(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CRED_INFO *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 2);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->principal_realm))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->principal_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecBitString(dd0, 0x3, &(val)->flags))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->authtime))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000005) {
        (val)->o[0] |= 0x8;
        if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000006) {
        (val)->o[0] |= 0x4;
        if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->endtime))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000007) {
        (val)->o[0] |= 0x2;
        if (!ASN1BERDecExplicitTag(dd, 0x80000007, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000008) {
        (val)->o[0] |= 0x1;
        if (!ASN1BERDecExplicitTag(dd, 0x80000008, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->service_realm))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000009) {
        (val)->o[1] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000009, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->service_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000a) {
        (val)->o[1] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x8000000a, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_HOST_ADDRESSES(dd0, 0, &(val)->client_addresses))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_CRED_INFO(KERB_CRED_INFO *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->key);
        if ((val)->o[0] & 0x80) {
            ASN1ztcharstring_free((val)->principal_realm);
        }
        if ((val)->o[0] & 0x40) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->principal_name);
        }
        if ((val)->o[0] & 0x20) {
            ASN1bitstring_free(&(val)->flags);
        }
        if ((val)->o[0] & 0x10) {
        }
        if ((val)->o[0] & 0x8) {
        }
        if ((val)->o[0] & 0x4) {
        }
        if ((val)->o[0] & 0x2) {
        }
        if ((val)->o[0] & 0x1) {
            ASN1ztcharstring_free((val)->service_realm);
        }
        if ((val)->o[1] & 0x80) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->service_name);
        }
        if ((val)->o[1] & 0x40) {
            ASN1Free_PKERB_HOST_ADDRESSES(&(val)->client_addresses);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ERROR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ERROR *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000001e, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->client_time))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->client_usec))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->server_time))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->server_usec))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->error_code))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x20) {
        t = lstrlenA((val)->client_realm);
        if (!ASN1BEREncExplicitTag(enc, 0x80000007, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->client_realm))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000008, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->client_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    t = lstrlenA((val)->realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000009, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x8000000a, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->server_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x8) {
        if (!ASN1BEREncExplicitTag(enc, 0x8000000b, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, ((val)->error_text).length, ((val)->error_text).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x4) {
        if (!ASN1BEREncExplicitTag(enc, 0x8000000c, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->error_data).length, ((val)->error_data).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ERROR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ERROR *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000001e, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->client_time))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->client_usec))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->server_time))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->server_usec))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->error_code))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000007) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000007, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->client_realm))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000008) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000008, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->client_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000009, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x8000000a, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->server_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000b) {
        (val)->o[0] |= 0x8;
        if (!ASN1BERDecExplicitTag(dd, 0x8000000b, &dd0, &di0))
            return 0;
        if (!ASN1BERDecCharString(dd0, 0x1b, &(val)->error_text))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000c) {
        (val)->o[0] |= 0x4;
        if (!ASN1BERDecExplicitTag(dd, 0x8000000c, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->error_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ERROR(KERB_ERROR *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
        }
        if ((val)->o[0] & 0x20) {
            ASN1ztcharstring_free((val)->client_realm);
        }
        if ((val)->o[0] & 0x10) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->client_name);
        }
        ASN1ztcharstring_free((val)->realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->server_name);
        if ((val)->o[0] & 0x8) {
            ASN1charstring_free(&(val)->error_text);
        }
        if ((val)->o[0] & 0x4) {
            ASN1octetstring_free(&(val)->error_data);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ERROR_METHOD_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ERROR_METHOD_DATA *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->data_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->data_value).length, ((val)->data_value).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ERROR_METHOD_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ERROR_METHOD_DATA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->data_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->data_value))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ERROR_METHOD_DATA(KERB_ERROR_METHOD_DATA *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1octetstring_free(&(val)->data_value);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_TYPED_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TYPED_DATA *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->data_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->data_value).length, ((val)->data_value).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TYPED_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TYPED_DATA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->data_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->data_value))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TYPED_DATA(KERB_TYPED_DATA *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->data_value);
    }
}

static int ASN1CALL ASN1Enc_TYPED_DATA(ASN1encoding_t enc, ASN1uint32_t tag, PTYPED_DATA *val)
{
    PTYPED_DATA f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_TYPED_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TYPED_DATA(ASN1decoding_t dec, ASN1uint32_t tag, PTYPED_DATA *val)
{
    PTYPED_DATA *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PTYPED_DATA)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_TYPED_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TYPED_DATA(PTYPED_DATA *val)
{
    PTYPED_DATA f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_TYPED_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_EtypeList(ASN1encoding_t enc, ASN1uint32_t tag, PEtypeList *val)
{
    PEtypeList f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1BEREncS32(enc, 0x2, f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_EtypeList(ASN1decoding_t dec, ASN1uint32_t tag, PEtypeList *val)
{
    PEtypeList *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PEtypeList)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecS32Val(dd, 0x2, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_EtypeList(PEtypeList *val)
{
    PEtypeList f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_EXT_ERROR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_EXT_ERROR *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->status))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->klininfo))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->flags))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_EXT_ERROR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_EXT_ERROR *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->status))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->klininfo))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->flags))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Enc_KERB_ERROR_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ERROR_DATA *val)
{
    if (!ASN1Enc_KERB_ERROR_METHOD_DATA(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ERROR_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ERROR_DATA *val)
{
    if (!ASN1Dec_KERB_ERROR_METHOD_DATA(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ERROR_DATA(KERB_ERROR_DATA *val)
{
    if (val) {
        ASN1Free_KERB_ERROR_METHOD_DATA(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PAC_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PAC_REQUEST *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncBool(enc, 0x1, (val)->include_pac))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PAC_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PAC_REQUEST *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBool(dd0, 0x1, &(val)->include_pac))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Enc_KERB_AD_RESTRICTION_ENTRY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AD_RESTRICTION_ENTRY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->restriction_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->restriction).length, ((val)->restriction).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AD_RESTRICTION_ENTRY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AD_RESTRICTION_ENTRY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->restriction_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->restriction))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AD_RESTRICTION_ENTRY(KERB_AD_RESTRICTION_ENTRY *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->restriction);
    }
}

static int ASN1CALL ASN1Enc_PKERB_AD_RESTRICTION(ASN1encoding_t enc, ASN1uint32_t tag, PPKERB_AD_RESTRICTION *val)
{
    PPKERB_AD_RESTRICTION f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_AD_RESTRICTION_ENTRY(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKERB_AD_RESTRICTION(ASN1decoding_t dec, ASN1uint32_t tag, PPKERB_AD_RESTRICTION *val)
{
    PPKERB_AD_RESTRICTION *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKERB_AD_RESTRICTION)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_AD_RESTRICTION_ENTRY(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKERB_AD_RESTRICTION(PPKERB_AD_RESTRICTION *val)
{
    PPKERB_AD_RESTRICTION f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_AD_RESTRICTION_ENTRY(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PAC_OPTIONS(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PAC_OPTIONS *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->pac_flags).length, ((val)->pac_flags).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PAC_OPTIONS(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PAC_OPTIONS *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->pac_flags))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PAC_OPTIONS(KERB_PA_PAC_OPTIONS *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->pac_flags);
    }
}

static int ASN1CALL ASN1Enc_KERB_KEY_LIST_REQ(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KEY_LIST_REQ *val)
{
    PKERB_KEY_LIST_REQ f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1BEREncS32(enc, 0x2, f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KEY_LIST_REQ(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KEY_LIST_REQ *val)
{
    PKERB_KEY_LIST_REQ *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KEY_LIST_REQ)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecS32Val(dd, 0x2, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KEY_LIST_REQ(PKERB_KEY_LIST_REQ *val)
{
    PKERB_KEY_LIST_REQ f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KEY_LIST_REP(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KEY_LIST_REP *val)
{
    PKERB_KEY_LIST_REP f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KEY_LIST_REP(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KEY_LIST_REP *val)
{
    PKERB_KEY_LIST_REP *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KEY_LIST_REP)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KEY_LIST_REP(PKERB_KEY_LIST_REP *val)
{
    PKERB_KEY_LIST_REP f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_CHANGE_PASSWORD_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CHANGE_PASSWORD_DATA *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->new_password).length, ((val)->new_password).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->target_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        t = lstrlenA((val)->target_realm);
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->target_realm))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_CHANGE_PASSWORD_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CHANGE_PASSWORD_DATA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->new_password))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->target_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->target_realm))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_CHANGE_PASSWORD_DATA(KERB_CHANGE_PASSWORD_DATA *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->new_password);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->target_name);
        }
        if ((val)->o[0] & 0x40) {
            ASN1ztcharstring_free((val)->target_realm);
        }
    }
}

static int ASN1CALL ASN1Enc_KDC_PROXY_MESSAGE(ASN1encoding_t enc, ASN1uint32_t tag, KDC_PROXY_MESSAGE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->kerb_message).length, ((val)->kerb_message).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        t = lstrlenA((val)->target_domain);
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->target_domain))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->dclocator_hint))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KDC_PROXY_MESSAGE(ASN1decoding_t dec, ASN1uint32_t tag, KDC_PROXY_MESSAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->kerb_message))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->target_domain))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->dclocator_hint))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KDC_PROXY_MESSAGE(KDC_PROXY_MESSAGE *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->kerb_message);
        if ((val)->o[0] & 0x80) {
            ASN1ztcharstring_free((val)->target_domain);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_FOR_USER(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_FOR_USER *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->userName))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->userRealm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->userRealm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->cksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->authentication_package);
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->authentication_package))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->authorization_data).length, ((val)->authorization_data).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_FOR_USER(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_FOR_USER *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->userName))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->userRealm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->cksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->authentication_package))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->authorization_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_FOR_USER(KERB_PA_FOR_USER *val)
{
    if (val) {
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->userName);
        ASN1ztcharstring_free((val)->userRealm);
        ASN1Free_KERB_CHECKSUM(&(val)->cksum);
        ASN1ztcharstring_free((val)->authentication_package);
        if ((val)->o[0] & 0x80) {
            ASN1octetstring_free(&(val)->authorization_data);
        }
    }
}

static int ASN1CALL ASN1Enc_S4UUserID(ASN1encoding_t enc, ASN1uint32_t tag, S4UUserID *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->cname))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    t = lstrlenA((val)->crealm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->crealm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->certificate).length, ((val)->certificate).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncBitString(enc, 0x3, ((val)->options).length, ((val)->options).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_S4UUserID(ASN1decoding_t dec, ASN1uint32_t tag, S4UUserID *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->cname))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->crealm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->certificate))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1BERDecBitString(dd0, 0x3, &(val)->options))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_S4UUserID(S4UUserID *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->cname);
        }
        ASN1ztcharstring_free((val)->crealm);
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->certificate);
        }
        if ((val)->o[0] & 0x20) {
            ASN1bitstring_free(&(val)->options);
        }
    }
}

static int ASN1CALL ASN1Enc_KrbFastArmor(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastArmor *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->armor_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->armor_value).length, ((val)->armor_value).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastArmor(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastArmor *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->armor_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->armor_value))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastArmor(KrbFastArmor *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->armor_value);
    }
}

static int ASN1CALL ASN1Enc_KrbFastArmoredReq(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastArmoredReq *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_KrbFastArmor(enc, 0, &(val)->armor))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->req_checksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_EncryptedData(enc, 0, &(val)->enc_fast_req))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastArmoredReq(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastArmoredReq *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000000) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KrbFastArmor(dd0, 0, &(val)->armor))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->req_checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_EncryptedData(dd0, 0, &(val)->enc_fast_req))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastArmoredReq(KrbFastArmoredReq *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KrbFastArmor(&(val)->armor);
        }
        ASN1Free_KERB_CHECKSUM(&(val)->req_checksum);
        ASN1Free_EncryptedData(&(val)->enc_fast_req);
    }
}

static int ASN1CALL ASN1Enc_KrbFastReq(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastReq *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->fast_options).length, ((val)->fast_options).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1Enc_KrbFastReq_padata(enc, 0, &(val)->padata))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REQUEST_BODY(enc, 0, &(val)->req_body))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastReq(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastReq *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->fast_options))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1Dec_KrbFastReq_padata(dd, 0, &(val)->padata))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REQUEST_BODY(dd0, 0, &(val)->req_body))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastReq(KrbFastReq *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->fast_options);
        ASN1Free_KrbFastReq_padata(&(val)->padata);
        ASN1Free_KERB_KDC_REQUEST_BODY(&(val)->req_body);
    }
}

static int ASN1CALL ASN1Enc_KrbFastArmoredRep(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastArmoredRep *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_EncryptedData(enc, 0, &(val)->enc_fast_rep))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastArmoredRep(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastArmoredRep *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_EncryptedData(dd0, 0, &(val)->enc_fast_rep))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastArmoredRep(KrbFastArmoredRep *val)
{
    if (val) {
        ASN1Free_EncryptedData(&(val)->enc_fast_rep);
    }
}

static int ASN1CALL ASN1Enc_KrbFastFinished(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastFinished *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->timestamp))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->usec))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->crealm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->crealm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->cname))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->ticket_checksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastFinished(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastFinished *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->timestamp))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->usec))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->crealm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->cname))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->ticket_checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastFinished(KrbFastFinished *val)
{
    if (val) {
        ASN1ztcharstring_free((val)->crealm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->cname);
        ASN1Free_KERB_CHECKSUM(&(val)->ticket_checksum);
    }
}

static int ASN1CALL ASN1Enc_EncryptedChallenge(ASN1encoding_t enc, ASN1uint32_t tag, EncryptedChallenge *val)
{
    if (!ASN1Enc_EncryptedData(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_EncryptedChallenge(ASN1decoding_t dec, ASN1uint32_t tag, EncryptedChallenge *val)
{
    if (!ASN1Dec_EncryptedData(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_EncryptedChallenge(EncryptedChallenge *val)
{
    if (val) {
        ASN1Free_EncryptedData(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_SERV_REFERRAL(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_SERV_REFERRAL *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->referred_server_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    t = lstrlenA((val)->referred_server_realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->referred_server_realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_SERV_REFERRAL(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_SERV_REFERRAL *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->referred_server_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->referred_server_realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_SERV_REFERRAL(KERB_PA_SERV_REFERRAL *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->referred_server_name);
        }
        ASN1ztcharstring_free((val)->referred_server_realm);
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REQ *val)
{
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x80000000, ((val)->signed_auth_pack).length, ((val)->signed_auth_pack).value))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1Enc_KERB_PA_PK_AS_REQ_trusted_certifiers(enc, 0, &(val)->trusted_certifiers))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1DEREncOctetString(enc, 0x80000003, ((val)->kdc_pk_id).length, ((val)->kdc_pk_id).value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REQ *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecOctetString(dd, 0x80000000, &(val)->signed_auth_pack))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1Dec_KERB_PA_PK_AS_REQ_trusted_certifiers(dd, 0, &(val)->trusted_certifiers))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecOctetString(dd, 0x80000003, &(val)->kdc_pk_id))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ(KERB_PA_PK_AS_REQ *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->signed_auth_pack);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PA_PK_AS_REQ_trusted_certifiers(&(val)->trusted_certifiers);
        }
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->kdc_pk_id);
        }
    }
}

static int ASN1CALL ASN1Enc_TrustedCA(ASN1encoding_t enc, ASN1uint32_t tag, TrustedCA *val)
{
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1DEREncOctetString(enc, 0x80000000, ((val)->subjectName).length, ((val)->subjectName).value))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1DEREncOctetString(enc, 0x80000001, ((val)->issuerAndSerialNumber).length, ((val)->issuerAndSerialNumber).value))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1DEREncOctetString(enc, 0x80000002, ((val)->subjectKeyIdentifier).length, ((val)->subjectKeyIdentifier).value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TrustedCA(ASN1decoding_t dec, ASN1uint32_t tag, TrustedCA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000000) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecOctetString(dd, 0x80000000, &(val)->subjectName))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecOctetString(dd, 0x80000001, &(val)->issuerAndSerialNumber))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecOctetString(dd, 0x80000002, &(val)->subjectKeyIdentifier))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TrustedCA(TrustedCA *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1octetstring_free(&(val)->subjectName);
        }
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->issuerAndSerialNumber);
        }
        if ((val)->o[0] & 0x20) {
            ASN1octetstring_free(&(val)->subjectKeyIdentifier);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PK_AUTHENTICATOR(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PK_AUTHENTICATOR *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->kdc_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->kdc_realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->kdc_realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->cusec))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PK_AUTHENTICATOR(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PK_AUTHENTICATOR *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->kdc_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->kdc_realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->cusec))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PK_AUTHENTICATOR(KERB_PK_AUTHENTICATOR *val)
{
    if (val) {
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->kdc_name);
        ASN1ztcharstring_free((val)->kdc_realm);
    }
}

static int ASN1CALL ASN1Enc_TD_TRUSTED_CERTIFIERS(ASN1encoding_t enc, ASN1uint32_t tag, PTD_TRUSTED_CERTIFIERS *val)
{
    PTD_TRUSTED_CERTIFIERS f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1DEREncOctetString(enc, 0x4, (f->value).length, (f->value).value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TD_TRUSTED_CERTIFIERS(ASN1decoding_t dec, ASN1uint32_t tag, PTD_TRUSTED_CERTIFIERS *val)
{
    PTD_TRUSTED_CERTIFIERS *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PTD_TRUSTED_CERTIFIERS)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecOctetString(dd, 0x4, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TD_TRUSTED_CERTIFIERS(PTD_TRUSTED_CERTIFIERS *val)
{
    PTD_TRUSTED_CERTIFIERS f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1octetstring_free(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_TD_INVALID_CERTIFICATES(ASN1encoding_t enc, ASN1uint32_t tag, PTD_INVALID_CERTIFICATES *val)
{
    PTD_INVALID_CERTIFICATES f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1DEREncOctetString(enc, 0x4, (f->value).length, (f->value).value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TD_INVALID_CERTIFICATES(ASN1decoding_t dec, ASN1uint32_t tag, PTD_INVALID_CERTIFICATES *val)
{
    PTD_INVALID_CERTIFICATES *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PTD_INVALID_CERTIFICATES)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecOctetString(dd, 0x4, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TD_INVALID_CERTIFICATES(PTD_INVALID_CERTIFICATES *val)
{
    PTD_INVALID_CERTIFICATES f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1octetstring_free(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KRB5PrincipalName(ASN1encoding_t enc, ASN1uint32_t tag, KRB5PrincipalName *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t t = 0;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    t = lstrlenA((val)->realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->principalName))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KRB5PrincipalName(ASN1decoding_t dec, ASN1uint32_t tag, KRB5PrincipalName *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->principalName))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KRB5PrincipalName(KRB5PrincipalName *val)
{
    if (val) {
        ASN1ztcharstring_free((val)->realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->principalName);
    }
}

static int ASN1CALL ASN1Enc_AD_INITIAL_VERIFIED_CAS(ASN1encoding_t enc, ASN1uint32_t tag, PAD_INITIAL_VERIFIED_CAS *val)
{
    PAD_INITIAL_VERIFIED_CAS f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_TrustedCA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_AD_INITIAL_VERIFIED_CAS(ASN1decoding_t dec, ASN1uint32_t tag, PAD_INITIAL_VERIFIED_CAS *val)
{
    PAD_INITIAL_VERIFIED_CAS *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PAD_INITIAL_VERIFIED_CAS)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_TrustedCA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_AD_INITIAL_VERIFIED_CAS(PAD_INITIAL_VERIFIED_CAS *val)
{
    PAD_INITIAL_VERIFIED_CAS f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_TrustedCA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_DHRepInfo(ASN1encoding_t enc, ASN1uint32_t tag, DHRepInfo *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x80000000, ((val)->dhSignedData).length, ((val)->dhSignedData).value))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->serverDHNonce).length, ((val)->serverDHNonce).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_DHRepInfo(ASN1decoding_t dec, ASN1uint32_t tag, DHRepInfo *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecOctetString(dd, 0x80000000, &(val)->dhSignedData))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->serverDHNonce))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_DHRepInfo(DHRepInfo *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->dhSignedData);
        if ((val)->o[0] & 0x80) {
            ASN1octetstring_free(&(val)->serverDHNonce);
        }
    }
}

static int ASN1CALL ASN1Enc_KDCDHKeyInfo(ASN1encoding_t enc, ASN1uint32_t tag, KDCDHKeyInfo *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->subjectPublicKey).length, ((val)->subjectPublicKey).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncU32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->dhKeyExpiration))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KDCDHKeyInfo(ASN1decoding_t dec, ASN1uint32_t tag, KDCDHKeyInfo *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->subjectPublicKey))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecU32Val(dd0, 0x2, (ASN1uint32_t *) &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->dhKeyExpiration))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KDCDHKeyInfo(KDCDHKeyInfo *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->subjectPublicKey);
        if ((val)->o[0] & 0x80) {
        }
    }
}

static int ASN1CALL ASN1Enc_PKOcspData(ASN1encoding_t enc, ASN1uint32_t tag, PPKOcspData *val)
{
    PPKOcspData f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1DEREncOctetString(enc, 0x4, (f->value).length, (f->value).value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKOcspData(ASN1decoding_t dec, ASN1uint32_t tag, PPKOcspData *val)
{
    PPKOcspData *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PPKOcspData)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecOctetString(dd, 0x4, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKOcspData(PPKOcspData *val)
{
    PPKOcspData f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1octetstring_free(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_PKAuthenticator(ASN1encoding_t enc, ASN1uint32_t tag, PKAuthenticator *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncU32(enc, 0x2, (val)->cusec))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncU32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->paChecksum).length, ((val)->paChecksum).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->freshnessToken).length, ((val)->freshnessToken).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PKAuthenticator(ASN1decoding_t dec, ASN1uint32_t tag, PKAuthenticator *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecU32Val(dd0, 0x2, (ASN1uint32_t *) &(val)->cusec))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->client_time))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecU32Val(dd0, 0x2, (ASN1uint32_t *) &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->paChecksum))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->freshnessToken))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PKAuthenticator(PKAuthenticator *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1octetstring_free(&(val)->paChecksum);
        }
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->freshnessToken);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ALGORITHM_IDENTIFIER(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ALGORITHM_IDENTIFIER *val)
{
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncObjectIdentifier(enc, 0x6, &(val)->algorithm))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncOpenType(enc, &(val)->parameters))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ALGORITHM_IDENTIFIER(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ALGORITHM_IDENTIFIER *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecObjectIdentifier(dd, 0x6, &(val)->algorithm))
        return 0;
    if (ASN1BERDecPeekTag(dd, &t)) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecOpenType2(dd, &(val)->parameters))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ALGORITHM_IDENTIFIER(KERB_ALGORITHM_IDENTIFIER *val)
{
    if (val) {
        ASN1objectidentifier_free(&(val)->algorithm);
        if ((val)->o[0] & 0x80) {
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_SUBJECT_PUBLIC_KEY_INFO(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SUBJECT_PUBLIC_KEY_INFO *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ALGORITHM_IDENTIFIER(enc, 0, &(val)->algorithm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->subjectPublicKey).length, ((val)->subjectPublicKey).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SUBJECT_PUBLIC_KEY_INFO(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SUBJECT_PUBLIC_KEY_INFO *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ALGORITHM_IDENTIFIER(dd0, 0, &(val)->algorithm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->subjectPublicKey))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SUBJECT_PUBLIC_KEY_INFO(KERB_SUBJECT_PUBLIC_KEY_INFO *val)
{
    if (val) {
        ASN1Free_KERB_ALGORITHM_IDENTIFIER(&(val)->algorithm);
        ASN1bitstring_free(&(val)->subjectPublicKey);
    }
}

static int ASN1CALL ASN1Enc_KERB_DH_PARAMTER(ASN1encoding_t enc, ASN1uint32_t tag, KERB_DH_PARAMTER *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->prime))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->base))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->private_value_length))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_DH_PARAMTER(ASN1decoding_t dec, ASN1uint32_t tag, KERB_DH_PARAMTER *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->prime))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->base))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->private_value_length))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Enc_KERB_CERTIFICATE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_CERTIFICATE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->cert_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->cert_data).length, ((val)->cert_data).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_CERTIFICATE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_CERTIFICATE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->cert_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->cert_data))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_CERTIFICATE(KERB_CERTIFICATE *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->cert_data);
    }
}

static int ASN1CALL ASN1Enc_KERB_SIGNATURE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNATURE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ALGORITHM_IDENTIFIER(enc, 0, &(val)->signature_algorithm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->pkcs_signature).length, ((val)->pkcs_signature).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SIGNATURE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNATURE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ALGORITHM_IDENTIFIER(dd0, 0, &(val)->signature_algorithm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->pkcs_signature))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SIGNATURE(KERB_SIGNATURE *val)
{
    if (val) {
        ASN1Free_KERB_ALGORITHM_IDENTIFIER(&(val)->signature_algorithm);
        ASN1bitstring_free(&(val)->pkcs_signature);
    }
}

static int ASN1CALL ASN1Enc_KERB_SALTED_ENCRYPTED_TIMESTAMP(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SALTED_ENCRYPTED_TIMESTAMP *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->timestamp))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->usec))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->salt).length, ((val)->salt).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SALTED_ENCRYPTED_TIMESTAMP(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SALTED_ENCRYPTED_TIMESTAMP *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->timestamp))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->usec))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->salt))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SALTED_ENCRYPTED_TIMESTAMP(KERB_SALTED_ENCRYPTED_TIMESTAMP *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->salt);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENVELOPED_KEY_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENVELOPED_KEY_PACKAGE *val)
{
    ASN1uint32_t nLenOff0;
    switch ((val)->choice) {
    case 1:
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->u.encrypted_data))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    case 2:
        if (!ASN1DEREncOctetString(enc, 0x80000004, ((val)->u.pkinit_enveloped_data).length, ((val)->u.pkinit_enveloped_data).value))
            return 0;
        break;
    default:
        /* impossible */
        ASN1EncSetError(enc, ASN1_ERR_CHOICE);
        return 0;
    }
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENVELOPED_KEY_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENVELOPED_KEY_PACKAGE *val)
{
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecPeekTag(dec, &t))
        return 0;
    switch (t) {
    case 0x80000001:
        (val)->choice = 1;
        if (!ASN1BERDecExplicitTag(dec, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->u.encrypted_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    case 0x80000004:
        (val)->choice = 2;
        if (!ASN1BERDecOctetString(dec, 0x80000004, &(val)->u.pkinit_enveloped_data))
            return 0;
        break;
    default:
        ASN1DecSetError(dec, ASN1_ERR_CORRUPT);
        return 0;
    }
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENVELOPED_KEY_PACKAGE(KERB_ENVELOPED_KEY_PACKAGE *val)
{
    if (val) {
        switch ((val)->choice) {
        case 1:
            ASN1Free_KERB_ENCRYPTED_DATA(&(val)->u.encrypted_data);
            break;
        case 2:
            ASN1octetstring_free(&(val)->u.pkinit_enveloped_data);
            break;
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PKCS_SIGNATURE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PKCS_SIGNATURE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->encryption_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncOctetString(enc, 0x4, ((val)->signature).length, ((val)->signature).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PKCS_SIGNATURE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PKCS_SIGNATURE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->encryption_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->signature))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PKCS_SIGNATURE(KERB_PKCS_SIGNATURE *val)
{
    if (val) {
        ASN1octetstring_free(&(val)->signature);
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_DH_KEY_INFO(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_DH_KEY_INFO *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->subject_public_key).length, ((val)->subject_public_key).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_DH_KEY_INFO(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_DH_KEY_INFO *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->subject_public_key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_DH_KEY_INFO(KERB_KDC_DH_KEY_INFO *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->subject_public_key);
    }
}

static int ASN1CALL ASN1Enc_KERB_REPLY_KEY_PACKAGE2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE2 *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->reply_key))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncBitString(enc, 0x3, ((val)->subject_public_key).length, ((val)->subject_public_key).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_REPLY_KEY_PACKAGE2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE2 *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->reply_key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecBitString(dd0, 0x3, &(val)->subject_public_key))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_REPLY_KEY_PACKAGE2(KERB_REPLY_KEY_PACKAGE2 *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->reply_key);
        if ((val)->o[0] & 0x80) {
            ASN1bitstring_free(&(val)->subject_public_key);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_REPLY_KEY_PACKAGE3(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE3 *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->reply_key))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->as_checksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_REPLY_KEY_PACKAGE3(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE3 *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->reply_key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->as_checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_REPLY_KEY_PACKAGE3(KERB_REPLY_KEY_PACKAGE3 *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->reply_key);
        ASN1Free_KERB_CHECKSUM(&(val)->as_checksum);
    }
}

static int ASN1CALL ASN1Enc_KERB_KERBEROS_NAME(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KERBEROS_NAME *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t t = 0;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    t = lstrlenA((val)->realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->principal_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KERBEROS_NAME(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KERBEROS_NAME *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->principal_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KERBEROS_NAME(KERB_KERBEROS_NAME *val)
{
    if (val) {
        ASN1ztcharstring_free((val)->realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->principal_name);
    }
}

static int ASN1CALL ASN1Enc_KERB_REPLY_KEY_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->reply_key))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_REPLY_KEY_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_REPLY_KEY_PACKAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->reply_key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_REPLY_KEY_PACKAGE(KERB_REPLY_KEY_PACKAGE *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->reply_key);
    }
}

static int ASN1CALL ASN1Enc_KERB_TGT_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGT_REQUEST *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->server_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        t = lstrlenA((val)->server_realm);
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->server_realm))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TGT_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGT_REQUEST *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->server_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->server_realm))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TGT_REQUEST(KERB_TGT_REQUEST *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PRINCIPAL_NAME(&(val)->server_name);
        }
        if ((val)->o[0] & 0x40) {
            ASN1ztcharstring_free((val)->server_realm);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_TGT_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGT_REPLY *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_TICKET(enc, 0, &(val)->ticket))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TGT_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGT_REPLY *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_TICKET(dd0, 0, &(val)->ticket))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TGT_REPLY(KERB_TGT_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_TICKET(&(val)->ticket);
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ2_trusted_certifiers(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_trusted_certifiers *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_PA_PK_AS_REQ2_trusted_certifiers f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ2_trusted_certifiers(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_trusted_certifiers *val)
{
    PKERB_PA_PK_AS_REQ2_trusted_certifiers *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_PA_PK_AS_REQ2_trusted_certifiers)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ2_trusted_certifiers(PKERB_PA_PK_AS_REQ2_trusted_certifiers *val)
{
    PKERB_PA_PK_AS_REQ2_trusted_certifiers f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PRINCIPAL_NAME(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ2_user_certs(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_user_certs *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_PA_PK_AS_REQ2_user_certs f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_CERTIFICATE(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ2_user_certs(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ2_user_certs *val)
{
    PKERB_PA_PK_AS_REQ2_user_certs *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_PA_PK_AS_REQ2_user_certs)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_CERTIFICATE(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ2_user_certs(PKERB_PA_PK_AS_REQ2_user_certs *val)
{
    PKERB_PA_PK_AS_REQ2_user_certs f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_CERTIFICATE(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REP2_kdc_cert(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REP2_kdc_cert *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_PA_PK_AS_REP2_kdc_cert f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_CERTIFICATE(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REP2_kdc_cert(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REP2_kdc_cert *val)
{
    PKERB_PA_PK_AS_REP2_kdc_cert *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_PA_PK_AS_REP2_kdc_cert)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_CERTIFICATE(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REP2_kdc_cert(PKERB_PA_PK_AS_REP2_kdc_cert *val)
{
    PKERB_PA_PK_AS_REP2_kdc_cert f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_CERTIFICATE(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_AUTH_PACKAGE2_supportedCMSTypes(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_AUTH_PACKAGE2_supportedCMSTypes *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_AUTH_PACKAGE2_supportedCMSTypes f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_ALGORITHM_IDENTIFIER(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AUTH_PACKAGE2_supportedCMSTypes(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_AUTH_PACKAGE2_supportedCMSTypes *val)
{
    PKERB_AUTH_PACKAGE2_supportedCMSTypes *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_AUTH_PACKAGE2_supportedCMSTypes)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_ALGORITHM_IDENTIFIER(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AUTH_PACKAGE2_supportedCMSTypes(PKERB_AUTH_PACKAGE2_supportedCMSTypes *val)
{
    PKERB_AUTH_PACKAGE2_supportedCMSTypes f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_ALGORITHM_IDENTIFIER(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KrbFastResponse_padata(ASN1encoding_t enc, ASN1uint32_t tag, PKrbFastResponse_padata *val)
{
    ASN1uint32_t nLenOff0;
    PKrbFastResponse_padata f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastResponse_padata(ASN1decoding_t dec, ASN1uint32_t tag, PKrbFastResponse_padata *val)
{
    PKrbFastResponse_padata *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKrbFastResponse_padata)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastResponse_padata(PKrbFastResponse_padata *val)
{
    PKrbFastResponse_padata f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KrbFastReq_padata(ASN1encoding_t enc, ASN1uint32_t tag, PKrbFastReq_padata *val)
{
    ASN1uint32_t nLenOff0;
    PKrbFastReq_padata f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastReq_padata(ASN1decoding_t dec, ASN1uint32_t tag, PKrbFastReq_padata *val)
{
    PKrbFastReq_padata *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKrbFastReq_padata)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastReq_padata(PKrbFastReq_padata *val)
{
    PKrbFastReq_padata f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_CRED_ticket_info(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_ENCRYPTED_CRED_ticket_info *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_ENCRYPTED_CRED_ticket_info f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_CRED_INFO(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_CRED_ticket_info(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_ENCRYPTED_CRED_ticket_info *val)
{
    PKERB_ENCRYPTED_CRED_ticket_info *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_ENCRYPTED_CRED_ticket_info)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_CRED_INFO(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_CRED_ticket_info(PKERB_ENCRYPTED_CRED_ticket_info *val)
{
    PKERB_ENCRYPTED_CRED_ticket_info f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_CRED_INFO(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_CRED_tickets(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_CRED_tickets *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_CRED_tickets f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_TICKET(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_CRED_tickets(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_CRED_tickets *val)
{
    PKERB_CRED_tickets *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_CRED_tickets)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_TICKET(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_CRED_tickets(PKERB_CRED_tickets *val)
{
    PKERB_CRED_tickets f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_TICKET(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x8000000c, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *val)
{
    PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x8000000c, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data(PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data *val)
{
    PKERB_ENCRYPTED_KDC_REPLY_encrypted_pa_data f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REPLY_preauth_data(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REPLY_preauth_data *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_KDC_REPLY_preauth_data f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REPLY_preauth_data(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REPLY_preauth_data *val)
{
    PKERB_KDC_REPLY_preauth_data *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KDC_REPLY_preauth_data)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REPLY_preauth_data(PKERB_KDC_REPLY_preauth_data *val)
{
    PKERB_KDC_REPLY_preauth_data f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_BODY_additional_tickets(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_additional_tickets *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_KDC_REQUEST_BODY_additional_tickets f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x8000000b, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_TICKET(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_BODY_additional_tickets(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REQUEST_BODY_additional_tickets *val)
{
    PKERB_KDC_REQUEST_BODY_additional_tickets *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x8000000b, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KDC_REQUEST_BODY_additional_tickets)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_TICKET(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_BODY_additional_tickets(PKERB_KDC_REQUEST_BODY_additional_tickets *val)
{
    PKERB_KDC_REQUEST_BODY_additional_tickets f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_TICKET(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST_preauth_data(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_REQUEST_preauth_data *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_KDC_REQUEST_preauth_data f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST_preauth_data(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_REQUEST_preauth_data *val)
{
    PKERB_KDC_REQUEST_preauth_data *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KDC_REQUEST_preauth_data)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REQUEST_preauth_data(PKERB_KDC_REQUEST_preauth_data *val)
{
    PKERB_KDC_REQUEST_preauth_data f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_ISSUED_AUTH_DATA_elements(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_KDC_ISSUED_AUTH_DATA_elements *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_KDC_ISSUED_AUTH_DATA_elements f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_PA_DATA(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_ISSUED_AUTH_DATA_elements(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_KDC_ISSUED_AUTH_DATA_elements *val)
{
    PKERB_KDC_ISSUED_AUTH_DATA_elements *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_KDC_ISSUED_AUTH_DATA_elements)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_PA_DATA(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_ISSUED_AUTH_DATA_elements(PKERB_KDC_ISSUED_AUTH_DATA_elements *val)
{
    PKERB_KDC_ISSUED_AUTH_DATA_elements f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_PA_DATA(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_ISSUED_AUTH_DATA(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_ISSUED_AUTH_DATA *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SIGNATURE(enc, 0, &(val)->checksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_ISSUED_AUTH_DATA_elements(enc, 0, &(val)->elements))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_ISSUED_AUTH_DATA(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_ISSUED_AUTH_DATA *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SIGNATURE(dd0, 0, &(val)->checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_ISSUED_AUTH_DATA_elements(dd, 0, &(val)->elements))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_ISSUED_AUTH_DATA(KERB_KDC_ISSUED_AUTH_DATA *val)
{
    if (val) {
        ASN1Free_KERB_SIGNATURE(&(val)->checksum);
        ASN1Free_KERB_KDC_ISSUED_AUTH_DATA_elements(&(val)->elements);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_TICKET(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_TICKET *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t t = 0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000003, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1DEREncBitString(enc, 0x3, ((val)->flags).length, ((val)->flags).value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTION_KEY_ASN1(enc, 0, &(val)->key))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    t = lstrlenA((val)->client_realm);
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->client_realm))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PRINCIPAL_NAME(enc, 0, &(val)->client_name))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_TRANSITED_ENCODING(enc, 0, &(val)->transited))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000005, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->authtime))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000006, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000007, &nLenOff0))
        return 0;
    if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->endtime))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000008, &nLenOff0))
            return 0;
        if (!ASN1DEREncGeneralizedTime(enc, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000009, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_HOST_ADDRESSES(enc, 0, &(val)->client_addresses))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x8000000a, &nLenOff0))
            return 0;
        if (!ASN1Enc_PKERB_AUTHORIZATION_DATA(enc, 0, &(val)->authorization_data))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_TICKET(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_TICKET *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000003, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecBitString(dd0, 0x3, &(val)->flags))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTION_KEY_ASN1(dd0, 0, &(val)->key))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->client_realm))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PRINCIPAL_NAME(dd0, 0, &(val)->client_name))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_TRANSITED_ENCODING(dd0, 0, &(val)->transited))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000005, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->authtime))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000006) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000006, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->starttime))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000007, &dd0, &di0))
        return 0;
    if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->endtime))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000008) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000008, &dd0, &di0))
            return 0;
        if (!ASN1BERDecGeneralizedTime(dd0, 0x18, &(val)->renew_until))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000009) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000009, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_HOST_ADDRESSES(dd0, 0, &(val)->client_addresses))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x8000000a) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x8000000a, &dd0, &di0))
            return 0;
        if (!ASN1Dec_PKERB_AUTHORIZATION_DATA(dd0, 0, &(val)->authorization_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_TICKET(KERB_ENCRYPTED_TICKET *val)
{
    if (val) {
        ASN1bitstring_free(&(val)->flags);
        ASN1Free_KERB_ENCRYPTION_KEY_ASN1(&(val)->key);
        ASN1ztcharstring_free((val)->client_realm);
        ASN1Free_KERB_PRINCIPAL_NAME(&(val)->client_name);
        ASN1Free_KERB_TRANSITED_ENCODING(&(val)->transited);
        if ((val)->o[0] & 0x80) {
        }
        if ((val)->o[0] & 0x40) {
        }
        if ((val)->o[0] & 0x20) {
            ASN1Free_PKERB_HOST_ADDRESSES(&(val)->client_addresses);
        }
        if ((val)->o[0] & 0x10) {
            ASN1Free_PKERB_AUTHORIZATION_DATA(&(val)->authorization_data);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_KDC_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_KDC_REQUEST *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1Enc_KERB_KDC_REQUEST_preauth_data(enc, 0, &(val)->preauth_data))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REQUEST_BODY(enc, 0, &(val)->request_body))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_KDC_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_KDC_REQUEST *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x80;
        if (!ASN1Dec_KERB_KDC_REQUEST_preauth_data(dd, 0, &(val)->preauth_data))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REQUEST_BODY(dd0, 0, &(val)->request_body))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_KDC_REQUEST(KERB_KDC_REQUEST *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_KDC_REQUEST_preauth_data(&(val)->preauth_data);
        }
        ASN1Free_KERB_KDC_REQUEST_BODY(&(val)->request_body);
    }
}

static int ASN1CALL ASN1Enc_KERB_MARSHALLED_REQUEST_BODY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_MARSHALLED_REQUEST_BODY *val)
{
    if (!ASN1Enc_KERB_KDC_REQUEST_BODY(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_MARSHALLED_REQUEST_BODY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_MARSHALLED_REQUEST_BODY *val)
{
    if (!ASN1Dec_KERB_KDC_REQUEST_BODY(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_MARSHALLED_REQUEST_BODY(KERB_MARSHALLED_REQUEST_BODY *val)
{
    if (val) {
        ASN1Free_KERB_KDC_REQUEST_BODY(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_AS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AS_REPLY *val)
{
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000000b, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REPLY(enc, 0, val))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AS_REPLY *val)
{
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000000b, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REPLY(dd0, 0, val))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AS_REPLY(KERB_AS_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_KDC_REPLY(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_TGS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGS_REPLY *val)
{
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000000d, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REPLY(enc, 0, val))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TGS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGS_REPLY *val)
{
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000000d, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REPLY(dd0, 0, val))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TGS_REPLY(KERB_TGS_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_KDC_REPLY(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_AS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_AS_REPLY *val)
{
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000019, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_KDC_REPLY(enc, 0, val))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_AS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_AS_REPLY *val)
{
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000019, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_KDC_REPLY(dd0, 0, val))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_AS_REPLY(KERB_ENCRYPTED_AS_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_KDC_REPLY(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_ENCRYPTED_TGS_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, KERB_ENCRYPTED_TGS_REPLY *val)
{
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000001a, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENCRYPTED_KDC_REPLY(enc, 0, val))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_ENCRYPTED_TGS_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, KERB_ENCRYPTED_TGS_REPLY *val)
{
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000001a, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENCRYPTED_KDC_REPLY(dd0, 0, val))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_ENCRYPTED_TGS_REPLY(KERB_ENCRYPTED_TGS_REPLY *val)
{
    if (val) {
        ASN1Free_KERB_ENCRYPTED_KDC_REPLY(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_SAFE_MESSAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SAFE_MESSAGE *val)
{
    ASN1uint32_t nExplTagLenOff0;
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000014, &nExplTagLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->version))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->message_type))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SAFE_BODY(enc, 0, &(val)->safe_body))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->checksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nExplTagLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SAFE_MESSAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SAFE_MESSAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t pExplTagDec0;
    ASN1octet_t *pbExplTagDataEnd0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000014, &pExplTagDec0, &pbExplTagDataEnd0))
        return 0;
    if (!ASN1BERDecExplicitTag(pExplTagDec0, 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->version))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->message_type))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SAFE_BODY(dd0, 0, &(val)->safe_body))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(pExplTagDec0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, pExplTagDec0, pbExplTagDataEnd0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SAFE_MESSAGE(KERB_SAFE_MESSAGE *val)
{
    if (val) {
        ASN1Free_KERB_SAFE_BODY(&(val)->safe_body);
        ASN1Free_KERB_CHECKSUM(&(val)->checksum);
    }
}

static int ASN1CALL ASN1Enc_PA_S4U_X509_USER(ASN1encoding_t enc, ASN1uint32_t tag, PA_S4U_X509_USER *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_S4UUserID(enc, 0, &(val)->user_id))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_CHECKSUM(enc, 0, &(val)->checksum))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_PA_S4U_X509_USER(ASN1decoding_t dec, ASN1uint32_t tag, PA_S4U_X509_USER *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_S4UUserID(dd0, 0, &(val)->user_id))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_CHECKSUM(dd0, 0, &(val)->checksum))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_PA_S4U_X509_USER(PA_S4U_X509_USER *val)
{
    if (val) {
        ASN1Free_S4UUserID(&(val)->user_id);
        ASN1Free_KERB_CHECKSUM(&(val)->checksum);
    }
}

static int ASN1CALL ASN1Enc_PA_FX_FAST_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, PA_FX_FAST_REQUEST *val)
{
    ASN1uint32_t nLenOff0;
    switch ((val)->choice) {
    case 1:
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_KrbFastArmoredReq(enc, 0, &(val)->u.armored_data))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    default:
        /* impossible */
        ASN1EncSetError(enc, ASN1_ERR_CHOICE);
        return 0;
    }
    return 1;
}

static int ASN1CALL ASN1Dec_PA_FX_FAST_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, PA_FX_FAST_REQUEST *val)
{
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecPeekTag(dec, &t))
        return 0;
    switch (t) {
    case 0x80000000:
        (val)->choice = 1;
        if (!ASN1BERDecExplicitTag(dec, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KrbFastArmoredReq(dd0, 0, &(val)->u.armored_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    default:
        ASN1DecSetError(dec, ASN1_ERR_CORRUPT);
        return 0;
    }
    return 1;
}

static void ASN1CALL ASN1Free_PA_FX_FAST_REQUEST(PA_FX_FAST_REQUEST *val)
{
    if (val) {
        switch ((val)->choice) {
        case 1:
            ASN1Free_KrbFastArmoredReq(&(val)->u.armored_data);
            break;
        }
    }
}

static int ASN1CALL ASN1Enc_PA_FX_FAST_REPLY(ASN1encoding_t enc, ASN1uint32_t tag, PA_FX_FAST_REPLY *val)
{
    ASN1uint32_t nLenOff0;
    switch ((val)->choice) {
    case 1:
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_KrbFastArmoredRep(enc, 0, &(val)->u.armored_data))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    default:
        /* impossible */
        ASN1EncSetError(enc, ASN1_ERR_CHOICE);
        return 0;
    }
    return 1;
}

static int ASN1CALL ASN1Dec_PA_FX_FAST_REPLY(ASN1decoding_t dec, ASN1uint32_t tag, PA_FX_FAST_REPLY *val)
{
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecPeekTag(dec, &t))
        return 0;
    switch (t) {
    case 0x80000000:
        (val)->choice = 1;
        if (!ASN1BERDecExplicitTag(dec, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KrbFastArmoredRep(dd0, 0, &(val)->u.armored_data))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    default:
        ASN1DecSetError(dec, ASN1_ERR_CORRUPT);
        return 0;
    }
    return 1;
}

static void ASN1CALL ASN1Free_PA_FX_FAST_REPLY(PA_FX_FAST_REPLY *val)
{
    if (val) {
        switch ((val)->choice) {
        case 1:
            ASN1Free_KrbFastArmoredRep(&(val)->u.armored_data);
            break;
        }
    }
}

static int ASN1CALL ASN1Enc_KrbFastResponse(ASN1encoding_t enc, ASN1uint32_t tag, KrbFastResponse *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1Enc_KrbFastResponse_padata(enc, 0, &(val)->padata))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_EncryptionKey(enc, 0, &(val)->strengthen_key))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1Enc_KrbFastFinished(enc, 0, &(val)->finished))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
        return 0;
    if (!ASN1BEREncS32(enc, 0x2, (val)->nonce))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KrbFastResponse(ASN1decoding_t dec, ASN1uint32_t tag, KrbFastResponse *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1Dec_KrbFastResponse_padata(dd, 0, &(val)->padata))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_EncryptionKey(dd0, 0, &(val)->strengthen_key))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KrbFastFinished(dd0, 0, &(val)->finished))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
        return 0;
    if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->nonce))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KrbFastResponse(KrbFastResponse *val)
{
    if (val) {
        ASN1Free_KrbFastResponse_padata(&(val)->padata);
        if ((val)->o[0] & 0x80) {
            ASN1Free_EncryptionKey(&(val)->strengthen_key);
        }
        if ((val)->o[0] & 0x40) {
            ASN1Free_KrbFastFinished(&(val)->finished);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_AUTH_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AUTH_PACKAGE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_PK_AUTHENTICATOR(enc, 0, &(val)->pk_authenticator))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_SUBJECT_PUBLIC_KEY_INFO(enc, 0, &(val)->client_public_value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AUTH_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AUTH_PACKAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_PK_AUTHENTICATOR(dd0, 0, &(val)->pk_authenticator))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_SUBJECT_PUBLIC_KEY_INFO(dd0, 0, &(val)->client_public_value))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AUTH_PACKAGE(KERB_AUTH_PACKAGE *val)
{
    if (val) {
        ASN1Free_KERB_PK_AUTHENTICATOR(&(val)->pk_authenticator);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_SUBJECT_PUBLIC_KEY_INFO(&(val)->client_public_value);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_AUTH_PACKAGE2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AUTH_PACKAGE2 *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_PKAuthenticator(enc, 0, &(val)->pkAuthenticator))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_SUBJECT_PUBLIC_KEY_INFO(enc, 0, &(val)->clientPublicValue))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1Enc_KERB_AUTH_PACKAGE2_supportedCMSTypes(enc, 0, &(val)->supportedCMSTypes))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->clientDHNonce).length, ((val)->clientDHNonce).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AUTH_PACKAGE2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AUTH_PACKAGE2 *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_PKAuthenticator(dd0, 0, &(val)->pkAuthenticator))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_SUBJECT_PUBLIC_KEY_INFO(dd0, 0, &(val)->clientPublicValue))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1Dec_KERB_AUTH_PACKAGE2_supportedCMSTypes(dd, 0, &(val)->supportedCMSTypes))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->clientDHNonce))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AUTH_PACKAGE2(KERB_AUTH_PACKAGE2 *val)
{
    if (val) {
        ASN1Free_PKAuthenticator(&(val)->pkAuthenticator);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_SUBJECT_PUBLIC_KEY_INFO(&(val)->clientPublicValue);
        }
        if ((val)->o[0] & 0x40) {
            ASN1Free_KERB_AUTH_PACKAGE2_supportedCMSTypes(&(val)->supportedCMSTypes);
        }
        if ((val)->o[0] & 0x20) {
            ASN1octetstring_free(&(val)->clientDHNonce);
        }
    }
}

static int ASN1CALL ASN1Enc_TD_DH_PARAMETERS(ASN1encoding_t enc, ASN1uint32_t tag, PTD_DH_PARAMETERS *val)
{
    PTD_DH_PARAMETERS f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_ALGORITHM_IDENTIFIER(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_TD_DH_PARAMETERS(ASN1decoding_t dec, ASN1uint32_t tag, PTD_DH_PARAMETERS *val)
{
    PTD_DH_PARAMETERS *f;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PTD_DH_PARAMETERS)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_ALGORITHM_IDENTIFIER(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_TD_DH_PARAMETERS(PTD_DH_PARAMETERS *val)
{
    PTD_DH_PARAMETERS f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_ALGORITHM_IDENTIFIER(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REP(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REP *val)
{
    ASN1uint32_t nLenOff0;
    switch ((val)->choice) {
    case 1:
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_DHRepInfo(enc, 0, &(val)->u.dhInfo))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    case 2:
        if (!ASN1DEREncOctetString(enc, 0x80000001, ((val)->u.key_package).length, ((val)->u.key_package).value))
            return 0;
        break;
    default:
        /* impossible */
        ASN1EncSetError(enc, ASN1_ERR_CHOICE);
        return 0;
    }
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REP(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REP *val)
{
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecPeekTag(dec, &t))
        return 0;
    switch (t) {
    case 0x80000000:
        (val)->choice = 1;
        if (!ASN1BERDecExplicitTag(dec, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_DHRepInfo(dd0, 0, &(val)->u.dhInfo))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    case 0x80000001:
        (val)->choice = 2;
        if (!ASN1BERDecOctetString(dec, 0x80000001, &(val)->u.key_package))
            return 0;
        break;
    default:
        ASN1DecSetError(dec, ASN1_ERR_CORRUPT);
        return 0;
    }
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REP(KERB_PA_PK_AS_REP *val)
{
    if (val) {
        switch ((val)->choice) {
        case 1:
            ASN1Free_DHRepInfo(&(val)->u.dhInfo);
            break;
        case 2:
            ASN1octetstring_free(&(val)->u.key_package);
            break;
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_SIGNED_REPLY_KEY_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNED_REPLY_KEY_PACKAGE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_REPLY_KEY_PACKAGE2(enc, 0, &(val)->reply_key_package))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SIGNATURE(enc, 0, &(val)->reply_key_signature))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SIGNED_REPLY_KEY_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNED_REPLY_KEY_PACKAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_REPLY_KEY_PACKAGE2(dd0, 0, &(val)->reply_key_package))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SIGNATURE(dd0, 0, &(val)->reply_key_signature))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SIGNED_REPLY_KEY_PACKAGE(KERB_SIGNED_REPLY_KEY_PACKAGE *val)
{
    if (val) {
        ASN1Free_KERB_REPLY_KEY_PACKAGE2(&(val)->reply_key_package);
        ASN1Free_KERB_SIGNATURE(&(val)->reply_key_signature);
    }
}

static int ASN1CALL ASN1Enc_KERB_SIGNED_KDC_PUBLIC_VALUE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNED_KDC_PUBLIC_VALUE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SUBJECT_PUBLIC_KEY_INFO(enc, 0, &(val)->kdc_public_value))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SIGNATURE(enc, 0, &(val)->kdc_public_value_sig))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SIGNED_KDC_PUBLIC_VALUE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNED_KDC_PUBLIC_VALUE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SUBJECT_PUBLIC_KEY_INFO(dd0, 0, &(val)->kdc_public_value))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SIGNATURE(dd0, 0, &(val)->kdc_public_value_sig))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SIGNED_KDC_PUBLIC_VALUE(KERB_SIGNED_KDC_PUBLIC_VALUE *val)
{
    if (val) {
        ASN1Free_KERB_SUBJECT_PUBLIC_KEY_INFO(&(val)->kdc_public_value);
        ASN1Free_KERB_SIGNATURE(&(val)->kdc_public_value_sig);
    }
}

static int ASN1CALL ASN1Enc_KERB_SIGNED_AUTH_PACKAGE(ASN1encoding_t enc, ASN1uint32_t tag, KERB_SIGNED_AUTH_PACKAGE *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_AUTH_PACKAGE(enc, 0, &(val)->auth_package))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SIGNATURE(enc, 0, &(val)->auth_package_signature))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_SIGNED_AUTH_PACKAGE(ASN1decoding_t dec, ASN1uint32_t tag, KERB_SIGNED_AUTH_PACKAGE *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_AUTH_PACKAGE(dd0, 0, &(val)->auth_package))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SIGNATURE(dd0, 0, &(val)->auth_package_signature))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_SIGNED_AUTH_PACKAGE(KERB_SIGNED_AUTH_PACKAGE *val)
{
    if (val) {
        ASN1Free_KERB_AUTH_PACKAGE(&(val)->auth_package);
        ASN1Free_KERB_SIGNATURE(&(val)->auth_package_signature);
    }
}

static int ASN1CALL ASN1Enc_KERB_TRUSTED_CAS(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TRUSTED_CAS *val)
{
    ASN1uint32_t nLenOff0;
    switch ((val)->choice) {
    case 1:
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_KERBEROS_NAME(enc, 0, &(val)->u.principal_name))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    case 2:
        if (!ASN1DEREncOctetString(enc, 0x80000001, ((val)->u.ca_name).length, ((val)->u.ca_name).value))
            return 0;
        break;
    case 3:
        if (!ASN1DEREncOctetString(enc, 0x80000002, ((val)->u.issuer_and_serial).length, ((val)->u.issuer_and_serial).value))
            return 0;
        break;
    default:
        /* impossible */
        ASN1EncSetError(enc, ASN1_ERR_CHOICE);
        return 0;
    }
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TRUSTED_CAS(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TRUSTED_CAS *val)
{
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecPeekTag(dec, &t))
        return 0;
    switch (t) {
    case 0x80000000:
        (val)->choice = 1;
        if (!ASN1BERDecExplicitTag(dec, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_KERBEROS_NAME(dd0, 0, &(val)->u.principal_name))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    case 0x80000001:
        (val)->choice = 2;
        if (!ASN1BERDecOctetString(dec, 0x80000001, &(val)->u.ca_name))
            return 0;
        break;
    case 0x80000002:
        (val)->choice = 3;
        if (!ASN1BERDecOctetString(dec, 0x80000002, &(val)->u.issuer_and_serial))
            return 0;
        break;
    default:
        ASN1DecSetError(dec, ASN1_ERR_CORRUPT);
        return 0;
    }
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TRUSTED_CAS(KERB_TRUSTED_CAS *val)
{
    if (val) {
        switch ((val)->choice) {
        case 1:
            ASN1Free_KERB_KERBEROS_NAME(&(val)->u.principal_name);
            break;
        case 2:
            ASN1octetstring_free(&(val)->u.ca_name);
            break;
        case 3:
            ASN1octetstring_free(&(val)->u.issuer_and_serial);
            break;
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ_trusted_certifiers(ASN1encoding_t enc, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ_trusted_certifiers *val)
{
    ASN1uint32_t nLenOff0;
    PKERB_PA_PK_AS_REQ_trusted_certifiers f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x80000002, &nLenOff0))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1Enc_KERB_TRUSTED_CAS(enc, 0, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ_trusted_certifiers(ASN1decoding_t dec, ASN1uint32_t tag, PKERB_PA_PK_AS_REQ_trusted_certifiers *val)
{
    PKERB_PA_PK_AS_REQ_trusted_certifiers *f;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x80000002, &dd0, &di0))
        return 0;
    if (!ASN1BERDecExplicitTag(dd0, 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PKERB_PA_PK_AS_REQ_trusted_certifiers)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1Dec_KERB_TRUSTED_CAS(dd, 0, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dd0, dd, di))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ_trusted_certifiers(PKERB_PA_PK_AS_REQ_trusted_certifiers *val)
{
    PKERB_PA_PK_AS_REQ_trusted_certifiers f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1Free_KERB_TRUSTED_CAS(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_AS_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_AS_REQUEST *val)
{
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000000a, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REQUEST(enc, 0, val))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_AS_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_AS_REQUEST *val)
{
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000000a, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REQUEST(dd0, 0, val))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_AS_REQUEST(KERB_AS_REQUEST *val)
{
    if (val) {
        ASN1Free_KERB_KDC_REQUEST(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_TGS_REQUEST(ASN1encoding_t enc, ASN1uint32_t tag, KERB_TGS_REQUEST *val)
{
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x4000000c, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_KDC_REQUEST(enc, 0, val))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_TGS_REQUEST(ASN1decoding_t dec, ASN1uint32_t tag, KERB_TGS_REQUEST *val)
{
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x4000000c, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_KDC_REQUEST(dd0, 0, val))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd0, di0))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_TGS_REQUEST(KERB_TGS_REQUEST *val)
{
    if (val) {
        ASN1Free_KERB_KDC_REQUEST(val);
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REP2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REP2 *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_ENCRYPTED_DATA(enc, 0, &(val)->key_package))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_ENVELOPED_KEY_PACKAGE(enc, 0, &(val)->temp_key_package))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1Enc_KERB_SIGNED_KDC_PUBLIC_VALUE(enc, 0, &(val)->signed_kdc_public_value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1Enc_KERB_PA_PK_AS_REP2_kdc_cert(enc, 0, &(val)->kdc_cert))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REP2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REP2 *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000000) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_ENCRYPTED_DATA(dd0, 0, &(val)->key_package))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_ENVELOPED_KEY_PACKAGE(dd0, 0, &(val)->temp_key_package))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1Dec_KERB_SIGNED_KDC_PUBLIC_VALUE(dd0, 0, &(val)->signed_kdc_public_value))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1Dec_KERB_PA_PK_AS_REP2_kdc_cert(dd, 0, &(val)->kdc_cert))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REP2(KERB_PA_PK_AS_REP2 *val)
{
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_ENCRYPTED_DATA(&(val)->key_package);
        }
        ASN1Free_KERB_ENVELOPED_KEY_PACKAGE(&(val)->temp_key_package);
        if ((val)->o[0] & 0x40) {
            ASN1Free_KERB_SIGNED_KDC_PUBLIC_VALUE(&(val)->signed_kdc_public_value);
        }
        if ((val)->o[0] & 0x20) {
            ASN1Free_KERB_PA_PK_AS_REP2_kdc_cert(&(val)->kdc_cert);
        }
    }
}

static int ASN1CALL ASN1Enc_KERB_PA_PK_AS_REQ2(ASN1encoding_t enc, ASN1uint32_t tag, KERB_PA_PK_AS_REQ2 *val)
{
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_KERB_SIGNED_AUTH_PACKAGE(enc, 0, &(val)->signed_auth_pack))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1Enc_KERB_PA_PK_AS_REQ2_user_certs(enc, 0, &(val)->user_certs))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1Enc_KERB_PA_PK_AS_REQ2_trusted_certifiers(enc, 0, &(val)->trusted_certifiers))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1BEREncS32(enc, 0x2, (val)->serial_number))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_KERB_PA_PK_AS_REQ2(ASN1decoding_t dec, ASN1uint32_t tag, KERB_PA_PK_AS_REQ2 *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t *di0 = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_KERB_SIGNED_AUTH_PACKAGE(dd0, 0, &(val)->signed_auth_pack))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1Dec_KERB_PA_PK_AS_REQ2_user_certs(dd, 0, &(val)->user_certs))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1Dec_KERB_PA_PK_AS_REQ2_trusted_certifiers(dd, 0, &(val)->trusted_certifiers))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecS32Val(dd0, 0x2, &(val)->serial_number))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_KERB_PA_PK_AS_REQ2(KERB_PA_PK_AS_REQ2 *val)
{
    if (val) {
        ASN1Free_KERB_SIGNED_AUTH_PACKAGE(&(val)->signed_auth_pack);
        if ((val)->o[0] & 0x80) {
            ASN1Free_KERB_PA_PK_AS_REQ2_user_certs(&(val)->user_certs);
        }
        if ((val)->o[0] & 0x40) {
            ASN1Free_KERB_PA_PK_AS_REQ2_trusted_certifiers(&(val)->trusted_certifiers);
        }
    }
}