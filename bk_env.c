#include "bk_shell.h"

/**
 * bk_env - Prints the current environment
 * 
 *@args: An array of arguments passed to the shell
 *@start: Pointer to pionter to the start of args
 *
 *Return: If an error occurs -1
 *	       Otherwise 0
 */
int bk_env(char **args, char __attribute__((__unused__)) **start)
{
        int idx;
        char nc = '\n';

        if (!environ)
                return (-1);

        for (idx = 0; environ[idx]; idx++)
        {
                write(STDOUT_FILENO, environ[idx], _strlen(environ[idx]));
                write(STDOUT_FILENO, &nc, 1);
        }

        (void)args;
        return (0);
}
