#ifndef __ASN1_TSSSP_H__
#define __ASN1_TSSSP_H__

#include "asn1_base.h"

#define ASN1_PDU_TSPASSWORDCREDS			0
#define ASN1_PDU_TSSMARTCARDCREDS			1
#define ASN1_PDU_TSCREDENTIALS				2
#define ASN1_PDU_TSREQUEST					3
#define ASN1_PDU_TSREMOTEGUARDCREDS			4
#define ASN1_PDU_TSREMOTEGUARDINNERPACKET	5

/*

TSRequest ::= SEQUENCE {
	version     [0] INTEGER,
	negoTokens  [1] NegoData OPTIONAL,
	authInfo    [2] OCTET STRING OPTIONAL,
	pubKeyAuth  [3] OCTET STRING OPTIONAL,
	errorCode   [4] INTEGER OPTIONAL,
	clientNonce [5] OCTET STRING OPTIONAL
}

NegoData ::= SEQUENCE OF SEQUENCE {
	negoToken	[0] OCTET STRING
}

*/

typedef struct _NegoData
{
	struct _NegoData* Next;
	ASN1octetstring_t NegoToken;
} NegoData;

#define TSREQUEST_HAS_NEGOTOKENS	0x80
#define TSREQUEST_HAS_AUTHINFO		0x40
#define TSREQUEST_HAS_PUBKEYAUTH	0x20
#define TSREQUEST_HAS_ERRORCODE		0x10
#define TSREQUEST_HAS_CLIENTNONCE	0x08

typedef struct _TSRequest
{
	ASN1uint8_t Flags;
	ASN1int32_t Version;
	NegoData* NegoTokens;
	ASN1octetstring_t AuthInfo;
	ASN1octetstring_t PubKeyAuth;
	ASN1int32_t ErrorCode;
	ASN1octetstring_t ClientNonce;
} TSRequest;

/*

TSCredentials ::= SEQUENCE {
	credType	[0] INTEGER,
	credentials	[1] OCTET STRING
}

*/

typedef enum _TSCREDENTIAL_TYPE
{
	TsCredTypePassword = 1,
	TsCredTypeSmartCard = 2,
	TsCredTypeLoopback = 4,
	TsCredTypeRemoteGuard = 6,
} TSCREDENTIAL_TYPE;

typedef struct _TSCredentials
{
	ASN1int32_t CredType;
	ASN1octetstring_t Credentials;
} TSCredentials;

/*

TSPasswordCreds ::= SEQUENCE {
	domainName  [0] OCTET STRING,
	userName    [1] OCTET STRING,
	password    [2] OCTET STRING
}

*/

typedef struct _TSPasswordCreds
{
	ASN1octetstring_t DomainName;
	ASN1octetstring_t UserName;
	ASN1octetstring_t Password;
} TSPasswordCreds;

/*

TSCspDataDetail ::= SEQUENCE {
	keySpec       [0] INTEGER,
	cardName      [1] OCTET STRING OPTIONAL,
	readerName    [2] OCTET STRING OPTIONAL,
	containerName [3] OCTET STRING OPTIONAL,
	cspName       [4] OCTET STRING OPTIONAL
}

TSSmartCardCreds ::= SEQUENCE {
	pin         [0] OCTET STRING,
	cspData     [1] TSCspDataDetail,
	userHint    [2] OCTET STRING OPTIONAL,
	domainHint  [3] OCTET STRING OPTIONAL
}

*/

typedef struct _TSCspDataDetail
{
	ASN1int32_t KeySpec;
	ASN1octetstring_t CardName;
	ASN1octetstring_t ReaderName;
	ASN1octetstring_t ContainerName;
	ASN1octetstring_t CspName;
} TSCspDataDetail;

typedef struct _TSSmartCardCreds // Structure size is wrong, should be 128 (not 120)
{
	ASN1octetstring_t Pin;
	TSCspDataDetail CspData;
	ASN1octetstring_t UserHint;
	ASN1octetstring_t DomainHint;
} TSSmartCardCreds;

/*

TSRemoteGuardPackageCred ::= SEQUENCE{
	packageName [0] OCTET STRING,
	credBuffer  [1] OCTET STRING
}

TSRemoteGuardCreds ::= SEQUENCE{
	logonCred           [0] TSRemoteGuardPackageCred,
	supplementalCreds   [1] SEQUENCE OF TSRemoteGuardPackageCred OPTIONAL
}

*/

typedef struct _TSRemoteGuardPackageCred
{
	ASN1octetstring_t PackageName;
	ASN1octetstring_t CredBuffer;
} TSRemoteGuardPackageCred;

typedef struct _TSRemoteGuardCreds_supplementalCreds
{
	struct _TSRemoteGuardCreds_supplementalCreds* Next;
	TSRemoteGuardPackageCred Value;
} TSRemoteGuardCreds_supplementalCreds, *PTSRemoteGuardCreds_supplementalCreds;

#define TSREMOTEGUARDCREDS_HAS_SUPPLEMENTAL_CREDS 0x80

typedef struct _TSRemoteGuardCreds
{
	ASN1uint8_t Flags;
	TSRemoteGuardPackageCred LogonCred;
	TSRemoteGuardCreds_supplementalCreds* SupplementalCreds;
} TSRemoteGuardCreds;

/*

TSRemoteGuardVersion ::= ENUMERATED {
	tsremoteguardv1 (0)
}

TSRemoteGuardInnerPacket ::= SEQUENCE {
	version		[0] TSRemoteGuardVersion DEFAULT tsremoteguardv1,
	packageName [1] OCTETSTRINGNOCOPY,
	buffer		[2] OCTETSTRINGNOCOPY,
	extension	[3] ANYNOCOPY OPTIONAL, -- future extension point
	...
}

*/

typedef enum _TSRemoteGuardVersion
{
	TsRemoteGuardv1 = 0,
} TSRemoteGuardVersion;

#define TSREMOTEGUARDINNERPACKET_HAS_VERSION	0x80
#define TSREMOTEGUARDINNERPACKET_HAS_EXTENSION	0x40

typedef struct _TSRemoteGuardInnerPacket
{
	ASN1uint8_t Flags;
	TSRemoteGuardVersion Version;
	ASN1octetstring_t PackageName;
	ASN1octetstring_t Buffer;
	ASN1open_t Extension;
} TSRemoteGuardInnerPacket;

BOOL ASN1CALL asn1_startup_tsssp();
void ASN1CALL asn1_cleanup_tsssp();

BOOL asn1_encode_tsssp(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData);
BOOL asn1_decode_tsssp(LPCVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct);
BOOL asn1_free_tsssp(PVOID pDataStruct, DWORD dwPdu);

#endif