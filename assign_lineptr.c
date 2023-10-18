#include "bk_shell.h"

/**
 *_lineptr_assign - Reassigns the lineptr var for _getline function
 *
 *@lineptr: A buffer to store an input string
 *@n: Size of lineptr
 *@buffer: String to assign to lineptr
 *@b: Size of buffer
 *
 *Return: Void
 */

void _lineptr_assign(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 160)
			*n = b;
		else
			*n = 160;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 160)
			*n = b;
		else
			*n = 160;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
