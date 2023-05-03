#include "lists.h"
#include <stdlib.h>

/**
* free_listint2 - Frees a linked list of type listint_t.
* @head: Pointer to a pointer to the first node in the list to be freed.
*/

void free_listint2(listint_t **head)

{
	if (head == NULL)

		return;

	for (; *head; *head = (*head)->next)
		free(*head);

	*head = NULL;
}

