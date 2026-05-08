

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for rcg_KerbCredIsoRemote.idl:
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
#include "rcg_KerbCredIsoRemote_h.h"

#define TYPE_FORMAT_STRING_SIZE   1601                              
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _rcg_KerbCredIsoRemote_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } rcg_KerbCredIsoRemote_MIDL_TYPE_FORMAT_STRING;

typedef struct _rcg_KerbCredIsoRemote_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } rcg_KerbCredIsoRemote_MIDL_PROC_FORMAT_STRING;

typedef struct _rcg_KerbCredIsoRemote_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } rcg_KerbCredIsoRemote_MIDL_EXPR_FORMAT_STRING;


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


extern const rcg_KerbCredIsoRemote_MIDL_TYPE_FORMAT_STRING rcg_KerbCredIsoRemote__MIDL_TypeFormatString;
extern const rcg_KerbCredIsoRemote_MIDL_PROC_FORMAT_STRING rcg_KerbCredIsoRemote__MIDL_ProcFormatString;
extern const rcg_KerbCredIsoRemote_MIDL_EXPR_FORMAT_STRING rcg_KerbCredIsoRemote__MIDL_ExprFormatString;

/* Standard interface: __MIDL_itf_rcg_KerbCredIsoRemote_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const rcg_KerbCredIsoRemote_MIDL_PROC_FORMAT_STRING rcg_KerbCredIsoRemote__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const rcg_KerbCredIsoRemote_MIDL_TYPE_FORMAT_STRING rcg_KerbCredIsoRemote__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x1,	/* FC_UP [all_nodes] */
/*  4 */	NdrFcShort( 0x372 ),	/* Offset= 882 (886) */
/*  6 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/*  8 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 10 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 12 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 14 */	NdrFcShort( 0x2 ),	/* Offset= 2 (16) */
/* 16 */	NdrFcShort( 0x48 ),	/* 72 */
/* 18 */	NdrFcShort( 0x19 ),	/* 25 */
/* 20 */	NdrFcLong( 0x100 ),	/* 256 */
/* 24 */	NdrFcShort( 0x94 ),	/* Offset= 148 (172) */
/* 26 */	NdrFcLong( 0x101 ),	/* 257 */
/* 30 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (228) */
/* 32 */	NdrFcLong( 0x102 ),	/* 258 */
/* 36 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (280) */
/* 38 */	NdrFcLong( 0x103 ),	/* 259 */
/* 42 */	NdrFcShort( 0x152 ),	/* Offset= 338 (380) */
/* 44 */	NdrFcLong( 0x104 ),	/* 260 */
/* 48 */	NdrFcShort( 0x17c ),	/* Offset= 380 (428) */
/* 50 */	NdrFcLong( 0x105 ),	/* 261 */
/* 54 */	NdrFcShort( 0x18a ),	/* Offset= 394 (448) */
/* 56 */	NdrFcLong( 0x106 ),	/* 262 */
/* 60 */	NdrFcShort( 0x19e ),	/* Offset= 414 (474) */
/* 62 */	NdrFcLong( 0x107 ),	/* 263 */
/* 66 */	NdrFcShort( 0x1ae ),	/* Offset= 430 (496) */
/* 68 */	NdrFcLong( 0x108 ),	/* 264 */
/* 72 */	NdrFcShort( 0x1be ),	/* Offset= 446 (518) */
/* 74 */	NdrFcLong( 0x109 ),	/* 265 */
/* 78 */	NdrFcShort( 0x1d0 ),	/* Offset= 464 (542) */
/* 80 */	NdrFcLong( 0x10a ),	/* 266 */
/* 84 */	NdrFcShort( 0x1e0 ),	/* Offset= 480 (564) */
/* 86 */	NdrFcLong( 0x10b ),	/* 267 */
/* 90 */	NdrFcShort( 0x20c ),	/* Offset= 524 (614) */
/* 92 */	NdrFcLong( 0x10c ),	/* 268 */
/* 96 */	NdrFcShort( 0x222 ),	/* Offset= 546 (642) */
/* 98 */	NdrFcLong( 0x10d ),	/* 269 */
/* 102 */	NdrFcShort( 0x22a ),	/* Offset= 554 (656) */
/* 104 */	NdrFcLong( 0x10e ),	/* 270 */
/* 108 */	NdrFcShort( 0x232 ),	/* Offset= 562 (670) */
/* 110 */	NdrFcLong( 0x10f ),	/* 271 */
/* 114 */	NdrFcShort( 0x25a ),	/* Offset= 602 (716) */
/* 116 */	NdrFcLong( 0x110 ),	/* 272 */
/* 120 */	NdrFcShort( 0x26c ),	/* Offset= 620 (740) */
/* 122 */	NdrFcLong( 0x111 ),	/* 273 */
/* 126 */	NdrFcShort( 0x284 ),	/* Offset= 644 (770) */
/* 128 */	NdrFcLong( 0x112 ),	/* 274 */
/* 132 */	NdrFcShort( 0x294 ),	/* Offset= 660 (792) */
/* 134 */	NdrFcLong( 0x113 ),	/* 275 */
/* 138 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (828) */
/* 140 */	NdrFcLong( 0x114 ),	/* 276 */
/* 144 */	NdrFcShort( 0x1c ),	/* Offset= 28 (172) */
/* 146 */	NdrFcLong( 0x115 ),	/* 277 */
/* 150 */	NdrFcShort( 0x2be ),	/* Offset= 702 (852) */
/* 152 */	NdrFcLong( 0x116 ),	/* 278 */
/* 156 */	NdrFcShort( 0x42 ),	/* Offset= 66 (222) */
/* 158 */	NdrFcLong( 0x117 ),	/* 279 */
/* 162 */	NdrFcShort( 0x3c ),	/* Offset= 60 (222) */
/* 164 */	NdrFcLong( 0x118 ),	/* 280 */
/* 168 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (858) */
/* 170 */	NdrFcShort( 0xffff ),	/* Offset= -1 (169) */
/* 172 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 174 */	NdrFcShort( 0x4 ),	/* 4 */
/* 176 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 178 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 180 */	NdrFcShort( 0x1 ),	/* 1 */
/* 182 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 188 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 190 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 192 */	NdrFcShort( 0x10 ),	/* 16 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x6 ),	/* Offset= 6 (202) */
/* 198 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 200 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 202 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 204 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (178) */
/* 206 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 208 */	NdrFcShort( 0x20 ),	/* 32 */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* Offset= 0 (212) */
/* 214 */	0xf,		/* FC_IGNORE */
			0x8,		/* FC_LONG */
