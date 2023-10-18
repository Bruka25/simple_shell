#include "bk_shell.h"

/**
 *find_new_len - Gets new length of a line split
 *               by ";", "||", "&&&", or "#"
 * 
 *@line: Line to check
 *
 *Return: New length of the line
 */

ssize_t find_new_len(char *line)
{
        size_t i;
        ssize_t new_len = 0;
        char current, next;

        for (i = 0; line[i]; i++)
        {
                current = line[i];
                next = line[i + 1];
                if (current == '#')
                {
                        if (i == 0 || line[i - 1] == ' ')
                        {
                                line[i] = '\0';
                                break;
                        }
                }
                else if (i != 0)
                {
                        if (current == ';')
                        {
                                if (next == ';' && line[i - 1] != ' ' && line[i - 1] != ';')
                                {
                                        new_len += 2;
                                        continue;
                                }
                                else if (line[i - 1] == ';' && next != ' ')
                                {
                                        new_len += 2;
                                        continue;
                                }
                                if (line[i - 1] != ' ')
                                        new_len++;
                                if (next != ' ')
                                        new_len++;
                        }
                        else
                                operate_logically(&line[i], &new_len);
                }
                else if (current == ';')
                {
                        if (i != 0 && line[i - 1] != ' ')
                                new_len++;
                        if (next != ' ' && next != ';')
                                new_len++;
                }
                new_len++;
        }
        return (new_len);
}
