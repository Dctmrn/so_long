#include "../so_long.h"

void	handle_win(t_map *game)
{
	game->move++;
	ft_printf(GREEN "\n");
	ft_printf(GREEN "  🎊 🏆 🎊 🏆 🎊 🏆 🎊\n");
	ft_printf(GREEN "   🌟   YOU WON!  🌟\n");
	ft_printf(GREEN "  🎊 🏆 🎊 🏆 🎊 🏆 🎊\n" RESET);
	ft_printf(CYAN ITALIC"\n   ~ With %d moves ~ \n\n" RESET, game->move);
	close_game(game);
}

void	handle_collect(t_map *game, int new_x, int new_y)
{
	ft_printf(RED "\n ~ You can't exit yet! Collect all items first ~\n\n"
		RESET);
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->move++;
}

void	handle_move(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collect--;
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->move++;
}

void	move_player(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E' && game->collect == 0)
		handle_win(game);
	else if (game->map[new_y][new_x] == 'E' && game->collect > 0)
	{
		// Remplacer l'exit par un autre caractère (par exemple 'X')
		game->map[game->player_y][game->player_x] = '0'; // Libérer l'ancienne position du joueur
		game->map[new_y][new_x] = 'X'; // Remplacer l'exit par 'X'
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P'; // Mettre à jour la position du joueur
		ft_printf(RED "\n ~ You can't exit yet! Collect all items first ~\n\n" RESET);
		game->move++;
		draw_map(game); // Redessiner la carte pour mettre à jour l'affichage
		ft_printf(PURPLE ITALIC "Moves : %d\n" RESET, game->move);
	}
else if (game->map[new_y][new_x] == '0')
	{
		handle_move(game, new_x, new_y);
		draw_map(game); // Redessiner la carte
		ft_printf(PURPLE ITALIC "Moves : %d\n" RESET, game->move);
	}
	else if (game->map[new_y][new_x] == 'C')
	{
		handle_move(game, new_x, new_y); // Gérer la collecte
		game->map[game->player_y][game->player_x] = '0'; // Libérer l'ancienne position
		draw_map(game); // Redessiner la carte
		ft_printf(PURPLE ITALIC "Moves : %d\n" RESET, game->move);
	}
}

//printf("Keycode pressed: %d\n", keycode);
int	key_hook(int keycode, t_map *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119)
		new_y -= 1;
	else if (keycode == 115)
		new_y += 1;
	else if (keycode == 97)
		new_x -= 1;
	else if (keycode == 100)
		new_x += 1;
	if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height)
		move_player(game, new_x, new_y);
	return (0);
}