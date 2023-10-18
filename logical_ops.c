#include "bk_shell.h"

/**
 *operate_logically - Checks a line for logical operators "||" or "&&"
 *
 * @line: Pointer to the character to check in the line
 * @new_len: Pointer to new_len in find_new_len functiom
 * 
 *Return: Void
 */
void operate_logically(char *line, ssize_t *new_len)
{
        char previous, current, next;

        previous = *(line - 1);
        current = *line;
        next = *(line + 1);

        if (current == '&')
        {
                if (next == '&' && previous != ' ')
                        (*new_len)++;
                else if (previous == '&' && next != ' ')
                        (*new_len)++;
        }
        else if (current == '|')
        {
                if (next == '|' && previous != ' ')
                        (*new_len)++;
                else if (previous == '|' && next != ' ')
                        (*new_len)++;
        }
}
