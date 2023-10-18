#include "bk_shell.h"

/**
 * bk_unsetenv_help - Displays information about builtin command
 *                    'unsetenv'
 *Return: Void
 */
void bk_unsetenv_help(void)
{
        char *message = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

        bk_print(message);
        message = "environmental variable.\n\n\tUpon failure, prints a ";
        bk_print(message);
        message = "message to stderr.\n";
        bk_print(message);
}
