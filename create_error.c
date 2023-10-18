#include "bk_shell.h"
#include "error.h"


/**
 * error_print - Prints an error message to STDERR
 * 
 *@args: An array of arguments
 * @err: Error value
 *
 * Return: Error value
 */

int error_print(char **args, int err)
{
        char *error;

        switch (err)
        {
        case -1:
                error = environ_err(args);
                break;
        case 1:
                error = err_one(args);
                break;
        case 2:
                if (*(args[0]) == 'e')
                        error = error_exit2(++args);
                else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
                        error = error_syntax2(args);
                else
                        error = error_cd2(args);
                break;
        case 126:
                error = _error126(args);
                break;
        case 127:
                error = _error127(args);
                break;
        }
        print_err(error);

        if (error)
                free(error);
        return (err);

}
