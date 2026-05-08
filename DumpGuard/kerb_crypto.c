#include "kerb_crypto.h"

extern NTSTATUS WINAPI CDLocateCSystem(KERB_ETYPE etype, KERB_ECRYPT** ppEngine);
extern NTSTATUS WINAPI CDLocateCheckSum(KERB_CTYPE ctype, KERB_ECHECKSUM** ppCheckSum);

BOOL kerb_hash_password(KERB_ETYPE etype, LPCWSTR password, LPCWSTR salt, ULONG iterations, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;
	NTSTATUS status = 0;

	*ppvOutput = NULL;
	*pcbOutput = 0;

	KERB_ECRYPT* engine = NULL;

	if (NT_SUCCESS(status = CDLocateCSystem(etype, &engine)))
	{
		PVOID pvTemp = malloc(engine->KeySize);

		if (pvTemp != NULL)
		{
			UNICODE_STRING Password;
			RtlInitUnicodeString(&Password, password);

			UNICODE_STRING Salt;
			RtlInitUnicodeString(&Salt, salt);

			if (!NT_SUCCESS(status = engine->HashPassword(&Password, &Salt, iterations, pvTemp)))
				free(pvTemp);
			else
			{
				*ppvOutput = pvTemp;
				*pcbOutput = engine->KeySize;

				result = TRUE;
			}
		}
	}

	return result;
}

BOOL kerb_checksum(KERB_CTYPE ctype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	BOOL result = FALSE;
	NTSTATUS status = 0;

	*ppvOutput = NULL;
	*pcbOutput = 0;

	KERB_ECHECKSUM* checksum = NULL;

	if (NT_SUCCESS(status = CDLocateCheckSum(ctype, &checksum)))
	{
		PVOID context = NULL;

		if (NT_SUCCESS(status = checksum->InitializeEx(pvKey, cbKey, key_usage, &context)))
		{
			if (NT_SUCCESS(status = checksum->Sum(context, cbData, pvData)))
			{
				PVOID pvTemp = malloc(checksum->Size);

				if (pvTemp != NULL)
				{
					if (!NT_SUCCESS(status = checksum->Finalize(context, pvTemp)))
						free(pvTemp);
					else
					{
						*ppvOutput = pvTemp;
						*pcbOutput = checksum->Size;

						result = TRUE;
					}
				}
			}

			checksum->Finish(&context);
		}
	}

	return result;
}

BOOL kerb_transform(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput, BOOL fEncrypt)
{
	BOOL result = FALSE;
	NTSTATUS status = 0;

	*ppvOutput = NULL;
	*pcbOutput = 0;

	KERB_ECRYPT* engine = NULL;

	if (NT_SUCCESS(status = CDLocateCSystem(etype, &engine)) && engine->KeySize == cbKey)
	{
		PVOID context = NULL;

		if (NT_SUCCESS(status = engine->Initialize(pvKey, cbKey, key_usage, &context)))
		{
			ULONG cbTemp = cbData;
			ULONG cbTempMod = cbTemp % engine->BlockSize;

			if (cbTempMod != 0)
				cbTemp += engine->BlockSize - cbTempMod;

			cbTemp += engine->MetaSize;

			PVOID pvTemp = malloc(cbTemp);

			if (pvTemp != NULL)
			{
				if (!NT_SUCCESS(status = (fEncrypt ? engine->Encrypt : engine->Decrypt)(context, pvData, cbData, pvTemp, &cbTemp)))
					free(pvTemp);
				else
				{
					*ppvOutput = pvTemp;
					*pcbOutput = cbTemp;

					result = TRUE;
				}
			}

			engine->Finish(&context);
		}
	}

	return result;
}

BOOL kerb_encrypt(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	return kerb_transform(etype, key_usage, pvKey, cbKey, pvData, cbData, ppvOutput, pcbOutput, TRUE);
}

BOOL kerb_decrypt(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, LPCVOID pvData, ULONG cbData, PVOID* ppvOutput, ULONG* pcbOutput)
{
	return kerb_transform(etype, key_usage, pvKey, cbKey, pvData, cbData, ppvOutput, pcbOutput, FALSE);
}

BOOL kerb_seal_transform(KERB_ETYPE etype, KERB_KEY_USAGE key_usage, LPCVOID pvKey, ULONG cbKey, PBYTE pvData, ULONG cbData, BOOL fEncrypt)
{
	BOOL result = FALSE;
	NTSTATUS status = 0;

	KERB_ECRYPT* engine = NULL;

	if (NT_SUCCESS(status = CDLocateCSystem(etype, &engine)))
	{
		PVOID context = NULL;

		if (NT_SUCCESS(status = engine->Initialize(pvKey, cbKey, key_usage, &context)))
		{
			ULONG cbConfounder = 16;
			ULONG cbTrailer = cbData - cbConfounder;

			if (NT_SUCCESS(status = (fEncrypt ? engine->EncryptPlain : engine->DecryptPlain)(context, cbTrailer, cbConfounder, pvData)))
			{
				while (cbTrailer > 0)
				{
					if (cbTrailer <= 2 * engine->BlockSize)
					{
						if (!NT_SUCCESS(status = (fEncrypt ? engine->EncryptPlain : engine->DecryptPlain)(context, 0, cbTrailer, &pvData[cbData - cbTrailer])))
							break;

						cbTrailer = 0;
					}
					else
					{
						if (!NT_SUCCESS(status = (fEncrypt ? engine->EncryptPlain : engine->DecryptPlain)(context, cbTrailer, engine->BlockSize, &pvData[cbData - cbTrailer])))
							break;

						cbTrailer -= engine->BlockSize;
					}
				}

				if (cbTrailer == 0)
					result = TRUE;
			}

			engine->Finish(&context);
		}
	}

	return result;
}