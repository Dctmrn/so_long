#include "../so_long.h"

void	draw_element(t_map *game, char element, int x, int y)
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

void	draw_map(t_map *game)
{
	int	i;
	int	y;
	int	j;
	int	x;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		x = 0;
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

void	init_img(t_map *game)
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
// void	load_image(t_map *game, void **img_ptr, char *path)
// {
// 	*img_ptr = mlx_xpm_file_to_image(game->img.mlx_ptr, path,
// 			&game->pixel, &game->pixel);
// 	if (!(*img_ptr))
// 		error(game, "Error loading image");
// }

// void	init_img(t_map *game)
// {
// 	ft_bzero(&(game->img), sizeof(t_img));
// 	game->img.mlx_ptr = mlx_init();
// 	if (!game->img.mlx_ptr)
// 		error(game, "Error initializing mlx");
// 	game->img.win_ptr = mlx_new_window(game->img.mlx_ptr,
// 			game->width * game->pixel, game->height * game->pixel, "so_long");
// 	if (!game->img.win_ptr)
// 		error(game, "Error creating window");
// 	load_image(game, (void **)&game->img.player_img, "./img/hp.xpm");
// 	load_image(game, (void **)&game->img.wall_img, "./img/nuage.xpm");
// 	load_image(game, (void **)&game->img.floor_img, "./img/ciel.xpm");
// 	load_image(game, (void **)&game->img.collect_img, "./img/felix.xpm");
// 	load_image(game, (void **)&game->img.exit_img, "./img/vif.xpm");
// 	draw_map(game);
// }
