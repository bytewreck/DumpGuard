

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for rcg_RemoteGuardCallIds.idl:
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


#ifndef __rcg_RemoteGuardCallIds_h__
#define __rcg_RemoteGuardCallIds_h__

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



#ifndef __RemoteGuardCallIds_LIBRARY_DEFINED__
#define __RemoteGuardCallIds_LIBRARY_DEFINED__

/* library RemoteGuardCallIds */
/* [version][uuid] */ 

typedef 
enum _RemoteGuardCallId
    {
        RemoteCallMinimum	= 0,
        RemoteCallGenericMinimum	= 0,
        RemoteCallGenericReserved	= 0,
        RemoteCallGenericMaximum	= 0xff,
        RemoteCallKerbMinimum	= 0x100,
        RemoteCallKerbNegotiateVersion	= 0x100,
        RemoteCallKerbBuildAsReqAuthenticator	= ( RemoteCallKerbNegotiateVersion + 1 ) ,
        RemoteCallKerbVerifyServiceTicket	= ( RemoteCallKerbBuildAsReqAuthenticator + 1 ) ,
        RemoteCallKerbCreateApReqAuthenticator	= ( RemoteCallKerbVerifyServiceTicket + 1 ) ,
        RemoteCallKerbDecryptApReply	= ( RemoteCallKerbCreateApReqAuthenticator + 1 ) ,
        RemoteCallKerbUnpackKdcReplyBody	= ( RemoteCallKerbDecryptApReply + 1 ) ,
        RemoteCallKerbComputeTgsChecksum	= ( RemoteCallKerbUnpackKdcReplyBody + 1 ) ,
        RemoteCallKerbBuildEncryptedAuthData	= ( RemoteCallKerbComputeTgsChecksum + 1 ) ,
        RemoteCallKerbPackApReply	= ( RemoteCallKerbBuildEncryptedAuthData + 1 ) ,
        RemoteCallKerbHashS4UPreauth	= ( RemoteCallKerbPackApReply + 1 ) ,
        RemoteCallKerbSignS4UPreauthData	= ( RemoteCallKerbHashS4UPreauth + 1 ) ,
        RemoteCallKerbVerifyChecksum	= ( RemoteCallKerbSignS4UPreauthData + 1 ) ,
        RemoteCallKerbBuildTicketArmorKey	= ( RemoteCallKerbVerifyChecksum + 1 ) ,
        RemoteCallKerbBuildExplicitArmorKey	= ( RemoteCallKerbBuildTicketArmorKey + 1 ) ,
        RemoteCallKerbVerifyFastArmoredTgsReply	= ( RemoteCallKerbBuildExplicitArmorKey + 1 ) ,
        RemoteCallKerbVerifyEncryptedChallengePaData	= ( RemoteCallKerbVerifyFastArmoredTgsReply + 1 ) ,
        RemoteCallKerbBuildFastArmoredKdcRequest	= ( RemoteCallKerbVerifyEncryptedChallengePaData + 1 ) ,
        RemoteCallKerbDecryptFastArmoredKerbError	= ( RemoteCallKerbBuildFastArmoredKdcRequest + 1 ) ,
        RemoteCallKerbDecryptFastArmoredAsReply	= ( RemoteCallKerbDecryptFastArmoredKerbError + 1 ) ,
        RemoteCallKerbDecryptPacCredentials	= ( RemoteCallKerbDecryptFastArmoredAsReply + 1 ) ,
        RemoteCallKerbCreateECDHKeyAgreement	= ( RemoteCallKerbDecryptPacCredentials + 1 ) ,
        RemoteCallKerbCreateDHKeyAgreement	= ( RemoteCallKerbCreateECDHKeyAgreement + 1 ) ,
        RemoteCallKerbDestroyKeyAgreement	= ( RemoteCallKerbCreateDHKeyAgreement + 1 ) ,
        RemoteCallKerbKeyAgreementGenerateNonce	= ( RemoteCallKerbDestroyKeyAgreement + 1 ) ,
        RemoteCallKerbFinalizeKeyAgreement	= ( RemoteCallKerbKeyAgreementGenerateNonce + 1 ) ,
        RemoteCallKerbSignPkcsMessage	= ( RemoteCallKerbFinalizeKeyAgreement + 1 ) ,
        RemoteCallKerbConvertCredManPasswordToKerbPassword	= ( RemoteCallKerbSignPkcsMessage + 1 ) ,
        RemoteCallKerbMaximum	= 0x1ff,
        RemoteCallNtlmMinimum	= 0x200,
        RemoteCallNtlmNegotiateVersion	= 0x200,
        RemoteCallNtlmProtectCredential	= ( RemoteCallNtlmNegotiateVersion + 1 ) ,
        RemoteCallNtlmLm20GetNtlm3ChallengeResponse	= ( RemoteCallNtlmProtectCredential + 1 ) ,
        RemoteCallNtlmCalculateNtResponse	= ( RemoteCallNtlmLm20GetNtlm3ChallengeResponse + 1 ) ,
        RemoteCallNtlmCalculateUserSessionKeyNt	= ( RemoteCallNtlmCalculateNtResponse + 1 ) ,
        RemoteCallNtlmCompareCredentials	= ( RemoteCallNtlmCalculateUserSessionKeyNt + 1 ) ,
        RemoteCallNtlmMaximum	= 0x2ff,
        RemoteCallMaximum	= 0x2ff,
        RemoteCallInvalid	= 0xffff
    } 	RemoteGuardCallId;


EXTERN_C const IID LIBID_RemoteGuardCallIds;
#endif /* __RemoteGuardCallIds_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


