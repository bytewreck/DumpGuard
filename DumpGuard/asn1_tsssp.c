#include "asn1_tsssp.h"

ASN1int32_t ASN1CALL ASN1Enc_TSPasswordCreds(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSPasswordCreds* Data) { return 0; }
ASN1int32_t ASN1CALL ASN1Dec_TSPasswordCreds(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSPasswordCreds* Data) { return 0; }
void ASN1Free_TSPasswordCreds(void* data) { /* Don't really care about the credential structures */ }

ASN1int32_t ASN1CALL ASN1Enc_TSSmartCardCreds(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSSmartCardCreds* Data) { return 0; }
ASN1int32_t ASN1CALL ASN1Dec_TSSmartCardCreds(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSSmartCardCreds* Data) { return 0; }
void ASN1Free_TSSmartCardCreds(void* data) { /* Don't really care about the credential structures */ }

ASN1int32_t ASN1CALL ASN1Enc_TSCredentials(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSCredentials* Data)
{
	if (Tag == 0)
		Tag = 16;

	ASN1uint32_t tag_length_offsets[10];
	memset(tag_length_offsets, 0, sizeof(tag_length_offsets));

	if (!ASN1BEREncExplicitTag(Encoder, Tag, &tag_length_offsets[0]))
		return 0;

	if (!ASN1BEREncExplicitTag(Encoder, 0x80000000, &tag_length_offsets[1]) ||
		!ASN1BEREncS32(Encoder, 2, Data->CredType) ||
		!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
	{
		return 0;
	}

	if (!ASN1BEREncExplicitTag(Encoder, 0x80000001, &tag_length_offsets[1]) ||
		!ASN1BEREncOctetString(Encoder, 4, Data->Credentials.length, Data->Credentials.value) ||
		!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
	{
		return 0;
	}

	return ASN1BEREncEndOfContents(Encoder, tag_length_offsets[0]) != 0;
}

ASN1int32_t ASN1CALL ASN1Dec_TSCredentials(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSCredentials* Data)
{
	if (Tag == 0)
		Tag = 16;

	ASN1decoding_t tag_decoders[10];
	memset(tag_decoders, 0, sizeof(tag_decoders));

	ASN1octet_t* tag_ids[10];
	memset(tag_ids, 0, sizeof(tag_ids));

	if (!ASN1BERDecExplicitTag(Decoder, Tag, &tag_decoders[0], &tag_ids[0]))
		return 0;

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000000, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecS32Val(tag_decoders[1], 2, &Data->CredType) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000001, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecOctetString(tag_decoders[1], 4, &Data->Credentials) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	while (ASN1BERDecNotEndOfContents(tag_decoders[0], tag_ids[0]))
	{
		if (!ASN1BERDecSkip(tag_decoders[0]))
			return 0;
	}

	return ASN1BERDecEndOfContents(Decoder, tag_decoders[0], tag_ids[0]) != 0;
}

void ASN1Free_TSCredentials(TSCredentials* Data)
{ 
	if (Data != NULL)
		ASN1octetstring_free(&Data->Credentials);
}

ASN1int32_t ASN1CALL ASN1Enc_TSRequest(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSRequest* Data) 
{ 
	if (Tag == 0)
		Tag = 16;

	ASN1uint32_t tag_length_offsets[10];
	memset(tag_length_offsets, 0, sizeof(tag_length_offsets));

	if (!ASN1BEREncExplicitTag(Encoder, Tag, &tag_length_offsets[0]))
		return 0;
	
	if (!ASN1BEREncExplicitTag(Encoder, 0x80000000, &tag_length_offsets[1]) ||
		!ASN1BEREncS32(Encoder, 2, Data->Version) ||
		!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
	{
		return 0;
	}

	if ((Data->Flags & TSREQUEST_HAS_NEGOTOKENS) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000001, &tag_length_offsets[1]) ||
			!ASN1BEREncExplicitTag(Encoder, 16, &tag_length_offsets[2]))
		{
			return 0;
		}

		for (NegoData* current = Data->NegoTokens; current != NULL; current = current->Next)
		{
			if (!ASN1BEREncExplicitTag(Encoder, 16, &tag_length_offsets[3]) ||
				!ASN1BEREncExplicitTag(Encoder, 0x80000000, &tag_length_offsets[4]) ||
				!ASN1BEREncOctetString(Encoder, 4, current->NegoToken.length, current->NegoToken.value) ||
				!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[4]) ||
				!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[3]))
			{
				return 0;
			}
		}

		if (!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[2]) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}

	if ((Data->Flags & TSREQUEST_HAS_AUTHINFO) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000002, &tag_length_offsets[1]) ||
			!ASN1BEREncOctetString(Encoder, 4, Data->AuthInfo.length, Data->AuthInfo.value) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}

	if ((Data->Flags & TSREQUEST_HAS_PUBKEYAUTH) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000003, &tag_length_offsets[1]) ||
			!ASN1BEREncOctetString(Encoder, 4, Data->PubKeyAuth.length, Data->PubKeyAuth.value) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}

	if ((Data->Flags & TSREQUEST_HAS_ERRORCODE) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000004, &tag_length_offsets[1]) ||
			!ASN1BEREncS32(Encoder, 2, Data->ErrorCode) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}
	
	if ((Data->Flags & TSREQUEST_HAS_CLIENTNONCE) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000005, &tag_length_offsets[1]) ||
			!ASN1BEREncOctetString(Encoder, 4, Data->ClientNonce.length, Data->ClientNonce.value) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}

	return ASN1BEREncEndOfContents(Encoder, tag_length_offsets[0]) != 0;
}

