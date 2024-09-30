#include "../so_long.h"

void flood_fill(t_map *game, int x, int y)
{
    //printf("flood fill...\n");
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == 'V')
		return;
	if (game->map[y][x] == 'C')
		game->flood_collect++;
	if (game->map[y][x] == 'E')
		game->flood_exit++;
	if (game->map[y][x] == 'P')
		game->flood_player = 1;
	game->map[y][x] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}	


void flood_check_ec(t_map *game)
{
	if (game->flood_collect != game->collect)
		error(game, "Collectibles are not reachable");
	if (game->flood_exit == 0)
		error(game, "Exit is not reachable");
	if (game->flood_player == 0)
		error(game, "Player is not reachable");

	//ft_printf("All collectibles, exit, and player are reachable!\n");
}

void restore_map(t_map *game)
{
   //printf("restoring map...\n");
    int i;
    int j;

    i = 0;
    while (i < game->height)
    {
        j = 0;
        while (j < game->width)
        {
            if (game->map[i][j] == 'V')
                game->map[i][j] = '0';
            j++;
        }
        i++;
    }
}

void start_flood_fill(t_map *game)
{
    int i, j;
    int found_player = 0;
    //printf("starting flood fill...\n");
    i = 0;
    while (i < game->height && !found_player)
    {
        j = 0;
        while (j < game->width && !found_player)
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
                found_player = 1;
            }
            j++;
        }
        i++;
    }
    if (!found_player)
        error(game, "Player position not found");

    flood_fill(game, game->player_x, game->player_y);
    flood_check_ec(game);
    restore_map(game);
}



