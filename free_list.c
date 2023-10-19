#include "bk_shell.h"

/**
 *free_list - Frees list_type linked list
 *
 *@head: Head of the list_type list
 *
 *Return: void
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
