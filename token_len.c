#include "bk_shell.h"

/**
 *token_length - Locates the delimiter idx marking the end
 *                of the first token contained within a string
 * 
 *@string: String to be examined
 *@delim: Delimiter
 *
 *Return: Delimiter idx marking the end of
 *        the first token
 */
int token_length(char *str, char *delim)
{
        int idx = 0, len = 0;

        while (*(str + idx) && *(str + idx) != *delim)
        {
                len++;
                idx++;
        }

        return (len);
}
