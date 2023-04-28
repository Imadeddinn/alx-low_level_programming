#include <stdlib.h>
#include "lists.h"
/**
 * list_len - calculates and returns N° of elements in a linked list
 * @h: Pointer to the list_t list.
 * Return: Number of elements in h.
 */

size_t list_len(const list_t *h)
{
	size_t num_elements = 0;

	for (; h != NULL; h = h->next)
		num_elements++;
	return (num_elements);
}
