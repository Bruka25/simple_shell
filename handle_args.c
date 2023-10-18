#include "bk_shell.h"

/**
 *argument_handle - Calls,gets and runs the execution of a command
 *
 *@exe_ret: The return value of the parent process last executed command
 *
 *Return: If an EOF is read - END_OF_FILE (-2)
 *        -1 if the input cannot be tokenized 
 *        else the exit value of the last executed command
 */

int argument_handle(int *exe_ret)
{
        int ret = 0, idx;
        char **args, *line = NULL, **start;

        line = bk_get_arg(line, exe_ret);
        if (!line)
                return (END_OF_FILE);

        args = _strtok(line, " ");
        free(line);
        if (!args)
                return (ret);
        if (bk_check_args(args) != 0)
        {
                *exe_ret = 2;
               _args_tofree(args, args);
                return (*exe_ret);
        }
        start = args;

        for (idx = 0; args[idx]; idx++)
        {
                if (_strncmp(args[idx], ";", 1) == 0)
                {
                        free(args[idx]);
                        args[idx] = NULL;
                        ret = bk_call_args(args, start, exe_ret);
                        args = &args[++idx];
                        idx = 0;
                }
        }
        if (args)
                ret = bk_call_args(args, start, exe_ret);

        free(start);
        return (ret);
}
