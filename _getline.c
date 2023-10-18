#include "bk_shell.h"

/**
 * _getline - Reads input from STDIN
 * 
 * @lineptr: Buffer to store the input
 * @num: Size of lineptr
 * @stream: Input stream
 *
 * Return: Number of bytes that has been read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
        static ssize_t input;
        ssize_t ret;
        char c = 'x', *buffer;
        int r;

        if (input == 0)
                fflush(stream);
        else
                return (-1);
        input = 0;

        buffer = malloc(sizeof(char) * 160);
        if (!buffer)
                return (-1);

        while (c != '\n')
        {
                r = read(STDIN_FILENO, &c, 1);
                if (r == -1 || (r == 0 && input == 0))
                {
                        free(buffer);
                        return (-1);
                }
                if (r == 0 && input != 0)
                {
                        input++;
                        break;
                }

                if (input >= 160)
                        buffer = bk_realloc(buffer, input, input + 1);

                buffer[input] = c;
                input++;
        }
        buffer[input] = '\0';

        _lineptr_assign(lineptr, n, buffer, input);

        ret = input;
        if (r != 0)
                input = 0;
        return (ret);
}
