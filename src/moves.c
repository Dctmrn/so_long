#include "../so_long.h"

void	move_player(t_map *game, int new_x, int new_y)
{
    // Vérifier si le joueur peut se déplacer vers la nouvelle position
	if (game->map[new_y][new_x] == 'E' && game->collect == 0)
	{
		ft_printf(GREEN "ok.won\n" RESET);
		game->move++;
		ft_printf(GREEN "You won! Moves: %d\n" RESET, game->move);
		close_game(game);
	}
	else if (game->map[new_y][new_x] == 'E' && game->collect > 0)
	{
		ft_printf(GREEN "okCollect>0\n" RESET);
		printf("You can't exit yet! Collect all items first.\n");
		printf("Coordonnées de la sortie : exit_x = %d, exit_y = %d\n", game->exit_x, game->exit_y);
		game->map[game->player_y][game->player_x] = 'E'; 
		draw_map(game);
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P'; 
		game->move++;
	}
	else if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		ft_printf(GREEN "okelse\n" RESET);
		if (game->map[new_y][new_x] == 'C')
			game->collect--;
		game->map[game->player_y][game->player_x] = '0'; 
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P'; 
		game->move++;
	}
	else
        printf("Invalid move to: (%d, %d)\n", new_x, new_y);
	
	if(game->player_x == game->exit_x && game->player_y == game->exit_y && game->map[game->player_y][game->player_x] != 'P')
	{
		ft_printf(GREEN "okexit\n" RESET);
		game->map[game->player_y][game->player_x] = 'E';
		draw_map(game); 
		
	}
	draw_map(game);

}

int	key_hook(int keycode, t_map *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	printf("Keycode pressed: %d\n", keycode);
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
	else
		printf("Invalid move to: (%d, %d)\n", new_x, new_y); // Affiche si le mouvement est invalide
	return (0);
}
