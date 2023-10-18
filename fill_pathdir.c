#include "bk_shell.h"

/**
 *replace_col_dir - Copies path but also replaces trailing colons
 *                  within current working directory
 * 
 *@path: Colon separated list of directories
 *
 *Return: Copy of path with any leading/sandwiched/trailing (:) 
 *         replaced with the current working directory
 */

char *replace_col_dir(char *path)
{
        int i, length = 0;
        char *path_copy, *pwd;

        pwd = *(_environget("PWD")) + 4;
        for (i = 0; path[i]; i++)
        {
                if (path[i] == ':')
                {
                        if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
                                length += _strlen(pwd) + 1;
                        else
                                length++;
                }
                else
                        length++;
        }
        path_copy = malloc(sizeof(char) * (length + 1));
        if (!path_copy)
                return (NULL);
        path_copy[0] = '\0';
        for (i = 0; path[i]; i++)
        {
                if (path[i] == ':')
                {
                        if (i == 0)
                        {
                                _strcat(path_copy, pwd);
                                _strcat(path_copy, ":");
                        }
                        else if (path[i + 1] == ':' || path[i + 1] == '\0')
                        {
                                _strcat(path_copy, ":");
                                _strcat(path_copy, pwd);
                        }
                        else
                                _strcat(path_copy, ":");
                }
                else
                {
                        _strncat(path_copy, &path[i], 1);
                }
        }
        return (path_copy);
}
