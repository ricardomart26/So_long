#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "struct.h"
#include <stdbool.h>

#define FLOOR 0
#define WALL 1
#define P 2
#define C 3
#define E 4

typedef struct	s_pos
{
	int	collect_x;
	int	collect_y;
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;
	bool	is_alloc;
}	t_pos;


typedef	struct	s_map
{
	int total;
	int width;
	int height;
	t_pos pos;
	int **array_of_map;
	bool	is_alloc;
}	t_map;


typedef	struct	s_player
{
	t_img	img;
	int	player_x;
	int	player_y;
	bool	is_alloc;
}	t_player;


typedef	struct	s_collect
{
	t_img	img;
	int		in_map;
	int		collect_x;
	int		collect_y;
	bool	is_collected;
	bool	is_alloc;
}	t_collect;


typedef	struct	s_master
{
	void		*mlx;
	void		*win;
	void		*mlx_img;
	int			win_h;
	int			win_w;
	t_player	*pla;
	t_img		*floor;
	t_img		*walls;
	t_img		img;
	t_map		map;
	t_collect	*col;
} t_master;

t_master	draw(t_master *master, int x, int y, int color);
int	check_file(char *file, char *ext);
void	parse_file(int fd, t_map *map, char *file_name);
t_img	load_image(void	*mlx, char *path);
void	init_avatars(t_master *master);
void	init_master(t_master *master);
void	init_map(t_map *map);

#endif
