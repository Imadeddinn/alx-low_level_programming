#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
* free_listint2 - Frees a linked list of type listint_t.
* @head: Pointer to a pointer to the first node in the list to be freed.
*/

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
	return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

