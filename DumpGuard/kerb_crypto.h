#ifndef __KERB_CRYPTO_H__
#define __KERB_CRYPTO_H__

#include "kerb_base.h"

#include <Windows.h>
#include <winternl.h>

typedef enum _KERB_CTYPE
{
    kerb_ctype_none = 0,
    kerb_ctype_kerb_crc32 = 1,
    kerb_ctype_md4 = 2,
    kerb_ctype_des_mac_1510 = 4,
    kerb_ctype_des_mac_k = 5,
    kerb_ctype_md5 = 7,
    kerb_ctype_hmac_sha_96_aes128 = 15,
    kerb_ctype_hmac_sha_96_aes256 = 16,
    kerb_ctype_sha = 0xffffff7d,
    kerb_ctype_crc32 = 0xffffff7c,
    kerb_ctype_des_mac = 0xffffff7b,
    kerb_ctype_des_mac_md5 = 0xffffff7a,
    kerb_ctype_md25 = 0xffffff79,
    kerb_ctype_md5_hmac = 0xffffff77,
    kerb_ctype_hmac_md5 = 0xffffff76,
    kerb_ctype_hmac_sha_96_aes128_ki = 0xffffff6a,
    kerb_ctype_hmac_sha_96_aes256_ki = 0xffffff69,
} KERB_CTYPE;

typedef NTSTATUS (WINAPI* KERB_CHECKSUM_Initialize_t)(BOOL fReserved, PVOID* ppContext);
typedef NTSTATUS (WINAPI* KERB_CHECKSUM_Sum_t)(PVOID pContext, ULONG cbData, LPCVOID pvData);
typedef NTSTATUS (WINAPI* KERB_CHECKSUM_Finalize_t)(PVOID pContext, PVOID pvBuffer);
typedef NTSTATUS (WINAPI* KERB_CHECKSUM_Finish_t)(PVOID* ppContext);
typedef NTSTATUS (WINAPI* KERB_CHECKSUM_InitializeEx_t)(LPCVOID pvKey, ULONG cbKey, KERB_KEY_USAGE KeyUsage, PVOID* ppContext);

typedef struct _KERB_ECHECKSUM
{
    KERB_CTYPE Type;
    ULONG Size;
    ULONG Reserved1;
    ULONG Reserved2;
    KERB_CHECKSUM_Initialize_t Initialize;
    KERB_CHECKSUM_Sum_t Sum;
    KERB_CHECKSUM_Finalize_t Finalize;
    KERB_CHECKSUM_Finish_t Finish;
    KERB_CHECKSUM_InitializeEx_t InitializeEx;
    PVOID InitializeEx2;
} KERB_ECHECKSUM, *PKERB_ECHECKSUM;

typedef enum _KERB_ETYPE
{
    kerb_etype_none = 0,
    kerb_etype_des_crc32 = 1,                      // Kerberos DES-CBC-CRC
    kerb_etype_des_md5 = 3,                        // Kerberos DES-CBC-MD5
    kerb_etype_aes128 = 17,                        // Kerberos AES128-CTS-HMAC-SHA1-96
    kerb_etype_aes256 = 18,                        // Kerberos AES256-CTS-HMAC-SHA1-96
    kerb_etype_rc4_hmac = 23,                      // RSADSI RC4-HMAC
    kerb_etype_rc4_hmac_exp = 24,                  // RSADSI RC4-HMAC
    kerb_etype_rc4_md4 = 0xffffff80,               // RSADSI RC4-MD4
    kerb_etype_des_plain = 0xffffff7c,             // Kerberos DES-Plain
    kerb_etype_rc4_hmac_old = 0xffffff7b,          // RSADSI RC4-HMAC
    kerb_etype_rc4_plain_old = 0xffffff7a,         // RSADSI RC4
    kerb_etype_rc4_hmac_old_exp = 0xffffff79,      // RSADSI RC4-HMAC
    kerb_etype_rc4_plain_old_exp = 0xffffff78,     // RSADSI RC4-EXP
    kerb_etype_rc4_plain = 0xffffff74,             // RSADSI RC4
    kerb_etype_rc4_plain_exp = 0xffffff73,         // RSADSI RC4-EXP
    kerb_etype_aes128_plain = 0xffffff6c,          // Kerberos AES128-CTS-HMAC-SHA1-96-PLAIN
    kerb_etype_aes256_plain = 0xffffff6b,          // Kerberos AES256-CTS-HMAC-SHA1-96-PLAIN
} KERB_ETYPE;

typedef NTSTATUS (WINAPI* KERB_ECRYPT_Initialize_t)(LPCVOID pvKey, ULONG cbKey, KERB_KEY_USAGE KeyUsage, PVOID* ppContext);
typedef NTSTATUS (WINAPI* KERB_ECRYPT_Crypt_t)(PVOID pContext, LPCVOID pvInput, ULONG cbInput, PVOID pvOutput, ULONG* pcbOutput);
typedef NTSTATUS (WINAPI* KERB_ECRYPT_Finish_t)(PVOID* pContext);
typedef NTSTATUS (WINAPI* KERB_ECRYPT_HashPassword_t)(PCUNICODE_STRING Password, PCUNICODE_STRING Salt, ULONG IterationCount, PVOID pvOutput);
typedef NTSTATUS (WINAPI* KERB_ECRYPT_RandomKey_t)(LPCVOID pvKey, ULONG cbKey, PVOID pvOutput);
typedef NTSTATUS (WINAPI* KERB_ECRYPT_Control_t)(BOOL fReserved, PVOID pContext, PUCHAR pvInput, ULONG cbInput);
typedef NTSTATUS (WINAPI* KERB_ECRYPT_Crypt_Plain_t)(PVOID pContext, ULONG cbTrailer, ULONG cbData, PVOID pvData);

typedef struct _KERB_ECRYPT
{
    KERB_ETYPE Type;
    ULONG BlockSize;
    ULONG Reserved1; // Duplicate of Type (?)
    ULONG KeySize;
    ULONG MetaSize;
    ULONG Reserved2;
    ULONG Reserved3;
    ULONG Reserved4;
    PCWSTR AlgorithmName;
    KERB_ECRYPT_Initialize_t Initialize;
    KERB_ECRYPT_Crypt_t Encrypt;
    KERB_ECRYPT_Crypt_t Decrypt;
    KERB_ECRYPT_Finish_t Finish;
    KERB_ECRYPT_HashPassword_t HashPassword;
    KERB_ECRYPT_RandomKey_t RandomKey;
    KERB_ECRYPT_Control_t Control;
    KERB_ECRYPT_Crypt_Plain_t EncryptPlain;
    KERB_ECRYPT_Crypt_Plain_t DecryptPlain;
    PVOID PseudoRandommFunction;
    PVOID PseudoRandommFunctionPlus;
} KERB_ECRYPT, *PKERB_ECRYPT;

BOOL kerb_hash_password(KERB_ETYPE etype, LPCWSTR password, LPCWSTR salt, ULONG iterations, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL kerb_checksum(KERB_CTYPE ctype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL kerb_encrypt(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);
BOOL kerb_decrypt(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput);

BOOL kerb_seal_transform(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, PBYTE pvData, ULONG cbData, BOOL fEncrypt);

#endif