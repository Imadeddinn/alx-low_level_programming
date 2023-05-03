#include "lists.h"
#include <stdlib.h>
/**
* free_listint - Releases the memory used by a linked list.
* @head: Pointer to the first element of the list.
*/

void free_listint(listint_t *head)
{
	while (head)
	{
		listint_t *current = head;

		head = head->next;
		free(current);
	}
}

