#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "struct.h"
# include <stdbool.h>
# include "../minilibx_mms_20200219/mlx.h"

# define IMG_HEIGHT	99
# define IMG_WIDTH	99
# define FLOOR 0
# define WALL 1
# define P 2
# define C 3
# define E 4
# define ESC 53
# define IMG_SIZE 64
# define ESC 53
# define MV_U 13
# define MV_D 1
# define MV_R 2
# define MV_L 0

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct parse_info
{
	int exit_exist;
	int collect_exist;
	int player_exist;
} t_parse_info;

typedef	struct	s_map
{
	int		total;
	int		width;
	int		height;
	int		**map2d;
	t_vector pos_x_y;
}	t_map;


typedef	struct	s_player
{
	t_img	img;
	t_vector pos;
	t_vector last_pos;
}	t_player;


typedef	struct	s_collect
{
	t_img	img;
	int		in_map;
	int		number_of_c;
	bool	is_collected;
	bool	is_alloc;
}	t_collect;


typedef	struct	s_master
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	t_player	*pla;
	t_img		floor;
	t_img		walls;
	t_img		img;
	t_img		exit;
	t_map		map;
	t_collect	*col;
	int player_moves;
} t_master;

// typedef struct s_color
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	a;
// }	t_color;

void	draw(t_master *master);
int		check_file(char *file, char *ext);
void	parse_file(int fd, t_map *map, char *file_name);
t_img	load_image(void	*mlx, char *path);
void	init_avatars(t_master *master);
void	init_master(t_master *master);
void	init_map(t_map *map);
void	init_exit(t_master *master);
void	get_map_cordinates(t_map *map, int x, int y);
void	render_img(t_master *master, t_img *img, t_map *map);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		is_valid(char c);
void	error_msg(char *str);

void	print_double_array(int	**array, int width, int height);

#endif
