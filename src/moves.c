#include "../so_long.h"

void	move_player(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collect--;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->move++;
	}
	else if (game->map[new_y][new_x] == 'E' && game->collect == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->move++;
		ft_printf(GREEN "You won! Moves: %d\n" RESET, game->move);
		close_game(game);
	}
}

int	key_hook(int keycode, t_map *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 53)
		close_game(game);
	else if (keycode == 13)
		new_y -= 1;
	else if (keycode == 1)
		new_y += 1;
	else if (keycode == 0)
		new_x -= 1;
	else if (keycode == 2)
		new_x += 1;
	if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height)
		move_player(game, new_x, new_y);
	return (0);
}
