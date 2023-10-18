#include "bk_shell.h"

/**
 *_environcopy - Creates a copy of the environment
 *
 * Return: NULL if there is an error or pointer to pointer of
 *         the copied environment
 */
char **_environcopy(void)
{
        char **new_environ;
        size_t size;
        int idx;

        for (size = 0; environ[size]; size++)
                ;

        new_environ = malloc(sizeof(char *) * (size + 1));
        if (!new_environ)
                return (NULL);

        for (idx = 0; environ[idx]; idx++)
        {
                new_environ[idx] = malloc(_strlen(environ[idx]) + 1);

                if (!new_environ[idx])
                {
                        for (idx--; idx >= 0; idx--)
                                free(new_environ[idx]);
                        free(new_environ);
                        return (NULL);
                }
                _strcpy(new_environ[idx], environ[idx]);
        }
        new_environ[idx] = NULL;

        return (new_environ);
}
