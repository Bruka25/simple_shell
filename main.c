#include "bk_shell.h"

/**
 * main - Entry point to the simple shell
 * 
 * @argc: Number of arguments
 * @argv: Pointers to the arguments
 *
 * Return: Return value of the last executed command
 */

int main(int argc, char *argv[])
{
        int ret = 0, retn;
        int *exe_ret = &retn;
        char *prompt = "brukas$ ", *new_line = "\n";

        name = argv[0];
        hist = 1;
        aliases = NULL;
        signal(SIGINT, handle_signal);

        *exe_ret = 0;
        environ = _environcopy();
        if (!environ)
                exit(-100);

        if (argc != 1)
        {
                ret = run_file_cmds(argv[1], exe_ret);
               environ_free();
                free_list_alias(aliases);
                return (*exe_ret);
        }

        if (!isatty(STDIN_FILENO))
        {
                while (ret != END_OF_FILE && ret != EXIT)
                        ret = argument_handle(exe_ret);
               environ_free();
                free_list_alias(aliases);
                return (*exe_ret);
        }

        while (1)
        {
                bk_print(prompt);
                ret = argument_handle(exe_ret);
                if (ret == END_OF_FILE || ret == EXIT)
                {
                        if (ret == END_OF_FILE)
                                bk_print(new_line);
                       environ_free();
                        free_list_alias(aliases);
                        exit(*exe_ret);
                }
        }

       environ_free();
        free_list_alias(aliases);
        return (*exe_ret);
}



/**
 *handle_signal -Prints a new prompt when it is signalled
 *
 *@sig: The signal to be handled
 * 
 *Return: Void
 */
void handle_signal(int sig)
{
        char *new_prompt = "\nbrukas$ ";

        (void)sig;
        signal(SIGINT, handle_signal);
        write(STDIN_FILENO, new_prompt, 3);
}

/**
 * execute - Child process executor to a command
 * 
 * @args: An array of arguments
 * @start: Pointer to pointer to the start of args
 *
 * Return: When error occurs a corresponding error code
 *         else the exit value of the last executed command
 */
int execute(char **args, char **start)
{
        pid_t child_pid;
        int status, flag = 0, ret = 0;
        char *command = args[0];

        if (command[0] != '/' && command[0] != '.')
        {
                flag = 1;
                command = find_location(command);
        }

        if (!command || (access(command, F_OK) == -1))
        {
                if (errno == EACCES)
                        ret = (error_print(args, 126));
                else
                        ret = (error_print(args, 127));
        }
        else
        {
                child_pid = fork();
                if (child_pid == -1)
                {
                        if (flag)
                                free(command);
                        perror("Error child:");
                        return (1);
                }
                if (child_pid == 0)
                {
                        execve(command, args, environ);
                        if (errno == EACCES)
                                ret = (error_print(args, 126));
                       environ_free();
                       _args_tofree(args, start);
                        free_list_alias(aliases);
                        _exit(ret);
                }
                else
                {
                        wait(&status);
                        ret = WEXITSTATUS(status);
                }
        }
        if (flag)
                free(command);
        return (ret);
}
