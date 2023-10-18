#include "error.h"
#include "bk_shell.h"

/**
 * error_cd2 - Creates an error message for cd errors
 * 
 *@args: An array of arguments given to the command
 *
 * Return: String of an error
 */
char *error_cd2(char **args)
{
        char *error, *hist_str;
        int len;

        hist_str = _itoa(hist);
        if (!hist_str)
                return (NULL);

        if (args[0][0] == '-')
                args[0][2] = '\0';
        len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
        {
                free(hist_str);
                return (NULL);
        }

        _strcpy(error, name);
        _strcat(error, ": ");
        _strcat(error, hist_str);
        if (args[0][0] == '-')
                _strcat(error, ": cd: Illegal option ");
        else
                _strcat(error, ": cd: can't cd to ");
        _strcat(error, args[0]);
        _strcat(error, "\n");

        free(hist_str);
        return (error);
}
