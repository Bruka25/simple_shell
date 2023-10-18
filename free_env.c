#include "bk_shell.h"

/**
 * environ_free - Frees the copied environment
 * 
 *Return: Void
 */
void environ_free(void)
{
        int idx;

        for (idx = 0; environ[idx]; idx++)
                free(environ[idx]);
        free(environ);
}
