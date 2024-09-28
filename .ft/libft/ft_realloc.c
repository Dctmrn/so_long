#include "libft.h"

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }
    if (!ptr)
        return malloc(new_size);
    if (new_size <= old_size)
        return ptr;
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    ft_memcpy(new_ptr, ptr, old_size); // Copie les données de l'ancien vers le nouveau pointeur
    free(ptr);
    return new_ptr;
}
