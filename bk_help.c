#include "bk_shell.h"



/**
 * bk_help - Displays information about bk builtin commands.
 * @args: An array of arguments.
 * @start: A pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int bk_help(char **args, char __attribute__((__unused__)) **start)
{
        if (!args[0])
                bk_help_all();
        else if (_strcmp(args[0], "alias") == 0)
                bk_help_alias();
        else if (_strcmp(args[0], "cd") == 0)
                bk_help_cd();
        else if (_strcmp(args[0], "exit") == 0)
                bk_help_exit();
        else if (_strcmp(args[0], "env") == 0)
                bk_env_help();
        else if (_strcmp(args[0], "setenv") == 0)
                bk_help_setenv();
        else if (_strcmp(args[0], "unsetenv") == 0)
                bk_unsetenv_help();
        else if (_strcmp(args[0], "help") == 0)
                help();
        else
                print_err(name);

        return (0);
}
