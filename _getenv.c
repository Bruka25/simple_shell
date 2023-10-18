#include "bk_shell.h"

/**
 *_environget - Gets an environmental variable from the PATH
 * 
 *@var: Name of the environment variable
 *
 *Return: NULL if the environment variable exist or pointer
 *         to pointer to the environment variable
 */
char **_environget(const char *var)
{
        int idx, len;

        len = _strlen(var);
        for (idx = 0; environ[idx]; idx++)
        {
                if (_strncmp(var, environ[idx], len) == 0)
                        return (&environ[idx]);
        }

        return (NULL);
}
