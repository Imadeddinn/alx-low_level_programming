#include "lists.h"

/**
 * listint_len - Returns the num of elements in a linked list of integers.
 *
 * @h: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	for (; h; h = h->next, count++)
		;

	return (count);
}