ASN1int32_t ASN1CALL ASN1Dec_TSRequest(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSRequest* Data) 
{
	if (Tag == 0)
		Tag = 16;

	ASN1decoding_t tag_decoders[10];
	memset(tag_decoders, 0, sizeof(tag_decoders));

	ASN1octet_t* tag_ids[10];
	memset(tag_ids, 0, sizeof(tag_ids));

	if (!ASN1BERDecExplicitTag(Decoder, Tag, &tag_decoders[0], &tag_ids[0]))
		return 0;

	Data->Flags = 0;

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000000, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecS32Val(tag_decoders[1], 2, &Data->Version) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	ASN1uint32_t tag_temp = 0;
	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000001)
	{
		Data->Flags |= TSREQUEST_HAS_NEGOTOKENS;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000001, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecExplicitTag(tag_decoders[1], 16, &tag_decoders[2], &tag_ids[2]))
		{
			return 0;
		}

		NegoData** current = &Data->NegoTokens;

		while (ASN1BERDecNotEndOfContents(tag_decoders[2], tag_ids[2]))
		{
			if (!ASN1BERDecPeekTag(tag_decoders[2], &tag_temp))
				return 0;

			NegoData* next = (NegoData*)ASN1DecAlloc(tag_decoders[2], sizeof(NegoData));
			*current = next;

			if (!next)
				return 0;

			if (!ASN1BERDecExplicitTag(tag_decoders[2], 16, &tag_decoders[3], &tag_ids[3]) ||
				!ASN1BERDecExplicitTag(tag_decoders[3], 0x80000000, &tag_decoders[4], &tag_ids[4]) ||
				!ASN1BERDecOctetString(tag_decoders[4], 4, &next->NegoToken) ||
				!ASN1BERDecEndOfContents(tag_decoders[3], tag_decoders[4], tag_ids[4]) ||
				!ASN1BERDecEndOfContents(tag_decoders[2], tag_decoders[3], tag_ids[3]))
			{
				return 0;
			}

			current = (NegoData**)next; // review
		}

		*current = NULL;

		if (!ASN1BERDecEndOfContents(tag_decoders[1], tag_decoders[2], tag_ids[2]) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000002)
	{
		Data->Flags |= TSREQUEST_HAS_AUTHINFO;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000002, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecOctetString(tag_decoders[1], 4, &Data->AuthInfo) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000003)
	{
		Data->Flags |= TSREQUEST_HAS_PUBKEYAUTH;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000003, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecOctetString(tag_decoders[1], 4, &Data->PubKeyAuth) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000004)
	{
		Data->Flags |= TSREQUEST_HAS_ERRORCODE;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000004, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecS32Val(tag_decoders[1], 2, &Data->ErrorCode) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000005)
	{
		Data->Flags |= TSREQUEST_HAS_CLIENTNONCE;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000005, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecOctetString(tag_decoders[1], 4, &Data->ClientNonce) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	while (ASN1BERDecNotEndOfContents(tag_decoders[0], tag_ids[0]))
	{
		if (!ASN1BERDecSkip(tag_decoders[0]))
			return 0;
	}

	return ASN1BERDecEndOfContents(Decoder, tag_decoders[0], tag_ids[0]) != 0;
}

