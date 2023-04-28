#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node - inserts a new node at the beginning of a linked list.
*
* @head: takes in a double pointer to a linked list of type list_t.
* @str: New string to add in the node.
*
* Return: Address of the new element, or NULL if it fails.
*/

list_t *add_node(list_t **head, const char *str)
{
list_t *new;

if (!head || !str)
return (NULL);

new = malloc(sizeof(list_t));

if (!new)
return (NULL);

new->str = strdup(str);
new->len = strlen(str);
new->next = *head;
*head = new;

return (new);
}
