#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_listint_safe - Deallocates memory for a linked list.
* @h: A pointer to the beginning of the linked list.
* Return: The number of nodes that were successfully freed.
*/

size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *temp = NULL;

	if (!h || !*h)
		return (0);

	while (*h && *h > (*h)->next)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		len++;
	}

	if (*h)
	{
		free(*h);
		*h = NULL;
		len++;
	}

	return (len);
}

