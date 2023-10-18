#include "error.h"
#include "bk_shell.h"

/**
 * error_exit2 - Creates an error message for exit errors
 * 
 *@args: An array of arguments given to the command
 *
 *Return: String of the error
 */
char *error_exit2(char **args)
{
        char *error, *hist_str;
        int len;

        hist_str = _itoa(hist);
        if (!hist_str)
                return (NULL);

        len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
        {
                free(hist_str);
                return (NULL);
        }

        _strcpy(error, name);
        _strcat(error, ": ");
        _strcat(error, hist_str);
        _strcat(error, ": exit: Illegal number: ");
        _strcat(error, args[0]);
        _strcat(error, "\n");

        free(hist_str);
        return (error);
}
