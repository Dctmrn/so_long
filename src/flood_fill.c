/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:28 by marida-c          #+#    #+#             */
/*   Updated: 2024/10/09 13:42:29 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_map *game, char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		game->flood_exit++;
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (map[y][x] == 'C')
		game->flood_collect++;
	map[y][x] = '1';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
}

void	flood_check_ec(t_map *game)
{
	if (game->flood_collect != game->collect)
		error(game, "Collectible not reachable.");
	if (game->flood_exit == 0)
		error(game, "Exit not reachable.");
}

char	**ft_cpy(char **cpy, int height)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	while (i < height)
	{
		new[i] = ft_strdup(cpy[i]);
		if (!new[i])
			free_map_cpy(new, height);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	free_map_cpy(char **cpy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(cpy[i]);
		i++;
	}
	free(cpy);
}

void	start_flood_fill(t_map *game)
{
	char	**map_cpy;
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	map_cpy = ft_cpy(game->map, game->height);
	flood_fill(game, map_cpy, game->player_x, game->player_y);
	free_map_cpy(map_cpy, game->height);
	flood_check_ec(game);
}
