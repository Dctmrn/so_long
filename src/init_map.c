#include "../so_long.h"

void	empty_line(t_map *game, char *line, int fd)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || ft_strcmp(line, "\n") == 0)
	{
		free(line);
		close(fd);
		ft_printf(RED "\nError: Empty line found in map.\n\n" RESET);
		if (game->map)
		{
			while (i < game->height)
			{
				free(game->map[i]);
				i++;
			}
			free(game->map);
			game->map = NULL;
		}
		exit(EXIT_FAILURE);
	}
}

void	add_line_to_map(t_map *game, char *line, int i)
{
	char	**new_map;

	new_map = (char **)ft_realloc(game->map, sizeof(char *) * (i + 1),
			sizeof(char *) * (i + 2));
	if (!new_map)
	{
		free(line);
		error(game, "Allocating memory failed.");
	}
	game->map = new_map;
	game->map[i] = ft_strdup(line);
	if (!game->map[i])
	{
		free(line);
		error(game, "Memory allocation for map line failed.");
	}
}

void	map_empty(t_map *game, int fd, int i)
{
	if (i > 0)
		game->map[i] = NULL;
	else
		(close(fd), error(game, "Map empty."));
}

int	init_map(t_map *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	(ft_bzero(game, sizeof(t_map)), game->pixel = 128);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(game, "Opening map file.");
	game->map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->height = i;
		empty_line(game, line, fd);
		if (line && line[0] != '\0' && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		(add_line_to_map(game, line, i), free(line));
		i++;
		line = get_next_line(fd);
	}
	map_empty(game, fd, i);
	return (close(fd), 1);
}