/* 216 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 218 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (190) */
			0x5b,		/* FC_END */
/* 222 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 226 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 228 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 230 */	NdrFcShort( 0x18 ),	/* 24 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x6 ),	/* Offset= 6 (240) */
/* 236 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 238 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 240 */	
			0x12, 0x0,	/* FC_UP */
/* 242 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (206) */
/* 244 */	
			0x12, 0x0,	/* FC_UP */
/* 246 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (206) */
/* 248 */	
			0x12, 0x0,	/* FC_UP */
/* 250 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (222) */
/* 252 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 258 */	NdrFcShort( 0x4 ),	/* 4 */
/* 260 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 262 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 264 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 266 */	NdrFcShort( 0x10 ),	/* 16 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x6 ),	/* Offset= 6 (276) */
/* 272 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 274 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 276 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 278 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (252) */
/* 280 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 282 */	NdrFcShort( 0x18 ),	/* 24 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x6 ),	/* Offset= 6 (292) */
/* 288 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 290 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 292 */	
			0x12, 0x0,	/* FC_UP */
/* 294 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (264) */
/* 296 */	
			0x12, 0x0,	/* FC_UP */
/* 298 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (206) */
/* 300 */	
			0x12, 0x0,	/* FC_UP */
/* 302 */	NdrFcShort( 0xffb0 ),	/* Offset= -80 (222) */
/* 304 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 306 */	NdrFcShort( 0x2 ),	/* 2 */
/* 308 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x55,		/* FC_DIV_2 */
/* 310 */	NdrFcShort( 0x2 ),	/* 2 */
/* 312 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 314 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x55,		/* FC_DIV_2 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 320 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 322 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 324 */	NdrFcShort( 0x10 ),	/* 16 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x8 ),	/* Offset= 8 (336) */
/* 330 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 332 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 334 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 336 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 338 */	NdrFcShort( 0xffde ),	/* Offset= -34 (304) */
/* 340 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	0x17,		/* Corr desc:  field pointer, FC_USHORT */
			0x0,		/*  */
