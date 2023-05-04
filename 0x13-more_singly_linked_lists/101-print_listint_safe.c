#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_listint_safe - Safely prints a list of listint_t.
* @head: A pointer to the head of the list.
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current = head;
const size_t max_nodes = 1024;
size_t i, j;

for (i = 0; i < max_nodes && current; i++)
{
printf("[%p] %d\n", (void *)current, current->n);
current = current->next;

for (j = 0; j < i; j++)
{
if (current == head)
{
printf("-> [%p] %d\n", (void *)current, current->n);
return (i + 1);
}

if (current == head->next)
break;

head = head->next;
}
}

return (i);
}
