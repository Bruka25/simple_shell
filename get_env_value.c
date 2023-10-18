#include "bk_shell.h"

/**
 *find_env_value - Gets the value in environment var=value pair
 * 
 * @var_environ: Environmental variable to search
 * @len: Length of the environmental variable to search
 *
 *Return: Empty stringing if variable is not found else
 *         value of the environmental variable
 */
char *find_env_value(char *beginning, int len)
{
        char **var_addr;
        char *replacement = NULL, *temp, *var;

        var = malloc(len + 1);
        if (!var)
                return (NULL);
        var[0] = '\0';
        _strncat(var, beginning, len);

        var_addr = _environget(var);
        free(var);
        if (var_addr)
        {
                temp = *var_addr;
                while (*temp != '=')
                        temp++;
                temp++;
                replacement = malloc(_strlen(temp) + 1);
                if (replacement)
                        _strcpy(replacement, temp);
        }

        return (replacement);
}
