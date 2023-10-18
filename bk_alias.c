#include "bk_shell.h"

/**
 *bk_alias -Prints all aliases
 * 
 *@args: An array of arguments
 *@start:Pointer to pointer at the start of args
 *
 * Return:On error -1 otherwise 0 for success
 */

int bk_alias(char **args, char __attribute__((__unused__)) **start)
{
        alias_t *temp = aliases;
        int i, ret = 0;
        char *value;

        if (!args[0])
        {
                while (temp)
                {
                        alias_print(temp);
                        temp = temp->next;
                }
                return (ret);
        }
        for (i = 0; args[i]; i++)
        {
                temp = aliases;
                value = _strchr(args[i], '=');
                if (!value)
                {
                        while (temp)
                        {
                                if (_strcmp(args[i], temp->name) == 0)
                                {
                                        alias_print(temp);
                                        break;
                                }
                                temp = temp->next;
                        }
                        if (!temp)
                                ret = error_print(args + i, 1);
                }
                else
                        alias_set(args[i], value);
        }
        return (ret);
}
