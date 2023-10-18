#include "bk_shell.h"

/**
 *alias_print - Prints the alias in the format name='value'
 * 
 *@alias: Pointer to an alias
 * 
 *Rwturn: Void
 */

void alias_print(alias_t *alias)
{
        char *alias_string;
        int len = _strlen(alias->name) + _strlen(alias->value) + 4;

        alias_string = malloc(sizeof(char) * (len + 1));
        if (!alias_string)
                return;
        _strcpy(alias_string, alias->name);
        _strcat(alias_string, "='");
        _strcat(alias_string, alias->value);
        _strcat(alias_string, "'\n");

        bk_print(alias_string);
        free(alias_string);
}
