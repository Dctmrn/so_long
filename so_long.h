#ifndef SO_LONG_H
# define SO_LONG_H

# include "../.ft/gnl/gnl.h"
# include "../.ft/libft/libft.h"
# include "../.ft/printf/ft_printf.h"
# include "minilibx-linux/mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*player_img;
	char	*wall_img;
	char	*floor_img;
	char	*collect_img;
	char	*exit_img;
}				t_img;

typedef struct s_map
{
	char	**map;
	int		pixel;
	int		player;
	int		exit;
	int		collect;
	int		height;
	int		width;
	int		move;
	int		player_x;
	int		player_y;
	int		flood_collect;
	int		flood_exit;
	int		flood_player;
	t_img	img;

}				t_map;

int		init_map(t_map *game, char *file);
void	empty_line(t_map *game, char *line);

void	check_file(t_map *game, char *file);
void	check_10pec(t_map *game);
void	check_pec(t_map *game);
void	check_height_width(t_map *game);
void	check_map_border(t_map *game);

void	error(t_map *game, const char *msg);
void	free_map(t_map *game);
void	free_mlx_img(t_img *img);
int		close_game(t_map *game);
void	close_display(t_map *game);

void	init_img(t_map *game);
void	draw_map(t_map *game);
void	draw_elements(t_map *game, int x, int y);

int		key_hook(int keycode, t_map *game);
void	move_player(t_map *game, int new_x, int new_y);

void	start_flood_fill(t_map *game);
void	flood_fill(t_map *game, int x, int y);
void	flood_check_ec(t_map *game);
void	restore_map(t_map *game);

#endif