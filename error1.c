#include "error.h"
#include "bk_shell.h"

/**
 *err_one - Creates an error message for alias errors
 *
 *@args: An array of arguments given to the command
 *
 *Return: String of the error
 */
char *err_one(char **args)
{
        char *error;
        int len;

        len = _strlen(name) + _strlen(args[0]) + 13;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
                return (NULL);

        _strcpy(error, "alias: ");
        _strcat(error, args[0]);
        _strcat(error, " not found\n");

        return (error);
}
