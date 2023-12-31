#include "bk_shell.h"

/**
 *replace_vars - Replaces variable's
 * 
 *@line: Pointer to pointer containing command and arguments
 *@exe_ret: Pointer to the return value of the last executed command
 *
 *Return: Void
 */
void replace_vars(char **line, int *exe_ret)
{
        int j, k = 0, len;
        char *replacement = NULL, *old_line = NULL, *new_line;

        old_line = *line;
        for (j = 0; old_line[j]; j++)
        {
                if (old_line[j] == '$' && old_line[j + 1] &&
                                old_line[j + 1] != ' ')
                {
                        if (old_line[j + 1] == '$')
                        {
                                replacement = process_id();
                                k = j + 2;
                        }
                        else if (old_line[j + 1] == '?')
                        {
                                replacement = _itoa(*exe_ret);
                                k = j + 2;
                        }
                        else if (old_line[j + 1])
                        {
                                
                                for (k = j + 1; old_line[k] &&
                                                old_line[k] != '$' &&
                                                old_line[k] != ' '; k++)
                                        ;
                                len = k - (j + 1);
                                replacement = find_env_value(&old_line[j + 1], len);
                        }
                        new_line = malloc(j + _strlen(replacement)
                                          + _strlen(&old_line[k]) + 1);
                        if (!line)
                                return;
                        new_line[0] = '\0';
                        _strncat(new_line, old_line, j);
                        if (replacement)
                        {
                                _strcat(new_line, replacement);
                                free(replacement);
                                replacement = NULL;
                        }
                        _strcat(new_line, &old_line[k]);
                        free(old_line);
                        *line = new_line;
                        old_line = new_line;
                        j = -1;
                }
        }
}
