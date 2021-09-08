/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:43:11 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:43:42 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define IMG_H	79
# define IMG_W	79
# define WIN_WIDTH	1000
# define WIN_HEIGHT	500
# define FLOOR 0
# define WALL 1
# define P 2
# define C 3
# define E 4
# define D 5
# define IMG_SIZE 64
# define ESC 53
# define MV_U 13
# define MV_D 1
# define MV_R 2
# define MV_L 0
# define ENTER 36

typedef struct s_global
{
	int	height;
	int	width;
}		t_global;

t_global	g_struct;

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
	int			w;
	int			h;
	int			**map2d;
	t_vector	pos_x_y;
}		t_map;

typedef struct s_player
{
	t_img		img;
	t_vector	pos;
	t_vector	last;
}		t_player;

typedef struct s_collect
{
	t_img	img;
	int		in_map;
	int		number_of_c;
	bool	is_collected;
	int		total;
}		t_collect;

typedef struct s_master
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			player_moves;
	int			lives;
	t_player	pla;
	t_player	enemy;
	t_img		floor;
	t_map		*map;
	t_collect	col;
	t_img		rocket;
	t_img		final;
	t_img		lava_ground;
	t_img		life;
	t_img		moon;
	t_img		black;
}		t_master;

void	add_last_position(t_player *player, int x, int y);
int		exit_win_hook(t_master *master);
void	draw(t_master *master);
void	put_img(t_master *master, t_img *img, t_map *map);
void	get_map_cordinates(t_map *map, int x, int y);
void	refresh_map(t_master *master, int newx, int newy);
int		check_file(char *file, char *ext);
void	parse_file(int fd, t_map *map, char *file_name, t_parse_info *info);
int		is_valid(char c, char after_c);
void	error_msg(char *str);
void	width_map(int *width, char *buffer, int *counter, int *index);
void	open_file(int *fd, char *fname, int opt);
void	update_coll(t_master *master, int x, int y);
int		not_wall(t_master *master, int x, int y);
void	update_positions(t_master *master, int key);
int		exit_hook(t_master *master);
void	init_images(t_master *master);
void	start_game(t_master *m);
int		game_finished(t_master *master, int x, int y);
void	add_position(t_player *player, int x, int y);

#endif