/* 346 */	NdrFcShort( 0x2 ),	/* 2 */
/* 348 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 350 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 354 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 356 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 358 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (322) */
/* 360 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 362 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 364 */	NdrFcShort( 0x10 ),	/* 16 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x8 ),	/* Offset= 8 (376) */
/* 370 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 372 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 374 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 376 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 378 */	NdrFcShort( 0xffda ),	/* Offset= -38 (340) */
/* 380 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 382 */	NdrFcShort( 0x48 ),	/* 72 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0xe ),	/* Offset= 14 (400) */
/* 388 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 390 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 392 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 394 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 396 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 398 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 400 */	
			0x12, 0x0,	/* FC_UP */
/* 402 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (206) */
/* 404 */	
			0x12, 0x0,	/* FC_UP */
/* 406 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (362) */
/* 408 */	
			0x12, 0x0,	/* FC_UP */
/* 410 */	NdrFcShort( 0xffa8 ),	/* Offset= -88 (322) */
/* 412 */	
			0x12, 0x0,	/* FC_UP */
/* 414 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (222) */
/* 416 */	
			0x12, 0x0,	/* FC_UP */
/* 418 */	NdrFcShort( 0xff2c ),	/* Offset= -212 (206) */
/* 420 */	
			0x12, 0x0,	/* FC_UP */
/* 422 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (264) */
/* 424 */	
			0x12, 0x0,	/* FC_UP */
/* 426 */	NdrFcShort( 0xff5e ),	/* Offset= -162 (264) */
/* 428 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x6 ),	/* Offset= 6 (440) */
/* 436 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 438 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 440 */	
			0x12, 0x0,	/* FC_UP */
/* 442 */	NdrFcShort( 0xff4e ),	/* Offset= -178 (264) */
/* 444 */	
			0x12, 0x0,	/* FC_UP */
/* 446 */	NdrFcShort( 0xff10 ),	/* Offset= -240 (206) */
/* 448 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 450 */	NdrFcShort( 0x20 ),	/* 32 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x8 ),	/* Offset= 8 (462) */
/* 456 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 458 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 460 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 462 */	
			0x12, 0x0,	/* FC_UP */
/* 464 */	NdrFcShort( 0xff38 ),	/* Offset= -200 (264) */
/* 466 */	
			0x12, 0x0,	/* FC_UP */
/* 468 */	NdrFcShort( 0xfefa ),	/* Offset= -262 (206) */
/* 470 */	
			0x12, 0x0,	/* FC_UP */
/* 472 */	NdrFcShort( 0xfef6 ),	/* Offset= -266 (206) */
/* 474 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 476 */	NdrFcShort( 0x18 ),	/* 24 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x8 ),	/* Offset= 8 (488) */
/* 482 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 484 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 486 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 488 */	
			0x12, 0x0,	/* FC_UP */
/* 490 */	NdrFcShort( 0xff1e ),	/* Offset= -226 (264) */
/* 492 */	
			0x12, 0x0,	/* FC_UP */
/* 494 */	NdrFcShort( 0xfee0 ),	/* Offset= -288 (206) */
/* 496 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 498 */	NdrFcShort( 0x18 ),	/* 24 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x8 ),	/* Offset= 8 (510) */
/* 504 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 506 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 508 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 510 */	
			0x12, 0x0,	/* FC_UP */
/* 512 */	NdrFcShort( 0xfece ),	/* Offset= -306 (206) */
/* 514 */	
			0x12, 0x0,	/* FC_UP */
