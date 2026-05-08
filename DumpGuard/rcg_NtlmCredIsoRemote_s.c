

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for rcg_NtlmCredIsoRemote.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>
#include "rcg_NtlmCredIsoRemote_h.h"

#define TYPE_FORMAT_STRING_SIZE   523                               
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _rcg_NtlmCredIsoRemote_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } rcg_NtlmCredIsoRemote_MIDL_TYPE_FORMAT_STRING;

typedef struct _rcg_NtlmCredIsoRemote_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } rcg_NtlmCredIsoRemote_MIDL_PROC_FORMAT_STRING;

typedef struct _rcg_NtlmCredIsoRemote_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } rcg_NtlmCredIsoRemote_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax_2_0 = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax_1_0 = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, (ObjectType *)pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, (ObjectType *)pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol
#endif


extern const rcg_NtlmCredIsoRemote_MIDL_TYPE_FORMAT_STRING rcg_NtlmCredIsoRemote__MIDL_TypeFormatString;
extern const rcg_NtlmCredIsoRemote_MIDL_PROC_FORMAT_STRING rcg_NtlmCredIsoRemote__MIDL_ProcFormatString;
extern const rcg_NtlmCredIsoRemote_MIDL_EXPR_FORMAT_STRING rcg_NtlmCredIsoRemote__MIDL_ExprFormatString;

/* Standard interface: __MIDL_itf_rcg_NtlmCredIsoRemote_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const rcg_NtlmCredIsoRemote_MIDL_PROC_FORMAT_STRING rcg_NtlmCredIsoRemote__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const rcg_NtlmCredIsoRemote_MIDL_TYPE_FORMAT_STRING rcg_NtlmCredIsoRemote__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x1,	/* FC_UP [all_nodes] */
/*  4 */	NdrFcShort( 0x14e ),	/* Offset= 334 (338) */
/*  6 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/*  8 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 10 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 12 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 14 */	NdrFcShort( 0x2 ),	/* Offset= 2 (16) */
/* 16 */	NdrFcShort( 0x28 ),	/* 40 */
/* 18 */	NdrFcShort( 0x6 ),	/* 6 */
/* 20 */	NdrFcLong( 0x200 ),	/* 512 */
/* 24 */	NdrFcShort( 0x22 ),	/* Offset= 34 (58) */
/* 26 */	NdrFcLong( 0x201 ),	/* 513 */
/* 30 */	NdrFcShort( 0x60 ),	/* Offset= 96 (126) */
/* 32 */	NdrFcLong( 0x202 ),	/* 514 */
/* 36 */	NdrFcShort( 0xb6 ),	/* Offset= 182 (218) */
/* 38 */	NdrFcLong( 0x203 ),	/* 515 */
/* 42 */	NdrFcShort( 0xdc ),	/* Offset= 220 (262) */
/* 44 */	NdrFcLong( 0x204 ),	/* 516 */
/* 48 */	NdrFcShort( 0xfa ),	/* Offset= 250 (298) */
/* 50 */	NdrFcLong( 0x205 ),	/* 517 */
/* 54 */	NdrFcShort( 0x108 ),	/* Offset= 264 (318) */
/* 56 */	NdrFcShort( 0xffff ),	/* Offset= -1 (55) */
/* 58 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 60 */	NdrFcShort( 0x4 ),	/* 4 */
/* 62 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 64 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 66 */	NdrFcShort( 0x14 ),	/* 20 */
/* 68 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 70 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 72 */	NdrFcShort( 0x14 ),	/* 20 */
/* 74 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 76 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (64) */
/* 78 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 80 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 82 */	NdrFcShort( 0x10 ),	/* 16 */
/* 84 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 86 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 88 */	NdrFcShort( 0x10 ),	/* 16 */
/* 90 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 92 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (80) */
/* 94 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 96 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x1,		/* 1 */
/* 98 */	NdrFcShort( 0x50 ),	/* 80 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x0 ),	/* Offset= 0 (102) */
/* 104 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 106 */	0x2,		/* FC_CHAR */
			0x3d,		/* FC_STRUCTPAD1 */
