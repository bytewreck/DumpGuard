#include "asn1_gssapi.h"

ASN1module_t GSSAPI_Module = NULL;

static int ASN1CALL ASN1Enc_InitialContextToken(ASN1encoding_t enc, ASN1uint32_t tag, InitialContextToken *val);
static int ASN1CALL ASN1Dec_InitialContextToken(ASN1decoding_t dec, ASN1uint32_t tag, InitialContextToken *val);
static void ASN1CALL ASN1Free_InitialContextToken(InitialContextToken *val);

typedef ASN1BerEncFun_t ASN1EncFun_t;
static const ASN1EncFun_t encfntab[1] = {
    (ASN1EncFun_t) ASN1Enc_InitialContextToken,
};
typedef ASN1BerDecFun_t ASN1DecFun_t;
static const ASN1DecFun_t decfntab[1] = {
    (ASN1DecFun_t) ASN1Dec_InitialContextToken,
};
static const ASN1FreeFun_t freefntab[1] = {
    (ASN1FreeFun_t) ASN1Free_InitialContextToken,
};
static const ULONG sizetab[1] = {
    SIZE_GSSAPI_Module_PDU_0,
};

BOOL ASN1CALL asn1_startup_gssapi()
{
    return (GSSAPI_Module = ASN1_CreateModule(0x10000, ASN1_BER_RULE_DER, ASN1FLAGS_NOASSERT, 1, (const ASN1GenericFun_t*)encfntab, (const ASN1GenericFun_t*)decfntab, freefntab, sizetab, 0x61737367)) != 0;
}

void ASN1CALL asn1_cleanup_gssapi()
{
    ASN1_CloseModule(GSSAPI_Module);
    GSSAPI_Module = NULL;
}

BOOL asn1_encode_gssapi(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData)
{
    BOOL Result = FALSE;

    if (GSSAPI_Module != NULL)
    {
        ASN1encoding_t Encoder = NULL;

        if (ASN1_CreateEncoder(GSSAPI_Module, &Encoder, NULL, 0, NULL) == ASN1_SUCCESS && Encoder != NULL)
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

BOOL asn1_decode_gssapi(LPCVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct)
{
    BOOL Result = FALSE;

    if (GSSAPI_Module != NULL)
    {
        ASN1decoding_t Decoder = NULL;

        if (ASN1_CreateDecoder(GSSAPI_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
        {
            Result = ASN1_Decode(Decoder, ppDataStruct, dwPdu, ASN1DECODE_SETBUFFER, (ASN1octet_t*)pvData, (ASN1uint32_t)cbData) >= 0;
            ASN1_CloseDecoder(Decoder);
        }
    }

    return Result;
}

BOOL asn1_free_gssapi(PVOID pDataStruct, DWORD dwPdu)
{
    BOOL Result = FALSE;

    if (GSSAPI_Module != NULL)
    {
        ASN1decoding_t Decoder = NULL;
        if (ASN1_CreateDecoder(GSSAPI_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
        {
            ASN1_FreeDecoded(Decoder, pDataStruct, dwPdu);
            ASN1_CloseDecoder(Decoder);
        }
    }

    return Result;
}

static int ASN1CALL ASN1Enc_InitialContextToken(ASN1encoding_t enc, ASN1uint32_t tag, InitialContextToken *val)
{
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000000, &nLenOff))
        return 0;
    if (!ASN1BEREncObjectIdentifier(enc, 0x6, &(val)->thisMech))
        return 0;
    
    *(ASN1uint16_t*)enc->pos = (val)->tokId;
    enc->pos += sizeof(ASN1uint16_t);

    if (!ASN1BEREncOpenType(enc, &(val)->innerToken))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_InitialContextToken(ASN1decoding_t dec, ASN1uint32_t tag, InitialContextToken *val)
{
    ASN1decoding_t dd = 0;
    ASN1octet_t *di = 0;
    
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000000, &dd, &di))
        return 0;
    if (!ASN1BERDecObjectIdentifier(dd, 0x6, &(val)->thisMech))
        return 0;

    (val)->tokId = *(ASN1uint16_t*)dd->pos;
    dd->pos += sizeof(ASN1uint16_t);

    if (!ASN1BERDecOpenType(dd, &(val)->innerToken))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_InitialContextToken(InitialContextToken *val)
{
    if (val) {
        ASN1objectidentifier_free(&(val)->thisMech);
        ASN1open_free(&(val)->innerToken);
    }
}