/* 516 */	NdrFcShort( 0xff04 ),	/* Offset= -252 (264) */
/* 518 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 520 */	NdrFcShort( 0x18 ),	/* 24 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x6 ),	/* Offset= 6 (530) */
/* 526 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 528 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 530 */	
			0x12, 0x0,	/* FC_UP */
/* 532 */	NdrFcShort( 0xfef4 ),	/* Offset= -268 (264) */
/* 534 */	
			0x12, 0x0,	/* FC_UP */
/* 536 */	NdrFcShort( 0xfef0 ),	/* Offset= -272 (264) */
/* 538 */	
			0x12, 0x0,	/* FC_UP */
/* 540 */	NdrFcShort( 0xfeb2 ),	/* Offset= -334 (206) */
/* 542 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 544 */	NdrFcShort( 0x18 ),	/* 24 */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x8 ),	/* Offset= 8 (556) */
/* 550 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 552 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 554 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 556 */	
			0x12, 0x0,	/* FC_UP */
/* 558 */	NdrFcShort( 0xfeda ),	/* Offset= -294 (264) */
/* 560 */	
			0x12, 0x0,	/* FC_UP */
/* 562 */	NdrFcShort( 0xfe9c ),	/* Offset= -356 (206) */
/* 564 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 566 */	NdrFcShort( 0x20 ),	/* 32 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x8 ),	/* Offset= 8 (578) */
/* 572 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 574 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 576 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 578 */	
			0x12, 0x0,	/* FC_UP */
/* 580 */	NdrFcShort( 0xfe8a ),	/* Offset= -374 (206) */
/* 582 */	
			0x12, 0x0,	/* FC_UP */
/* 584 */	NdrFcShort( 0xfec0 ),	/* Offset= -320 (264) */
/* 586 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 588 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 590 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 592 */	NdrFcShort( 0x1 ),	/* 1 */
/* 594 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 596 */	NdrFcShort( 0xc ),	/* 12 */
/* 598 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 600 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 602 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 606 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 608 */	NdrFcShort( 0x18 ),	/* 24 */
/* 610 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 612 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 614 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 616 */	NdrFcShort( 0x28 ),	/* 40 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0xa ),	/* Offset= 10 (630) */
/* 622 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 624 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 626 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 628 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 630 */	
			0x12, 0x0,	/* FC_UP */
/* 632 */	NdrFcShort( 0xfe56 ),	/* Offset= -426 (206) */
/* 634 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 636 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (590) */
/* 638 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 640 */	NdrFcShort( 0xffda ),	/* Offset= -38 (602) */
/* 642 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x4 ),	/* Offset= 4 (652) */
/* 650 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 652 */	
			0x12, 0x0,	/* FC_UP */
/* 654 */	NdrFcShort( 0xfe40 ),	/* Offset= -448 (206) */
/* 656 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x4 ),	/* Offset= 4 (666) */
/* 664 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 666 */	
			0x12, 0x0,	/* FC_UP */
/* 668 */	NdrFcShort( 0xfe32 ),	/* Offset= -462 (206) */
/* 670 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 672 */	NdrFcShort( 0x20 ),	/* 32 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x8 ),	/* Offset= 8 (684) */
/* 678 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 680 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 682 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 684 */	
			0x12, 0x0,	/* FC_UP */
/* 686 */	NdrFcShort( 0xfe5a ),	/* Offset= -422 (264) */
/* 688 */	
			0x12, 0x0,	/* FC_UP */
/* 690 */	NdrFcShort( 0xfe56 ),	/* Offset= -426 (264) */
/* 692 */	
			0x12, 0x0,	/* FC_UP */
/* 694 */	NdrFcShort( 0xfe18 ),	/* Offset= -488 (206) */
/* 696 */	
			0x12, 0x0,	/* FC_UP */
/* 698 */	NdrFcShort( 0xfe14 ),	/* Offset= -492 (206) */
/* 700 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 702 */	NdrFcShort( 0x18 ),	/* 24 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x0 ),	/* Offset= 0 (706) */
/* 708 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 710 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 712 */	NdrFcShort( 0xfdf6 ),	/* Offset= -522 (190) */
/* 714 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 716 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 718 */	NdrFcShort( 0x18 ),	/* 24 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x6 ),	/* Offset= 6 (728) */
/* 724 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 726 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 728 */	
			0x12, 0x0,	/* FC_UP */
