#include "bk_shell.h"

/**
 * alias_set - Sets an existing alias with a new value
 *             or creates new alias
 * 
 * @var_name: Name of the alias
 * @value: Value of the alias. First character is a '='
 * 
 *Return: Void
 */




void alias_set(char *var_name, char *value)
{
        alias_t *temp = aliases;
        int len, j, k;
        char *new_value;

        *value = '\0';
        value++;
        len = _strlen(value) - _strspn(value, "'\"");
        new_value = malloc(sizeof(char) * (len + 1));
        if (!new_value)
                return;
        for (j = 0, k = 0; value[j]; j++)
        {
                if (value[j] != '\'' && value[j] != '"')
                        new_value[k++] = value[j];
        }
        new_value[k] = '\0';
        while (temp)
        {
                if (_strcmp(var_name, temp->name) == 0)
                {
                        free(temp->value);
                        temp->value = new_value;
                        break;
                }
                temp = temp->next;
        }
        if (!temp)
                alias_addend(&aliases, var_name, new_value);
}
