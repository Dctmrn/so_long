#include "../so_long.h"


void draw_element(t_map *game, char element, int x, int y)
{
    if (element == '1')
        mlx_put_image_to_window(game->img.mlx_ptr, game->img.win_ptr, game->img.wall_img, x, y);
    else if (element == '0')
        mlx_put_image_to_window(game->img.mlx_ptr, game->img.win_ptr, game->img.floor_img, x, y);
    else if (element == 'C')
        mlx_put_image_to_window(game->img.mlx_ptr, game->img.win_ptr, game->img.collect_img, x, y);
    else if (element == 'E')
        mlx_put_image_to_window(game->img.mlx_ptr, game->img.win_ptr, game->img.exit_img, x, y);
    else if (element == 'P')
    {
        mlx_put_image_to_window(game->img.mlx_ptr, game->img.win_ptr, game->img.floor_img, x, y);
        mlx_put_image_to_window(game->img.mlx_ptr, game->img.win_ptr, game->img.player_img, x, y);
    }
}
void draw_map(t_map *game)
{
    int i = 0;
    int y = 0;

    while (game->map[i])
    {
        int j = 0;
        int x = 0;
        while (game->map[i][j])
        {
            draw_element(game, game->map[i][j], x, y);
            j++;
            x += game->pixel;
        }
        i++;
        y += game->pixel;
    }
}
void move_player(t_map *game, int new_x, int new_y)
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

void init_game(t_map *game)
{
	game->img.mlx_ptr = mlx_init();
	if (!game->img.mlx_ptr)
		error(game, "Error initializing mlx");
	game->img.win_ptr = mlx_new_window(game->img.mlx_ptr, game->width * game->pixel, game->height * game->pixel, "so_long");
	if (!game->img.win_ptr)
		error(game, "Error creating window");
	game->img.player_img = mlx_xpm_file_to_image(game->img.mlx_ptr, "./img/hp.xpm", &game->pixel, &game->pixel);
	if (!game->img.player_img)
    	error(game, "Error loading player image");
	game->img.wall_img = mlx_xpm_file_to_image(game->img.mlx_ptr, "./img/nuage.xpm", &game->pixel, &game->pixel);
	if (!game->img.wall_img)
    	error(game, "Error loading wall image");
	game->img.floor_img = mlx_xpm_file_to_image(game->img.mlx_ptr, "./img/ciel.xpm", &game->pixel, &game->pixel);
	if (!game->img.floor_img)
		error(game, "Error loading floor image");
	game->img.collect_img = mlx_xpm_file_to_image(game->img.mlx_ptr, "./img/felix.xpm", &game->pixel, &game->pixel);
	if (!game->img.collect_img)
		error(game, "Error loading collectible image");
	game->img.exit_img = mlx_xpm_file_to_image(game->img.mlx_ptr, "./img/vif.xpm", &game->pixel, &game->pixel);
	if (!game->img.exit_img)
		error(game, "Error loading exit image");
	draw_map(game);
}
void check_map(t_map *game, char *file)
{
    check_file_extension(game, file);
    check_10pec(game);
    check_pec(game);
    check_height_width(game);
    check_map_border(game);
}

int	key_hook(int keycode, t_map *game)
{
	int new_x;
	int new_y;

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

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
	{
		ft_printf(RED " Argument error : try, &s <map_dir>/<map_file>\n" RESET, argv[0]);
		return (0);
	}
	init_map(&game, argv[1]);
	check_map(&game, argv[1]);
	start_flood_fill(&game);
	init_game(&game);
	mlx_hook(game.img.win_ptr, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.img.win_ptr, 17, 1L << 17, close_game, &game);
	mlx_loop(game.img.mlx_ptr);
	close_game(&game);
	free_map(&game);
}