/* 730 */	NdrFcShort( 0xfdf4 ),	/* Offset= -524 (206) */
/* 732 */	
			0x12, 0x0,	/* FC_UP */
/* 734 */	NdrFcShort( 0xfdf0 ),	/* Offset= -528 (206) */
/* 736 */	
			0x12, 0x0,	/* FC_UP */
/* 738 */	NdrFcShort( 0xffda ),	/* Offset= -38 (700) */
/* 740 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 742 */	NdrFcShort( 0x28 ),	/* 40 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x8 ),	/* Offset= 8 (754) */
/* 748 */	0xb,		/* FC_HYPER */
			0x36,		/* FC_POINTER */
/* 750 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 752 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 754 */	
			0x12, 0x0,	/* FC_UP */
/* 756 */	NdrFcShort( 0xfe14 ),	/* Offset= -492 (264) */
/* 758 */	
			0x12, 0x0,	/* FC_UP */
/* 760 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (700) */
/* 762 */	
			0x12, 0x0,	/* FC_UP */
/* 764 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (700) */
/* 766 */	
			0x12, 0x0,	/* FC_UP */
/* 768 */	NdrFcShort( 0xfdce ),	/* Offset= -562 (206) */
/* 770 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 772 */	NdrFcShort( 0x18 ),	/* 24 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x8 ),	/* Offset= 8 (784) */
/* 778 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 780 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 782 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 784 */	
			0x12, 0x0,	/* FC_UP */
/* 786 */	NdrFcShort( 0xfdf6 ),	/* Offset= -522 (264) */
/* 788 */	
			0x12, 0x0,	/* FC_UP */
/* 790 */	NdrFcShort( 0xfdb8 ),	/* Offset= -584 (206) */
/* 792 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 794 */	NdrFcShort( 0x18 ),	/* 24 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x6 ),	/* Offset= 6 (804) */
/* 800 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 802 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 804 */	
			0x12, 0x0,	/* FC_UP */
/* 806 */	NdrFcShort( 0xfde2 ),	/* Offset= -542 (264) */
/* 808 */	
			0x12, 0x0,	/* FC_UP */
/* 810 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (264) */
/* 812 */	
			0x12, 0x0,	/* FC_UP */
/* 814 */	NdrFcShort( 0xfda0 ),	/* Offset= -608 (206) */
/* 816 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 818 */	NdrFcShort( 0x1 ),	/* 1 */
/* 820 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 822 */	NdrFcShort( 0x10 ),	/* 16 */
/* 824 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 826 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 828 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 830 */	NdrFcShort( 0x20 ),	/* 32 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0xa ),	/* Offset= 10 (844) */
/* 836 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 838 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 840 */	0x40,		/* FC_STRUCTPAD4 */
			0x36,		/* FC_POINTER */
/* 842 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 844 */	
			0x12, 0x0,	/* FC_UP */
/* 846 */	NdrFcShort( 0xfd80 ),	/* Offset= -640 (206) */
/* 848 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 850 */	NdrFcShort( 0xffde ),	/* Offset= -34 (816) */
/* 852 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 856 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 858 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 860 */	NdrFcShort( 0x28 ),	/* 40 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0xa ),	/* Offset= 10 (874) */
/* 866 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 868 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 870 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 872 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 874 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 876 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 878 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 880 */	NdrFcShort( 0xfede ),	/* Offset= -290 (590) */
/* 882 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 884 */	NdrFcShort( 0xfee6 ),	/* Offset= -282 (602) */
/* 886 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 888 */	NdrFcShort( 0x50 ),	/* 80 */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x0 ),	/* Offset= 0 (892) */
/* 894 */	0xd,		/* FC_ENUM16 */
			0x40,		/* FC_STRUCTPAD4 */
/* 896 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 898 */	NdrFcShort( 0xfc84 ),	/* Offset= -892 (6) */
/* 900 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 902 */	
			0x12, 0x1,	/* FC_UP [all_nodes] */
