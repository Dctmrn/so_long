#include "../so_long.h"

void	check_map(t_map *game, char *file)
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
		ft_printf(RED " Argument error : try, &s <map_dir>/<map_file>\n"
			RESET, argv[0]);
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
