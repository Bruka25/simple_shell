#include "bk_shell.h"

/**
 * _args_tofree - Frees up memory taken by args
 * 
 * @args: A null-terminated double pointer containing commands/arguments
 * @start: A double pointer to the var_environ of args
 * 
 * Return: Void
 */
void _args_tofree(char **args, char **start)
{
        size_t i;

        for (i = 0; args[i] || args[i + 1]; i++)
                free(args[i]);

        free(start);
}