/* 904 */	NdrFcShort( 0x2a8 ),	/* Offset= 680 (1584) */
/* 906 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 908 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 910 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 912 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 914 */	NdrFcShort( 0x2 ),	/* Offset= 2 (916) */
/* 916 */	NdrFcShort( 0x38 ),	/* 56 */
/* 918 */	NdrFcShort( 0x19 ),	/* 25 */
/* 920 */	NdrFcLong( 0x100 ),	/* 256 */
/* 924 */	NdrFcShort( 0xfd10 ),	/* Offset= -752 (172) */
/* 926 */	NdrFcLong( 0x101 ),	/* 257 */
/* 930 */	NdrFcShort( 0xff1a ),	/* Offset= -230 (700) */
/* 932 */	NdrFcLong( 0x102 ),	/* 258 */
/* 936 */	NdrFcShort( 0x88 ),	/* Offset= 136 (1072) */
/* 938 */	NdrFcLong( 0x103 ),	/* 259 */
/* 942 */	NdrFcShort( 0x92 ),	/* Offset= 146 (1088) */
/* 944 */	NdrFcLong( 0x104 ),	/* 260 */
/* 948 */	NdrFcShort( 0xa0 ),	/* Offset= 160 (1108) */
/* 950 */	NdrFcLong( 0x105 ),	/* 261 */
/* 954 */	NdrFcShort( 0xa8 ),	/* Offset= 168 (1122) */
/* 956 */	NdrFcLong( 0x106 ),	/* 262 */
/* 960 */	NdrFcShort( 0x94 ),	/* Offset= 148 (1108) */
/* 962 */	NdrFcLong( 0x107 ),	/* 263 */
/* 966 */	NdrFcShort( 0x8e ),	/* Offset= 142 (1108) */
/* 968 */	NdrFcLong( 0x108 ),	/* 264 */
/* 972 */	NdrFcShort( 0xa6 ),	/* Offset= 166 (1138) */
/* 974 */	NdrFcLong( 0x109 ),	/* 265 */
/* 978 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (1170) */
/* 980 */	NdrFcLong( 0x10a ),	/* 266 */
/* 984 */	NdrFcShort( 0xde ),	/* Offset= 222 (1206) */
/* 986 */	NdrFcLong( 0x10b ),	/* 267 */
/* 990 */	NdrFcShort( 0xfcce ),	/* Offset= -818 (172) */
/* 992 */	NdrFcLong( 0x10c ),	/* 268 */
/* 996 */	NdrFcShort( 0xea ),	/* Offset= 234 (1230) */
/* 998 */	NdrFcLong( 0x10d ),	/* 269 */
/* 1002 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (1250) */
/* 1004 */	NdrFcLong( 0x10e ),	/* 270 */
/* 1008 */	NdrFcShort( 0x110 ),	/* Offset= 272 (1280) */
/* 1010 */	NdrFcLong( 0x10f ),	/* 271 */
/* 1014 */	NdrFcShort( 0x122 ),	/* Offset= 290 (1304) */
/* 1016 */	NdrFcLong( 0x110 ),	/* 272 */
/* 1020 */	NdrFcShort( 0x12a ),	/* Offset= 298 (1318) */
/* 1022 */	NdrFcLong( 0x111 ),	/* 273 */
/* 1026 */	NdrFcShort( 0x132 ),	/* Offset= 306 (1332) */
/* 1028 */	NdrFcLong( 0x112 ),	/* 274 */
/* 1032 */	NdrFcShort( 0x140 ),	/* Offset= 320 (1352) */
/* 1034 */	NdrFcLong( 0x113 ),	/* 275 */
/* 1038 */	NdrFcShort( 0x188 ),	/* Offset= 392 (1430) */
/* 1040 */	NdrFcLong( 0x114 ),	/* 276 */
/* 1044 */	NdrFcShort( 0x1a0 ),	/* Offset= 416 (1460) */
/* 1046 */	NdrFcLong( 0x115 ),	/* 277 */
/* 1050 */	NdrFcShort( 0x1c8 ),	/* Offset= 456 (1506) */
/* 1052 */	NdrFcLong( 0x116 ),	/* 278 */
/* 1056 */	NdrFcShort( 0xff34 ),	/* Offset= -204 (852) */
/* 1058 */	NdrFcLong( 0x117 ),	/* 279 */
/* 1062 */	NdrFcShort( 0x1e8 ),	/* Offset= 488 (1550) */
/* 1064 */	NdrFcLong( 0x118 ),	/* 280 */
/* 1068 */	NdrFcShort( 0x1f6 ),	/* Offset= 502 (1570) */
/* 1070 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1069) */
/* 1072 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1074 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1078) */
/* 1080 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1082 */	NdrFcShort( 0xfcce ),	/* Offset= -818 (264) */
/* 1084 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1086 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1088 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1090 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1094) */
/* 1096 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1098 */	NdrFcShort( 0xfc94 ),	/* Offset= -876 (222) */
/* 1100 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1102 */	NdrFcShort( 0xfcba ),	/* Offset= -838 (264) */
/* 1104 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1106 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1108 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1110 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1114) */
/* 1116 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1118 */	NdrFcShort( 0xfcaa ),	/* Offset= -854 (264) */
/* 1120 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1122 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1124 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1128) */
/* 1130 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1132 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1134 */	NdrFcShort( 0xfc9a ),	/* Offset= -870 (264) */
/* 1136 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1138 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1140 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1150) */
/* 1146 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1148 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1150 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1152 */	NdrFcShort( 0xfc32 ),	/* Offset= -974 (178) */
/* 1154 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1156 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1158) */
/* 1158 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1160 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1162 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1168 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1170 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1172 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1182) */
/* 1178 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1180 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1182 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1184 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1186 */	
			0x12, 0x30,	/* FC_UP [pointer_deref] [maybenull_sizeis] */
