// Copyright (C) 2024 Evan McBroom
//
// [MS-SPNG]: Simple and Protected GSS-API Negotiation Mechanism (SPNEGO) Extension
//
#include "asn1_spnego.h"

ASN1module_t SPNEGO_Module = NULL;

static int ASN1CALL ASN1Enc_SavedMechTypeList(ASN1encoding_t enc, ASN1uint32_t tag, SavedMechTypeList* val);
static int ASN1CALL ASN1Enc_MechTypeList(ASN1encoding_t enc, ASN1uint32_t tag, PMechTypeList* val);
static int ASN1CALL ASN1Enc_NegHints(ASN1encoding_t enc, ASN1uint32_t tag, NegHints* val);
static int ASN1CALL ASN1Enc_NegTokenInit(ASN1encoding_t enc, ASN1uint32_t tag, NegTokenInit* val);
static int ASN1CALL ASN1Enc_NegTokenInit2(ASN1encoding_t enc, ASN1uint32_t tag, NegTokenInit2* val);
static int ASN1CALL ASN1Enc_NegTokenTarg(ASN1encoding_t enc, ASN1uint32_t tag, NegTokenTarg* val);
static int ASN1CALL ASN1Enc_NegotiationToken(ASN1encoding_t enc, ASN1uint32_t tag, NegotiationToken* val);
static int ASN1CALL ASN1Enc_InitialNegToken(ASN1encoding_t enc, ASN1uint32_t tag, InitialNegToken* val);
static int ASN1CALL ASN1Dec_SavedMechTypeList(ASN1decoding_t dec, ASN1uint32_t tag, SavedMechTypeList* val);
static int ASN1CALL ASN1Dec_MechTypeList(ASN1decoding_t dec, ASN1uint32_t tag, PMechTypeList* val);
static int ASN1CALL ASN1Dec_NegHints(ASN1decoding_t dec, ASN1uint32_t tag, NegHints* val);
static int ASN1CALL ASN1Dec_NegTokenInit(ASN1decoding_t dec, ASN1uint32_t tag, NegTokenInit* val);
static int ASN1CALL ASN1Dec_NegTokenInit2(ASN1decoding_t dec, ASN1uint32_t tag, NegTokenInit2* val);
static int ASN1CALL ASN1Dec_NegTokenTarg(ASN1decoding_t dec, ASN1uint32_t tag, NegTokenTarg* val);
static int ASN1CALL ASN1Dec_NegotiationToken(ASN1decoding_t dec, ASN1uint32_t tag, NegotiationToken* val);
static int ASN1CALL ASN1Dec_InitialNegToken(ASN1decoding_t dec, ASN1uint32_t tag, InitialNegToken* val);
static void ASN1CALL ASN1Free_SavedMechTypeList(SavedMechTypeList* val);
static void ASN1CALL ASN1Free_MechTypeList(PMechTypeList* val);
static void ASN1CALL ASN1Free_NegHints(NegHints* val);
static void ASN1CALL ASN1Free_NegTokenInit(NegTokenInit* val);
static void ASN1CALL ASN1Free_NegTokenInit2(NegTokenInit2* val);
static void ASN1CALL ASN1Free_NegTokenTarg(NegTokenTarg* val);
static void ASN1CALL ASN1Free_NegotiationToken(NegotiationToken* val);
static void ASN1CALL ASN1Free_InitialNegToken(InitialNegToken* val);

typedef ASN1BerEncFun_t ASN1EncFun_t;
static const ASN1EncFun_t encfntab[3] = {
    (ASN1EncFun_t)ASN1Enc_SavedMechTypeList,
    (ASN1EncFun_t)ASN1Enc_NegotiationToken,
    (ASN1EncFun_t)ASN1Enc_InitialNegToken,
};
typedef ASN1BerDecFun_t ASN1DecFun_t;
static const ASN1DecFun_t decfntab[3] = {
    (ASN1DecFun_t)ASN1Dec_SavedMechTypeList,
    (ASN1DecFun_t)ASN1Dec_NegotiationToken,
    (ASN1DecFun_t)ASN1Dec_InitialNegToken,
};
static const ASN1FreeFun_t freefntab[3] = {
    (ASN1FreeFun_t)ASN1Free_SavedMechTypeList,
    (ASN1FreeFun_t)ASN1Free_NegotiationToken,
    (ASN1FreeFun_t)ASN1Free_InitialNegToken,
};
static const ULONG sizetab[3] = {
    SIZE_SPNEGO_Module_PDU_0,
    SIZE_SPNEGO_Module_PDU_1,
    SIZE_SPNEGO_Module_PDU_2,
};

