/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:20 by marida-c          #+#    #+#             */
/*   Updated: 2024/10/09 13:42:21 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_printf(RED "\nInvalid map. (It must be a .ber file)\n\n"
			RESET);
		exit(EXIT_FAILURE);
	}
}

void	check_10pec(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C')
				error(game, "The map must only contain the characters 10PEC.");
			j++;
		}
		i++;
	}
	check_pec(game);
}

void	check_pec(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j++])
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collect++;
		}
		i++;
	}
	if (game->player != 1)
		error(game, "You must have precisely one player.");
	if (game->exit != 1)
		error(game, "You must have precisely one exit.");
	if (game->collect < 1)
		error(game, "You must include at least one collectible.");
	check_height_width(game);
}

void	check_height_width(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->map || !game->map[0])
		error(game, "Map is empty or not initialized.");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
			j++;
		if (i == 0)
			game->width = j;
		else if (j != game->width)
			error(game, "Map must be rectangular.");
		i++;
	}
	game->height = i;
	check_map_border(game);
}

void	check_map_border(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->height - 1)
			{
				if (game->map[i][j] != '1')
					error(game, "The map must be surrounded by walls.");
			}
			else if (j == 0 || j == game->width - 1)
			{
				if (game->map[i][j] != '1')
					error(game, "The map must be surrounded by walls.");
			}
			j++;
		}
		i++;
	}
}
