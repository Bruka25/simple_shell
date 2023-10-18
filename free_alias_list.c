#include "bk_shell.h"

/**
 *free_list_alias - Frees a alias_type list
 * 
 *@head: Head of the alias_type list
 * 
 *Return: Void
 */
void free_list_alias(alias_t *head)
{
        alias_t *next;

        while (head)
        {
                next = head->next;
                free(head->name);
                free(head->value);
                free(head);
                head = next;
        }
}
