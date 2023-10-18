#include "bk_shell.h"

/**
 * help - Displays information about builtin command "help"
 * 
 *Return: Void
 */
void help(void)
{
        char *message = "help: help\n\tSee all possible bk builtin commands.\n";

        bk_print(message);
        message = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
        bk_print(message);
        message = "builtin command.\n";
        bk_print(message);
}
