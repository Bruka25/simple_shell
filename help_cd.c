#include "bk_shell.h"

/**
 * bk_help_cd - Displays information about builtin command "cd"
 * 
 *Return: Void
 */

void bk_help_cd(void)
{
        char *message = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

        bk_print(message);
        message = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
        bk_print(message);
        message = "command is interpreted as cd $HOME. If the argument '-' is";
        bk_print(message);
        message = " given, the command is interpreted as cd $OLDPWD.\n\n";
        bk_print(message);
        message = "\tThe environment variables PWD and OLDPWD are updated ";
        bk_print(message);
        message = "after a change of directory.\n";
        bk_print(message);
}
