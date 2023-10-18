#include "bk_shell.h"


/**
 * bk_env_help - Displays information about builtin command 'env'
 * 
 *Return: Void
 */
void bk_env_help(void)
{
        char *message = "env: env\n\tPrints the current environment.\n";

        write(STDOUT_FILENO, message, _strlen(message));
}
