#include "bk_shell.h"

/**
 * bk_exit -Causes normal process termination for the bk_shell
 * 
 * @args: An array of arguments containing the exit value.
 * @start: A double pointer to the beginning of args.
 *
 * Return: If there are no arguments - -3
 *         If the given exit value is invalid - 2
 *         otherwise - exits with the given status value
 */
int bk_exit(char **args, char **start)
{
        int i, len_of_int = 10;
        unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

        if (args[0])
        {
                if (args[0][0] == '+')
                {
                        i = 1;
                        len_of_int++;
                }
                for (; args[0][i]; i++)
                {
                        if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
                                num = (num * 10) + (args[0][i] - '0');
                        else
                                return (error_print(--args, 2));
                }
        }
        else
        {
                return (-3);
        }
        if (num > max - 1)
                return (error_print(--args, 2));
        args -= 1;
       _args_tofree(args, start);
       environ_free();
        free_list_alias(aliases);
        exit(num);
}
