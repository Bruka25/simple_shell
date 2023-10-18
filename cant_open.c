#include "bk_shell.h"

/**
 * cant_open_file - If the file doesn't exist or lacks permissions,
 *                  error explaining it can't open the file
 *                   
 * @file_path: Path to the file that will be opened
 *
 * Return: Error no 127
 */
int cant_open_file(char *file_path)
{
        char *error, *hist_str;
        int len;

        hist_str = _itoa(hist);
        if (!hist_str)
                return (127);

        len = _strlen(name) + _strlen(hist_str) + _strlen(file_path) + 16;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
        {
                free(hist_str);
                return (127);
        }

        _strcpy(error, name);
        _strcat(error, ": ");
        _strcat(error, hist_str);
        _strcat(error, ": Can't open ");
        _strcat(error, file_path);
        _strcat(error, "\n");

        free(hist_str);
        write(STDERR_FILENO, error, len);
        free(error);
        return (127);
}
