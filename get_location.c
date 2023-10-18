#include "bk_shell.h"

/**
 *find_location - Locates a command in the PATH dir
 *
 *@command: Command to locate
 *
 *Return: Null if error occurs locating the command
 *        else the full pathname of the command
 */

char *find_location(char *command)
{
        char **path, *temp;
        list_t *dirs, *head;
        struct stat st;

        path = _environget("PATH");
        if (!path || !(*path))
                return (NULL);

        dirs = parse_dir(*path + 5);
        head = dirs;

        while (dirs)
        {
                temp = malloc(_strlen(dirs->dir) + _strlen(command) + 2);
                if (!temp)
                        return (NULL);

                _strcpy(temp, dirs->dir);
                _strcat(temp, "/");
                _strcat(temp, command);

                if (stat(temp, &st) == 0)
                {
                        free_list(head);
                        return (temp);
                }

                dirs = dirs->next;
                free(temp);
        }

        free_list(head);

        return (NULL);
}
