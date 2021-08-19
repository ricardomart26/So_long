#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "struct.h"


typedef struct	s_pos
{
	int	collect_x;
	int	collect_y;
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;
}	t_pos;


typedef	struct	s_map
{
	int width;
	int height;
	t_pos pos;
	int **map;
}	t_map;

typedef	struct	s_master
{
	void	*mlx;
	void	*win;
	void	*mlx_img;
	int		win_h;
	int		win_w;
	t_img 	img;
	t_map	map;
} t_master;

int	check_file(char *file, char *ext);
void	parse_file(int fd, t_map *map);

#endif