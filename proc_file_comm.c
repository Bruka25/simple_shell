#include "bk_shell.h"

/**
 *run_file_cmds - Takes a file and attempts to run the commands stored
 *                 inside it
 * 
 * @file_path: Path to the file
 * @exe_ret: Return value of the last executed command
 *
 * Return: If file can't be opened 127
 *	       If memory allocation fails -1
 *	       else return value of the last command run
 */
int run_file_cmds(char *file_path, int *exe_ret)
{
        ssize_t file, b_read, i;
        unsigned int line_size = 0;
        unsigned int old_size = 160;
        char *line, **args, **start;
        char buffer[160];
        int ret;

        hist = 0;
        file = open(file_path, O_RDONLY);
        if (file == -1)
        {
                *exe_ret = cant_open_file(file_path);
                return (*exe_ret);
        }
        line = malloc(sizeof(char) * old_size);
        if (!line)
                return (-1);
        do {
                b_read = read(file, buffer, 159);
                if (b_read == 0 && line_size == 0)
                        return (*exe_ret);
                buffer[b_read] = '\0';
                line_size += b_read;
                line = bk_realloc(line, old_size, line_size);
                _strcat(line, buffer);
                old_size = line_size;
        } while (b_read);
        for (i = 0; line[i] == '\n'; i++)
                line[i] = ' ';
        for (; i < line_size; i++)
        {
                if (line[i] == '\n')
                {
                        line[i] = ';';
                        for (i += 1; i < line_size && line[i] == '\n'; i++)
                                line[i] = ' ';
                }
        }
       replace_vars(&line, exe_ret);
       line_handler(&line, line_size);
        args = _strtok(line, " ");
        free(line);
        if (!args)
                return (0);
        if (bk_check_args(args) != 0)
        {
                *exe_ret = 2;
               _args_tofree(args, args);
                return (*exe_ret);
        }
        start = args;

        for (i = 0; args[i]; i++)
        {
                if (_strncmp(args[i], ";", 1) == 0)
                {
                        free(args[i]);
                        args[i] = NULL;
                        ret = bk_call_args(args, start, exe_ret);
                        args = &args[++i];
                        i = 0;
                }
        }

        ret = bk_call_args(args, start, exe_ret);

        free(start);
        return (ret);
}
