#include "bk_shell.h"
#include "error.h"

/**
 *bk_print - prints response to standard output
 *
 *Return: Void
 */

void bk_print(char *message) {
    write(STDOUT_FILENO, message, _strlen(message));
}