/* 1188 */	NdrFcShort( 0xffde ),	/* Offset= -34 (1154) */
/* 1190 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1192 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1194) */
/* 1194 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1196 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1198 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1202 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1204 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1206 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1208 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1218) */
/* 1214 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1216 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1218 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1220 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1222 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1224 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1226 */	
			0x12, 0x30,	/* FC_UP [pointer_deref] [maybenull_sizeis] */
/* 1228 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1190) */
/* 1230 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1232 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1242) */
/* 1238 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1240 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1242 */	
			0x12, 0x0,	/* FC_UP */
/* 1244 */	NdrFcShort( 0xfbf2 ),	/* Offset= -1038 (206) */
/* 1246 */	
			0x12, 0x0,	/* FC_UP */
/* 1248 */	NdrFcShort( 0xfbee ),	/* Offset= -1042 (206) */
/* 1250 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1252 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	NdrFcShort( 0x8 ),	/* Offset= 8 (1264) */
/* 1258 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1260 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1262 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1264 */	
			0x12, 0x0,	/* FC_UP */
/* 1266 */	NdrFcShort( 0xfbdc ),	/* Offset= -1060 (206) */
/* 1268 */	
			0x12, 0x0,	/* FC_UP */
/* 1270 */	NdrFcShort( 0xfbd8 ),	/* Offset= -1064 (206) */
/* 1272 */	
			0x12, 0x0,	/* FC_UP */
/* 1274 */	NdrFcShort( 0xfbd4 ),	/* Offset= -1068 (206) */
/* 1276 */	
			0x12, 0x0,	/* FC_UP */
/* 1278 */	NdrFcShort( 0xfbd0 ),	/* Offset= -1072 (206) */
/* 1280 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1282 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1292) */
/* 1288 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1290 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1292 */	
			0x12, 0x0,	/* FC_UP */
/* 1294 */	NdrFcShort( 0xfbc0 ),	/* Offset= -1088 (206) */
/* 1296 */	
			0x12, 0x0,	/* FC_UP */
/* 1298 */	NdrFcShort( 0xfbf6 ),	/* Offset= -1034 (264) */
/* 1300 */	
			0x12, 0x0,	/* FC_UP */