/* 108 */	0xd,		/* FC_ENUM16 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 110 */	0x0,		/* 0 */
			NdrFcShort( 0xffd7 ),	/* Offset= -41 (70) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 114 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (86) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 118 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (86) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 122 */	0x0,		/* 0 */
			NdrFcShort( 0xffcb ),	/* Offset= -53 (70) */
			0x5b,		/* FC_END */
/* 126 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x4 ),	/* Offset= 4 (136) */
/* 134 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 136 */	
			0x12, 0x0,	/* FC_UP */
/* 138 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (96) */
/* 140 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 144 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 146 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x1 ),	/* 1 */
/* 150 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 152 */	NdrFcShort( 0x1c ),	/* 28 */
/* 154 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 156 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 158 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 160 */	NdrFcShort( 0x28 ),	/* 40 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0xe ),	/* Offset= 14 (178) */
/* 166 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 168 */	0x2,		/* FC_CHAR */
			0x3d,		/* FC_STRUCTPAD1 */
/* 170 */	0xd,		/* FC_ENUM16 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 172 */	0x0,		/* 0 */
			NdrFcShort( 0xff99 ),	/* Offset= -103 (70) */
			0x8,		/* FC_LONG */
/* 176 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 178 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 180 */	NdrFcShort( 0xffde ),	/* Offset= -34 (146) */
/* 182 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 184 */	NdrFcShort( 0x2 ),	/* 2 */
/* 186 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x55,		/* FC_DIV_2 */
/* 188 */	NdrFcShort( 0x2 ),	/* 2 */
/* 190 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 192 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x55,		/* FC_DIV_2 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 198 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 200 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 202 */	NdrFcShort( 0x10 ),	/* 16 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x8 ),	/* Offset= 8 (214) */
/* 208 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 210 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 212 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 214 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 216 */	NdrFcShort( 0xffde ),	/* Offset= -34 (182) */
/* 218 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 220 */	NdrFcShort( 0x28 ),	/* 40 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0xc ),	/* Offset= 12 (236) */
/* 226 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 228 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 230 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 232 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (140) */
/* 234 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 236 */	
			0x12, 0x0,	/* FC_UP */
/* 238 */	NdrFcShort( 0xffb0 ),	/* Offset= -80 (158) */
/* 240 */	
			0x12, 0x0,	/* FC_UP */
/* 242 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (200) */
/* 244 */	
			0x12, 0x0,	/* FC_UP */
/* 246 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (200) */
/* 248 */	
			0x12, 0x0,	/* FC_UP */
/* 250 */	NdrFcShort( 0xffce ),	/* Offset= -50 (200) */
/* 252 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 256 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 258 */	NdrFcShort( 0xff8a ),	/* Offset= -118 (140) */
/* 260 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 262 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 264 */	NdrFcShort( 0x10 ),	/* 16 */
/* 266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 268 */	NdrFcShort( 0x6 ),	/* Offset= 6 (274) */
/* 270 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 272 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 274 */	
			0x12, 0x0,	/* FC_UP */
/* 276 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (252) */
/* 278 */	
			0x12, 0x0,	/* FC_UP */
/* 280 */	NdrFcShort( 0xff86 ),	/* Offset= -122 (158) */
/* 282 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 284 */	NdrFcShort( 0x18 ),	/* 24 */
/* 286 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 288 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 290 */	NdrFcShort( 0x18 ),	/* 24 */
/* 292 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 294 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (282) */
/* 296 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 298 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 300 */	NdrFcShort( 0x10 ),	/* 16 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x6 ),	/* Offset= 6 (310) */
/* 306 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 308 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 310 */	
			0x12, 0x0,	/* FC_UP */
/* 312 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (288) */
/* 314 */	
			0x12, 0x0,	/* FC_UP */
/* 316 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (158) */
/* 318 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 320 */	NdrFcShort( 0x10 ),	/* 16 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x6 ),	/* Offset= 6 (330) */
/* 326 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 328 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 330 */	
			0x12, 0x0,	/* FC_UP */
/* 332 */	NdrFcShort( 0xff52 ),	/* Offset= -174 (158) */
/* 334 */	
			0x12, 0x0,	/* FC_UP */
