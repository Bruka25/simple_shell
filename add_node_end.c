#include "bk_shell.h"
/**
 *addnode_toend - Adds a node to the end of a list_type list
 *
 *@head: Pointer to the head of the list_type linked list
 *@dir: Directory path for the new node to contain
 *
 *Return: NULL if error occurs, otherwise a pointer to
 *        the new node
 */

list_t *addnode_toend(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}
