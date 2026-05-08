/* Copyright (C) Boris Nikolaus, Germany, 1996-1997. All rights reserved. */
/* Copyright (C) Microsoft Corporation 1997-1998, All rights reserved. */

#ifndef __ASN1_BASE_H__
#define __ASN1_BASE_H__

#include <Windows.h>
#include <pshpack8.h> /* Assume 8 byte packing throughout */

#ifdef __cplusplus
extern "C" {
#endif

    /* ------ Basic integer types ------ */

    typedef unsigned char   ASN1uint8_t;
    typedef signed char     ASN1int8_t;

    typedef unsigned short  ASN1uint16_t;
    typedef signed short    ASN1int16_t;

    typedef unsigned long   ASN1uint32_t;
    typedef signed long     ASN1int32_t;


    /* ------ Function modifiers ------ */

#ifdef ASN1LIB
#define ASN1_PUBLIC
#elif defined(ASN1C)
#define ASN1_PUBLIC
#else
#define ASN1_PUBLIC     __declspec(dllimport)
#endif
#define ASN1API         __stdcall
#define ASN1CALL        __stdcall


    /* ------ Basic ASN.1 types ------ */

    typedef ASN1uint8_t ASN1octet_t;

    typedef ASN1uint8_t ASN1bool_t;

    typedef struct tagASN1intx_t
    {
        ASN1uint32_t length;
        ASN1octet_t *value;
    }
    ASN1intx_t;

    typedef struct tagASN1octetstring_t
    {
        ASN1uint32_t length;
        ASN1octet_t *value;
    }
    ASN1octetstring_t;

    typedef struct tagASN1octetstring2_t
    {
        ASN1uint32_t length;
        ASN1octet_t value[1];
    }
    ASN1octetstring2_t;

    typedef struct ASN1iterator_s
    {
        struct ASN1iterator_s *next;
        void *value;
    }
    ASN1iterator_t;

    typedef struct tagASN1bitstring_t
    {
        ASN1uint32_t length;
        ASN1octet_t *value;
    }
    ASN1bitstring_t;

    typedef char ASN1char_t;

    typedef struct tagASN1charstring_t
    {
        ASN1uint32_t length;
        ASN1char_t *value;
    }
    ASN1charstring_t;

    typedef ASN1uint16_t ASN1char16_t;

    typedef struct tagASN1char16string_t
    {
        ASN1uint32_t length;
        ASN1char16_t *value;
    }
    ASN1char16string_t;

    typedef ASN1uint32_t ASN1char32_t;

    typedef struct tagASN1char32string_t
    {
        ASN1uint32_t length;
        ASN1char32_t *value;
    }
    ASN1char32string_t;

    typedef ASN1char_t *ASN1ztcharstring_t;
    typedef ASN1char16_t *ASN1ztchar16string_t;
    typedef ASN1char32_t *ASN1ztchar32string_t;

    typedef struct tagASN1wstring_t
    {
        ASN1uint32_t length;
        WCHAR *value;
    }
    ASN1wstring_t;

    typedef struct ASN1objectidentifier_s
    {
        struct ASN1objectidentifier_s *next;
        ASN1uint32_t value;
    }
    *ASN1objectidentifier_t;

    typedef struct tagASN1objectidentifier2_t
    {
        ASN1uint16_t count;
        ASN1uint32_t value[16];
    }
    ASN1objectidentifier2_t;

    typedef struct tagASN1encodedOID_t
    {
        ASN1uint16_t length;
        ASN1octet_t  *value;
    }
    ASN1encodedOID_t;

    typedef struct tagASN1stringtableentry_t
    {
        ASN1char32_t lower;
        ASN1char32_t upper;
        ASN1uint32_t value;
    }
    ASN1stringtableentry_t;

    typedef struct tagASN1stringtable_t
    {
        ASN1uint32_t length;
        ASN1stringtableentry_t *values;
    }
    ASN1stringtable_t;

    typedef ASN1ztcharstring_t ASN1objectdescriptor_t;

    typedef struct tagASN1generalizedtime_t
    {
        ASN1uint16_t year;
        ASN1uint8_t month;
        ASN1uint8_t day;
        ASN1uint8_t hour;
        ASN1uint8_t minute;
        ASN1uint8_t second;
        ASN1uint16_t millisecond;
        ASN1bool_t universal;
        ASN1int16_t diff;
    }
    ASN1generalizedtime_t;

    typedef struct tagASN1utctime_t
    {
        ASN1uint8_t year;
        ASN1uint8_t month;
        ASN1uint8_t day;
        ASN1uint8_t hour;
        ASN1uint8_t minute;
        ASN1uint8_t second;
        ASN1bool_t universal;
        ASN1int16_t diff;
    }
    ASN1utctime_t;

    typedef struct tagASN1open_t
    {
        // encoded
        ASN1uint32_t    length;
        union
        {
            void           *encoded;
            void           *value;
        };
    }
    ASN1open_t;

    typedef enum tagASN1blocktype_e
    {
        ASN1_DER_SET_OF_BLOCK,
    }
    ASN1blocktype_e;

    typedef ASN1int32_t     ASN1enum_t;     // enumerated type

    typedef ASN1uint16_t    ASN1choice_t;   // choice

    typedef ASN1uint32_t    ASN1magic_t;

    /* ------ Current version of this ASN.1 software ------ */

#define ASN1_MAKE_VERSION(major,minor)  (((major) << 16) | (minor))
#define ASN1_THIS_VERSION               ASN1_MAKE_VERSION(1,0)

    enum
    {
        ASN1_CHOICE_BASE      = 1,
        ASN1_CHOICE_INVALID   = -1,     // invalid choice
        ASN1_CHOICE_EXTENSION = 0,      // extension choice
    };



    /*
    Error codes for decoding functions:
    - err == 0:    data has been successfully decoded
    - err <  0:    fatal error has occured, no data has been generated
    err contains the error number
    - err >  0:    non-fatal event has occured, data has been generated
    err is a bit set of occured events
    */

    typedef enum tagASN1error_e
    {
        ASN1_SUCCESS        = 0,            /* success */

        // Teles specific error codes
        ASN1_ERR_INTERNAL   = (-1001),      /* internal error */
        ASN1_ERR_EOD        = (-1002),      /* unexpected end of data */
        ASN1_ERR_CORRUPT    = (-1003),      /* corrupted data */
        ASN1_ERR_LARGE      = (-1004),      /* value too large */
        ASN1_ERR_CONSTRAINT = (-1005),      /* constraint violated */
        ASN1_ERR_MEMORY     = (-1006),      /* out of memory */
        ASN1_ERR_OVERFLOW   = (-1007),      /* buffer overflow */
        ASN1_ERR_BADPDU     = (-1008),      /* function not supported for this pdu*/
        ASN1_ERR_BADARGS    = (-1009),      /* bad arguments to function call */
        ASN1_ERR_BADREAL    = (-1010),      /* bad real value */
        ASN1_ERR_BADTAG     = (-1011),      /* bad tag value met */
        ASN1_ERR_CHOICE     = (-1012),      /* bad choice value */
        ASN1_ERR_RULE       = (-1013),      /* bad encoding rule */
        ASN1_ERR_UTF8       = (-1014),      /* bad unicode (utf8) */

        // New error codes
        ASN1_ERR_PDU_TYPE   = (-1051),      /* bad pdu type */
        ASN1_ERR_NYI        = (-1052),      /* not yet implemented */

        // Teles specific warning codes
        ASN1_WRN_EXTENDED   = 1001,         /* skipped unknown extension(s) */
        ASN1_WRN_NOEOD      = 1002,         /* end of data expected */
    }
    ASN1error_e;

#define ASN1_SUCCEEDED(ret)     (((int) (ret)) >= 0)
#define ASN1_FAILED(ret)        (((int) (ret)) < 0)


    /* ------ Encoding rules ------ */

    typedef enum
    {
        ASN1_PER_RULE_ALIGNED       = 0x0001,
        ASN1_PER_RULE_UNALIGNED     = 0x0002, // not supported
        ASN1_PER_RULE               = ASN1_PER_RULE_ALIGNED | ASN1_PER_RULE_UNALIGNED,

        ASN1_BER_RULE_BER           = 0x0100,
        ASN1_BER_RULE_CER           = 0x0200,
        ASN1_BER_RULE_DER           = 0x0400,
        ASN1_BER_RULE               = ASN1_BER_RULE_BER | ASN1_BER_RULE_CER | ASN1_BER_RULE_DER,
    }
    ASN1encodingrule_e;

    /* ------ public structures ------ */

    typedef struct ASN1encoding_s   *ASN1encoding_t;
    typedef struct ASN1decoding_s   *ASN1decoding_t;

    typedef ASN1int32_t (ASN1CALL *ASN1PerEncFun_t)(ASN1encoding_t enc, void *data);
    typedef ASN1int32_t (ASN1CALL *ASN1PerDecFun_t)(ASN1decoding_t enc, void *data);
    typedef struct tagASN1PerFunArr_t
    {
        const ASN1PerEncFun_t *apfnEncoder;
        const ASN1PerDecFun_t *apfnDecoder;
    }
    ASN1PerFunArr_t;

    typedef ASN1int32_t (ASN1CALL *ASN1BerEncFun_t)(ASN1encoding_t enc, ASN1uint32_t tag, void *data);
    typedef ASN1int32_t (ASN1CALL *ASN1BerDecFun_t)(ASN1decoding_t enc, ASN1uint32_t tag, void *data);
    typedef struct tagASN1BerFunArr_t
    {
        const ASN1BerEncFun_t *apfnEncoder;
        const ASN1BerDecFun_t *apfnDecoder;
    }
    ASN1BerFunArr_t;

    typedef void (ASN1CALL *ASN1GenericFun_t)(void);
    typedef void (ASN1CALL *ASN1FreeFun_t)(void *data);

    typedef struct tagASN1module_t
    {
        ASN1magic_t             nModuleName;
        ASN1encodingrule_e      eRule;
        ASN1uint32_t            dwFlags;
        ASN1uint32_t            cPDUs;

        const ASN1FreeFun_t    *apfnFreeMemory;
        const ASN1uint32_t     *acbStructSize;
        union
        {
            ASN1PerFunArr_t     PER;
            ASN1BerFunArr_t     BER;
        };
    }
    *ASN1module_t;


    struct ASN1encoding_s
    {
        ASN1magic_t         magic;  /* magic for this structure */
        ASN1uint32_t        version;/* version number of this library */
        ASN1module_t        module; /* module this encoding_t depends to */
        ASN1octet_t        *buf;    /* buffer to encode into */
        ASN1uint32_t        size;   /* current size of buffer */
        ASN1uint32_t        len;    /* len of encoded data in buffer */
        ASN1error_e         err;    /* error code for last encoding */
        ASN1uint32_t        bit;
        ASN1octet_t        *pos;
        ASN1uint32_t        cbExtraHeader;
        ASN1encodingrule_e  eRule;
        ASN1uint32_t        dwFlags;
    };

    struct ASN1decoding_s
    {
        ASN1magic_t         magic;  /* magic for this structure */
        ASN1uint32_t        version;/* version number of this library */
        ASN1module_t        module; /* module this decoding_t depends to */
        ASN1octet_t        *buf;    /* buffer to decode from */
        ASN1uint32_t        size;   /* size of buffer */
        ASN1uint32_t        len;    /* len of decoded data in buffer */
        ASN1error_e         err;    /* error code for last decoding */
        ASN1uint32_t        bit;
        ASN1octet_t        *pos;
        ASN1encodingrule_e  eRule;
        ASN1uint32_t        dwFlags;
    };


    /* --- flags for functions --- */

#define ASN1DECFREE_NON_PDU_ID    ((ASN1uint32_t) -1)

    enum
    {
        ASN1FLAGS_NONE              = 0x00000000L, /* no flags */
        ASN1FLAGS_NOASSERT          = 0x00001000L, /* no asertion */
    };

    enum
    {
        ASN1ENCODE_APPEND           = 0x00000001L, /* append to current buffer*/
        ASN1ENCODE_REUSEBUFFER      = 0x00000004L, /* empty destination buffer */
        ASN1ENCODE_SETBUFFER        = 0x00000008L, /* use a user-given destination buffer */
        ASN1ENCODE_ALLOCATEBUFFER   = 0x00000010L, /* do not free/reuse buffer */
        ASN1ENCODE_NOASSERT         = ASN1FLAGS_NOASSERT, /* no asertion */
    };

    enum
    {
        ASN1DECODE_APPENDED         = 0x00000001L, /* continue behind last pdu*/
        ASN1DECODE_REWINDBUFFER     = 0x00000004L, /* rescan from buffer start*/
        ASN1DECODE_SETBUFFER        = 0x00000008L, /* use a user-given src buffer */
        ASN1DECODE_AUTOFREEBUFFER   = 0x00000010L, /* Assume responsibility for allocated buffer */
        ASN1DECODE_NOASSERT         = ASN1FLAGS_NOASSERT, /* no asertion */
    };

    /* ------ public basic ASN.1 API ------ */

    extern ASN1module_t ASN1API ASN1_CreateModule
    (
        ASN1uint32_t            nVersion,
        ASN1encodingrule_e      eRule,
        ASN1uint32_t            dwFlags, /* ASN1FLAGS_NONE or ASN1FLAGS_NOASSERT */
        ASN1uint32_t            cPDU,
        const ASN1GenericFun_t  apfnEncoder[],
        const ASN1GenericFun_t  apfnDecoder[],
        const ASN1FreeFun_t     apfnFreeMemory[],
        const ASN1uint32_t      acbStructSize[],
        ASN1magic_t             nModuleName
    );

    extern void ASN1API ASN1_CloseModule
    (
        ASN1module_t        pModule
    );

    extern ASN1error_e ASN1API ASN1_CreateEncoder
    (
        ASN1module_t        pModule,
        ASN1encoding_t     *ppEncoderInfo,
        ASN1octet_t        *pbBuf,
        ASN1uint32_t        cbBufSize,
        ASN1encoding_t      pParent
    );

    extern ASN1error_e ASN1API ASN1_Encode
    (
        ASN1encoding_t      pEncoderInfo,
        void               *pDataStruct,
        ASN1uint32_t        nPduNum,
        ASN1uint32_t        dwFlags,
        ASN1octet_t        *pbBuf,
        ASN1uint32_t        cbBufSize
    );

    extern void ASN1API ASN1_CloseEncoder
    (
        ASN1encoding_t      pEncoderInfo
    );

    extern void ASN1API ASN1_CloseEncoder2
    (
        ASN1encoding_t      pEncoderInfo
    );

    extern ASN1error_e ASN1API ASN1_CreateDecoder
    (
        ASN1module_t        pModule,
        ASN1decoding_t     *ppDecoderInfo,
        ASN1octet_t        *pbBuf,
        ASN1uint32_t        cbBufSize,
        ASN1decoding_t      pParent
    );

    extern ASN1error_e ASN1API ASN1_CreateDecoderEx
    (
        ASN1module_t        pModule,
        ASN1decoding_t     *ppDecoderInfo,
        ASN1octet_t        *pbBuf,
        ASN1uint32_t        cbBufSize,
        ASN1decoding_t      pParent,
        ASN1uint32_t        dwFlags
    );

    extern ASN1error_e ASN1API ASN1_Decode
    (
        ASN1decoding_t      pDecoderInfo,
        void              **ppDataStruct,
        ASN1uint32_t        nPduNum,
        ASN1uint32_t        dwFlags,
        ASN1octet_t        *pbBuf,
        ASN1uint32_t        cbBufSize
    );

    extern void ASN1API ASN1_CloseDecoder
    (
        ASN1decoding_t      pDecoderInfo
    );


    extern void ASN1API ASN1_FreeEncoded
    (
        ASN1encoding_t      pEncoderInfo,
        void               *pBuf
    );

    extern void ASN1API ASN1_FreeDecoded
    (
        ASN1decoding_t      pDecoderInfo,
        void               *pDataStruct,
        ASN1uint32_t        nPduNum
    );


    /* ------ public advanced ASN.1 API ------ */

    typedef enum
    {
        // common set option
        ASN1OPT_CHANGE_RULE                 = 0x101,

        // common get option
        ASN1OPT_GET_RULE                    = 0x201,

        // set encoder option
        ASN1OPT_NOT_REUSE_BUFFER            = 0x301,
        ASN1OPT_REWIND_BUFFER               = 0x302,

        // get encoder option

        // set decoder option
        ASN1OPT_SET_DECODED_BUFFER          = 0x501,
        ASN1OPT_DEL_DECODED_BUFFER          = 0x502,

        // get decoder option
        ASN1OPT_GET_DECODED_BUFFER_SIZE     = 0x601,
    }
    ASN1option_e;

    typedef struct tagASN1optionparam_t
    {
        ASN1option_e    eOption;
        union
        {
            ASN1encodingrule_e              eRule;
            ASN1uint32_t                    cbRequiredDecodedBufSize;
            struct
            {
                ASN1octet_t    *pbBuf;
                ASN1uint32_t    cbBufSize;
            }                               Buffer;
        };
    }
    ASN1optionparam_t, ASN1optionparam_s;


    extern ASN1error_e ASN1API ASN1_SetEncoderOption
    (
        ASN1encoding_t      pEncoderInfo,
        ASN1optionparam_t  *pOptParam
    );

    extern ASN1error_e ASN1API ASN1_GetEncoderOption
    (
        ASN1encoding_t      pEncoderInfo,
        ASN1optionparam_t  *pOptParam
    );

    extern ASN1error_e ASN1API ASN1_SetDecoderOption
    (
        ASN1decoding_t      pDecoderInfo,
        ASN1optionparam_t  *pOptParam
    );

    extern ASN1error_e ASN1API ASN1_GetDecoderOption
    (
        ASN1decoding_t      pDecoderInfo,
        ASN1optionparam_t  *pOptParam
    );


    /* ------ internal ASN.1 API ------ */

    extern void ASN1API ASN1bitstring_free(ASN1bitstring_t *);
    extern void ASN1API ASN1octetstring_free(ASN1octetstring_t *);
    extern void ASN1API ASN1objectidentifier_free(ASN1objectidentifier_t *);
    extern void ASN1API ASN1charstring_free(ASN1charstring_t *);
    extern void ASN1API ASN1char16string_free(ASN1char16string_t *);
    extern void ASN1API ASN1char32string_free(ASN1char32string_t *);
    extern void ASN1API ASN1ztcharstring_free(ASN1ztcharstring_t);
    extern void ASN1API ASN1ztchar16string_free(ASN1ztchar16string_t);
    extern void ASN1API ASN1ztchar32string_free(ASN1ztchar32string_t);
    extern void ASN1API ASN1open_free(ASN1open_t *);
    extern void ASN1API ASN1utf8string_free(ASN1wstring_t *);

    extern void * ASN1API ASN1DecAlloc(ASN1decoding_t dec, ASN1uint32_t size);
    extern void * ASN1API ASN1DecRealloc(ASN1decoding_t dec, void *ptr, ASN1uint32_t size);
    extern void   ASN1API ASN1Free(void *ptr);

    extern ASN1error_e ASN1API ASN1EncSetError(ASN1encoding_t enc, ASN1error_e err);
    extern ASN1error_e ASN1API ASN1DecSetError(ASN1decoding_t dec, ASN1error_e err);

    extern void ASN1API ASN1intx_sub(ASN1intx_t *, ASN1intx_t *, ASN1intx_t *);
    extern ASN1uint32_t ASN1API ASN1intx_uoctets(ASN1intx_t *);
    extern void ASN1API ASN1intx_free(ASN1intx_t *);
    extern void ASN1API ASN1intx_add(ASN1intx_t *, ASN1intx_t *, ASN1intx_t *);
    extern ASN1int32_t ASN1intx2int32(ASN1intx_t *val);
    extern ASN1uint32_t ASN1intx2uint32(ASN1intx_t *val);
    extern int ASN1intxisuint32(ASN1intx_t *val);
    extern void ASN1intx_setuint32(ASN1intx_t *dst, ASN1uint32_t val);

    extern void ASN1API ASN1DbgMemTrackDumpCurrent ( ASN1uint32_t nModuleName );

    extern ASN1uint32_t ASN1API ASN1uint32_uoctets(ASN1uint32_t);

    extern int ASN1API ASN1objectidentifier_cmp(ASN1objectidentifier_t *v1, ASN1objectidentifier_t *v2);
    extern int ASN1API ASN1objectidentifier2_cmp(ASN1objectidentifier2_t *v1, ASN1objectidentifier2_t *v2);
    extern int ASN1API ASN1bitstring_cmp(ASN1bitstring_t *, ASN1bitstring_t *, int);
    extern int ASN1API ASN1octetstring_cmp(ASN1octetstring_t *, ASN1octetstring_t *);
    extern int ASN1API ASN1objectidentifier_cmp(ASN1objectidentifier_t *, ASN1objectidentifier_t *);
    extern int ASN1API ASN1charstring_cmp(ASN1charstring_t *, ASN1charstring_t *);
    extern int ASN1API ASN1char16string_cmp(ASN1char16string_t *, ASN1char16string_t *);
    extern int ASN1API ASN1char32string_cmp(ASN1char32string_t *, ASN1char32string_t *);
    extern int ASN1API ASN1ztcharstring_cmp(ASN1ztcharstring_t, ASN1ztcharstring_t);
    extern int ASN1API ASN1ztchar16string_cmp(ASN1ztchar16string_t, ASN1ztchar16string_t);
    extern int ASN1API ASN1open_cmp(ASN1open_t *, ASN1open_t *);
    extern int ASN1API ASN1generalizedtime_cmp(ASN1generalizedtime_t *, ASN1generalizedtime_t *);
    extern int ASN1API ASN1utctime_cmp(ASN1utctime_t *, ASN1utctime_t *);


    /* --------------------------------------------------------- */
    /* The following is not supported.                           */
    /* --------------------------------------------------------- */

    typedef enum tagASN1real_e
    {
        eReal_Normal,
        eReal_PlusInfinity,
        eReal_MinusInfinity
    }
    ASN1real_e;

    typedef struct tagASN1real_t
    {
        ASN1real_e type;
        ASN1intx_t mantissa;
        ASN1uint32_t base;
        ASN1intx_t exponent;
    }
    ASN1real_t;

    typedef struct tagASN1external_t
    {
#   define ASN1external_data_value_descriptor_o 0
        ASN1octet_t o[1];
        struct ASN1external_identification_s
        {
            ASN1uint8_t o;
            union
            {
#            define ASN1external_identification_syntax_o 1
                ASN1objectidentifier_t syntax;
#            define ASN1external_identification_presentation_context_id_o 2
                ASN1uint32_t presentation_context_id;
#            define ASN1external_identification_context_negotiation_o 3
                struct ASN1external_identification_context_negotiation_s
                {
                    ASN1uint32_t presentation_context_id;
                    ASN1objectidentifier_t transfer_syntax;
                } context_negotiation;
            } u;
        } identification;
        ASN1objectdescriptor_t data_value_descriptor;
        struct ASN1external_data_value_s
        {
            ASN1uint8_t o;
            union
            {
#            define ASN1external_data_value_notation_o 0
                ASN1open_t notation;
#            define ASN1external_data_value_encoded_o 1
                ASN1bitstring_t encoded;
            } u;
        } data_value;
    }
    ASN1external_t;

    typedef struct ASN1external_identification_s ASN1external_identification_t;
    typedef struct ASN1external_identification_context_negotiation_s ASN1external_identification_context_negotiation_t;
    typedef struct ASN1external_data_value_s ASN1external_data_value_t;

    typedef struct tagASN1embeddedpdv_t
    {
        struct ASN1embeddedpdv_identification_s
        {
            ASN1uint8_t o;
            union
            {
#            define ASN1embeddedpdv_identification_syntaxes_o 0
                struct ASN1embeddedpdv_identification_syntaxes_s
                {
                    ASN1objectidentifier_t abstract;
                    ASN1objectidentifier_t transfer;
                } syntaxes;
#            define ASN1embeddedpdv_identification_syntax_o 1
                ASN1objectidentifier_t syntax;
#            define ASN1embeddedpdv_identification_presentation_context_id_o 2
                ASN1uint32_t presentation_context_id;
#            define ASN1embeddedpdv_identification_context_negotiation_o 3
                struct ASN1embeddedpdv_identification_context_negotiation_s
                {
                    ASN1uint32_t presentation_context_id;
                    ASN1objectidentifier_t transfer_syntax;
                } context_negotiation;
#            define ASN1embeddedpdv_identification_transfer_syntax_o 4
                ASN1objectidentifier_t transfer_syntax;
#            define ASN1embeddedpdv_identification_fixed_o 5
            } u;
        } identification;
        struct ASN1embeddedpdv_data_value_s
        {
            ASN1uint8_t o;
            union
            {
#            define ASN1embeddedpdv_data_value_notation_o 0
                ASN1open_t notation;
#            define ASN1embeddedpdv_data_value_encoded_o 1
                ASN1bitstring_t encoded;
            } u;
        } data_value;
    }
    ASN1embeddedpdv_t;

    typedef struct ASN1embeddedpdv_identification_s ASN1embeddedpdv_identification_t;
    typedef struct ASN1embeddedpdv_identification_syntaxes_s ASN1embeddedpdv_identification_syntaxes_t;
    typedef struct ASN1embeddedpdv_identification_context_negotiation_s ASN1embeddedpdv_identification_context_negotiation_t;
    typedef struct ASN1embeddedpdv_data_value_s ASN1embeddedpdv_data_value_t;

    typedef struct tagASN1characterstring_t
    {
        struct ASN1characterstring_identification_s
        {
            ASN1uint8_t o;
            union
            {
#            define ASN1characterstring_identification_syntaxes_o 0
                struct ASN1characterstring_identification_syntaxes_s
                {
                    ASN1objectidentifier_t abstract;
                    ASN1objectidentifier_t transfer;
                } syntaxes;
#            define ASN1characterstring_identification_syntax_o 1
                ASN1objectidentifier_t syntax;
#            define ASN1characterstring_identification_presentation_context_id_o 2
                ASN1uint32_t presentation_context_id;
#            define ASN1characterstring_identification_context_negotiation_o 3
                struct ASN1characterstring_identification_context_negotiation_s
                {
                    ASN1uint32_t presentation_context_id;
                    ASN1objectidentifier_t transfer_syntax;
                } context_negotiation;
#            define ASN1characterstring_identification_transfer_syntax_o 4
                ASN1objectidentifier_t transfer_syntax;
#            define ASN1characterstring_identification_fixed_o 5
            } u;
        } identification;
        struct ASN1characterstring_data_value_s
        {
            ASN1uint8_t o;
            union
            {
#            define ASN1characterstring_data_value_notation_o 0
                ASN1open_t notation;
#            define ASN1characterstring_data_value_encoded_o 1
                ASN1octetstring_t encoded;
            } u;
        } data_value;
    } ASN1characterstring_t;

    typedef struct ASN1characterstring_identification_s ASN1characterstring_identification_t;
    typedef struct ASN1characterstring_identification_syntaxes_s ASN1characterstring_identification_syntaxes_t;
    typedef struct ASN1characterstring_identification_context_negotiation_s ASN1characterstring_identification_context_negotiation_t;
    typedef struct ASN1characterstring_data_value_s ASN1characterstring_data_value_t;


    extern void ASN1API ASN1real_free(ASN1real_t *);
    extern void ASN1API ASN1external_free(ASN1external_t *);
    extern void ASN1API ASN1embeddedpdv_free(ASN1embeddedpdv_t *);
    extern void ASN1API ASN1characterstring_free(ASN1characterstring_t *);

    extern int WINAPI ASN1BEREncCharString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t,ASN1char_t *);
    extern int WINAPI ASN1BEREncChar16String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t,ASN1char16_t *);
    extern int WINAPI ASN1BEREncChar32String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t,ASN1char32_t *);
    extern int WINAPI ASN1BEREncOctetString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t len,ASN1octet_t *val);
    extern int WINAPI ASN1BEREncBitString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t,ASN1octet_t *);
    extern int WINAPI ASN1BEREncDouble(ASN1encoding_t enc,ASN1uint32_t tag,double);
    extern int WINAPI ASN1BEREncGeneralizedTime(ASN1encoding_t enc,ASN1uint32_t tag,ASN1generalizedtime_t *);
    extern int WINAPI ASN1BEREncS32(ASN1encoding_t enc,ASN1uint32_t tag,ASN1int32_t);
    extern int WINAPI ASN1BEREncSX(ASN1encoding_t enc,ASN1uint32_t tag,ASN1intx_t *);
    extern int WINAPI ASN1BEREncZeroMultibyteString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1ztcharstring_t);
    extern int WINAPI ASN1BEREncMultibyteString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1charstring_t *);
    extern int WINAPI ASN1BEREncNull(ASN1encoding_t enc,ASN1uint32_t tag);
    extern int WINAPI ASN1BEREncObjectIdentifier(ASN1encoding_t enc,ASN1uint32_t tag,ASN1objectidentifier_t *);
    extern int WINAPI ASN1BEREncObjectIdentifier2(ASN1encoding_t enc,ASN1uint32_t tag,ASN1objectidentifier2_t *val);
    extern int WINAPI ASN1BEREncRemoveZeroBits(ASN1uint32_t *,ASN1octet_t *);
    extern int WINAPI ASN1BEREncUTCTime(ASN1encoding_t enc,ASN1uint32_t tag,ASN1utctime_t *);
    extern int WINAPI ASN1BEREncFlush(ASN1encoding_t enc);
    extern int WINAPI ASN1BEREncOpenType(ASN1encoding_t enc,ASN1open_t *);
    extern int WINAPI ASN1BERDecExplicitTag(ASN1decoding_t dec,ASN1uint32_t tag,ASN1decoding_t *dd,ASN1octet_t **di);
    extern int WINAPI ASN1BERDecEndOfContents(ASN1decoding_t dec,ASN1decoding_t dd,ASN1octet_t *di);
    extern int WINAPI ASN1BERDecOctetString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1octetstring_t *val);
    extern int WINAPI ASN1BERDecOctetString2(ASN1decoding_t dec,ASN1uint32_t tag,ASN1octetstring_t *val);
    extern int WINAPI ASN1BERDecBitString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1bitstring_t *);
    extern int WINAPI ASN1BERDecBitString2(ASN1decoding_t dec,ASN1uint32_t tag,ASN1bitstring_t *);
    extern int WINAPI ASN1BERDecChar16String(ASN1decoding_t dec,ASN1uint32_t tag,ASN1char16string_t *);
    extern int WINAPI ASN1BERDecChar32String(ASN1decoding_t dec,ASN1uint32_t tag,ASN1char32string_t *);
    extern int WINAPI ASN1BERDecCharString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1charstring_t *);
    extern int WINAPI ASN1BERDecDouble(ASN1decoding_t dec,ASN1uint32_t tag,double *);
    extern int WINAPI ASN1BERDecGeneralizedTime(ASN1decoding_t dec,ASN1uint32_t tag,ASN1generalizedtime_t *);
    extern int WINAPI ASN1BERDecZeroMultibyteString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1ztcharstring_t *);
    extern int WINAPI ASN1BERDecMultibyteString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1charstring_t *);
    extern int WINAPI ASN1BERDecNull(ASN1decoding_t dec,ASN1uint32_t tag);
    extern int WINAPI ASN1BERDecObjectIdentifier(ASN1decoding_t dec,ASN1uint32_t tag,ASN1objectidentifier_t *);
    extern int WINAPI ASN1BERDecObjectIdentifier2(ASN1decoding_t dec,ASN1uint32_t tag,ASN1objectidentifier2_t *);
    extern int WINAPI ASN1BERDecS8Val(ASN1decoding_t dec,ASN1uint32_t tag,ASN1int8_t *);
    extern int WINAPI ASN1BERDecS16Val(ASN1decoding_t dec,ASN1uint32_t tag,ASN1int16_t *);
    extern int WINAPI ASN1BERDecS32Val(ASN1decoding_t dec,ASN1uint32_t tag,ASN1int32_t *);
    extern int WINAPI ASN1BERDecSXVal(ASN1decoding_t dec,ASN1uint32_t tag,ASN1intx_t *);
    extern int WINAPI ASN1BERDecU8Val(ASN1decoding_t dec,ASN1uint32_t tag,ASN1uint8_t *);
    extern int WINAPI ASN1BERDecU16Val(ASN1decoding_t dec,ASN1uint32_t tag,ASN1uint16_t *);
    extern int WINAPI ASN1BERDecUTCTime(ASN1decoding_t dec,ASN1uint32_t tag,ASN1utctime_t *);
    extern int WINAPI ASN1BERDecZeroChar16String(ASN1decoding_t dec,ASN1uint32_t tag,ASN1ztchar16string_t *);
    extern int WINAPI ASN1BERDecZeroChar32String(ASN1decoding_t dec,ASN1uint32_t tag,ASN1ztchar32string_t *);
    extern int WINAPI ASN1BERDecZeroCharString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1ztcharstring_t *);
    extern int WINAPI ASN1BERDecSkip(ASN1decoding_t dec);
    extern int WINAPI ASN1BERDecFlush(ASN1decoding_t dec);
    extern int WINAPI ASN1BERDecOpenType(ASN1decoding_t dec,ASN1open_t *);
    extern int WINAPI ASN1BERDecOpenType2(ASN1decoding_t dec,ASN1open_t *);
    extern int WINAPI ASN1BEREncCheck(ASN1encoding_t enc,ASN1uint32_t noctets);
    extern int WINAPI ASN1BEREncTag(ASN1encoding_t enc,ASN1uint32_t tag);
    extern int WINAPI ASN1BEREncExplicitTag(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t *pLengthOffset);
    extern int WINAPI ASN1BEREncEndOfContents(ASN1encoding_t enc,ASN1uint32_t LengthOffset);
    extern int WINAPI ASN1BEREncLength(ASN1encoding_t enc,ASN1uint32_t len);
    extern int WINAPI ASN1BERDecCheck(ASN1decoding_t dec,ASN1uint32_t len);
    extern int WINAPI ASN1BERDecTag(ASN1decoding_t dec,ASN1uint32_t tag,ASN1uint32_t *constructed);
    extern int WINAPI ASN1BERDecLength(ASN1decoding_t dec,ASN1uint32_t *len,ASN1uint32_t *infinite);
    extern int WINAPI ASN1BERDecNotEndOfContents(ASN1decoding_t dec,ASN1octet_t *di);
    extern int WINAPI ASN1BERDecPeekTag(ASN1decoding_t dec,ASN1uint32_t *tag);
    extern int WINAPI ASN1BEREncU32(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t);
    extern int WINAPI ASN1BERDecU32Val(ASN1decoding_t dec,ASN1uint32_t tag,ASN1uint32_t *val);
    extern int WINAPI ASN1BEREncBool(ASN1encoding_t enc,ASN1uint32_t tag,ASN1bool_t);
    extern int WINAPI ASN1BERDecBool(ASN1decoding_t dec,ASN1uint32_t tag,ASN1bool_t *);
    extern int WINAPI ASN1BEREncEoid(ASN1encoding_t enc,ASN1uint32_t tag,ASN1encodedOID_t *);
    extern int WINAPI ASN1BERDecEoid(ASN1decoding_t dec,ASN1uint32_t tag,ASN1encodedOID_t *);
    extern int WINAPI ASN1BERDotVal2Eoid(ASN1encoding_t enc,char *pszDotVal,ASN1encodedOID_t *pOut);
    extern int WINAPI ASN1BEREoid2DotVal(ASN1decoding_t dec,ASN1encodedOID_t *pIn,char **ppszDotVal);
    extern void WINAPI ASN1BEREoid_free(ASN1encodedOID_t *);
    extern int WINAPI ASN1BEREncUTF8String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t length,WCHAR *value);
    extern int WINAPI ASN1BERDecUTF8String(ASN1decoding_t dec,ASN1uint32_t tag,ASN1wstring_t *val);
    extern int WINAPI ASN1CEREncCharString(ASN1encoding_t enc,ASN1uint32_t,ASN1uint32_t,ASN1char_t *);
    extern int WINAPI ASN1CEREncChar16String(ASN1encoding_t enc,ASN1uint32_t,ASN1uint32_t,ASN1char16_t *);
    extern int WINAPI ASN1CEREncChar32String(ASN1encoding_t enc,ASN1uint32_t,ASN1uint32_t,ASN1char32_t *);
    extern int WINAPI ASN1CEREncBitString(ASN1encoding_t enc,ASN1uint32_t,ASN1uint32_t,ASN1octet_t *);
    extern int WINAPI ASN1CEREncGeneralizedTime(ASN1encoding_t enc,ASN1uint32_t,ASN1generalizedtime_t *);
    extern int WINAPI ASN1CEREncZeroMultibyteString(ASN1encoding_t enc,ASN1uint32_t,ASN1ztcharstring_t);
    extern int WINAPI ASN1CEREncMultibyteString(ASN1encoding_t enc,ASN1uint32_t,ASN1charstring_t *);
    extern int WINAPI ASN1CEREncOctetString(ASN1encoding_t enc,ASN1uint32_t,ASN1uint32_t,ASN1octet_t *);
    extern int WINAPI ASN1CEREncUTCTime(ASN1encoding_t enc,ASN1uint32_t,ASN1utctime_t *);
    extern int WINAPI ASN1CEREncBeginBlk(ASN1encoding_t enc,ASN1blocktype_e eBlkType,void **ppBlk);
    extern int WINAPI ASN1CEREncNewBlkElement(void *pBlk,ASN1encoding_t *enc2);
    extern int WINAPI ASN1CEREncFlushBlkElement(void *pBlk);
    extern int WINAPI ASN1CEREncEndBlk(void *pBlk);

    extern int WINAPI ASN1DEREncGeneralizedTime(ASN1encoding_t enc,ASN1uint32_t tag,ASN1generalizedtime_t *val);
    extern int WINAPI ASN1DEREncUTCTime(ASN1encoding_t enc,ASN1uint32_t tag,ASN1utctime_t *val);
    extern int WINAPI ASN1DEREncBeginBlk(ASN1encoding_t enc,ASN1blocktype_e eBlkType,void **ppBlk);
    extern int WINAPI ASN1DEREncNewBlkElement(void *pBlk,ASN1encoding_t *enc2);
    extern int WINAPI ASN1DEREncFlushBlkElement(void *pBlk);
    extern int WINAPI ASN1DEREncEndBlk(void *pBlk);
    extern int WINAPI ASN1DEREncCharString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t len,ASN1char_t *val);
    extern int WINAPI ASN1DEREncChar16String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t len,ASN1char16_t *val);
    extern int WINAPI ASN1DEREncChar32String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t len,ASN1char32_t *val);
    extern int WINAPI ASN1DEREncBitString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t len,ASN1octet_t *val);
    extern int WINAPI ASN1DEREncZeroMultibyteString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1ztcharstring_t val);
    extern int WINAPI ASN1DEREncMultibyteString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1charstring_t *val);
    extern int WINAPI ASN1DEREncOctetString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t len,ASN1octet_t *val);
    extern int WINAPI ASN1DEREncUTF8String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t length,WCHAR *value);
    extern int WINAPI ASN1CEREncUTF8String(ASN1encoding_t enc,ASN1uint32_t tag,ASN1uint32_t length,WCHAR *value);

    extern int WINAPI ASN1BEREncEmbeddedPdv(ASN1encoding_t enc,ASN1uint32_t tag,ASN1embeddedpdv_t *);
    extern int WINAPI ASN1BEREncExternal(ASN1encoding_t enc,ASN1uint32_t tag,ASN1external_t *);
    extern int WINAPI ASN1BEREncCharacterString(ASN1encoding_t enc,ASN1uint32_t tag,ASN1characterstring_t *);
    extern int WINAPI ASN1BERDecEmbeddedPdv(ASN1decoding_t dec,ASN1uint32_t tag,ASN1embeddedpdv_t *);
    extern int WINAPI ASN1BERDecExternal(ASN1decoding_t dec,ASN1uint32_t tag,ASN1external_t *);
    extern int WINAPI ASN1BERDecCharacterString(ASN1decoding_t dec,ASN1uint32_t tag,ASN1characterstring_t *);

    BOOL asn1_initialize_module();

#ifdef __cplusplus
}
#endif

#include <poppack.h> /* End 8-byte packing */

#endif // __MS_ASN1_H__