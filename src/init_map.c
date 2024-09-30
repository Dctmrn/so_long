#include "../so_long.h"

void empty_line(t_map *game, char *line)
{
    if (line[0] == '\0' || ft_strcmp(line, "\n") == 0)
    {
        free(line);
        error(game,"Empty line found in map");
    }
}
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
        if (line && line[0] != '\0' && line[strlen(line) - 1] == '\n') 
            line[strlen(line) - 1] = '\0';

        char **new_map = (char **)ft_realloc(game->map, sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
        if (!new_map)
        {
            free(line);
            close(fd);
            error(game,"Allocating memory failed");
        }

        game->map = new_map;
        if (!(game->map[i] = ft_strdup(line)))
        {
            free(line);
            close(fd);
            error(game, "Memory allocation for map line failed");
        }

        
        free(line);
        i++;
    }
    game->map[i] = NULL;
    //for (int k = 0; game->map[k]; k++) 
       // printf("Ligne [%d]: %s\n", k, game->map[k]);

    close(fd);
    return 1;
}


//penser a limiter la taille de la map envoye
// definir taille de la fenetre avec map
