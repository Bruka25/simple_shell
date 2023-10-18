#include "bk_shell.h"
#include "error.h"

/**
 *alias_addend - Adds a node to the end of a alias_type
 *
 *@head: Pointer to the head of the list_type list
 *@name: Name of the new alias to be added
 *@value: Value of the new alias to be added
 *
 *Return: Pointer to the new node or NULL if error occurs
 */
alias_t *alias_addend(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

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