BOOL ASN1CALL asn1_startup_spnego()
{
    return (SPNEGO_Module = ASN1_CreateModule(0x10000, ASN1_BER_RULE_DER, ASN1FLAGS_NOASSERT, 3, (const ASN1GenericFun_t*)encfntab, (const ASN1GenericFun_t*)decfntab, freefntab, sizetab, 0x656e7073)) != NULL;
}

void ASN1CALL asn1_cleanup_spnego() {
    ASN1_CloseModule(SPNEGO_Module);
    SPNEGO_Module = NULL;
}

BOOL asn1_encode_spnego(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData)
{
    BOOL Result = FALSE;

    if (SPNEGO_Module != NULL)
    {
        ASN1encoding_t Encoder = NULL;

        if (ASN1_CreateEncoder(SPNEGO_Module, &Encoder, NULL, 0, NULL) == ASN1_SUCCESS && Encoder != NULL)
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

BOOL asn1_decode_spnego(LPCVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct)
{
    BOOL Result = FALSE;

    if (SPNEGO_Module != NULL)
    {
        ASN1decoding_t Decoder = NULL;

        if (ASN1_CreateDecoder(SPNEGO_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
        {
            Result = ASN1_Decode(Decoder, ppDataStruct, dwPdu, ASN1DECODE_SETBUFFER, (ASN1octet_t*)pvData, (ASN1uint32_t)cbData) >= 0;
            ASN1_CloseDecoder(Decoder);
        }
    }

    return Result;
}

BOOL asn1_free_spnego(PVOID pDataStruct, DWORD dwPdu)
{
    BOOL Result = FALSE;

    if (SPNEGO_Module != NULL)
    {
        ASN1decoding_t Decoder = NULL;

        if (ASN1_CreateDecoder(SPNEGO_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
        {
            ASN1_FreeDecoded(Decoder, pDataStruct, dwPdu);
            ASN1_CloseDecoder(Decoder);
        }
    }

    return Result;
}

static int ASN1CALL ASN1Enc_SavedMechTypeList(ASN1encoding_t enc, ASN1uint32_t tag, SavedMechTypeList* val) {
    if (!ASN1Enc_MechTypeList(enc, tag, val))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_SavedMechTypeList(ASN1decoding_t dec, ASN1uint32_t tag, SavedMechTypeList* val) {
    if (!ASN1Dec_MechTypeList(dec, tag, val))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_SavedMechTypeList(SavedMechTypeList* val) {
    if (val) {
        ASN1Free_MechTypeList(val);
    }
}

static int ASN1CALL ASN1Enc_MechTypeList(ASN1encoding_t enc, ASN1uint32_t tag, PMechTypeList* val) {
    PMechTypeList f;
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    for (f = *val; f; f = f->next) {
        if (!ASN1BEREncObjectIdentifier(enc, 0x6, &f->value))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_MechTypeList(ASN1decoding_t dec, ASN1uint32_t tag, PMechTypeList* val) {
    PMechTypeList* f;
    ASN1decoding_t dd = 0;
    ASN1octet_t* di = 0;
    ASN1uint32_t t = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    f = val;
    while (ASN1BERDecNotEndOfContents(dd, di)) {
        if (!ASN1BERDecPeekTag(dd, &t))
            return 0;
        if (!(*f = (PMechTypeList)ASN1DecAlloc(dd, sizeof(**f))))
            return 0;
        if (!ASN1BERDecObjectIdentifier(dd, 0x6, &(*f)->value))
            return 0;
        f = &(*f)->next;
    }
    *f = NULL;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_MechTypeList(PMechTypeList* val) {
    PMechTypeList f = 0, ff = 0;
    if (val) {
        for (f = *val; f; f = ff) {
            ASN1objectidentifier_free(&f->value);
            ff = f->next;
            ASN1Free(f);
        }
    }
}

static int ASN1CALL ASN1Enc_NegHints(ASN1encoding_t enc, ASN1uint32_t tag, NegHints* val) {
    ASN1uint32_t nLenOff;
    ASN1uint32_t t = 0;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        t = lstrlenA((val)->hintName);
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1DEREncCharString(enc, 0x1b, t, (val)->hintName))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->hintAddress).length, ((val)->hintAddress).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_NegHints(ASN1decoding_t dec, ASN1uint32_t tag, NegHints* val) {
    ASN1decoding_t dd = 0;
    ASN1octet_t* di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t* di0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000000) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1BERDecZeroCharString(dd0, 0x1b, &(val)->hintName))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->hintAddress))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_NegHints(NegHints* val) {
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1ztcharstring_free((val)->hintName);
        }
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->hintAddress);
        }
    }
}

static int ASN1CALL ASN1Enc_NegTokenInit(ASN1encoding_t enc, ASN1uint32_t tag, NegTokenInit* val) {
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t r;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
        return 0;
    if (!ASN1Enc_MechTypeList(enc, 0, &(val)->mechTypes))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff0))
        return 0;
    if ((val)->o[0] & 0x80) {
        r = ((val)->reqFlags).length;
        ASN1BEREncRemoveZeroBits(&r, ((val)->reqFlags).value);
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncBitString(enc, 0x3, r, ((val)->reqFlags).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->mechToken).length, ((val)->mechToken).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->mechListMIC).length, ((val)->mechListMIC).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_NegTokenInit(ASN1decoding_t dec, ASN1uint32_t tag, NegTokenInit* val) {
    ASN1decoding_t dd = 0;
    ASN1octet_t* di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t* di0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
        return 0;
    if (!ASN1Dec_MechTypeList(dd0, 0, &(val)->mechTypes))
        return 0;
    if (!ASN1BERDecEndOfContents(dd, dd0, di0))
        return 0;
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecBitString(dd0, 0x3, &(val)->reqFlags))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->mechToken))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->mechListMIC))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_NegTokenInit(NegTokenInit* val) {
    if (val) {
        ASN1Free_MechTypeList(&(val)->mechTypes);
        if ((val)->o[0] & 0x80) {
            ASN1bitstring_free(&(val)->reqFlags);
        }
        if ((val)->o[0] & 0x40) {
            ASN1octetstring_free(&(val)->mechToken);
        }
        if ((val)->o[0] & 0x20) {
            ASN1octetstring_free(&(val)->mechListMIC);
        }
    }
}