void ASN1Free_TSRequest(TSRequest* Data) 
{
	if ((Data->Flags & TSREQUEST_HAS_NEGOTOKENS) != 0)
	{
		NegoData* current = Data->NegoTokens;

		while (current != NULL)
		{
			ASN1octetstring_free(&current->NegoToken);

			NegoData* next = current->Next;
			ASN1Free(current);
			current = next;
		}
	}

	if ((Data->Flags & TSREQUEST_HAS_AUTHINFO) != 0)
		ASN1octetstring_free(&Data->AuthInfo);

	if ((Data->Flags & TSREQUEST_HAS_PUBKEYAUTH) != 0)
		ASN1octetstring_free(&Data->PubKeyAuth);

	if ((Data->Flags & TSREQUEST_HAS_CLIENTNONCE) != 0)
		ASN1octetstring_free(&Data->ClientNonce);
}

ASN1int32_t ASN1CALL ASN1Enc_TSRemoteGuardPackageCred(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSRemoteGuardPackageCred* Data)
{
	return 0; // TODO: Do we care about the encoder?
}

ASN1int32_t ASN1CALL ASN1Dec_TSRemoteGuardPackageCred(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSRemoteGuardPackageCred* Data)
{
	ASN1decoding_t tag_decoders[10];
	memset(tag_decoders, 0, sizeof(tag_decoders));

	ASN1octet_t* tag_ids[10];
	memset(tag_ids, 0, sizeof(tag_ids));

	if (!ASN1BERDecExplicitTag(Decoder, 16, &tag_decoders[0], &tag_ids[0]))
		return 0;

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000000, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecOctetString(tag_decoders[1], 4, &Data->PackageName) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000001, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecOctetString(tag_decoders[1], 4, &Data->CredBuffer) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	while (ASN1BERDecNotEndOfContents(tag_decoders[0], tag_ids[0]))
	{
		if (!ASN1BERDecSkip(tag_decoders[0]))
			return 0;
	}

	return ASN1BERDecEndOfContents(Decoder, tag_decoders[0], tag_ids[0]) != 0;
}

void ASN1Free_TSRemoteGuardPackageCred(TSRemoteGuardPackageCred* data)
{
	if (data != NULL)
	{
		ASN1octetstring_free(&data->PackageName);
		ASN1octetstring_free(&data->CredBuffer);
	}
}

ASN1int32_t ASN1CALL ASN1Enc_TSRemoteGuardCreds_supplementalCreds(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSRemoteGuardCreds_supplementalCreds* Data)
{
	return 0; // TODO: Do we care about the encoder?
}

