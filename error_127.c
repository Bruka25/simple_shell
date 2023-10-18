#include "error.h"
#include "bk_shell.h"

/**
 *_error127 - Error message for command not found failures
 * 
 *@args: An array of arguments given to the command
 *
 *Return: String of an error
 */
char *_error127(char **args)
{
        char *error, *hist_str;
        int len;

        hist_str = _itoa(hist);
        if (!hist_str)
                return (NULL);

        len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
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
        _strcat(error, ": not found\n");

        free(hist_str);
        return (error);
}
