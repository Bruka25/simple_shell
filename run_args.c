#include "bk_shell.h"

/**
 *bk_run_arg - Executes the command
 * 
 *@args: An array of arguments
 *@start: Pointer to a pointer to the stringart of args
 *@exe_ret: Return value of the parent process last executed command
 *
 *Return: Return value of the last executed command
 */

int bk_run_args(char **args, char **start, int *exe_ret)
{
        int ret, i;
        int (*builtin)(char **args, char **start);

        builtin = builtin_get(args[0]);

        if (builtin)
        {
                ret = builtin(args + 1, start);
                if (ret != EXIT)
                        *exe_ret = ret;
        }
        else
        {
                *exe_ret = execute(args, start);
                ret = *exe_ret;
        }

        hist++;

        for (i = 0; args[i]; i++)
                free(args[i]);

        return (ret);
}
