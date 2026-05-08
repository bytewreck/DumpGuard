

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for rcg_BaseTypes.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __rcg_BaseTypes_h__
#define __rcg_BaseTypes_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_rcg_BaseTypes_0000_0000 */
/* [local] */ 

#pragma comment(lib, "rpcrt4.lib")
typedef /* [context_handle] */ void *CONTEXT_HANDLE;

typedef long long IUM_HANDLE;

typedef int IUM_BOOL;

typedef struct _IUM_LARGE_INTEGER
    {
    long long QuadPart;
    } 	IUM_LARGE_INTEGER;

typedef struct _IUM_LARGE_INTEGER *PIUM_LARGE_INTEGER;

typedef struct _IUM_UNICODE_STRING
    {
    unsigned short Length;
    unsigned short MaximumLength;
    /* [length_is][size_is][unique] */ wchar_t *Buffer;
    } 	IUM_UNICODE_STRING;

typedef struct _IUM_UNICODE_STRING *PIUM_UNICODE_STRING;

typedef struct _IUM_STRING
    {
    unsigned short Length;
    unsigned short MaximumLength;
    /* [length_is][size_is][unique] */ byte *Buffer;
    } 	IUM_STRING;

typedef struct _IUM_STRING *PIUM_STRING;

typedef struct _IUM_OCTET_STRING
    {
    unsigned int Length;
    /* [size_is][unique] */ unsigned char *Value;
    } 	IUM_OCTET_STRING;

typedef struct _IUM_OCTET_STRING *PIUM_OCTET_STRING;



extern RPC_IF_HANDLE __MIDL_itf_rcg_BaseTypes_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rcg_BaseTypes_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


