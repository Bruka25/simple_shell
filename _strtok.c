#include "bk_shell.h"

/**
 *_strtok - Tokenizes the given string
 *
 *@line: The string
 *@delim: Delimiter character to tokenize the string
 *
 * Return: Pointer to an array containing the tokenized words
 */
char **_strtok(char *line, char *delim)
{
        char **ptr;
        int idx = 0, tokens, t, letters, l;

        tokens = token_count(line, delim);
        if (tokens == 0)
                return (NULL);

        ptr = malloc(sizeof(char *) * (tokens + 2));
        if (!ptr)
                return (NULL);

        for (t = 0; t < tokens; t++)
        {
                while (line[idx] == *delim)
                        idx++;

                letters = token_length(line + idx, delim);

                ptr[t] = malloc(sizeof(char) * (letters + 1));
                if (!ptr[t])
                {
                        for (idx -= 1; idx >= 0; idx--)
                                free(ptr[idx]);
                        free(ptr);
                        return (NULL);
                }

                for (l = 0; l < letters; l++)
                {
                        ptr[t][l] = line[idx];
                        idx++;
                }

                ptr[t][l] = '\0';
        }
        ptr[t] = NULL;
        ptr[t + 1] = NULL;

        return (ptr);
} 
