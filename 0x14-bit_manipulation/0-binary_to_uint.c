#include "main.h"
#include <stdlib.h>

/**
* binary_to_uint - Converts a binary number to an unsigned integer.
* @b: A string representing the binary number.
* Return: Converted number, or 0 if @b is NULL or contains non-binary digits.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		dec_val = dec_val << 1;
		if (*b++ == '1')
			dec_val += 1;
	}

	return (dec_val);
}

