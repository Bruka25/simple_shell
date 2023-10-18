#include "bk_shell.h"


/**
 * bk_help_alias - Displays information about builtin command "alias"
 * 
 *Return: Void
 */
void bk_help_alias(void)
{
        char *message = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

        bk_print(message);
        message = "\n\talias: Prints a list of all aliases, one per line, in ";
        bk_print(message);
        message = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
        bk_print(message);
        message = " the aliases name, name2, etc. one per line, in the ";
        bk_print(message);
        message = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
        bk_print(message);
        message = " an alias for each NAME whose VALUE is given. If NAME ";
        bk_print(message);
        message = "is already an alias, replace its value with VALUE.\n";
        bk_print(message);
}
