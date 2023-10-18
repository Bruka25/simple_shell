#include "bk_shell.h"

/**
 *token_count - Counts the number of tokinized str
                 
 * @string: String to be examined
 * @delim: Delimiter
 *
 * Return: Number of words contained within the str
 */
int token_count(char *str, char *delim)
{
        int idx, tokens = 0, len = 0;

        for (idx = 0; *(str + idx); idx++)
                len++;

        for (idx = 0; idx < len; idx++)
        {
                if (*(str + idx) != *delim)
                {
                        tokens++;
                        idx += token_length(str + idx, delim);
                }
        }

        return (tokens);
}
