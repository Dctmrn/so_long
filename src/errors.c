#include "../so_long.h"

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	if (game == NULL || game->map == NULL)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_mlx_img(t_img *img)
{
	if (img->collect_img && img->mlx_ptr)
	{
		mlx_destroy_image(img->mlx_ptr, img->collect_img);
		img->collect_img = NULL;
	}
	if (img->exit_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->exit_img);
		img->exit_img = NULL;
	}
	if (img->floor_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->floor_img);
		img->floor_img = NULL;
	}
	if (img->player_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->player_img);
		img->player_img = NULL;
	}
	if (img->wall_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->wall_img);
		img->wall_img = NULL;
	}
}

int	close_game(t_map *game)
{
	if (game == NULL)
		return (-1);
	if (game->img.mlx_ptr != NULL)
		mlx_destroy_window(game->img.mlx_ptr, game->img.win_ptr);
	free_mlx_img(&game->img);
	if (game->img.win_ptr != NULL)
		close_display(game);
	free_map(game);
	return (0);
}

void	close_display(t_map *game)
{
	mlx_destroy_display(game->img.mlx_ptr);
	free(game->img.mlx_ptr);
	free_map(game);
	exit(0);
}

void	error(t_map *game, const char *message)
{
	ft_printf(RED "\nError : %s\n\n"RESET, message);
	free_mlx_img(&game->img);
	close_game(game);
	exit(EXIT_FAILURE);
}
