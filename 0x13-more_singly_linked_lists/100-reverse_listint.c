#include "lists.h"
#include <stdlib.h>

/**
* reverse_listint - Reverses a given linked list in place.
* @head: A pointer to the first node of the linked list.
* Return: A pointer to the first node of the reversed linked list.
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL, *next;

while (*head)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}

*head = prev;

return (prev);
}