/* 1302 */	NdrFcShort( 0xfbc8 ),	/* Offset= -1080 (222) */
/* 1304 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1314) */
/* 1312 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1314 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1316 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1318 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1328) */
/* 1326 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1328 */	
			0x12, 0x0,	/* FC_UP */
/* 1330 */	NdrFcShort( 0xfd8a ),	/* Offset= -630 (700) */
/* 1332 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1334 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1344) */
/* 1340 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1342 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1344 */	
			0x12, 0x0,	/* FC_UP */
/* 1346 */	NdrFcShort( 0xfbc6 ),	/* Offset= -1082 (264) */
/* 1348 */	
			0x12, 0x0,	/* FC_UP */
/* 1350 */	NdrFcShort( 0xfbc2 ),	/* Offset= -1086 (264) */
/* 1352 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1354 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1358 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1364) */
/* 1360 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1362 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1364 */	
			0x12, 0x0,	/* FC_UP */
/* 1366 */	NdrFcShort( 0xfb78 ),	/* Offset= -1160 (206) */
/* 1368 */	
			0x12, 0x0,	/* FC_UP */
/* 1370 */	NdrFcShort( 0xfbae ),	/* Offset= -1106 (264) */
/* 1372 */	
			0x12, 0x0,	/* FC_UP */
/* 1374 */	NdrFcShort( 0xfb80 ),	/* Offset= -1152 (222) */
/* 1376 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1378 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0xa ),	/* Offset= 10 (1392) */
/* 1384 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1386 */	NdrFcShort( 0xfbd8 ),	/* Offset= -1064 (322) */
/* 1388 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1390 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1392 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1394 */	NdrFcShort( 0xfdbe ),	/* Offset= -578 (816) */
/* 1396 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1400 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 1402 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 1404 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1406 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1410 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1412 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1414 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1376) */
/* 1416 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1418 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1422 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1396) */
/* 1424 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1424) */
/* 1426 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1428 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1430 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1440) */
/* 1438 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1440 */	
			0x12, 0x0,	/* FC_UP */
/* 1442 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (1418) */
/* 1444 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1446 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1448) */
/* 1448 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1450 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1452 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1454 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1456 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1458 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1460 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1462 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x8 ),	/* Offset= 8 (1474) */
/* 1468 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1470 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1472 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1474 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1476 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1478 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1480 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1482 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1484 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1486 */	
			0x12, 0x30,	/* FC_UP [pointer_deref] [maybenull_sizeis] */
/* 1488 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (1444) */
/* 1490 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1492 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1494) */
/* 1494 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1496 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1498 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1500 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1502 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1504 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1506 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1508 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0xa ),	/* Offset= 10 (1522) */
/* 1514 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1516 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1518 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1520 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1522 */	
			0x12, 0x0,	/* FC_UP */
/* 1524 */	NdrFcShort( 0xfaca ),	/* Offset= -1334 (190) */
/* 1526 */	
			0x12, 0x0,	/* FC_UP */
/* 1528 */	NdrFcShort( 0xfac6 ),	/* Offset= -1338 (190) */
/* 1530 */	
			0x12, 0x0,	/* FC_UP */
/* 1532 */	NdrFcShort( 0xfac2 ),	/* Offset= -1342 (190) */
/* 1534 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1536 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1538 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1540 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1542 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1544 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1546 */	
			0x12, 0x30,	/* FC_UP [pointer_deref] [maybenull_sizeis] */
/* 1548 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1490) */
/* 1550 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1552 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1562) */
/* 1558 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1560 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1562 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1564 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1566 */	
			0x12, 0x30,	/* FC_UP [pointer_deref] [maybenull_sizeis] */
/* 1568 */	NdrFcShort( 0xfe62 ),	/* Offset= -414 (1154) */
/* 1570 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1580) */
/* 1578 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1580 */	
			0x12, 0x0,	/* FC_UP */
/* 1582 */	NdrFcShort( 0xfaa0 ),	/* Offset= -1376 (206) */
/* 1584 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1586 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1590) */
/* 1592 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 1594 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1596 */	NdrFcShort( 0xfd4e ),	/* Offset= -690 (906) */
/* 1598 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };


#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for rcg_KerbCredIsoRemote.idl:
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

