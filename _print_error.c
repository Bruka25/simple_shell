#include "bk_shell.h"

/**
 *print_err - Prints response to standard error
 *
 *Return: Void
 */

void print_err(char *message) {
    write(STDERR_FILENO, message, _strlen(message));
}
