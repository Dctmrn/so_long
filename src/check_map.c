#include "../so_long.h"

void	check_file(t_map *game, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || !ft_strnstr(file + len - 4, ".ber", 4))
		error(game, "Invalid map file extension (it must be .ber)");
	check_10pec(game);
}

void	check_10pec(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C')
			{
				ft_printf("Verification caractere a la position [%d, %d] : '%c'"
					"(ASCII: %d)\n", i, j, game->map[i][j], game->map[i][j]);
				error(game, "The map must only contain the characters 10PEC");
			}
			j++;
		}
		i++;
	}
	check_pec(game);
}

void	check_pec(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j++])
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collect++;
		}
		i++;
	}
	if (game->player != 1)
		error(game, "You must have precisely one player");
	if (game->exit != 1)
		error(game, "You must have precisely one exit");
	if (game->collect < 1)
		error(game, "You must include at least one collectible");
	check_height_width(game);
}

void	check_height_width(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (i == 0)
			game->width = j;
		else if (j != game->width)
			error(game, "Map must be rectangular");
		i++;
	}
	game->height = i;
	check_map_border(game);
}

void	check_map_border(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->height - 1)
			{
				if (game->map[i][j] != '1')
					error(game, "The map must be surrounded by walls");
			}
			else if (j == 0 || j == game->width - 1)
			{
				if (game->map[i][j] != '1')
					error(game, "The map must be surrounded by walls");
			}
			j++;
		}
		i++;
	}
}
