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

void init_img(t_map *game)
{
	//printf("Initializing game...\n");
	ft_bzero(&(game->img), sizeof(t_img));
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
	init_img(&game);
	mlx_hook(game.img.win_ptr, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.img.win_ptr, 17, 1L << 17, close_game, &game);
	mlx_loop(game.img.mlx_ptr);
	close_game(&game);
	free_map(&game);
}


