#include "bk_shell.h"

/**
 * process_id - Gets the process ID
 *
 * Return: Process id or NULL
 */
char *process_id(void)
{
        size_t i = 0;
        char *buffer;
        ssize_t file;

        file = open("/proc/self/stat", O_RDONLY);
        if (file == -1)
        {
                perror("Cant read file");
                return (NULL);
        }
        buffer = malloc(160);
        if (!buffer)
        {
                close(file);
                return (NULL);
        }
        read(file, buffer, 160);
        while (buffer[i] != ' ')
                i++;
        buffer[i] = '\0';

        close(file);
        return (buffer);
}
