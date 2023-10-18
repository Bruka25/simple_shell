#include "bk_shell.h"

/**
 * bk_setenv - Changes or adds an environmental variable to the PATH
 * 
 * @args: An array of arguments passed to the shell
 * @start: A pointer to pointer to the start of args
 *
 * Return: -1 if an error, or 0 for success
 */

int bk_setenv(char **args, char __attribute__((__unused__)) **front)
{
        char **env_var = NULL, **new_environ, *new_value;
        size_t size;
        int idx;

        if (!args[0] || !args[1])
                return (error_print(args, -1));

        new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
        if (!new_value)
                return (error_print(args, -1));
        _strcpy(new_value, args[0]);
        _strcat(new_value, "=");
        _strcat(new_value, args[1]);

        env_var = _environget(args[0]);
        if (env_var)
        {
                free(*env_var);
                *env_var = new_value;
                return (0);
        }
        for (size = 0; environ[size]; size++)
                ;

        new_environ = malloc(sizeof(char *) * (size + 2));
        if (!new_environ)
        {
                free(new_value);
                return (error_print(args, -1));
        }

        for (idx = 0; environ[idx]; idx++)
                new_environ[idx] = environ[idx];

        free(environ);
        environ = new_environ;
        environ[idx] = new_value;
        environ[idx + 1] = NULL;

        return (0);
}
