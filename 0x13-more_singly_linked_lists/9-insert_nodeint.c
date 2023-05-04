#include "lists.h"
#include <stdlib.h>

/**
* insert_nodeint_at_index - inserts new node at given position in linked list
* @head: pointer to first node
* @idx: index where new node is added
* @n: data to insert in new node
* Return: pointer to new node or NULL
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i;
listint_t *new_node, *temp = *head;

new_node = malloc(sizeof(listint_t));
if (!new_node || !head)

return (NULL);

new_node->n = n;
new_node->next = NULL;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;

return (new_node);
}

for (i = 1; temp && i < idx; i++)
{
temp = temp->next;
}

if (temp)
{
new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}

return (NULL);
}
