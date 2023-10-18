#include "bk_shell.h"

/**
 * bk_setenv_help - Displays information about builtin command 'setenv'
 * 
 *Return: Void
 */
void bk_help_setenv(void)
{
        char *message = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

        bk_print(message);
        message = "environment variable, or modifies an existing one.\n\n";
        bk_print(message);
        message = "\tUpon failure, prints a message to stderr.\n";
        bk_print(message);
}
