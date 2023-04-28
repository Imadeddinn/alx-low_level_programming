#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints the elements of a linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	for (; h; h = h->next, s++)
		printf(h->str ? "[%u] %s\n" : "[0] (nil)\n", h->len, h->str);
	return (s);
}
