#include "error.h"
#include "bk_shell.h"

/**
 *error_syntax2 - Error messages for syntax errors
 * 
 *@args: An array of arguments passed to the command
 *
 *Return: String of an error
 */
char *error_syntax2(char **args)
{
        char *error, *hist_str;
        int len;

        hist_str = _itoa(hist);
        if (!hist_str)
                return (NULL);

        len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
        {
                free(hist_str);
                return (NULL);
        }

        _strcpy(error, name);
        _strcat(error, ": ");
        _strcat(error, hist_str);
        _strcat(error, ": Syntax error: \"");
        _strcat(error, args[0]);
        _strcat(error, "\" unexpected\n");

        free(hist_str);
        return (error);
}
