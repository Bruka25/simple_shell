#include "error.h"
#include "bk_shell.h"


/**
 *environ_err - Creates an error message for bk_env errors
 *
 * @args: An array of arguments passed to the command
 *
 *Return: String of an error
 */
char *environ_err(char **args)
{
        char *error, *hist_str;
        int len;

        hist_str = _itoa(hist);
        if (!hist_str)
                return (NULL);

        args--;
        len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
        {
                free(hist_str);
                return (NULL);
        }

        _strcpy(error, name);
        _strcat(error, ": ");
        _strcat(error, hist_str);
        _strcat(error, ": ");
        _strcat(error, args[0]);
        _strcat(error, ": Unable to add/remove from environment\n");

        free(hist_str);
        return (error);
}
