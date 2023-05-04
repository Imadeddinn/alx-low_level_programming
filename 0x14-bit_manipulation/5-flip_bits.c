#include <stdlib.h>
#include "main.h"

/**
* flip_bits - counts the number of bits to modify
* to transition from one number to another
* @n: 1st number
* @m: 2nd number
*
* Return: number of bits to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int exclusive = n ^ m;
unsigned int count = 0;

while (exclusive)
{
count += exclusive & 1;
exclusive >>= 1;
}

return (count);
}

