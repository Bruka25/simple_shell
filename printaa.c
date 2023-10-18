#include "bk_shell.h"
#include "error.h"

void bk_print(char *message) {
    write(STDOUT_FILENO, message, _strlen(message));
}
