#include "lists.h"
#include <stdlib.h>

/**
* sum_listint - Calculates sum of elements in a listint_t linked list.
* @head: A pointer to the first node of the linked list.
* Return: The sum of all the elements in the linked list.
*/

int sum_listint(listint_t *head)
{
int sum = 0;

for (; head; head = head->next)
sum += head->n;

return (sum);
}
