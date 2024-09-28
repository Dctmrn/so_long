#include "../so_long.h"

int init_map(t_map *game, char *file)
{
    ft_bzero(game, sizeof(t_map));
    game->pixel = 128;
    int fd;
    char *line;
    int i = 0;

    if ((fd = open(file, O_RDONLY)) < 0)
        error(game,"Error opening map file");
    game->map = NULL;
    while ((line = get_next_line(fd)) != NULL)
    {
       empty_line(game, line);
  
        char **new_map = (char **)ft_realloc(game->map, sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
        if (!new_map)
        {
            close(fd);
            error(game,"Allocating memory failed");
        }
        game->map = new_map;
        game->map[i++] = ft_strdup(line);
        free(line);
    }
    return 1;
}

void empty_line(t_map *game, char *line)
{
    if (line[0] == '\0' || ft_strcmp(line, "\n") == 0)
    {
        free(line);
        error(game,"Empty line found in map");
    }
}

//penser a limiter la taille de la map envoye
// definir taille de la fenetre avec map


void *ft_realloc(void *ptr, size_t old_size, size_t new_size) // à mettre dans libft
{
    void *new_ptr;

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    if (ptr) {
        ft_memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
        free(ptr);
    }
    return new_ptr;
}