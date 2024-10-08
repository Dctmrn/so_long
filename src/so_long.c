/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:52 by marida-c          #+#    #+#             */
/*   Updated: 2024/10/09 13:42:53 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
	{
		ft_printf(RED "\nARGUMENT ERROR (try -> %s <map_dir>/<map_file>)\n\n"
			RESET, argv[0]);
		return (0);
	}
	check_file(argv[1]);
	init_map(&game, argv[1]);
	check_10pec(&game);
	start_flood_fill(&game);
	init_img(&game);
	mlx_hook(game.img.win_ptr, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.img.win_ptr, 17, 1L << 17, close_game, &game);
	mlx_loop(game.img.mlx_ptr);
	close_game(&game);
	free_map(&game);
}
