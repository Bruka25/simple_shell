#include "bk_shell.h"

/**
 *bk_call_args - Splits operators from commands and calls them
 * 
 *@args: An array of arguments
 *@start: Pointer to pointer to the beginning of args
 *@exe_ret: Return value of the parent process last executed command
 *
 *Return: Ralue of the last executed command.
 */

int bk_call_args(char **args, char **start, int *exe_ret)
{
	int ret, idx;

	if (!args[0])
		return (*exe_ret);
	for (idx = 0; args[idx]; idx++)
	{
		if (_strncmp(args[idx], "||", 2) == 0)
		{
			free(args[idx]);
			args[idx] = NULL;
			args = replace_aliases(args);
			ret = bk_run_args(args, start, exe_ret);
			if (*exe_ret != 0)
			{
				args = &args[++idx];
				idx = 0;
			}
			else
			{
				for (idx++; args[idx]; idx++)
					free(args[idx]);
				return (ret);
			}
		}
		else if (_strncmp(args[idx], "&&", 2) == 0)
		{
			free(args[idx]);
			args[idx] = NULL;
			args = replace_aliases(args);
			ret = bk_run_args(args, start, exe_ret);
			if (*exe_ret == 0)
			{
				args = &args[++idx];
				idx = 0;
			}
			else
			{
				for (idx++; args[idx]; idx++)
					free(args[idx]);
				return (ret);
			}
		}
	}
	args = replace_aliases(args);
	ret = bk_run_args(args, start, exe_ret);
	return (ret);
}
