#include "bk_shell.h"


/**
 *line_handler - Partition a line read from standard input
 * 
 *@line: Pointer to Pointer to a line read from standard input
 *@read: Length of line
 *
 *Return: Void
 */
void line_handler(char **line, ssize_t read)
{
        char *old_line, *new_line;
        char previous, current, next;
        size_t i, j;
        ssize_t new_len;

        new_len = find_new_len(*line);
        if (new_len == read - 1)
                return;
        new_line = malloc(new_len + 1);
        if (!new_line)
                return;
        j = 0;
        old_line = *line;
        for (i = 0; old_line[i]; i++)
        {
                current = old_line[i];
                next = old_line[i + 1];
                if (i != 0)
                {
                        previous = old_line[i - 1];
                        if (current == ';')
                        {
                                if (next == ';' && previous != ' ' && previous != ';')
                                {
                                        new_line[j++] = ' ';
                                        new_line[j++] = ';';
                                        continue;
                                }
                                else if (previous == ';' && next != ' ')
                                {
                                        new_line[j++] = ';';
                                        new_line[j++] = ' ';
                                        continue;
                                }
                                if (previous != ' ')
                                        new_line[j++] = ' ';
                                new_line[j++] = ';';
                                if (next != ' ')
                                        new_line[j++] = ' ';
                                continue;
                        }
                        else if (current == '&')
                        {
                                if (next == '&' && previous != ' ')
                                        new_line[j++] = ' ';
                                else if (previous == '&' && next != ' ')
                                {
                                        new_line[j++] = '&';
                                        new_line[j++] = ' ';
                                        continue;
                                }
                        }
                        else if (current == '|')
                        {
                                if (next == '|' && previous != ' ')
                                        new_line[j++]  = ' ';
                                else if (previous == '|' && next != ' ')
                                {
                                        new_line[j++] = '|';
                                        new_line[j++] = ' ';
                                        continue;
                                }
                        }
                }
                else if (current == ';')
                {
                        if (i != 0 && old_line[i - 1] != ' ')
                                new_line[j++] = ' ';
                        new_line[j++] = ';';
                        if (next != ' ' && next != ';')
                                new_line[j++] = ' ';
                        continue;
                }
                new_line[j++] = old_line[i];
        }
        new_line[j] = '\0';

        free(*line);
        *line = new_line;
}