/* 336 */	NdrFcShort( 0xff4e ),	/* Offset= -178 (158) */
/* 338 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 340 */	NdrFcShort( 0x30 ),	/* 48 */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* Offset= 0 (344) */
/* 346 */	0xd,		/* FC_ENUM16 */
			0x40,		/* FC_STRUCTPAD4 */
/* 348 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 350 */	NdrFcShort( 0xfea8 ),	/* Offset= -344 (6) */
/* 352 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 354 */	
			0x12, 0x1,	/* FC_UP [all_nodes] */
/* 356 */	NdrFcShort( 0x96 ),	/* Offset= 150 (506) */
/* 358 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 360 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 362 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 364 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 366 */	NdrFcShort( 0x2 ),	/* Offset= 2 (368) */
/* 368 */	NdrFcShort( 0x40 ),	/* 64 */
/* 370 */	NdrFcShort( 0x6 ),	/* 6 */
/* 372 */	NdrFcLong( 0x200 ),	/* 512 */
/* 376 */	NdrFcShort( 0xfec2 ),	/* Offset= -318 (58) */
/* 378 */	NdrFcLong( 0x201 ),	/* 513 */
/* 382 */	NdrFcShort( 0x1c ),	/* Offset= 28 (410) */
/* 384 */	NdrFcLong( 0x202 ),	/* 514 */
/* 388 */	NdrFcShort( 0x3e ),	/* Offset= 62 (450) */
/* 390 */	NdrFcLong( 0x203 ),	/* 515 */
/* 394 */	NdrFcShort( 0x54 ),	/* Offset= 84 (478) */
/* 396 */	NdrFcLong( 0x204 ),	/* 516 */
/* 400 */	NdrFcShort( 0x58 ),	/* Offset= 88 (488) */
/* 402 */	NdrFcLong( 0x205 ),	/* 517 */
/* 406 */	NdrFcShort( 0x5c ),	/* Offset= 92 (498) */
/* 408 */	NdrFcShort( 0xffff ),	/* Offset= -1 (407) */
/* 410 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 412 */	NdrFcShort( 0x28 ),	/* 40 */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* Offset= 0 (416) */
/* 418 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 420 */	NdrFcShort( 0xfefa ),	/* Offset= -262 (158) */
/* 422 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 424 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 426 */	NdrFcShort( 0x18 ),	/* 24 */
/* 428 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 430 */	NdrFcShort( 0xfea2 ),	/* Offset= -350 (80) */
/* 432 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 434 */	NdrFcShort( 0xfeda ),	/* Offset= -294 (140) */
/* 436 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 438 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 440 */	NdrFcShort( 0x1 ),	/* 1 */
/* 442 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x0,		/*  */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 448 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 450 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 452 */	NdrFcShort( 0x40 ),	/* 64 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x12 ),	/* Offset= 18 (474) */
/* 458 */	0x6,		/* FC_SHORT */
			0x42,		/* FC_STRUCTPAD6 */
/* 460 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 462 */	0x0,		/* 0 */
			NdrFcShort( 0xffd9 ),	/* Offset= -39 (424) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 466 */	0x0,		/* 0 */
			NdrFcShort( 0xfe83 ),	/* Offset= -381 (86) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 470 */	0x0,		/* 0 */
			NdrFcShort( 0xff25 ),	/* Offset= -219 (252) */
			0x5b,		/* FC_END */
/* 474 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 476 */	NdrFcShort( 0xffda ),	/* Offset= -38 (438) */
/* 478 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 480 */	NdrFcShort( 0x18 ),	/* 24 */
/* 482 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 484 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (288) */
/* 486 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 488 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 490 */	NdrFcShort( 0x10 ),	/* 16 */
/* 492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 494 */	NdrFcShort( 0xfe68 ),	/* Offset= -408 (86) */
/* 496 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 498 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 500 */	NdrFcShort( 0xc ),	/* 12 */
/* 502 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 504 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 506 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 508 */	NdrFcShort( 0x48 ),	/* 72 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x0 ),	/* Offset= 0 (512) */
/* 514 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 516 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 518 */	NdrFcShort( 0xff60 ),	/* Offset= -160 (358) */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };


#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for rcg_NtlmCredIsoRemote.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"
#ifdef __cplusplus
namespace {
#endif


typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;
#ifdef __cplusplus
}
#endif


#include "poppack.h"

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