ASN1int32_t ASN1CALL ASN1Dec_TSRemoteGuardCreds_supplementalCreds(ASN1decoding_t Decoder, ASN1uint32_t Tag, PTSRemoteGuardCreds_supplementalCreds* Data)
{
	ASN1decoding_t tag_decoders[10];
	memset(tag_decoders, 0, sizeof(tag_decoders));

	ASN1octet_t* tag_ids[10];
	memset(tag_ids, 0, sizeof(tag_ids));

	if (!ASN1BERDecExplicitTag(Decoder, 0x80000001, &tag_decoders[0], &tag_ids[0]) ||
		!ASN1BERDecExplicitTag(Decoder, 16, &tag_decoders[1], &tag_ids[1]))
	{
		return 0;
	}
	
	PTSRemoteGuardCreds_supplementalCreds* current = Data;

	while (ASN1BERDecNotEndOfContents(tag_decoders[1], tag_ids[1]))
	{
		ASN1uint32_t tag_temp = 0;

		if (!ASN1BERDecPeekTag(tag_decoders[1], &tag_temp))
			return 0;

		TSRemoteGuardCreds_supplementalCreds* next = (TSRemoteGuardCreds_supplementalCreds*)
			ASN1DecAlloc(tag_decoders[1], sizeof(TSRemoteGuardCreds_supplementalCreds));

		*current = next;

		if (!next || !ASN1Dec_TSRemoteGuardPackageCred(tag_decoders[1], 0, &next->Value))
			return 0;
		
		current = (PTSRemoteGuardCreds_supplementalCreds*)next; // review
	}

	*current = NULL;

	return (ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]) != 0 &&
		ASN1BERDecEndOfContents(Decoder, tag_decoders[0], tag_ids[0]) != 0);
}

ASN1int32_t ASN1CALL ASN1Enc_TSRemoteGuardCreds(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSRemoteGuardCreds* Data) 
{
	return 0; // TODO: Do we care about the encoder?
}

ASN1int32_t ASN1CALL ASN1Dec_TSRemoteGuardCreds(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSRemoteGuardCreds* Data)
{
	if (Tag == 0)
		Tag = 16;

	ASN1decoding_t tag_decoders[10];
	memset(tag_decoders, 0, sizeof(tag_decoders));

	ASN1octet_t* tag_ids[10];
	memset(tag_ids, 0, sizeof(tag_ids));

	if (!ASN1BERDecExplicitTag(Decoder, Tag, &tag_decoders[0], &tag_ids[0]))
		return 0;

	Data->Flags = 0;

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000000, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1Dec_TSRemoteGuardPackageCred(tag_decoders[1], 0, &Data->LogonCred) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	ASN1uint32_t tag_temp = 0;
	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000001)
	{
		Data->Flags |= TSREMOTEGUARDCREDS_HAS_SUPPLEMENTAL_CREDS;
		
		if (!ASN1Dec_TSRemoteGuardCreds_supplementalCreds(tag_decoders[0], 0, &Data->SupplementalCreds))
			return 0;
	}

	while (ASN1BERDecNotEndOfContents(tag_decoders[0], tag_ids[0]))
	{
		if (!ASN1BERDecSkip(tag_decoders[0]))
			return 0;
	}

	return ASN1BERDecEndOfContents(Decoder, tag_decoders[0], tag_ids[0]) != 0;
}

void ASN1Free_TSRemoteGuardCreds(TSRemoteGuardCreds* Data)
{
	if (Data != NULL)
	{
		ASN1Free_TSRemoteGuardPackageCred(&Data->LogonCred);

		if ((Data->Flags & TSREMOTEGUARDCREDS_HAS_SUPPLEMENTAL_CREDS) != 0)
		{
			TSRemoteGuardCreds_supplementalCreds* current = Data->SupplementalCreds;

			while (current != NULL)
			{
				ASN1Free_TSRemoteGuardPackageCred(&current->Value);

				TSRemoteGuardCreds_supplementalCreds* next = current->Next;
				ASN1Free(current);
				current = next;
			}
		}
	}
}

