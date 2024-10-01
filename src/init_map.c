#include "../so_long.h"

void	empty_line(t_map *game, char *line)
{
	if (line[0] == '\0' || ft_strcmp(line, "\n") == 0)
	{
		free(line);
		error(game, "Empty line found in map");
	}
}

void	add_line_to_map(t_map *game, char *line, int i)
{
	char	**new_map;

	new_map = (char **)ft_realloc(game->map, sizeof(char *) * (i + 1),
			sizeof(char *) * (i + 2));
	if (!new_map)
		error(game, "Allocating memory failed");
	game->map = new_map;
	game->map[i] = ft_strdup(line);
	if (!game->map[i])
		error(game, "Memory allocation for map line failed");
}

int	init_map(t_map *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	ft_bzero(game, sizeof(t_map));
	game->pixel = 128;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(game, "Error opening map file");
	game->map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		empty_line(game, line);
		if (line && line[0] != '\0' && line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		add_line_to_map(game, line, i);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
