#include "bk_shell.h"

/**
 *bk_unsetenv - Removes an environmental variable from the PATH
 *
 *@args: An array of arguments passed to the shell
 *@start: Pointer to a pointer to start of arguments
 *
 *Return: -1 if an error occurs, or 0 if it succeeds
 */
int bk_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
        char **env_var, **new_environ;
        size_t size; 
        int idx, idx2;

        if (!args[0])
                return (error_print(args, -1));
        env_var = _environget(args[0]);
        if (!env_var)
                return (0);

        for (size = 0; environ[size]; size++)
                ;

        new_environ = malloc(sizeof(char *) * size);
        if (!new_environ)
                return (error_print(args, -1));

        for (idx = 0, idx2 = 0; environ[idx]; idx++)
        {
                if (*env_var == environ[idx])
                {
                        free(*env_var);
                        continue;
                }
                new_environ[idx2] = environ[idx];
                idx2++;
        }
        free(environ);
        environ = new_environ;
        environ[size - 1] = NULL;

        return (0);
}
