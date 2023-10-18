#include "bk_shell.h"

void print_err(char *message) {
    write(STDERR_FILENO, message, _strlen(message));
}
