#include "bk_shell.h"

/**
 *bk_realloc - Reallocates a memory
 *
 * @ptr: pointer to the previouslly allocated mem 
 * @old_size: Size in bytes of the allocated mem ptr
 * @new_size: The size in bytes for the new mem
 *
 *Return: If new size equals to the old_size, return ptr
 *        If new size is 0 and the ptr is not NULL, return NULL
 *        Otherwise a ptr to the newly allocated memo
 */
void *bk_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *mem;
        char *ptr_copy, *filler;
        unsigned int idx;

        if (new_size == old_size)
                return (ptr);

        if (ptr == NULL)
        {
                mem = malloc(new_size);
                if (mem == NULL)
                        return (NULL);

                return (mem);
        }

        if (new_size == 0 && ptr != NULL)
        {
                free(ptr);
                return (NULL);
        }

        ptr_copy = ptr;
        mem = malloc(sizeof(*ptr_copy) * new_size);
        if (mem == NULL)
        {
                free(ptr);
                return (NULL);
        }

        filler = mem;

        for (idx = 0; idx < old_size && idx < new_size; idx++)
                filler[idx] = *ptr_copy++;

        free(ptr);
        return (mem);
}
