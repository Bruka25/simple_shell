#include "bk_shell.h"

/**
 * bk_help_all - Displays all possible commands
 * 
 *Return: Void
 */
void bk_help_all(void)
{
        char *message = "brukas\nThese shell commands are defined internally.\n";

        write(STDOUT_FILENO, message, _strlen(message));
        message = "Type 'help' to see this list.\nType 'help name' to find ";
        write(STDOUT_FILENO, message, _strlen(message));
        message = "out more about the function 'name'.\n\n  alias   \t";
        write(STDOUT_FILENO, message, _strlen(message));
        message = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
        write(STDOUT_FILENO, message, _strlen(message));
        message = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
        write(STDOUT_FILENO, message, _strlen(message));
        message = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
        write(STDOUT_FILENO, message, _strlen(message));
        message = "unsetenv [VARIABLE]\n";
        write(STDOUT_FILENO, message, _strlen(message));
}
