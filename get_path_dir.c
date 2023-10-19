#include "bk_shell.h"

/**
 *parse_dir - Parses (:) separated list of directories
                 into a list_s linked list
 *
 *@path: Colon separated list of directories
 *
 * Return: Pointer to the initialized linked list
 */

list_t *parse_dir(char *path)
{
	int idx;
	char **dirs, *path_copy;
	list_t *head = NULL;

	path_copy = replace_col_dir(path);
	if (!path_copy)
		return (NULL);
	dirs = _strtok(path_copy, ":");
	free(path_copy);
	if (!dirs)
		return (NULL);

	for (idx = 0; dirs[idx]; idx++)
	{
		if (addnode_toend(&head, dirs[idx]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}

	free(dirs);

	return (head);
}
