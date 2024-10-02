#include "../so_long.h"

void	flood_fill(t_map *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == 'e' ||
		game->map[y][x] == 'o')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'c';
		game->flood_collect++;
	}
	if (game->map[y][x] == 'E')
	{
		game->flood_exit++;
		game->map[y][x] = 'e';
	}
	if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	flood_check_ec(t_map *game)
{
	if (game->flood_collect != game->collect)
		error(game, "Collectible not reachable.");
	if (game->flood_exit == 0)
		error(game, "Exit not reachable.");
	restore_map(game);
}

void	restore_map(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'o')
				game->map[i][j] = '0';
			if (game->map[i][j] == 'p')
				game->map[i][j] = 'P';
			if (game->map[i][j] == 'c')
				game->map[i][j] = 'C';
			if (game->map[i][j] == 'e')
			{
				game->map[i][j] = 'E';
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

void	start_flood_fill(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (game->map[game->player_y - 1][game->player_x] == '1' &&
			game->map[game->player_y + 1][game->player_x] == '1' &&
			game->map[game->player_y][game->player_x - 1] == '1' &&
			game->map[game->player_y][game->player_x + 1] == '1')
		error(game, "Player is surrounded by walls and cannot move.");
	flood_fill(game, game->player_x, game->player_y);
	flood_check_ec(game);
}
