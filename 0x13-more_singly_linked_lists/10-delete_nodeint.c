#include "lists.h"
#include "stdlib.h"

/**
* delete_nodeint_at_index - Removes node at specified index from linked list.
* @head: A pointer to the first node of the linked list.
* @index: The index of the node to remove.
* Return: 1 (Success) or -1 (Failure).
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head, *current = NULL;
	unsigned int i;

	if (!*head)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; temp && i < index - 1; i++)
		temp = temp->next;

	if (!temp || !temp->next)
		return (-1);

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}

