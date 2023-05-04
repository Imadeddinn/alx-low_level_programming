#include "main.h"
#include <stdlib.h>

#include "main.h"

/**
 * print_binary - Displays the binary equivalent of a decimal number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int i;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;
		_putchar((current & 1) ? '1' : '0');
	}
}

