#include "../so_long.h"

void	flood_fill(t_map *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == 'e' || game->map[y][x] == 'o' || game->map[y][x] == 'p')
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
	if (game->map[y][x] == 'P')
	{
		game->flood_player = 1;
		game->map[y][x] = 'p';
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
		error(game, "Collectibles are not reachable");
	if (game->flood_exit == 0)
		error(game, "Exit is not reachable");
	if (game->flood_player == 0)
		error(game, "Player is not reachable");
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
				printf("Coordonnées de la sortie : exit_x = %d, exit_y = %d\n", game->exit_x, game->exit_y);
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
	int	found_player;

	found_player = 0;
	i = 0;
	while (i < game->height && !found_player)
	{
		j = 0;
		while (j < game->width && !found_player)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				found_player = 1;
			}
			j++;
		}
		i++;
	}
	if (!found_player)
		error(game, "Player position not found");
	flood_fill(game, game->player_x, game->player_y);
	flood_check_ec(game);
}
