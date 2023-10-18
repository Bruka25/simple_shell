#include "bk_shell.h"

/**
 * bk_cd - Changes the current directory of the bk process
 * 
 * @args:An array to the arguments
 * @start:A pointer to pointer to the start of args
 *
 * Return: If the given string is not a directory - 2
 *         If an error occurs - -1
 *         Otherwise - 0
 */

int bk_cd(char **args, char __attribute__((__unused__)) **start)
{
        char **dir_info, *new_line = "\n";
        char *oldpwd = NULL, *pwd = NULL;
        struct stat dir;

        oldpwd = getcwd(oldpwd, 0);
        if (!oldpwd)
                return (-1);

        if (args[0])
        {
                if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
                {
                        if ((args[0][1] == '-' && args[0][2] == '\0') ||
                                        args[0][1] == '\0')
                        {
                                if (_environget("OLDPWD") != NULL)
                                        (chdir(*_environget("OLDPWD") + 7));
                        }
                        else
                        {
                                free(oldpwd);
                                return (error_print(args, 2));
                        }
                }
                else
                {
                        if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
                                        && ((dir.st_mode & S_IXUSR) != 0))
                                chdir(args[0]);
                        else
                        {
                                free(oldpwd);
                                return (error_print(args, 2));
                        }
                }
        }
        else
        {
                if (_environget("HOME") != NULL)
                        chdir(*(_environget("HOME")) + 5);
        }

        pwd = getcwd(pwd, 0);
        if (!pwd)
                return (-1);

        dir_info = malloc(sizeof(char *) * 2);
        if (!dir_info)
                return (-1);

        dir_info[0] = "OLDPWD";
        dir_info[1] = oldpwd;
        if (bk_setenv(dir_info, dir_info) == -1)
                return (-1);

        dir_info[0] = "PWD";
        dir_info[1] = pwd;
        if (bk_setenv(dir_info, dir_info) == -1)
                return (-1);
        if (args[0] && args[0][0] == '-' && args[0][1] != '-')
        {
                bk_print(pwd);
                bk_print(new_line);
        }
        free(oldpwd);
        free(pwd);
        free(dir_info);
        return (0);
}