static int ASN1CALL ASN1Enc_NegTokenInit2(ASN1encoding_t enc, ASN1uint32_t tag, NegTokenInit2* val) {
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    ASN1uint32_t r;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_MechTypeList(enc, 0, &(val)->mechTypes))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        r = ((val)->reqFlags).length;
        ASN1BEREncRemoveZeroBits(&r, ((val)->reqFlags).value);
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1DEREncBitString(enc, 0x3, r, ((val)->reqFlags).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->mechToken).length, ((val)->mechToken).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1Enc_NegHints(enc, 0, &(val)->negHints))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x8) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000004, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->mechListMIC).length, ((val)->mechListMIC).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_NegTokenInit2(ASN1decoding_t dec, ASN1uint32_t tag, NegTokenInit2* val) {
    ASN1decoding_t dd = 0;
    ASN1octet_t* di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t* di0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000000) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_MechTypeList(dd0, 0, &(val)->mechTypes))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecBitString(dd0, 0x3, &(val)->reqFlags))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->mechToken))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1Dec_NegHints(dd0, 0, &(val)->negHints))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000004) {
        (val)->o[0] |= 0x8;
        if (!ASN1BERDecExplicitTag(dd, 0x80000004, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->mechListMIC))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_NegTokenInit2(NegTokenInit2* val) {
    if (val) {
        if ((val)->o[0] & 0x80) {
            ASN1Free_MechTypeList(&(val)->mechTypes);
        }
        if ((val)->o[0] & 0x40) {
            ASN1bitstring_free(&(val)->reqFlags);
        }
        if ((val)->o[0] & 0x20) {
            ASN1octetstring_free(&(val)->mechToken);
        }
        if ((val)->o[0] & 0x10) {
            ASN1Free_NegHints(&(val)->negHints);
        }
        if ((val)->o[0] & 0x8) {
            ASN1octetstring_free(&(val)->mechListMIC);
        }
    }
}

static int ASN1CALL ASN1Enc_NegTokenTarg(ASN1encoding_t enc, ASN1uint32_t tag, NegTokenTarg* val) {
    ASN1uint32_t nLenOff;
    ASN1uint32_t nLenOff0;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x10, &nLenOff))
        return 0;
    if ((val)->o[0] & 0x80) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1BEREncU32(enc, 0xa, (val)->negResult))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x40) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1BEREncObjectIdentifier(enc, 0x6, &(val)->supportedMech))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x20) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->responseToken).length, ((val)->responseToken).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if ((val)->o[0] & 0x10) {
        if (!ASN1BEREncExplicitTag(enc, 0x80000003, &nLenOff0))
            return 0;
        if (!ASN1DEREncOctetString(enc, 0x4, ((val)->mechListMIC).length, ((val)->mechListMIC).value))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
    }
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_NegTokenTarg(ASN1decoding_t dec, ASN1uint32_t tag, NegTokenTarg* val) {
    ASN1decoding_t dd = 0;
    ASN1octet_t* di = 0;
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t* di0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x10, &dd, &di))
        return 0;
    ZeroMemory((val)->o, 1);
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000000) {
        (val)->o[0] |= 0x80;
        if (!ASN1BERDecExplicitTag(dd, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1BERDecU32Val(dd0, 0xa, (ASN1uint32_t*)&(val)->negResult))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000001) {
        (val)->o[0] |= 0x40;
        if (!ASN1BERDecExplicitTag(dd, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1BERDecObjectIdentifier(dd0, 0x6, &(val)->supportedMech))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000002) {
        (val)->o[0] |= 0x20;
        if (!ASN1BERDecExplicitTag(dd, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->responseToken))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    ASN1BERDecPeekTag(dd, &t);
    if (t == 0x80000003) {
        (val)->o[0] |= 0x10;
        if (!ASN1BERDecExplicitTag(dd, 0x80000003, &dd0, &di0))
            return 0;
        if (!ASN1BERDecOctetString(dd0, 0x4, &(val)->mechListMIC))
            return 0;
        if (!ASN1BERDecEndOfContents(dd, dd0, di0))
            return 0;
    }
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_NegTokenTarg(NegTokenTarg* val) {
    if (val) {
        if ((val)->o[0] & 0x40) {
            ASN1objectidentifier_free(&(val)->supportedMech);
        }
        if ((val)->o[0] & 0x20) {
            ASN1octetstring_free(&(val)->responseToken);
        }
        if ((val)->o[0] & 0x10) {
            ASN1octetstring_free(&(val)->mechListMIC);
        }
    }
}

static int ASN1CALL ASN1Enc_NegotiationToken(ASN1encoding_t enc, ASN1uint32_t tag, NegotiationToken* val) {
    ASN1uint32_t nLenOff0;
    switch ((val)->choice) {
    case 1:
        if (!ASN1BEREncExplicitTag(enc, 0x80000000, &nLenOff0))
            return 0;
        if (!ASN1Enc_NegTokenInit(enc, 0, &(val)->u.negTokenInit))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    case 2:
        if (!ASN1BEREncExplicitTag(enc, 0x80000001, &nLenOff0))
            return 0;
        if (!ASN1Enc_NegTokenTarg(enc, 0, &(val)->u.negTokenTarg))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    case 3:
        if (!ASN1BEREncExplicitTag(enc, 0x80000002, &nLenOff0))
            return 0;
        if (!ASN1Enc_NegTokenInit2(enc, 0, &(val)->u.negTokenInit2))
            return 0;
        if (!ASN1BEREncEndOfContents(enc, nLenOff0))
            return 0;
        break;
    default:
        ASN1EncSetError(enc, ASN1_ERR_CHOICE);
        return 0;
    }
    return 1;
}

static int ASN1CALL ASN1Dec_NegotiationToken(ASN1decoding_t dec, ASN1uint32_t tag, NegotiationToken* val) {
    ASN1uint32_t t = 0;
    ASN1decoding_t dd0 = 0;
    ASN1octet_t* di0;
    if (!ASN1BERDecPeekTag(dec, &t))
        return 0;
    switch (t) {
    case 0x80000000:
        (val)->choice = 1;
        if (!ASN1BERDecExplicitTag(dec, 0x80000000, &dd0, &di0))
            return 0;
        if (!ASN1Dec_NegTokenInit(dd0, 0, &(val)->u.negTokenInit))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    case 0x80000001:
        (val)->choice = 2;
        if (!ASN1BERDecExplicitTag(dec, 0x80000001, &dd0, &di0))
            return 0;
        if (!ASN1Dec_NegTokenTarg(dd0, 0, &(val)->u.negTokenTarg))
            return 0;
        if (!ASN1BERDecEndOfContents(dec, dd0, di0))
            return 0;
        break;
    case 0x80000002:
        (val)->choice = 3;
        if (!ASN1BERDecExplicitTag(dec, 0x80000002, &dd0, &di0))
            return 0;
        if (!ASN1Dec_NegTokenInit2(dd0, 0, &(val)->u.negTokenInit2))
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

static void ASN1CALL ASN1Free_NegotiationToken(NegotiationToken* val) {
    if (val) {
        switch ((val)->choice) {
        case 1:
            ASN1Free_NegTokenInit(&(val)->u.negTokenInit);
            break;
        case 2:
            ASN1Free_NegTokenTarg(&(val)->u.negTokenTarg);
            break;
        case 3:
            ASN1Free_NegTokenInit2(&(val)->u.negTokenInit2);
            break;
        }
    }
}

static int ASN1CALL ASN1Enc_InitialNegToken(ASN1encoding_t enc, ASN1uint32_t tag, InitialNegToken* val) {
    ASN1uint32_t nLenOff;
    if (!ASN1BEREncExplicitTag(enc, tag ? tag : 0x40000000, &nLenOff))
        return 0;
    if (!ASN1BEREncObjectIdentifier(enc, 0x6, &(val)->spnegoMech))
        return 0;
    if (!ASN1Enc_NegotiationToken(enc, 0, &(val)->negToken))
        return 0;
    if (!ASN1BEREncEndOfContents(enc, nLenOff))
        return 0;
    return 1;
}

static int ASN1CALL ASN1Dec_InitialNegToken(ASN1decoding_t dec, ASN1uint32_t tag, InitialNegToken* val) {
    ASN1decoding_t dd = 0;
    ASN1octet_t* di = 0;
    if (!ASN1BERDecExplicitTag(dec, tag ? tag : 0x40000000, &dd, &di))
        return 0;
    if (!ASN1BERDecObjectIdentifier(dd, 0x6, &(val)->spnegoMech))
        return 0;
    if (!ASN1Dec_NegotiationToken(dd, 0, &(val)->negToken))
        return 0;
    if (!ASN1BERDecEndOfContents(dec, dd, di))
        return 0;
    return 1;
}

static void ASN1CALL ASN1Free_InitialNegToken(InitialNegToken* val) {
    if (val) {
        ASN1objectidentifier_free(&(val)->spnegoMech);
        ASN1Free_NegotiationToken(&(val)->negToken);
    }
}