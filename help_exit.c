#include "bk_shell.h"
/**
 * bk_help_exit - Displays information about builtin command "exit"
 * 
 *Return: Void
 */
void bk_help_exit(void)
{
        char *message = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

        bk_print(message);
        message = "STATUS argument is the integer used to exit the shell.";
        bk_print(message);
        message = " If no argument is given, the command is interpreted as";
        bk_print(message);
        message = " exit 0.\n";
        bk_print(message);

}
