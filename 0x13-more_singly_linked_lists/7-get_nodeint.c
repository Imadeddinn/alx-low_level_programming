#include "lists.h"
#include <stdlib.h>

/**
* get_nodeint_at_index - Retrieve node at specific index of linked list.
* @head: pointer to the first element in the list
* @index: index of the node to be returned
* Return: pointer to node at index or NULL if it doesn't exist.
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *node = head;

	for (i = 0; node && i < index; i++)
		node = node->next;

	return (node ? node : NULL);
}