ASN1int32_t ASN1CALL ASN1Enc_TSRemoteGuardInnerPacket(ASN1encoding_t Encoder, ASN1uint32_t Tag, TSRemoteGuardInnerPacket* Data) 
{ 
	if (Tag == 0)
		Tag = 16;

	ASN1uint32_t tag_length_offsets[10];
	memset(tag_length_offsets, 0, sizeof(tag_length_offsets));

	if (!ASN1BEREncExplicitTag(Encoder, Tag, &tag_length_offsets[0]))
		return 0;

	DWORD dwFlags = Data->Flags & 0x7f;

	if (Data->Version != 0)
		dwFlags = Data->Flags;

	if ((dwFlags & TSREMOTEGUARDINNERPACKET_HAS_VERSION) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000000, &tag_length_offsets[1]) ||
			!ASN1BEREncU32(Encoder, 10, Data->Version) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}

	if (!ASN1BEREncExplicitTag(Encoder, 0x80000001, &tag_length_offsets[1]) ||
		!ASN1BEREncOctetString(Encoder, 4, Data->PackageName.length, Data->PackageName.value) ||
		!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
	{
		return 0;
	}

	if (!ASN1BEREncExplicitTag(Encoder, 0x80000002, &tag_length_offsets[1]) ||
		!ASN1BEREncOctetString(Encoder, 4, Data->Buffer.length, Data->Buffer.value) ||
		!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
	{
		return 0;
	}

	if ((dwFlags & TSREMOTEGUARDINNERPACKET_HAS_EXTENSION) != 0)
	{
		if (!ASN1BEREncExplicitTag(Encoder, 0x80000003, &tag_length_offsets[1]) ||
			!ASN1BEREncOpenType(Encoder, &Data->Extension) ||
			!ASN1BEREncEndOfContents(Encoder, tag_length_offsets[1]))
		{
			return 0;
		}
	}

	return ASN1BEREncEndOfContents(Encoder, tag_length_offsets[0]) != 0;
}

ASN1int32_t ASN1CALL ASN1Dec_TSRemoteGuardInnerPacket(ASN1decoding_t Decoder, ASN1uint32_t Tag, TSRemoteGuardInnerPacket* Data) 
{ 
	if (Tag == 0)
		Tag = 16;

	ASN1decoding_t tag_decoders[10];
	memset(tag_decoders, 0, sizeof(tag_decoders));

	ASN1octet_t* tag_ids[10];
	memset(tag_ids, 0, sizeof(tag_ids));

	if (!ASN1BERDecExplicitTag(Decoder, Tag, &tag_decoders[0], &tag_ids[0]))
		return 0;

	Data->Flags = 0;

	ASN1uint32_t tag_temp = 0;
	ASN1BERDecPeekTag(tag_decoders[0], &tag_temp);

	if (tag_temp == 0x80000000)
	{
		Data->Flags |= TSREMOTEGUARDINNERPACKET_HAS_VERSION;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000000, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecU32Val(tag_decoders[1], 10, (ASN1uint32_t*)&Data->Version) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000001, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecOctetString2(tag_decoders[1], 4, &Data->PackageName) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000002, &tag_decoders[1], &tag_ids[1]) ||
		!ASN1BERDecOctetString2(tag_decoders[1], 4, &Data->Buffer) ||
		!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
	{
		return 0;
	}

	if (ASN1BERDecPeekTag(tag_decoders[0], &tag_temp) && tag_temp == 0x80000003)
	{
		Data->Flags |= TSREMOTEGUARDINNERPACKET_HAS_EXTENSION;

		if (!ASN1BERDecExplicitTag(tag_decoders[0], 0x80000003, &tag_decoders[1], &tag_ids[1]) ||
			!ASN1BERDecOpenType2(tag_decoders[1], &Data->Extension) ||
			!ASN1BERDecEndOfContents(tag_decoders[0], tag_decoders[1], tag_ids[1]))
		{
			return 0;
		}
	}

	if ((Data->Flags & 0x80) == 0)
		Data->Version = TsRemoteGuardv1;

	while (ASN1BERDecNotEndOfContents(tag_decoders[0], tag_ids[0]))
	{
		if (!ASN1BERDecSkip(tag_decoders[0]))
			return 0;
	}

	return ASN1BERDecEndOfContents(Decoder, tag_decoders[0], tag_ids[0]) != 0;
}

void ASN1Free_TSRemoteGuardInnerPacket(void* Data) 
{
	// There's nothing to free (?)
}

ASN1GenericFun_t g_Encoders[] = 
{
	(ASN1GenericFun_t)ASN1Enc_TSPasswordCreds,
	(ASN1GenericFun_t)ASN1Enc_TSSmartCardCreds,
	(ASN1GenericFun_t)ASN1Enc_TSCredentials,
	(ASN1GenericFun_t)ASN1Enc_TSRequest,
	(ASN1GenericFun_t)ASN1Enc_TSRemoteGuardCreds,
	(ASN1GenericFun_t)ASN1Enc_TSRemoteGuardInnerPacket
};

ASN1GenericFun_t g_Decoders[] = 
{
	(ASN1GenericFun_t)ASN1Dec_TSPasswordCreds,
	(ASN1GenericFun_t)ASN1Dec_TSSmartCardCreds,
	(ASN1GenericFun_t)ASN1Dec_TSCredentials,
	(ASN1GenericFun_t)ASN1Dec_TSRequest,
	(ASN1GenericFun_t)ASN1Dec_TSRemoteGuardCreds,
	(ASN1GenericFun_t)ASN1Dec_TSRemoteGuardInnerPacket
};

ASN1FreeFun_t g_Cleanups[] = 
{
	(ASN1FreeFun_t)ASN1Free_TSPasswordCreds,
	(ASN1FreeFun_t)ASN1Free_TSSmartCardCreds,
	(ASN1FreeFun_t)ASN1Free_TSCredentials,
	(ASN1FreeFun_t)ASN1Free_TSRequest,
	(ASN1FreeFun_t)ASN1Free_TSRemoteGuardCreds,
	(ASN1FreeFun_t)ASN1Free_TSRemoteGuardInnerPacket
};

ASN1uint32_t g_StructSizes[] = 
{
	sizeof(TSPasswordCreds),
	sizeof(TSSmartCardCreds),
	sizeof(TSCredentials),
	sizeof(TSRequest),
	sizeof(TSRemoteGuardCreds),
	sizeof(TSRemoteGuardInnerPacket)
};

ASN1module_t TSSSP_Module = NULL;

BOOL ASN1CALL asn1_startup_tsssp()
{
	return (TSSSP_Module = ASN1_CreateModule(ASN1_THIS_VERSION, ASN1_BER_RULE_DER, ASN1FLAGS_NOASSERT, 6, g_Encoders, g_Decoders, g_Cleanups, g_StructSizes, 'rcgx')) != NULL;
}

void ASN1CALL asn1_cleanup_tsssp()
{
	ASN1_CloseModule(TSSSP_Module);
	TSSSP_Module = NULL;
}

BOOL asn1_encode_tsssp(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData)
{
	BOOL Result = FALSE;

	if (TSSSP_Module != NULL)
	{
		ASN1encoding_t Encoder = NULL;

		if (ASN1_CreateEncoder(TSSSP_Module, &Encoder, NULL, 0, NULL) == ASN1_SUCCESS && Encoder != NULL)
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

BOOL asn1_decode_tsssp(LPCVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct)
{
	BOOL Result = FALSE;

	if (TSSSP_Module != NULL)
	{
		ASN1decoding_t Decoder = NULL;

		if (ASN1_CreateDecoder(TSSSP_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
		{
			Result = ASN1_Decode(Decoder, ppDataStruct, dwPdu, ASN1DECODE_SETBUFFER, (ASN1octet_t*)pvData, (ASN1uint32_t)cbData) >= 0;
			ASN1_CloseDecoder(Decoder);
		}
	}

	return Result;
}

BOOL asn1_free_tsssp(PVOID pDataStruct, DWORD dwPdu)
{
	BOOL Result = FALSE;

	if (TSSSP_Module != NULL)
	{
		ASN1decoding_t Decoder = NULL;

		if (ASN1_CreateDecoder(TSSSP_Module, &Decoder, NULL, 0, NULL) == ASN1_SUCCESS && Decoder != NULL)
		{
			ASN1_FreeDecoded(Decoder, pDataStruct, dwPdu);
			ASN1_CloseDecoder(Decoder);
		}
	}

	return Result;
}