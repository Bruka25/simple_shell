#include "bk_shell.h"

/**
 *replace_aliases - Goes through the arguments and replace any matching alias
 *                 with their value
 * 
 * @args: Pointer to pointer to the args
 *
 * Return: Pointer to pointer to the args
 */
char **replace_aliases(char **args)
{
        alias_t *temp;
        int i;
        char *new_value;

        if (_strcmp(args[0], "alias") == 0)
                return (args);
        for (i = 0; args[i]; i++)
        {
                temp = aliases;
                while (temp)
                {
                        if (_strcmp(args[i], temp->name) == 0)
                        {
                                new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
                                if (!new_value)
                                {
                                       _args_tofree(args, args);
                                        return (NULL);
                                }
                                _strcpy(new_value, temp->value);
                                free(args[i]);
                                args[i] = new_value;
                                i--;
                                break;
                        }
                        temp = temp->next;
                }
        }

        return (args);
}
