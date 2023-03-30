#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
int n;
int a[5];
int *p;

a[2] = 1024;
p = &n;

/*
* Here, we are dereferencing the pointer `p` and adding an offset of 5 to it.
* This means we are assigning the value 98 to the memory location that is 5 integers
* away from the location pointed to by `p`.
* Since we have not allocated any memory at this location, this results in undefined behavior.
* However, in this specific case, it seems to be overwriting the value stored in `a[2]`.
*/
*(p + 5) = 98;

printf("a[2] = %d\n", a[2]);

return (0);
}
