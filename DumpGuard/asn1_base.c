#include "asn1_base.h"

typedef BOOL (ASN1API* ASN1BERDecBitString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1bitstring_t* p0);
static ASN1BERDecBitString_t _ASN1BERDecBitString = NULL;

BOOL ASN1API ASN1BERDecBitString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1bitstring_t* p0)
{
    if (_ASN1BERDecBitString != NULL)
        return _ASN1BERDecBitString(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecBitString2_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1bitstring_t* p0);
static ASN1BERDecBitString2_t _ASN1BERDecBitString2 = NULL;

BOOL ASN1API ASN1BERDecBitString2(ASN1decoding_t dec, ASN1uint32_t tag, ASN1bitstring_t* p0)
{
    if (_ASN1BERDecBitString2 != NULL)
        return _ASN1BERDecBitString2(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecBool_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1bool_t* p0);
static ASN1BERDecBool_t _ASN1BERDecBool = NULL;

BOOL ASN1API ASN1BERDecBool(ASN1decoding_t dec, ASN1uint32_t tag, ASN1bool_t* p0)
{
    if (_ASN1BERDecBool != NULL)
        return _ASN1BERDecBool(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecChar16String_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1char16string_t* p0);
static ASN1BERDecChar16String_t _ASN1BERDecChar16String = NULL;

BOOL ASN1API ASN1BERDecChar16String(ASN1decoding_t dec, ASN1uint32_t tag, ASN1char16string_t* p0)
{
    if (_ASN1BERDecChar16String != NULL)
        return _ASN1BERDecChar16String(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecChar32String_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1char32string_t* p0);
static ASN1BERDecChar32String_t _ASN1BERDecChar32String = NULL;

BOOL ASN1API ASN1BERDecChar32String(ASN1decoding_t dec, ASN1uint32_t tag, ASN1char32string_t* p0)
{
    if (_ASN1BERDecChar32String != NULL)
        return _ASN1BERDecChar32String(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecCharString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1charstring_t* p0);
static ASN1BERDecCharString_t _ASN1BERDecCharString = NULL;

BOOL ASN1API ASN1BERDecCharString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1charstring_t* p0)
{
    if (_ASN1BERDecCharString != NULL)
        return _ASN1BERDecCharString(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecCharacterString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1characterstring_t* p0);
static ASN1BERDecCharacterString_t _ASN1BERDecCharacterString = NULL;

BOOL ASN1API ASN1BERDecCharacterString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1characterstring_t* p0)
{
    if (_ASN1BERDecCharacterString != NULL)
        return _ASN1BERDecCharacterString(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecCheck_t)(ASN1decoding_t dec, ASN1uint32_t len);
static ASN1BERDecCheck_t _ASN1BERDecCheck = NULL;

BOOL ASN1API ASN1BERDecCheck(ASN1decoding_t dec, ASN1uint32_t len)
{
    if (_ASN1BERDecCheck != NULL)
        return _ASN1BERDecCheck(dec, len);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecDouble_t)(ASN1decoding_t dec, ASN1uint32_t tag, double* p0);
static ASN1BERDecDouble_t _ASN1BERDecDouble = NULL;

BOOL ASN1API ASN1BERDecDouble(ASN1decoding_t dec, ASN1uint32_t tag, double* p0)
{
    if (_ASN1BERDecDouble != NULL)
        return _ASN1BERDecDouble(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecEmbeddedPdv_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1embeddedpdv_t* p0);
static ASN1BERDecEmbeddedPdv_t _ASN1BERDecEmbeddedPdv = NULL;

BOOL ASN1API ASN1BERDecEmbeddedPdv(ASN1decoding_t dec, ASN1uint32_t tag, ASN1embeddedpdv_t* p0)
{
    if (_ASN1BERDecEmbeddedPdv != NULL)
        return _ASN1BERDecEmbeddedPdv(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecEndOfContents_t)(ASN1decoding_t dec, ASN1decoding_t dd, ASN1octet_t* di);
static ASN1BERDecEndOfContents_t _ASN1BERDecEndOfContents = NULL;

BOOL ASN1API ASN1BERDecEndOfContents(ASN1decoding_t dec, ASN1decoding_t dd, ASN1octet_t* di)
{
    if (_ASN1BERDecEndOfContents != NULL)
        return _ASN1BERDecEndOfContents(dec, dd, di);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecEoid_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1encodedOID_t* p0);
static ASN1BERDecEoid_t _ASN1BERDecEoid = NULL;

BOOL ASN1API ASN1BERDecEoid(ASN1decoding_t dec, ASN1uint32_t tag, ASN1encodedOID_t* p0)
{
    if (_ASN1BERDecEoid != NULL)
        return _ASN1BERDecEoid(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecExplicitTag_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1decoding_t* dd, ASN1octet_t** di);
static ASN1BERDecExplicitTag_t _ASN1BERDecExplicitTag = NULL;

BOOL ASN1API ASN1BERDecExplicitTag(ASN1decoding_t dec, ASN1uint32_t tag, ASN1decoding_t* dd, ASN1octet_t** di)
{
    if (_ASN1BERDecExplicitTag != NULL)
        return _ASN1BERDecExplicitTag(dec, tag, dd, di);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecExternal_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1external_t* p0);
static ASN1BERDecExternal_t _ASN1BERDecExternal = NULL;

BOOL ASN1API ASN1BERDecExternal(ASN1decoding_t dec, ASN1uint32_t tag, ASN1external_t* p0)
{
    if (_ASN1BERDecExternal != NULL)
        return _ASN1BERDecExternal(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecFlush_t)(ASN1decoding_t dec);
static ASN1BERDecFlush_t _ASN1BERDecFlush = NULL;

BOOL ASN1API ASN1BERDecFlush(ASN1decoding_t dec)
{
    if (_ASN1BERDecFlush != NULL)
        return _ASN1BERDecFlush(dec);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecGeneralizedTime_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1generalizedtime_t* p0);
static ASN1BERDecGeneralizedTime_t _ASN1BERDecGeneralizedTime = NULL;

BOOL ASN1API ASN1BERDecGeneralizedTime(ASN1decoding_t dec, ASN1uint32_t tag, ASN1generalizedtime_t* p0)
{
    if (_ASN1BERDecGeneralizedTime != NULL)
        return _ASN1BERDecGeneralizedTime(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecLength_t)(ASN1decoding_t dec, ASN1uint32_t* len, ASN1uint32_t* infinite);
static ASN1BERDecLength_t _ASN1BERDecLength = NULL;

BOOL ASN1API ASN1BERDecLength(ASN1decoding_t dec, ASN1uint32_t* len, ASN1uint32_t* infinite)
{
    if (_ASN1BERDecLength != NULL)
        return _ASN1BERDecLength(dec, len, infinite);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecMultibyteString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1charstring_t* p0);
static ASN1BERDecMultibyteString_t _ASN1BERDecMultibyteString = NULL;

BOOL ASN1API ASN1BERDecMultibyteString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1charstring_t* p0)
{
    if (_ASN1BERDecMultibyteString != NULL)
        return _ASN1BERDecMultibyteString(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecNotEndOfContents_t)(ASN1decoding_t dec, ASN1octet_t* di);
static ASN1BERDecNotEndOfContents_t _ASN1BERDecNotEndOfContents = NULL;

BOOL ASN1API ASN1BERDecNotEndOfContents(ASN1decoding_t dec, ASN1octet_t* di)
{
    if (_ASN1BERDecNotEndOfContents != NULL)
        return _ASN1BERDecNotEndOfContents(dec, di);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecNull_t)(ASN1decoding_t dec, ASN1uint32_t tag);
static ASN1BERDecNull_t _ASN1BERDecNull = NULL;

BOOL ASN1API ASN1BERDecNull(ASN1decoding_t dec, ASN1uint32_t tag)
{
    if (_ASN1BERDecNull != NULL)
        return _ASN1BERDecNull(dec, tag);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecObjectIdentifier_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1objectidentifier_t* p0);
static ASN1BERDecObjectIdentifier_t _ASN1BERDecObjectIdentifier = NULL;

BOOL ASN1API ASN1BERDecObjectIdentifier(ASN1decoding_t dec, ASN1uint32_t tag, ASN1objectidentifier_t* p0)
{
    if (_ASN1BERDecObjectIdentifier != NULL)
        return _ASN1BERDecObjectIdentifier(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecObjectIdentifier2_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1objectidentifier2_t* p0);
static ASN1BERDecObjectIdentifier2_t _ASN1BERDecObjectIdentifier2 = NULL;

BOOL ASN1API ASN1BERDecObjectIdentifier2(ASN1decoding_t dec, ASN1uint32_t tag, ASN1objectidentifier2_t* p0)
{
    if (_ASN1BERDecObjectIdentifier2 != NULL)
        return _ASN1BERDecObjectIdentifier2(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecOctetString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1octetstring_t* val);
static ASN1BERDecOctetString_t _ASN1BERDecOctetString = NULL;

BOOL ASN1API ASN1BERDecOctetString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1octetstring_t* val)
{
    if (_ASN1BERDecOctetString != NULL)
        return _ASN1BERDecOctetString(dec, tag, val);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecOctetString2_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1octetstring_t* val);
static ASN1BERDecOctetString2_t _ASN1BERDecOctetString2 = NULL;

BOOL ASN1API ASN1BERDecOctetString2(ASN1decoding_t dec, ASN1uint32_t tag, ASN1octetstring_t* val)
{
    if (_ASN1BERDecOctetString2 != NULL)
        return _ASN1BERDecOctetString2(dec, tag, val);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecOpenType_t)(ASN1decoding_t dec, ASN1open_t* p0);
static ASN1BERDecOpenType_t _ASN1BERDecOpenType = NULL;

BOOL ASN1API ASN1BERDecOpenType(ASN1decoding_t dec, ASN1open_t* p0)
{
    if (_ASN1BERDecOpenType != NULL)
        return _ASN1BERDecOpenType(dec, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecOpenType2_t)(ASN1decoding_t dec, ASN1open_t* p0);
static ASN1BERDecOpenType2_t _ASN1BERDecOpenType2 = NULL;

BOOL ASN1API ASN1BERDecOpenType2(ASN1decoding_t dec, ASN1open_t* p0)
{
    if (_ASN1BERDecOpenType2 != NULL)
        return _ASN1BERDecOpenType2(dec, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecPeekTag_t)(ASN1decoding_t dec, ASN1uint32_t* tag);
static ASN1BERDecPeekTag_t _ASN1BERDecPeekTag = NULL;

BOOL ASN1API ASN1BERDecPeekTag(ASN1decoding_t dec, ASN1uint32_t* tag)
{
    if (_ASN1BERDecPeekTag != NULL)
        return _ASN1BERDecPeekTag(dec, tag);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecS16Val_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1int16_t* p0);
static ASN1BERDecS16Val_t _ASN1BERDecS16Val = NULL;

BOOL ASN1API ASN1BERDecS16Val(ASN1decoding_t dec, ASN1uint32_t tag, ASN1int16_t* p0)
{
    if (_ASN1BERDecS16Val != NULL)
        return _ASN1BERDecS16Val(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecS32Val_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1int32_t* p0);
static ASN1BERDecS32Val_t _ASN1BERDecS32Val = NULL;

BOOL ASN1API ASN1BERDecS32Val(ASN1decoding_t dec, ASN1uint32_t tag, ASN1int32_t* p0)
{
    if (_ASN1BERDecS32Val != NULL)
        return _ASN1BERDecS32Val(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecS8Val_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1int8_t* p0);
static ASN1BERDecS8Val_t _ASN1BERDecS8Val = NULL;

BOOL ASN1API ASN1BERDecS8Val(ASN1decoding_t dec, ASN1uint32_t tag, ASN1int8_t* p0)
{
    if (_ASN1BERDecS8Val != NULL)
        return _ASN1BERDecS8Val(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecSXVal_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1intx_t* p0);
static ASN1BERDecSXVal_t _ASN1BERDecSXVal = NULL;

BOOL ASN1API ASN1BERDecSXVal(ASN1decoding_t dec, ASN1uint32_t tag, ASN1intx_t* p0)
{
    if (_ASN1BERDecSXVal != NULL)
        return _ASN1BERDecSXVal(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecSkip_t)(ASN1decoding_t dec);
static ASN1BERDecSkip_t _ASN1BERDecSkip = NULL;

BOOL ASN1API ASN1BERDecSkip(ASN1decoding_t dec)
{
    if (_ASN1BERDecSkip != NULL)
        return _ASN1BERDecSkip(dec);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecTag_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint32_t* constructed);
static ASN1BERDecTag_t _ASN1BERDecTag = NULL;

BOOL ASN1API ASN1BERDecTag(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint32_t* constructed)
{
    if (_ASN1BERDecTag != NULL)
        return _ASN1BERDecTag(dec, tag, constructed);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecU16Val_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint16_t* p0);
static ASN1BERDecU16Val_t _ASN1BERDecU16Val = NULL;

BOOL ASN1API ASN1BERDecU16Val(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint16_t* p0)
{
    if (_ASN1BERDecU16Val != NULL)
        return _ASN1BERDecU16Val(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecU32Val_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint32_t* val);
static ASN1BERDecU32Val_t _ASN1BERDecU32Val = NULL;

BOOL ASN1API ASN1BERDecU32Val(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint32_t* val)
{
    if (_ASN1BERDecU32Val != NULL)
        return _ASN1BERDecU32Val(dec, tag, val);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecU8Val_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint8_t* p0);
static ASN1BERDecU8Val_t _ASN1BERDecU8Val = NULL;

BOOL ASN1API ASN1BERDecU8Val(ASN1decoding_t dec, ASN1uint32_t tag, ASN1uint8_t* p0)
{
    if (_ASN1BERDecU8Val != NULL)
        return _ASN1BERDecU8Val(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecUTCTime_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1utctime_t* p0);
static ASN1BERDecUTCTime_t _ASN1BERDecUTCTime = NULL;

BOOL ASN1API ASN1BERDecUTCTime(ASN1decoding_t dec, ASN1uint32_t tag, ASN1utctime_t* p0)
{
    if (_ASN1BERDecUTCTime != NULL)
        return _ASN1BERDecUTCTime(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecUTF8String_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1wstring_t* val);
static ASN1BERDecUTF8String_t _ASN1BERDecUTF8String = NULL;

BOOL ASN1API ASN1BERDecUTF8String(ASN1decoding_t dec, ASN1uint32_t tag, ASN1wstring_t* val)
{
    if (_ASN1BERDecUTF8String != NULL)
        return _ASN1BERDecUTF8String(dec, tag, val);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecZeroChar16String_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztchar16string_t* p0);
static ASN1BERDecZeroChar16String_t _ASN1BERDecZeroChar16String = NULL;

BOOL ASN1API ASN1BERDecZeroChar16String(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztchar16string_t* p0)
{
    if (_ASN1BERDecZeroChar16String != NULL)
        return _ASN1BERDecZeroChar16String(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecZeroChar32String_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztchar32string_t* p0);
static ASN1BERDecZeroChar32String_t _ASN1BERDecZeroChar32String = NULL;

BOOL ASN1API ASN1BERDecZeroChar32String(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztchar32string_t* p0)
{
    if (_ASN1BERDecZeroChar32String != NULL)
        return _ASN1BERDecZeroChar32String(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecZeroCharString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztcharstring_t* p0);
static ASN1BERDecZeroCharString_t _ASN1BERDecZeroCharString = NULL;

BOOL ASN1API ASN1BERDecZeroCharString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztcharstring_t* p0)
{
    if (_ASN1BERDecZeroCharString != NULL)
        return _ASN1BERDecZeroCharString(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDecZeroMultibyteString_t)(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztcharstring_t* p0);
static ASN1BERDecZeroMultibyteString_t _ASN1BERDecZeroMultibyteString = NULL;

BOOL ASN1API ASN1BERDecZeroMultibyteString(ASN1decoding_t dec, ASN1uint32_t tag, ASN1ztcharstring_t* p0)
{
    if (_ASN1BERDecZeroMultibyteString != NULL)
        return _ASN1BERDecZeroMultibyteString(dec, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BERDotVal2Eoid_t)(ASN1encoding_t enc, char* pszDotVal, ASN1encodedOID_t* pOut);
static ASN1BERDotVal2Eoid_t _ASN1BERDotVal2Eoid = NULL;

BOOL ASN1API ASN1BERDotVal2Eoid(ASN1encoding_t enc, char* pszDotVal, ASN1encodedOID_t* pOut)
{
    if (_ASN1BERDotVal2Eoid != NULL)
        return _ASN1BERDotVal2Eoid(enc, pszDotVal, pOut);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncBitString_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1octet_t* p1);
static ASN1BEREncBitString_t _ASN1BEREncBitString = NULL;

BOOL ASN1API ASN1BEREncBitString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1octet_t* p1)
{
    if (_ASN1BEREncBitString != NULL)
        return _ASN1BEREncBitString(enc, tag, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncBool_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1bool_t p0);
static ASN1BEREncBool_t _ASN1BEREncBool = NULL;

BOOL ASN1API ASN1BEREncBool(ASN1encoding_t enc, ASN1uint32_t tag, ASN1bool_t p0)
{
    if (_ASN1BEREncBool != NULL)
        return _ASN1BEREncBool(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncChar16String_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1char16_t* p1);
static ASN1BEREncChar16String_t _ASN1BEREncChar16String = NULL;

BOOL ASN1API ASN1BEREncChar16String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1char16_t* p1)
{
    if (_ASN1BEREncChar16String != NULL)
        return _ASN1BEREncChar16String(enc, tag, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncChar32String_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1char32_t* p1);
static ASN1BEREncChar32String_t _ASN1BEREncChar32String = NULL;

BOOL ASN1API ASN1BEREncChar32String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1char32_t* p1)
{
    if (_ASN1BEREncChar32String != NULL)
        return _ASN1BEREncChar32String(enc, tag, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncCharString_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1char_t* p1);
static ASN1BEREncCharString_t _ASN1BEREncCharString = NULL;

BOOL ASN1API ASN1BEREncCharString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0, ASN1char_t* p1)
{
    if (_ASN1BEREncCharString != NULL)
        return _ASN1BEREncCharString(enc, tag, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncCharacterString_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1characterstring_t* p0);
static ASN1BEREncCharacterString_t _ASN1BEREncCharacterString = NULL;

BOOL ASN1API ASN1BEREncCharacterString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1characterstring_t* p0)
{
    if (_ASN1BEREncCharacterString != NULL)
        return _ASN1BEREncCharacterString(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncCheck_t)(ASN1encoding_t enc, ASN1uint32_t noctets);
static ASN1BEREncCheck_t _ASN1BEREncCheck = NULL;

BOOL ASN1API ASN1BEREncCheck(ASN1encoding_t enc, ASN1uint32_t noctets)
{
    if (_ASN1BEREncCheck != NULL)
        return _ASN1BEREncCheck(enc, noctets);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncDouble_t)(ASN1encoding_t enc, ASN1uint32_t tag, double p0);
static ASN1BEREncDouble_t _ASN1BEREncDouble = NULL;

BOOL ASN1API ASN1BEREncDouble(ASN1encoding_t enc, ASN1uint32_t tag, double p0)
{
    if (_ASN1BEREncDouble != NULL)
        return _ASN1BEREncDouble(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncEmbeddedPdv_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1embeddedpdv_t* p0);
static ASN1BEREncEmbeddedPdv_t _ASN1BEREncEmbeddedPdv = NULL;

BOOL ASN1API ASN1BEREncEmbeddedPdv(ASN1encoding_t enc, ASN1uint32_t tag, ASN1embeddedpdv_t* p0)
{
    if (_ASN1BEREncEmbeddedPdv != NULL)
        return _ASN1BEREncEmbeddedPdv(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncEndOfContents_t)(ASN1encoding_t enc, ASN1uint32_t LengthOffset);
static ASN1BEREncEndOfContents_t _ASN1BEREncEndOfContents = NULL;

BOOL ASN1API ASN1BEREncEndOfContents(ASN1encoding_t enc, ASN1uint32_t LengthOffset)
{
    if (_ASN1BEREncEndOfContents != NULL)
        return _ASN1BEREncEndOfContents(enc, LengthOffset);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncEoid_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1encodedOID_t* p0);
static ASN1BEREncEoid_t _ASN1BEREncEoid = NULL;

BOOL ASN1API ASN1BEREncEoid(ASN1encoding_t enc, ASN1uint32_t tag, ASN1encodedOID_t* p0)
{
    if (_ASN1BEREncEoid != NULL)
        return _ASN1BEREncEoid(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncExplicitTag_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t* pLengthOffset);
static ASN1BEREncExplicitTag_t _ASN1BEREncExplicitTag = NULL;

BOOL ASN1API ASN1BEREncExplicitTag(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t* pLengthOffset)
{
    if (_ASN1BEREncExplicitTag != NULL)
        return _ASN1BEREncExplicitTag(enc, tag, pLengthOffset);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncExternal_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1external_t* p0);
static ASN1BEREncExternal_t _ASN1BEREncExternal = NULL;

BOOL ASN1API ASN1BEREncExternal(ASN1encoding_t enc, ASN1uint32_t tag, ASN1external_t* p0)
{
    if (_ASN1BEREncExternal != NULL)
        return _ASN1BEREncExternal(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncFlush_t)(ASN1encoding_t enc);
static ASN1BEREncFlush_t _ASN1BEREncFlush = NULL;

BOOL ASN1API ASN1BEREncFlush(ASN1encoding_t enc)
{
    if (_ASN1BEREncFlush != NULL)
        return _ASN1BEREncFlush(enc);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncGeneralizedTime_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1generalizedtime_t* p0);
static ASN1BEREncGeneralizedTime_t _ASN1BEREncGeneralizedTime = NULL;

BOOL ASN1API ASN1BEREncGeneralizedTime(ASN1encoding_t enc, ASN1uint32_t tag, ASN1generalizedtime_t* p0)
{
    if (_ASN1BEREncGeneralizedTime != NULL)
        return _ASN1BEREncGeneralizedTime(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncLength_t)(ASN1encoding_t enc, ASN1uint32_t len);
static ASN1BEREncLength_t _ASN1BEREncLength = NULL;

BOOL ASN1API ASN1BEREncLength(ASN1encoding_t enc, ASN1uint32_t len)
{
    if (_ASN1BEREncLength != NULL)
        return _ASN1BEREncLength(enc, len);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncMultibyteString_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1charstring_t* p0);
static ASN1BEREncMultibyteString_t _ASN1BEREncMultibyteString = NULL;

BOOL ASN1API ASN1BEREncMultibyteString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1charstring_t* p0)
{
    if (_ASN1BEREncMultibyteString != NULL)
        return _ASN1BEREncMultibyteString(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncNull_t)(ASN1encoding_t enc, ASN1uint32_t tag);
static ASN1BEREncNull_t _ASN1BEREncNull = NULL;

BOOL ASN1API ASN1BEREncNull(ASN1encoding_t enc, ASN1uint32_t tag)
{
    if (_ASN1BEREncNull != NULL)
        return _ASN1BEREncNull(enc, tag);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncObjectIdentifier_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1objectidentifier_t* p0);
static ASN1BEREncObjectIdentifier_t _ASN1BEREncObjectIdentifier = NULL;

BOOL ASN1API ASN1BEREncObjectIdentifier(ASN1encoding_t enc, ASN1uint32_t tag, ASN1objectidentifier_t* p0)
{
    if (_ASN1BEREncObjectIdentifier != NULL)
        return _ASN1BEREncObjectIdentifier(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncObjectIdentifier2_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1objectidentifier2_t* val);
static ASN1BEREncObjectIdentifier2_t _ASN1BEREncObjectIdentifier2 = NULL;

BOOL ASN1API ASN1BEREncObjectIdentifier2(ASN1encoding_t enc, ASN1uint32_t tag, ASN1objectidentifier2_t* val)
{
    if (_ASN1BEREncObjectIdentifier2 != NULL)
        return _ASN1BEREncObjectIdentifier2(enc, tag, val);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncOctetString_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1octet_t* val);
static ASN1BEREncOctetString_t _ASN1BEREncOctetString = NULL;

BOOL ASN1API ASN1BEREncOctetString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1octet_t* val)
{
    if (_ASN1BEREncOctetString != NULL)
        return _ASN1BEREncOctetString(enc, tag, len, val);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncOpenType_t)(ASN1encoding_t enc, ASN1open_t* p0);
static ASN1BEREncOpenType_t _ASN1BEREncOpenType = NULL;

BOOL ASN1API ASN1BEREncOpenType(ASN1encoding_t enc, ASN1open_t* p0)
{
    if (_ASN1BEREncOpenType != NULL)
        return _ASN1BEREncOpenType(enc, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncRemoveZeroBits_t)(ASN1uint32_t* p0, ASN1octet_t* p1);
static ASN1BEREncRemoveZeroBits_t _ASN1BEREncRemoveZeroBits = NULL;

BOOL ASN1API ASN1BEREncRemoveZeroBits(ASN1uint32_t* p0, ASN1octet_t* p1)
{
    if (_ASN1BEREncRemoveZeroBits != NULL)
        return _ASN1BEREncRemoveZeroBits(p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncS32_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1int32_t p0);
static ASN1BEREncS32_t _ASN1BEREncS32 = NULL;

BOOL ASN1API ASN1BEREncS32(ASN1encoding_t enc, ASN1uint32_t tag, ASN1int32_t p0)
{
    if (_ASN1BEREncS32 != NULL)
        return _ASN1BEREncS32(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncSX_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1intx_t* p0);
static ASN1BEREncSX_t _ASN1BEREncSX = NULL;

BOOL ASN1API ASN1BEREncSX(ASN1encoding_t enc, ASN1uint32_t tag, ASN1intx_t* p0)
{
    if (_ASN1BEREncSX != NULL)
        return _ASN1BEREncSX(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncTag_t)(ASN1encoding_t enc, ASN1uint32_t tag);
static ASN1BEREncTag_t _ASN1BEREncTag = NULL;

BOOL ASN1API ASN1BEREncTag(ASN1encoding_t enc, ASN1uint32_t tag)
{
    if (_ASN1BEREncTag != NULL)
        return _ASN1BEREncTag(enc, tag);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncU32_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0);
static ASN1BEREncU32_t _ASN1BEREncU32 = NULL;

BOOL ASN1API ASN1BEREncU32(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t p0)
{
    if (_ASN1BEREncU32 != NULL)
        return _ASN1BEREncU32(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncUTCTime_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1utctime_t* p0);
static ASN1BEREncUTCTime_t _ASN1BEREncUTCTime = NULL;

BOOL ASN1API ASN1BEREncUTCTime(ASN1encoding_t enc, ASN1uint32_t tag, ASN1utctime_t* p0)
{
    if (_ASN1BEREncUTCTime != NULL)
        return _ASN1BEREncUTCTime(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncUTF8String_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t length, WCHAR* value);
static ASN1BEREncUTF8String_t _ASN1BEREncUTF8String = NULL;

BOOL ASN1API ASN1BEREncUTF8String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t length, WCHAR* value)
{
    if (_ASN1BEREncUTF8String != NULL)
        return _ASN1BEREncUTF8String(enc, tag, length, value);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREncZeroMultibyteString_t)(ASN1encoding_t enc, ASN1uint32_t tag, ASN1ztcharstring_t p0);
static ASN1BEREncZeroMultibyteString_t _ASN1BEREncZeroMultibyteString = NULL;

BOOL ASN1API ASN1BEREncZeroMultibyteString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1ztcharstring_t p0)
{
    if (_ASN1BEREncZeroMultibyteString != NULL)
        return _ASN1BEREncZeroMultibyteString(enc, tag, p0);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1BEREoid2DotVal_t)(ASN1decoding_t dec, ASN1encodedOID_t* pIn, char** ppszDotVal);
static ASN1BEREoid2DotVal_t _ASN1BEREoid2DotVal = NULL;

BOOL ASN1API ASN1BEREoid2DotVal(ASN1decoding_t dec, ASN1encodedOID_t* pIn, char** ppszDotVal)
{
    if (_ASN1BEREoid2DotVal != NULL)
        return _ASN1BEREoid2DotVal(dec, pIn, ppszDotVal);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncBeginBlk_t)(ASN1encoding_t enc, ASN1blocktype_e eBlkType, void** ppBlk);
static ASN1CEREncBeginBlk_t _ASN1CEREncBeginBlk = NULL;

BOOL ASN1API ASN1CEREncBeginBlk(ASN1encoding_t enc, ASN1blocktype_e eBlkType, void** ppBlk)
{
    if (_ASN1CEREncBeginBlk != NULL)
        return _ASN1CEREncBeginBlk(enc, eBlkType, ppBlk);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncBitString_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1octet_t* p2);
static ASN1CEREncBitString_t _ASN1CEREncBitString = NULL;

BOOL ASN1API ASN1CEREncBitString(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1octet_t* p2)
{
    if (_ASN1CEREncBitString != NULL)
        return _ASN1CEREncBitString(enc, p0, p1, p2);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncChar16String_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1char16_t* p2);
static ASN1CEREncChar16String_t _ASN1CEREncChar16String = NULL;

BOOL ASN1API ASN1CEREncChar16String(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1char16_t* p2)
{
    if (_ASN1CEREncChar16String != NULL)
        return _ASN1CEREncChar16String(enc, p0, p1, p2);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncChar32String_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1char32_t* p2);
static ASN1CEREncChar32String_t _ASN1CEREncChar32String = NULL;

BOOL ASN1API ASN1CEREncChar32String(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1char32_t* p2)
{
    if (_ASN1CEREncChar32String != NULL)
        return _ASN1CEREncChar32String(enc, p0, p1, p2);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncCharString_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1char_t* p2);
static ASN1CEREncCharString_t _ASN1CEREncCharString = NULL;

BOOL ASN1API ASN1CEREncCharString(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1char_t* p2)
{
    if (_ASN1CEREncCharString != NULL)
        return _ASN1CEREncCharString(enc, p0, p1, p2);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncEndBlk_t)(void* pBlk);
static ASN1CEREncEndBlk_t _ASN1CEREncEndBlk = NULL;

BOOL ASN1API ASN1CEREncEndBlk(void* pBlk)
{
    if (_ASN1CEREncEndBlk != NULL)
        return _ASN1CEREncEndBlk(pBlk);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncFlushBlkElement_t)(void* pBlk);
static ASN1CEREncFlushBlkElement_t _ASN1CEREncFlushBlkElement = NULL;

BOOL ASN1API ASN1CEREncFlushBlkElement(void* pBlk)
{
    if (_ASN1CEREncFlushBlkElement != NULL)
        return _ASN1CEREncFlushBlkElement(pBlk);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncGeneralizedTime_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1generalizedtime_t* p1);
static ASN1CEREncGeneralizedTime_t _ASN1CEREncGeneralizedTime = NULL;

BOOL ASN1API ASN1CEREncGeneralizedTime(ASN1encoding_t enc, ASN1uint32_t p0, ASN1generalizedtime_t* p1)
{
    if (_ASN1CEREncGeneralizedTime != NULL)
        return _ASN1CEREncGeneralizedTime(enc, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncMultibyteString_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1charstring_t* p1);
static ASN1CEREncMultibyteString_t _ASN1CEREncMultibyteString = NULL;

BOOL ASN1API ASN1CEREncMultibyteString(ASN1encoding_t enc, ASN1uint32_t p0, ASN1charstring_t* p1)
{
    if (_ASN1CEREncMultibyteString != NULL)
        return _ASN1CEREncMultibyteString(enc, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncNewBlkElement_t)(void* pBlk, ASN1encoding_t* enc2);
static ASN1CEREncNewBlkElement_t _ASN1CEREncNewBlkElement = NULL;

BOOL ASN1API ASN1CEREncNewBlkElement(void* pBlk, ASN1encoding_t* enc2)
{
    if (_ASN1CEREncNewBlkElement != NULL)
        return _ASN1CEREncNewBlkElement(pBlk, enc2);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncOctetString_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1octet_t* p2);
static ASN1CEREncOctetString_t _ASN1CEREncOctetString = NULL;

BOOL ASN1API ASN1CEREncOctetString(ASN1encoding_t enc, ASN1uint32_t p0, ASN1uint32_t p1, ASN1octet_t* p2)
{
    if (_ASN1CEREncOctetString != NULL)
        return _ASN1CEREncOctetString(enc, p0, p1, p2);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncUTCTime_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1utctime_t* p1);
static ASN1CEREncUTCTime_t _ASN1CEREncUTCTime = NULL;

BOOL ASN1API ASN1CEREncUTCTime(ASN1encoding_t enc, ASN1uint32_t p0, ASN1utctime_t* p1)
{
    if (_ASN1CEREncUTCTime != NULL)
        return _ASN1CEREncUTCTime(enc, p0, p1);

    return FALSE;
}

typedef BOOL (ASN1API* ASN1CEREncZeroMultibyteString_t)(ASN1encoding_t enc, ASN1uint32_t p0, ASN1ztcharstring_t p1);
static ASN1CEREncZeroMultibyteString_t _ASN1CEREncZeroMultibyteString = NULL;

BOOL ASN1API ASN1CEREncZeroMultibyteString(ASN1encoding_t enc, ASN1uint32_t p0, ASN1ztcharstring_t p1)
{
    if (_ASN1CEREncZeroMultibyteString != NULL)
        return _ASN1CEREncZeroMultibyteString(enc, p0, p1);

    return FALSE;
}

BOOL ASN1API ASN1DEREncGeneralizedTime(ASN1encoding_t enc,ASN1uint32_t tag,ASN1generalizedtime_t *val) 
{ 
    return ASN1CEREncGeneralizedTime(enc,tag,val); 
}

BOOL ASN1API ASN1DEREncUTCTime(ASN1encoding_t enc, ASN1uint32_t tag, ASN1utctime_t* val)
{
    return ASN1CEREncUTCTime(enc, tag, val);
}
BOOL ASN1API ASN1DEREncBeginBlk(ASN1encoding_t enc, ASN1blocktype_e eBlkType, void** ppBlk)
{
    return ASN1CEREncBeginBlk(enc, eBlkType, ppBlk);
}

BOOL ASN1API ASN1DEREncNewBlkElement(void* pBlk, ASN1encoding_t* enc2)
{
    return ASN1CEREncNewBlkElement(pBlk, enc2);
}

BOOL ASN1API ASN1DEREncFlushBlkElement(void* pBlk)
{
    return ASN1CEREncFlushBlkElement(pBlk);
}

BOOL ASN1API ASN1DEREncEndBlk(void* pBlk)
{
    return ASN1CEREncEndBlk(pBlk);
}

BOOL ASN1API ASN1DEREncCharString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1char_t* val)
{
    return ASN1BEREncCharString(enc, tag, len, val);
}

BOOL ASN1API ASN1DEREncChar16String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1char16_t* val)
{
    return ASN1BEREncChar16String(enc, tag, len, val);
}

BOOL ASN1API ASN1DEREncChar32String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1char32_t* val)
{
    return ASN1BEREncChar32String(enc, tag, len, val);
}

BOOL ASN1API ASN1DEREncBitString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1octet_t* val)
{
    return ASN1BEREncBitString(enc, tag, len, val);
}

BOOL ASN1API ASN1DEREncZeroMultibyteString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1ztcharstring_t val)
{
    return ASN1BEREncZeroMultibyteString(enc, tag, val);
}

BOOL ASN1API ASN1DEREncMultibyteString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1charstring_t* val)
{
    return ASN1BEREncMultibyteString(enc, tag, val);
}

BOOL ASN1API ASN1DEREncOctetString(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t len, ASN1octet_t* val)
{
    return ASN1BEREncOctetString(enc, tag, len, val);
}

BOOL ASN1API ASN1DEREncUTF8String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t length, WCHAR* value)
{
    return ASN1BEREncUTF8String(enc, tag, length, value);
}

BOOL ASN1API ASN1CEREncUTF8String(ASN1encoding_t enc, ASN1uint32_t tag, ASN1uint32_t length, WCHAR* value)
{
    return ASN1BEREncUTF8String(enc, tag, length, value);
}

typedef LPVOID (ASN1API* ASN1DecAlloc_t)(ASN1decoding_t dec, ASN1uint32_t size);
static ASN1DecAlloc_t _ASN1DecAlloc = NULL;

LPVOID ASN1API ASN1DecAlloc(ASN1decoding_t dec, ASN1uint32_t size)
{
    if (_ASN1DecAlloc != NULL)
        return _ASN1DecAlloc(dec, size);

    return NULL;
}

typedef LPVOID (ASN1API* ASN1DecRealloc_t)(ASN1decoding_t dec, LPVOID ptr, ASN1uint32_t size);
static ASN1DecRealloc_t _ASN1DecRealloc = NULL;

LPVOID ASN1API ASN1DecRealloc(ASN1decoding_t dec, LPVOID ptr, ASN1uint32_t size)
{
    if (_ASN1DecRealloc != NULL)
        return _ASN1DecRealloc(dec, ptr, size);

    return NULL;
}

typedef ASN1error_e (ASN1API* ASN1DecSetError_t)(ASN1decoding_t dec, ASN1error_e err);
static ASN1DecSetError_t _ASN1DecSetError = NULL;

ASN1error_e ASN1API ASN1DecSetError(ASN1decoding_t dec, ASN1error_e err)
{
    if (_ASN1DecSetError != NULL)
        return _ASN1DecSetError(dec, err);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1EncSetError_t)(ASN1encoding_t enc, ASN1error_e err);
static ASN1EncSetError_t _ASN1EncSetError = NULL;

ASN1error_e ASN1API ASN1EncSetError(ASN1encoding_t enc, ASN1error_e err)
{
    if (_ASN1EncSetError != NULL)
        return _ASN1EncSetError(enc, err);

    return ASN1_ERR_INTERNAL;
}

typedef void (ASN1API* ASN1Free_t)(LPVOID ptr);
static ASN1Free_t _ASN1Free = NULL;

void ASN1API ASN1Free(LPVOID ptr)
{
    if (_ASN1Free != NULL)
        _ASN1Free(ptr);
}

typedef void (ASN1API* ASN1_CloseDecoder_t)(ASN1decoding_t pDecoderInfo);
static ASN1_CloseDecoder_t _ASN1_CloseDecoder = NULL;

void ASN1API ASN1_CloseDecoder(ASN1decoding_t pDecoderInfo)
{
    if (_ASN1_CloseDecoder != NULL)
        _ASN1_CloseDecoder(pDecoderInfo);
}

typedef void (ASN1API* ASN1_CloseEncoder_t)(ASN1encoding_t pEncoderInfo);
static ASN1_CloseEncoder_t _ASN1_CloseEncoder = NULL;

void ASN1API ASN1_CloseEncoder(ASN1encoding_t pEncoderInfo)
{
    if (_ASN1_CloseEncoder != NULL)
        _ASN1_CloseEncoder(pEncoderInfo);
}

typedef void (ASN1API* ASN1_CloseEncoder2_t)(ASN1encoding_t pEncoderInfo);
static ASN1_CloseEncoder2_t _ASN1_CloseEncoder2 = NULL;

void ASN1API ASN1_CloseEncoder2(ASN1encoding_t pEncoderInfo)
{
    if (_ASN1_CloseEncoder2 != NULL)
        _ASN1_CloseEncoder2(pEncoderInfo);
}

typedef void (ASN1API* ASN1_CloseModule_t)(ASN1module_t pModule);
static ASN1_CloseModule_t _ASN1_CloseModule = NULL;

void ASN1API ASN1_CloseModule(ASN1module_t pModule)
{
    if (_ASN1_CloseModule != NULL)
        _ASN1_CloseModule(pModule);
}

typedef ASN1error_e (ASN1API* ASN1_CreateDecoder_t)(ASN1module_t pModule, ASN1decoding_t* ppDecoderInfo, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize, ASN1decoding_t pParent);
static ASN1_CreateDecoder_t _ASN1_CreateDecoder = NULL;

ASN1error_e ASN1API ASN1_CreateDecoder(ASN1module_t pModule, ASN1decoding_t* ppDecoderInfo, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize, ASN1decoding_t pParent)
{
    if (_ASN1_CreateDecoder != NULL)
        return _ASN1_CreateDecoder(pModule, ppDecoderInfo, pbBuf, cbBufSize, pParent);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1_CreateDecoderEx_t)(ASN1module_t pModule, ASN1decoding_t* ppDecoderInfo, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize, ASN1decoding_t pParent, ASN1uint32_t dwFlags);
static ASN1_CreateDecoderEx_t _ASN1_CreateDecoderEx = NULL;

ASN1error_e ASN1API ASN1_CreateDecoderEx(ASN1module_t pModule, ASN1decoding_t* ppDecoderInfo, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize, ASN1decoding_t pParent, ASN1uint32_t dwFlags)
{
    if (_ASN1_CreateDecoderEx != NULL)
        return _ASN1_CreateDecoderEx(pModule, ppDecoderInfo, pbBuf, cbBufSize, pParent, dwFlags);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1_CreateEncoder_t)(ASN1module_t pModule, ASN1encoding_t* ppEncoderInfo, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize, ASN1encoding_t pParent);
static ASN1_CreateEncoder_t _ASN1_CreateEncoder = NULL;

ASN1error_e ASN1API ASN1_CreateEncoder(ASN1module_t pModule, ASN1encoding_t* ppEncoderInfo, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize, ASN1encoding_t pParent)
{
    if (_ASN1_CreateEncoder != NULL)
        return _ASN1_CreateEncoder(pModule, ppEncoderInfo, pbBuf, cbBufSize, pParent);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1module_t (ASN1API* ASN1_CreateModule_t)(ASN1uint32_t nVersion, ASN1encodingrule_e eRule, ASN1uint32_t dwFlags,  ASN1uint32_t cPDU, const ASN1GenericFun_t apfnEncoder[], const ASN1GenericFun_t apfnDecoder[], const ASN1FreeFun_t apfnFreeMemory[], const ASN1uint32_t acbStructSize[], ASN1magic_t nModuleName);
static ASN1_CreateModule_t _ASN1_CreateModule = NULL;

ASN1module_t ASN1API ASN1_CreateModule(ASN1uint32_t nVersion, ASN1encodingrule_e eRule, ASN1uint32_t dwFlags,  ASN1uint32_t cPDU, const ASN1GenericFun_t apfnEncoder[], const ASN1GenericFun_t apfnDecoder[], const ASN1FreeFun_t apfnFreeMemory[], const ASN1uint32_t acbStructSize[], ASN1magic_t nModuleName)
{
    if (_ASN1_CreateModule != NULL)
        return _ASN1_CreateModule(nVersion, eRule, dwFlags, cPDU, apfnEncoder, apfnDecoder, apfnFreeMemory, acbStructSize, nModuleName);

    return NULL;
}

typedef ASN1error_e (ASN1API* ASN1_Decode_t)(ASN1decoding_t pDecoderInfo, void** ppDataStruct, ASN1uint32_t nPduNum, ASN1uint32_t dwFlags, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize);
static ASN1_Decode_t _ASN1_Decode = NULL;

ASN1error_e ASN1API ASN1_Decode(ASN1decoding_t pDecoderInfo, void** ppDataStruct, ASN1uint32_t nPduNum, ASN1uint32_t dwFlags, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize)
{
    if (_ASN1_Decode != NULL)
        return _ASN1_Decode(pDecoderInfo, ppDataStruct, nPduNum, dwFlags, pbBuf, cbBufSize);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1_Encode_t)(ASN1encoding_t pEncoderInfo, void* pDataStruct, ASN1uint32_t nPduNum, ASN1uint32_t dwFlags, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize);
static ASN1_Encode_t _ASN1_Encode = NULL;

ASN1error_e ASN1API ASN1_Encode(ASN1encoding_t pEncoderInfo, void* pDataStruct, ASN1uint32_t nPduNum, ASN1uint32_t dwFlags, ASN1octet_t* pbBuf, ASN1uint32_t cbBufSize)
{
    if (_ASN1_Encode != NULL)
        return _ASN1_Encode(pEncoderInfo, pDataStruct, nPduNum, dwFlags, pbBuf, cbBufSize);

    return ASN1_ERR_INTERNAL;
}

typedef void (ASN1API* ASN1_FreeDecoded_t)(ASN1decoding_t pDecoderInfo, void* pDataStruct, ASN1uint32_t nPduNum);
static ASN1_FreeDecoded_t _ASN1_FreeDecoded = NULL;

void ASN1API ASN1_FreeDecoded(ASN1decoding_t pDecoderInfo, void* pDataStruct, ASN1uint32_t nPduNum)
{
    if (_ASN1_FreeDecoded != NULL)
        _ASN1_FreeDecoded(pDecoderInfo, pDataStruct, nPduNum);
}

typedef void (ASN1API* ASN1_FreeEncoded_t)(ASN1encoding_t pEncoderInfo, void* pBuf);
static ASN1_FreeEncoded_t _ASN1_FreeEncoded = NULL;

void ASN1API ASN1_FreeEncoded(ASN1encoding_t pEncoderInfo, void* pBuf)
{
    if (_ASN1_FreeEncoded != NULL)
        _ASN1_FreeEncoded(pEncoderInfo, pBuf);
}

typedef ASN1error_e (ASN1API* ASN1_GetDecoderOption_t)(ASN1decoding_t pDecoderInfo, ASN1optionparam_t* pOptParam);
static ASN1_GetDecoderOption_t _ASN1_GetDecoderOption = NULL;

ASN1error_e ASN1API ASN1_GetDecoderOption(ASN1decoding_t pDecoderInfo, ASN1optionparam_t* pOptParam)
{
    if (_ASN1_GetDecoderOption != NULL)
        return _ASN1_GetDecoderOption(pDecoderInfo, pOptParam);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1_GetEncoderOption_t)(ASN1encoding_t pEncoderInfo, ASN1optionparam_t* pOptParam);
static ASN1_GetEncoderOption_t _ASN1_GetEncoderOption = NULL;

ASN1error_e ASN1API ASN1_GetEncoderOption(ASN1encoding_t pEncoderInfo, ASN1optionparam_t* pOptParam)
{
    if (_ASN1_GetEncoderOption != NULL)
        return _ASN1_GetEncoderOption(pEncoderInfo, pOptParam);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1_SetDecoderOption_t)(ASN1decoding_t pDecoderInfo, ASN1optionparam_t* pOptParam);
static ASN1_SetDecoderOption_t _ASN1_SetDecoderOption = NULL;

ASN1error_e ASN1API ASN1_SetDecoderOption(ASN1decoding_t pDecoderInfo, ASN1optionparam_t* pOptParam)
{
    if (_ASN1_SetDecoderOption != NULL)
        return _ASN1_SetDecoderOption(pDecoderInfo, pOptParam);

    return ASN1_ERR_INTERNAL;
}

typedef ASN1error_e (ASN1API* ASN1_SetEncoderOption_t)(ASN1encoding_t pEncoderInfo, ASN1optionparam_t* pOptParam);
static ASN1_SetEncoderOption_t _ASN1_SetEncoderOption = NULL;

ASN1error_e ASN1API ASN1_SetEncoderOption(ASN1encoding_t pEncoderInfo, ASN1optionparam_t* pOptParam)
{
    if (_ASN1_SetEncoderOption != NULL)
        return _ASN1_SetEncoderOption(pEncoderInfo, pOptParam);

    return ASN1_ERR_INTERNAL;
}

typedef int (ASN1API* ASN1bitstring_cmp_t)(ASN1bitstring_t* p0, ASN1bitstring_t* p1, int p2);
static ASN1bitstring_cmp_t _ASN1bitstring_cmp = NULL;

int ASN1API ASN1bitstring_cmp(ASN1bitstring_t* p0, ASN1bitstring_t* p1, int p2)
{
    if (_ASN1bitstring_cmp != NULL)
        return _ASN1bitstring_cmp(p0, p1, p2);

    return 0;
}

typedef void (ASN1API* ASN1bitstring_free_t)(ASN1bitstring_t* p0);
static ASN1bitstring_free_t _ASN1bitstring_free = NULL;

void ASN1API ASN1bitstring_free(ASN1bitstring_t* p0)
{
    if (_ASN1bitstring_free != NULL)
        _ASN1bitstring_free(p0);
}

typedef int (ASN1API* ASN1char16string_cmp_t)(ASN1char16string_t* p0, ASN1char16string_t* p1);
static ASN1char16string_cmp_t _ASN1char16string_cmp = NULL;

int ASN1API ASN1char16string_cmp(ASN1char16string_t* p0, ASN1char16string_t* p1)
{
    if (_ASN1char16string_cmp != NULL)
        return _ASN1char16string_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1char16string_free_t)(ASN1char16string_t* p0);
static ASN1char16string_free_t _ASN1char16string_free = NULL;

void ASN1API ASN1char16string_free(ASN1char16string_t* p0)
{
    if (_ASN1char16string_free != NULL)
        _ASN1char16string_free(p0);
}

typedef int (ASN1API* ASN1char32string_cmp_t)(ASN1char32string_t* p0, ASN1char32string_t* p1);
static ASN1char32string_cmp_t _ASN1char32string_cmp = NULL;

int ASN1API ASN1char32string_cmp(ASN1char32string_t* p0, ASN1char32string_t* p1)
{
    if (_ASN1char32string_cmp != NULL)
        return _ASN1char32string_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1char32string_free_t)(ASN1char32string_t* p0);
static ASN1char32string_free_t _ASN1char32string_free = NULL;

void ASN1API ASN1char32string_free(ASN1char32string_t* p0)
{
    if (_ASN1char32string_free != NULL)
        _ASN1char32string_free(p0);
}

typedef int (ASN1API* ASN1charstring_cmp_t)(ASN1charstring_t* p0, ASN1charstring_t* p1);
static ASN1charstring_cmp_t _ASN1charstring_cmp = NULL;

int ASN1API ASN1charstring_cmp(ASN1charstring_t* p0, ASN1charstring_t* p1)
{
    if (_ASN1charstring_cmp != NULL)
        return _ASN1charstring_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1charstring_free_t)(ASN1charstring_t* p0);
static ASN1charstring_free_t _ASN1charstring_free = NULL;

void ASN1API ASN1charstring_free(ASN1charstring_t* p0)
{
    if (_ASN1charstring_free != NULL)
        _ASN1charstring_free(p0);
}

typedef int (ASN1API* ASN1generalizedtime_cmp_t)(ASN1generalizedtime_t* p0, ASN1generalizedtime_t* p1);
static ASN1generalizedtime_cmp_t _ASN1generalizedtime_cmp = NULL;

int ASN1API ASN1generalizedtime_cmp(ASN1generalizedtime_t* p0, ASN1generalizedtime_t* p1)
{
    if (_ASN1generalizedtime_cmp != NULL)
        return _ASN1generalizedtime_cmp(p0, p1);

    return 0;
}

typedef ASN1int32_t (ASN1API* ASN1intx2int32_t)(ASN1intx_t* p0);
static ASN1intx2int32_t _ASN1intx2int32 = NULL;

ASN1int32_t ASN1API ASN1intx2int32(ASN1intx_t* p0)
{
    if (_ASN1intx2int32 != NULL)
        return _ASN1intx2int32(p0);

    return 0;
}

typedef ASN1uint32_t (ASN1API* ASN1intx2uint32_t)(ASN1intx_t* p0);
static ASN1intx2uint32_t _ASN1intx2uint32 = NULL;

ASN1uint32_t ASN1API ASN1intx2uint32(ASN1intx_t* p0)
{
    if (_ASN1intx2uint32 != NULL)
        return _ASN1intx2uint32(p0);

    return 0;
}

typedef int (ASN1API* ASN1intx_cmp_t)(ASN1intx_t* p0, ASN1intx_t* p1);
static ASN1intx_cmp_t _ASN1intx_cmp = NULL;

int ASN1API ASN1intx_cmp(ASN1intx_t* p0, ASN1intx_t* p1)
{
    if (_ASN1intx_cmp != NULL)
        return _ASN1intx_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1intx_free_t)(ASN1intx_t* p0);
static ASN1intx_free_t _ASN1intx_free = NULL;

void ASN1API ASN1intx_free(ASN1intx_t* p0)
{
    if (_ASN1intx_free != NULL)
        _ASN1intx_free(p0);
}

typedef void (ASN1API* ASN1intx_setuint32_t)(ASN1intx_t* dst, ASN1uint32_t val);
static ASN1intx_setuint32_t _ASN1intx_setuint32 = NULL;

void ASN1API ASN1intx_setuint32(ASN1intx_t* dst, ASN1uint32_t val)
{
    if (_ASN1intx_setuint32 != NULL)
        _ASN1intx_setuint32(dst, val);
}

typedef ASN1uint32_t (ASN1API* ASN1intx_uoctets_t)(ASN1intx_t* p0);
static ASN1intx_uoctets_t _ASN1intx_uoctets = NULL;

ASN1uint32_t ASN1API ASN1intx_uoctets(ASN1intx_t* p0)
{
    if (_ASN1intx_uoctets != NULL)
        return _ASN1intx_uoctets(p0);

    return 0;
}

typedef int (ASN1API* ASN1intxisuint32_t)(ASN1intx_t* p0);
static ASN1intxisuint32_t _ASN1intxisuint32 = NULL;

int ASN1API ASN1intxisuint32(ASN1intx_t* p0)
{
    if (_ASN1intxisuint32 != NULL)
        return _ASN1intxisuint32(p0);

    return 0;
}

typedef int (ASN1API* ASN1objectidentifier2_cmp_t)(ASN1objectidentifier2_t* p0, ASN1objectidentifier2_t* p1);
static ASN1objectidentifier2_cmp_t _ASN1objectidentifier2_cmp = NULL;

int ASN1API ASN1objectidentifier2_cmp(ASN1objectidentifier2_t* p0, ASN1objectidentifier2_t* p1)
{
    if (_ASN1objectidentifier2_cmp != NULL)
        return _ASN1objectidentifier2_cmp(p0, p1);

    return 0;
}

typedef int (ASN1API* ASN1objectidentifier_cmp_t)(ASN1objectidentifier_t* p0, ASN1objectidentifier_t* p1);
static ASN1objectidentifier_cmp_t _ASN1objectidentifier_cmp = NULL;

int ASN1API ASN1objectidentifier_cmp(ASN1objectidentifier_t* p0, ASN1objectidentifier_t* p1)
{
    if (_ASN1objectidentifier_cmp != NULL)
        return _ASN1objectidentifier_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1objectidentifier_free_t)(ASN1objectidentifier_t* p0);
static ASN1objectidentifier_free_t _ASN1objectidentifier_free = NULL;

void ASN1API ASN1objectidentifier_free(ASN1objectidentifier_t* p0)
{
    if (_ASN1objectidentifier_free != NULL)
        _ASN1objectidentifier_free(p0);
}

typedef int (ASN1API* ASN1octetstring_cmp_t)(ASN1octetstring_t* p0, ASN1octetstring_t* p1);
static ASN1octetstring_cmp_t _ASN1octetstring_cmp = NULL;

int ASN1API ASN1octetstring_cmp(ASN1octetstring_t* p0, ASN1octetstring_t* p1)
{
    if (_ASN1octetstring_cmp != NULL)
        return _ASN1octetstring_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1octetstring_free_t)(ASN1octetstring_t* p0);
static ASN1octetstring_free_t _ASN1octetstring_free = NULL;

void ASN1API ASN1octetstring_free(ASN1octetstring_t* p0)
{
    if (_ASN1octetstring_free != NULL)
        _ASN1octetstring_free(p0);
}

typedef int (ASN1API* ASN1open_cmp_t)(ASN1open_t* p0, ASN1open_t* p1);
static ASN1open_cmp_t _ASN1open_cmp = NULL;

int ASN1API ASN1open_cmp(ASN1open_t* p0, ASN1open_t* p1)
{
    if (_ASN1open_cmp != NULL)
        return _ASN1open_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1open_free_t)(ASN1open_t* p0);
static ASN1open_free_t _ASN1open_free = NULL;

void ASN1API ASN1open_free(ASN1open_t* p0)
{
    if (_ASN1open_free != NULL)
        _ASN1open_free(p0);
}

typedef ASN1uint32_t (ASN1API* ASN1uint32_uoctets_t)(ASN1uint32_t p0);
static ASN1uint32_uoctets_t _ASN1uint32_uoctets = NULL;

ASN1uint32_t ASN1API ASN1uint32_uoctets(ASN1uint32_t p0)
{
    if (_ASN1uint32_uoctets != NULL)
        return _ASN1uint32_uoctets(p0);

    return 0;
}

typedef int (ASN1API* ASN1utctime_cmp_t)(ASN1utctime_t* p0, ASN1utctime_t* p1);
static ASN1utctime_cmp_t _ASN1utctime_cmp = NULL;

int ASN1API ASN1utctime_cmp(ASN1utctime_t* p0, ASN1utctime_t* p1)
{
    if (_ASN1utctime_cmp != NULL)
        return _ASN1utctime_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1utf8string_free_t)(ASN1wstring_t* p0);
static ASN1utf8string_free_t _ASN1utf8string_free = NULL;

void ASN1API ASN1utf8string_free(ASN1wstring_t* p0)
{
    if (_ASN1utf8string_free != NULL)
        _ASN1utf8string_free(p0);
}

typedef int (ASN1API* ASN1ztchar16string_cmp_t)(ASN1ztchar16string_t p0, ASN1ztchar16string_t p1);
static ASN1ztchar16string_cmp_t _ASN1ztchar16string_cmp = NULL;

int ASN1API ASN1ztchar16string_cmp(ASN1ztchar16string_t p0, ASN1ztchar16string_t p1)
{
    if (_ASN1ztchar16string_cmp != NULL)
        return _ASN1ztchar16string_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1ztchar16string_free_t)(ASN1ztchar16string_t p0);
static ASN1ztchar16string_free_t _ASN1ztchar16string_free = NULL;

void ASN1API ASN1ztchar16string_free(ASN1ztchar16string_t p0)
{
    if (_ASN1ztchar16string_free != NULL)
        _ASN1ztchar16string_free(p0);
}

typedef int (ASN1API* ASN1ztchar32string_cmp_t)(ASN1ztchar32string_t p0, ASN1ztchar32string_t p1);
static ASN1ztchar32string_cmp_t _ASN1ztchar32string_cmp = NULL;

int ASN1API ASN1ztchar32string_cmp(ASN1ztchar32string_t p0, ASN1ztchar32string_t p1)
{
    if (_ASN1ztchar32string_cmp != NULL)
        return _ASN1ztchar32string_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1ztchar32string_free_t)(ASN1ztchar32string_t p0);
static ASN1ztchar32string_free_t _ASN1ztchar32string_free = NULL;

void ASN1API ASN1ztchar32string_free(ASN1ztchar32string_t p0)
{
    if (_ASN1ztchar32string_free != NULL)
        _ASN1ztchar32string_free(p0);
}

typedef int (ASN1API* ASN1ztcharstring_cmp_t)(ASN1ztcharstring_t p0, ASN1ztcharstring_t p1);
static ASN1ztcharstring_cmp_t _ASN1ztcharstring_cmp = NULL;

int ASN1API ASN1ztcharstring_cmp(ASN1ztcharstring_t p0, ASN1ztcharstring_t p1)
{
    if (_ASN1ztcharstring_cmp != NULL)
        return _ASN1ztcharstring_cmp(p0, p1);

    return 0;
}

typedef void (ASN1API* ASN1ztcharstring_free_t)(ASN1ztcharstring_t p0);
static ASN1ztcharstring_free_t _ASN1ztcharstring_free = NULL;

void ASN1API ASN1ztcharstring_free(ASN1ztcharstring_t p0)
{
    if (_ASN1ztcharstring_free != NULL)
        _ASN1ztcharstring_free(p0);
}

BOOL asn1_initialize_module()
{
    HMODULE hModule = LoadLibraryW(L"msasn1.dll");

    if (hModule == NULL)
        return FALSE;
    else
    {
        _ASN1BERDecBitString = (ASN1BERDecBitString_t)GetProcAddress(hModule, "ASN1BERDecBitString");
        _ASN1BERDecBitString2 = (ASN1BERDecBitString2_t)GetProcAddress(hModule, "ASN1BERDecBitString2");
        _ASN1BERDecBool = (ASN1BERDecBool_t)GetProcAddress(hModule, "ASN1BERDecBool");
        _ASN1BERDecChar16String = (ASN1BERDecChar16String_t)GetProcAddress(hModule, "ASN1BERDecChar16String");
        _ASN1BERDecChar32String = (ASN1BERDecChar32String_t)GetProcAddress(hModule, "ASN1BERDecChar32String");
        _ASN1BERDecCharString = (ASN1BERDecCharString_t)GetProcAddress(hModule, "ASN1BERDecCharString");
        _ASN1BERDecCharacterString = (ASN1BERDecCharacterString_t)GetProcAddress(hModule, "ASN1BERDecCharacterString");
        _ASN1BERDecCheck = (ASN1BERDecCheck_t)GetProcAddress(hModule, "ASN1BERDecCheck");
        _ASN1BERDecDouble = (ASN1BERDecDouble_t)GetProcAddress(hModule, "ASN1BERDecDouble");
        _ASN1BERDecEmbeddedPdv = (ASN1BERDecEmbeddedPdv_t)GetProcAddress(hModule, "ASN1BERDecEmbeddedPdv");
        _ASN1BERDecEndOfContents = (ASN1BERDecEndOfContents_t)GetProcAddress(hModule, "ASN1BERDecEndOfContents");
        _ASN1BERDecEoid = (ASN1BERDecEoid_t)GetProcAddress(hModule, "ASN1BERDecEoid");
        _ASN1BERDecExplicitTag = (ASN1BERDecExplicitTag_t)GetProcAddress(hModule, "ASN1BERDecExplicitTag");
        _ASN1BERDecExternal = (ASN1BERDecExternal_t)GetProcAddress(hModule, "ASN1BERDecExternal");
        _ASN1BERDecFlush = (ASN1BERDecFlush_t)GetProcAddress(hModule, "ASN1BERDecFlush");
        _ASN1BERDecGeneralizedTime = (ASN1BERDecGeneralizedTime_t)GetProcAddress(hModule, "ASN1BERDecGeneralizedTime");
        _ASN1BERDecLength = (ASN1BERDecLength_t)GetProcAddress(hModule, "ASN1BERDecLength");
        _ASN1BERDecMultibyteString = (ASN1BERDecMultibyteString_t)GetProcAddress(hModule, "ASN1BERDecMultibyteString");
        _ASN1BERDecNotEndOfContents = (ASN1BERDecNotEndOfContents_t)GetProcAddress(hModule, "ASN1BERDecNotEndOfContents");
        _ASN1BERDecNull = (ASN1BERDecNull_t)GetProcAddress(hModule, "ASN1BERDecNull");
        _ASN1BERDecObjectIdentifier = (ASN1BERDecObjectIdentifier_t)GetProcAddress(hModule, "ASN1BERDecObjectIdentifier");
        _ASN1BERDecObjectIdentifier2 = (ASN1BERDecObjectIdentifier2_t)GetProcAddress(hModule, "ASN1BERDecObjectIdentifier2");
        _ASN1BERDecOctetString = (ASN1BERDecOctetString_t)GetProcAddress(hModule, "ASN1BERDecOctetString");
        _ASN1BERDecOctetString2 = (ASN1BERDecOctetString2_t)GetProcAddress(hModule, "ASN1BERDecOctetString2");
        _ASN1BERDecOpenType = (ASN1BERDecOpenType_t)GetProcAddress(hModule, "ASN1BERDecOpenType");
        _ASN1BERDecOpenType2 = (ASN1BERDecOpenType2_t)GetProcAddress(hModule, "ASN1BERDecOpenType2");
        _ASN1BERDecPeekTag = (ASN1BERDecPeekTag_t)GetProcAddress(hModule, "ASN1BERDecPeekTag");
        _ASN1BERDecS16Val = (ASN1BERDecS16Val_t)GetProcAddress(hModule, "ASN1BERDecS16Val");
        _ASN1BERDecS32Val = (ASN1BERDecS32Val_t)GetProcAddress(hModule, "ASN1BERDecS32Val");
        _ASN1BERDecS8Val = (ASN1BERDecS8Val_t)GetProcAddress(hModule, "ASN1BERDecS8Val");
        _ASN1BERDecSXVal = (ASN1BERDecSXVal_t)GetProcAddress(hModule, "ASN1BERDecSXVal");
        _ASN1BERDecSkip = (ASN1BERDecSkip_t)GetProcAddress(hModule, "ASN1BERDecSkip");
        _ASN1BERDecTag = (ASN1BERDecTag_t)GetProcAddress(hModule, "ASN1BERDecTag");
        _ASN1BERDecU16Val = (ASN1BERDecU16Val_t)GetProcAddress(hModule, "ASN1BERDecU16Val");
        _ASN1BERDecU32Val = (ASN1BERDecU32Val_t)GetProcAddress(hModule, "ASN1BERDecU32Val");
        _ASN1BERDecU8Val = (ASN1BERDecU8Val_t)GetProcAddress(hModule, "ASN1BERDecU8Val");
        _ASN1BERDecUTCTime = (ASN1BERDecUTCTime_t)GetProcAddress(hModule, "ASN1BERDecUTCTime");
        _ASN1BERDecUTF8String = (ASN1BERDecUTF8String_t)GetProcAddress(hModule, "ASN1BERDecUTF8String");
        _ASN1BERDecZeroChar16String = (ASN1BERDecZeroChar16String_t)GetProcAddress(hModule, "ASN1BERDecZeroChar16String");
        _ASN1BERDecZeroChar32String = (ASN1BERDecZeroChar32String_t)GetProcAddress(hModule, "ASN1BERDecZeroChar32String");
        _ASN1BERDecZeroCharString = (ASN1BERDecZeroCharString_t)GetProcAddress(hModule, "ASN1BERDecZeroCharString");
        _ASN1BERDecZeroMultibyteString = (ASN1BERDecZeroMultibyteString_t)GetProcAddress(hModule, "ASN1BERDecZeroMultibyteString");
        _ASN1BERDotVal2Eoid = (ASN1BERDotVal2Eoid_t)GetProcAddress(hModule, "ASN1BERDotVal2Eoid");
        _ASN1BEREncBitString = (ASN1BEREncBitString_t)GetProcAddress(hModule, "ASN1BEREncBitString");
        _ASN1BEREncBool = (ASN1BEREncBool_t)GetProcAddress(hModule, "ASN1BEREncBool");
        _ASN1BEREncChar16String = (ASN1BEREncChar16String_t)GetProcAddress(hModule, "ASN1BEREncChar16String");
        _ASN1BEREncChar32String = (ASN1BEREncChar32String_t)GetProcAddress(hModule, "ASN1BEREncChar32String");
        _ASN1BEREncCharString = (ASN1BEREncCharString_t)GetProcAddress(hModule, "ASN1BEREncCharString");
        _ASN1BEREncCharacterString = (ASN1BEREncCharacterString_t)GetProcAddress(hModule, "ASN1BEREncCharacterString");
        _ASN1BEREncCheck = (ASN1BEREncCheck_t)GetProcAddress(hModule, "ASN1BEREncCheck");
        _ASN1BEREncDouble = (ASN1BEREncDouble_t)GetProcAddress(hModule, "ASN1BEREncDouble");
        _ASN1BEREncEmbeddedPdv = (ASN1BEREncEmbeddedPdv_t)GetProcAddress(hModule, "ASN1BEREncEmbeddedPdv");
        _ASN1BEREncEndOfContents = (ASN1BEREncEndOfContents_t)GetProcAddress(hModule, "ASN1BEREncEndOfContents");
        _ASN1BEREncEoid = (ASN1BEREncEoid_t)GetProcAddress(hModule, "ASN1BEREncEoid");
        _ASN1BEREncExplicitTag = (ASN1BEREncExplicitTag_t)GetProcAddress(hModule, "ASN1BEREncExplicitTag");
        _ASN1BEREncExternal = (ASN1BEREncExternal_t)GetProcAddress(hModule, "ASN1BEREncExternal");
        _ASN1BEREncFlush = (ASN1BEREncFlush_t)GetProcAddress(hModule, "ASN1BEREncFlush");
        _ASN1BEREncGeneralizedTime = (ASN1BEREncGeneralizedTime_t)GetProcAddress(hModule, "ASN1BEREncGeneralizedTime");
        _ASN1BEREncLength = (ASN1BEREncLength_t)GetProcAddress(hModule, "ASN1BEREncLength");
        _ASN1BEREncMultibyteString = (ASN1BEREncMultibyteString_t)GetProcAddress(hModule, "ASN1BEREncMultibyteString");
        _ASN1BEREncNull = (ASN1BEREncNull_t)GetProcAddress(hModule, "ASN1BEREncNull");
        _ASN1BEREncObjectIdentifier = (ASN1BEREncObjectIdentifier_t)GetProcAddress(hModule, "ASN1BEREncObjectIdentifier");
        _ASN1BEREncObjectIdentifier2 = (ASN1BEREncObjectIdentifier2_t)GetProcAddress(hModule, "ASN1BEREncObjectIdentifier2");
        _ASN1BEREncOctetString = (ASN1BEREncOctetString_t)GetProcAddress(hModule, "ASN1BEREncOctetString");
        _ASN1BEREncOpenType = (ASN1BEREncOpenType_t)GetProcAddress(hModule, "ASN1BEREncOpenType");
        _ASN1BEREncRemoveZeroBits = (ASN1BEREncRemoveZeroBits_t)GetProcAddress(hModule, "ASN1BEREncRemoveZeroBits");
        _ASN1BEREncS32 = (ASN1BEREncS32_t)GetProcAddress(hModule, "ASN1BEREncS32");
        _ASN1BEREncSX = (ASN1BEREncSX_t)GetProcAddress(hModule, "ASN1BEREncSX");
        _ASN1BEREncTag = (ASN1BEREncTag_t)GetProcAddress(hModule, "ASN1BEREncTag");
        _ASN1BEREncU32 = (ASN1BEREncU32_t)GetProcAddress(hModule, "ASN1BEREncU32");
        _ASN1BEREncUTCTime = (ASN1BEREncUTCTime_t)GetProcAddress(hModule, "ASN1BEREncUTCTime");
        _ASN1BEREncUTF8String = (ASN1BEREncUTF8String_t)GetProcAddress(hModule, "ASN1BEREncUTF8String");
        _ASN1BEREncZeroMultibyteString = (ASN1BEREncZeroMultibyteString_t)GetProcAddress(hModule, "ASN1BEREncZeroMultibyteString");
        _ASN1BEREoid2DotVal = (ASN1BEREoid2DotVal_t)GetProcAddress(hModule, "ASN1BEREoid2DotVal");
        _ASN1CEREncBeginBlk = (ASN1CEREncBeginBlk_t)GetProcAddress(hModule, "ASN1CEREncBeginBlk");
        _ASN1CEREncBitString = (ASN1CEREncBitString_t)GetProcAddress(hModule, "ASN1CEREncBitString");
        _ASN1CEREncChar16String = (ASN1CEREncChar16String_t)GetProcAddress(hModule, "ASN1CEREncChar16String");
        _ASN1CEREncChar32String = (ASN1CEREncChar32String_t)GetProcAddress(hModule, "ASN1CEREncChar32String");
        _ASN1CEREncCharString = (ASN1CEREncCharString_t)GetProcAddress(hModule, "ASN1CEREncCharString");
        _ASN1CEREncEndBlk = (ASN1CEREncEndBlk_t)GetProcAddress(hModule, "ASN1CEREncEndBlk");
        _ASN1CEREncFlushBlkElement = (ASN1CEREncFlushBlkElement_t)GetProcAddress(hModule, "ASN1CEREncFlushBlkElement");
        _ASN1CEREncGeneralizedTime = (ASN1CEREncGeneralizedTime_t)GetProcAddress(hModule, "ASN1CEREncGeneralizedTime");
        _ASN1CEREncMultibyteString = (ASN1CEREncMultibyteString_t)GetProcAddress(hModule, "ASN1CEREncMultibyteString");
        _ASN1CEREncNewBlkElement = (ASN1CEREncNewBlkElement_t)GetProcAddress(hModule, "ASN1CEREncNewBlkElement");
        _ASN1CEREncOctetString = (ASN1CEREncOctetString_t)GetProcAddress(hModule, "ASN1CEREncOctetString");
        _ASN1CEREncUTCTime = (ASN1CEREncUTCTime_t)GetProcAddress(hModule, "ASN1CEREncUTCTime");
        _ASN1CEREncZeroMultibyteString = (ASN1CEREncZeroMultibyteString_t)GetProcAddress(hModule, "ASN1CEREncZeroMultibyteString");
        _ASN1DecAlloc = (ASN1DecAlloc_t)GetProcAddress(hModule, "ASN1DecAlloc");
        _ASN1DecRealloc = (ASN1DecRealloc_t)GetProcAddress(hModule, "ASN1DecRealloc");
        _ASN1DecSetError = (ASN1DecSetError_t)GetProcAddress(hModule, "ASN1DecSetError");
        _ASN1EncSetError = (ASN1EncSetError_t)GetProcAddress(hModule, "ASN1EncSetError");
        _ASN1Free = (ASN1Free_t)GetProcAddress(hModule, "ASN1Free");
        _ASN1_CloseDecoder = (ASN1_CloseDecoder_t)GetProcAddress(hModule, "ASN1_CloseDecoder");
        _ASN1_CloseEncoder = (ASN1_CloseEncoder_t)GetProcAddress(hModule, "ASN1_CloseEncoder");
        _ASN1_CloseEncoder2 = (ASN1_CloseEncoder2_t)GetProcAddress(hModule, "ASN1_CloseEncoder2");
        _ASN1_CloseModule = (ASN1_CloseModule_t)GetProcAddress(hModule, "ASN1_CloseModule");
        _ASN1_CreateDecoder = (ASN1_CreateDecoder_t)GetProcAddress(hModule, "ASN1_CreateDecoder");
        _ASN1_CreateDecoderEx = (ASN1_CreateDecoderEx_t)GetProcAddress(hModule, "ASN1_CreateDecoderEx");
        _ASN1_CreateEncoder = (ASN1_CreateEncoder_t)GetProcAddress(hModule, "ASN1_CreateEncoder");
        _ASN1_CreateModule = (ASN1_CreateModule_t)GetProcAddress(hModule, "ASN1_CreateModule");
        _ASN1_Decode = (ASN1_Decode_t)GetProcAddress(hModule, "ASN1_Decode");
        _ASN1_Encode = (ASN1_Encode_t)GetProcAddress(hModule, "ASN1_Encode");
        _ASN1_FreeDecoded = (ASN1_FreeDecoded_t)GetProcAddress(hModule, "ASN1_FreeDecoded");
        _ASN1_FreeEncoded = (ASN1_FreeEncoded_t)GetProcAddress(hModule, "ASN1_FreeEncoded");
        _ASN1_GetDecoderOption = (ASN1_GetDecoderOption_t)GetProcAddress(hModule, "ASN1_GetDecoderOption");
        _ASN1_GetEncoderOption = (ASN1_GetEncoderOption_t)GetProcAddress(hModule, "ASN1_GetEncoderOption");
        _ASN1_SetDecoderOption = (ASN1_SetDecoderOption_t)GetProcAddress(hModule, "ASN1_SetDecoderOption");
        _ASN1_SetEncoderOption = (ASN1_SetEncoderOption_t)GetProcAddress(hModule, "ASN1_SetEncoderOption");
        _ASN1bitstring_cmp = (ASN1bitstring_cmp_t)GetProcAddress(hModule, "ASN1bitstring_cmp");
        _ASN1bitstring_free = (ASN1bitstring_free_t)GetProcAddress(hModule, "ASN1bitstring_free");
        _ASN1char16string_cmp = (ASN1char16string_cmp_t)GetProcAddress(hModule, "ASN1char16string_cmp");
        _ASN1char16string_free = (ASN1char16string_free_t)GetProcAddress(hModule, "ASN1char16string_free");
        _ASN1char32string_cmp = (ASN1char32string_cmp_t)GetProcAddress(hModule, "ASN1char32string_cmp");
        _ASN1char32string_free = (ASN1char32string_free_t)GetProcAddress(hModule, "ASN1char32string_free");
        _ASN1charstring_cmp = (ASN1charstring_cmp_t)GetProcAddress(hModule, "ASN1charstring_cmp");
        _ASN1charstring_free = (ASN1charstring_free_t)GetProcAddress(hModule, "ASN1charstring_free");
        _ASN1generalizedtime_cmp = (ASN1generalizedtime_cmp_t)GetProcAddress(hModule, "ASN1generalizedtime_cmp");
        _ASN1intx2int32 = (ASN1intx2int32_t)GetProcAddress(hModule, "ASN1intx2int32");
        _ASN1intx2uint32 = (ASN1intx2uint32_t)GetProcAddress(hModule, "ASN1intx2uint32");
        _ASN1intx_cmp = (ASN1intx_cmp_t)GetProcAddress(hModule, "ASN1intx_cmp");
        _ASN1intx_free = (ASN1intx_free_t)GetProcAddress(hModule, "ASN1intx_free");
        _ASN1intx_setuint32 = (ASN1intx_setuint32_t)GetProcAddress(hModule, "ASN1intx_setuint32");
        _ASN1intx_uoctets = (ASN1intx_uoctets_t)GetProcAddress(hModule, "ASN1intx_uoctets");
        _ASN1intxisuint32 = (ASN1intxisuint32_t)GetProcAddress(hModule, "ASN1intxisuint32");
        _ASN1objectidentifier2_cmp = (ASN1objectidentifier2_cmp_t)GetProcAddress(hModule, "ASN1objectidentifier2_cmp");
        _ASN1objectidentifier_cmp = (ASN1objectidentifier_cmp_t)GetProcAddress(hModule, "ASN1objectidentifier_cmp");
        _ASN1objectidentifier_free = (ASN1objectidentifier_free_t)GetProcAddress(hModule, "ASN1objectidentifier_free");
        _ASN1octetstring_cmp = (ASN1octetstring_cmp_t)GetProcAddress(hModule, "ASN1octetstring_cmp");
        _ASN1octetstring_free = (ASN1octetstring_free_t)GetProcAddress(hModule, "ASN1octetstring_free");
        _ASN1open_cmp = (ASN1open_cmp_t)GetProcAddress(hModule, "ASN1open_cmp");
        _ASN1open_free = (ASN1open_free_t)GetProcAddress(hModule, "ASN1open_free");
        _ASN1uint32_uoctets = (ASN1uint32_uoctets_t)GetProcAddress(hModule, "ASN1uint32_uoctets");
        _ASN1utctime_cmp = (ASN1utctime_cmp_t)GetProcAddress(hModule, "ASN1utctime_cmp");
        _ASN1utf8string_free = (ASN1utf8string_free_t)GetProcAddress(hModule, "ASN1utf8string_free");
        _ASN1ztchar16string_cmp = (ASN1ztchar16string_cmp_t)GetProcAddress(hModule, "ASN1ztchar16string_cmp");
        _ASN1ztchar16string_free = (ASN1ztchar16string_free_t)GetProcAddress(hModule, "ASN1ztchar16string_free");
        _ASN1ztchar32string_cmp = (ASN1ztchar32string_cmp_t)GetProcAddress(hModule, "ASN1ztchar32string_cmp");
        _ASN1ztchar32string_free = (ASN1ztchar32string_free_t)GetProcAddress(hModule, "ASN1ztchar32string_free");
        _ASN1ztcharstring_cmp = (ASN1ztcharstring_cmp_t)GetProcAddress(hModule, "ASN1ztcharstring_cmp");
        _ASN1ztcharstring_free = (ASN1ztcharstring_free_t)GetProcAddress(hModule, "ASN1ztcharstring_free");
        return TRUE;
    }
}
