#include <stdlib.h>
#include "main.h"

/**
* get_bit - returns the value of a bit at a given index in a decimal number
* @n: the number to search
* @index: the index of the bit to retrieve
* Return: the value of the bit
*/

int get_bit(unsigned long int n, unsigned int index)
{
int bit_value;

if (index > 63)
return (-1);

bit_value = (n >> index) & 1;

return (bit_value);
}
