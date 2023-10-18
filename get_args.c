#include "bk_shell.h"

/**
 *bk_get_arg - Gets command from STDIN
 *
 *@line: Buffer to store the command
 * @exe_ret: Return value of the last executed command
 *
 * Return: NULL if error occurs, else pointer to stored command         
 */

char *bk_get_arg(char *line, int *exe_ret)
{
        size_t n = 0;
        ssize_t read;
        char *prompt = "$ ";

        if (line)
                free(line);

        read = _getline(&line, &n, STDIN_FILENO);
        if (read == -1)
                return (NULL);
        if (read == 1)
        {
                hist++;
                if (isatty(STDIN_FILENO))
                        bk_print(prompt);
                return (bk_get_arg(line, exe_ret));
        }

        line[read - 1] = '\0';
       replace_vars(&line, exe_ret);
       line_handler(&line, read);

        return (line);
}
