#include "kerb_base.h"
#include "asn1_krb5.h"

BYTE kerb_reverse_bits(BYTE value)
{
	BYTE result = 0;

	for (int i = 0; i < 8; i++)
		result = (result << 1) | ((value >> i) & 1);

	return result;
}

void kerb_set_bitstring32(BYTE* bitstring, ULONG value)
{
	for (ULONG i = 0; i < sizeof(value); i++)
		bitstring[i] = kerb_reverse_bits(((BYTE*)&value)[i]);
}

ULONG kerb_get_bitstring32(BYTE* bitstring, ULONG length)
{
	ULONG result = 0;

	for (ULONG i = 0; i < sizeof(result) && i < length; i++)
		((BYTE*)&result)[i] = kerb_reverse_bits(bitstring[i]);

	return result;
}
