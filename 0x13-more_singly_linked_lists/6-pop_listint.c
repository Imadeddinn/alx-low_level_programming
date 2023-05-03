#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - removes the head node of a linked list
 * @head: pointer to the initial element in the linked list
 *
 * Return: the data within the element that was removed,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)

{
	listint_t *temp;
	int num;

	if (!head || !*head)
	return (0);

	num = (*head)->n;
	temp = (*head)->next;

	free(*head);

	*head = temp;

	return (num);
}

