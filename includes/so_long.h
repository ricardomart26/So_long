#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "struct.h"
# include <stdbool.h>
# include "../minilibx_mms_20200219/mlx.h"
# include "../Libft/libft.h"

# define IMG_HEIGHT	78
# define IMG_WIDTH	78
# define WIN_WIDTH	1500
# define WIN_HEIGHT	1000
# define FLOOR 0
# define WALL 1
# define P 2
# define C 3
# define E 4
# define IMG_SIZE 64
# define ESC 53
# define MV_U 13
# define MV_D 1
# define MV_R 2
# define MV_L 0


typedef struct s_global
{
	int	height;
	int	width;
}		t_global;

t_global g_struct;

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct parse_info
{
	int	e_exists;
	int	c_exists;
	int	p_exists;
}		t_parse_info;

typedef struct s_map
{
	int			total;
	int			width;
	int			height;
	int			**map2d;
	t_vector	pos_x_y;
}		t_map;

typedef struct s_player
{
	t_img		img;
	t_vector	pos;
	t_vector	last_pos;
}		t_player;

typedef struct s_collect
{
	t_img	img;
	int		in_map;
	int		number_of_c;
}		t_collect;

typedef struct s_master
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			player_moves;
	t_player	pla;
	t_img		floor;
	t_img		walls;
	t_img		img;
	t_img		exit;
	t_map		*map;
	t_collect	col;
	t_img		rocket;
	t_img		start_rocket;
	t_img		fly_rocket;
	t_img		lava_ground;
	t_img		lava;
t_img		moon;
}		t_master;

void	draw(t_master *master);
void	put_img(t_master *master, t_img *img, t_map *map);
void	get_map_cordinates(t_map *map, int x, int y);
void	refresh_map(t_master *master, int newx, int newy);
int		check_file(char *file, char *ext);
t_parse_info	parse_file(int fd, t_map *map, char *file_name);
void	init_master(t_master *master);
void	init_map(t_map **map);
void	init_exit(t_master *master);
int		is_valid(char c);
void	error_msg(char *str);
void	print_double_array(int	**array, int width, int height);
int		width_map(int *width, char *buffer, int *counter);
void	init_parse_info(t_parse_info *info);
void	open_file(int *fd, char *fname, int opt);
void	update_coll(t_master *master, int x, int y);
int		not_wall(t_master *master, int x, int y);
void	update_positions(t_master *master, int key);
int		exit_hook(t_master *master);
void	init_images(t_master *master);

#endif
