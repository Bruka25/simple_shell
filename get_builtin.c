#include "bk_shell.h"

/**
 *builtin_get -Matches a command with a corresponding builtin functiom
 *               
 *@command:Command to match
 *
 *Return:Pointer to the corresponding builtin
 */
int (*builtin_get(char *command))(char **args, char **start)
{
        builtin_t funcs[] = {
                { "exit", bk_exit },
                { "env", bk_env },
                { "setenv", bk_setenv },
                { "unsetenv", bk_unsetenv },
                { "cd", bk_cd },
                { "alias", bk_alias },
                { "help", bk_help },
                { NULL, NULL }
        };
        int i;

        for (i = 0; funcs[i].name; i++)
        {
                if (_strcmp(funcs[i].name, command) == 0)
                        break;
        }
        return (funcs[i].f);
}
