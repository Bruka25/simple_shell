#include "bk_shell.h"

/**
 *bk_check_args - Checks if there are any leading ';', ';;', '&&', or '||'
 *
 * @args: Ponter to pointer to tokenized commands & arguments
 *
 * Return: If a ';', '&&', or '||' is placed at an invalid position - 2.
 *	       else all the things are good return 0
 */
int bk_check_args(char **args)
{
	size_t i;
	char *cur, *nex;

	for (i = 0; args[i]; i++)
	{
		cur = args[i];
		if (cur[0] == ';' || cur[0] == '&' || cur[0] == '|')
		{
			if (i == 0 || cur[1] == ';')
				return (error_print(&args[i], 2));
			nex = args[i + 1];
			if (nex && (nex[0] == ';' || nex[0] == '&' || nex[0] == '|'))
				return (error_print(&args[i + 1], 2));
		}
	}
	return (0);
}
