#include "../includes/so_long.h"

void	put_img(t_master *master, t_img *img, t_map *map)
{
	mlx_put_image_to_window(master->mlx, master->win, img->img_var, \
		map->pos_x_y.x, map->pos_x_y.y);
}

void	get_map_cordinates(t_map *map, int x, int y)
{
	map->pos_x_y.x = IMG_WIDTH * x;
	map->pos_x_y.y = IMG_HEIGHT * y;
}

int	exit_hook(t_master *master)
{
	int	i;

	i = -1;
	while (++i < WIN_WIDTH)
		free(master->map->map2d[i]);
	free(master->map->map2d);
	mlx_destroy_image(master->mlx, master->floor.img_var);
	mlx_destroy_image(master->mlx, master->rocket.img_var);
	mlx_destroy_image(master->mlx, master->col.img.img_var);
	mlx_destroy_image(master->mlx, master->lava_ground.img_var);
	mlx_destroy_image(master->mlx, master->pla.img.img_var);
	mlx_destroy_image(master->mlx, master->enemy.img.img_var);
	mlx_destroy_image(master->mlx, master->final.img_var);
	mlx_destroy_image(master->mlx, master->life.img_var);
	mlx_destroy_image(master->mlx, master->black.img_var);
	mlx_destroy_window(master->mlx, master->win);
	exit(0);
	return (1);
}

int	winner(int keycode, t_master *master)
{
	master->map->pos_x_y.y = WIN_HEIGHT / 4 - 200;
	master->map->pos_x_y.x = WIN_WIDTH / 4 - 250;

	put_img(master, &master->final, master->map);
	if (keycode == ENTER || keycode == ESC)
		exit_hook(master);
	return (1);
}

int	exit_win_hook(t_master *master)
{
	int	i;

	i = -1;

	mlx_key_hook(master->win, winner, master);
	mlx_loop(master->mlx);
	return (0);
}

void	update_positions(t_master *master, int key)
{
	if (key == MV_U)
	{
		master->pla.pos.y = master->pla.last_pos.y - 1;
		master->pla.pos.x = master->pla.last_pos.x;
		if (not_wall(master, master->enemy.last_pos.x, master->enemy.last_pos.y + 1))
		{		
			if (master->enemy.pos.y < master->pla.pos.y)
			{
				master->enemy.pos.y = master->enemy.last_pos.y + 1;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
			else if (master->enemy.pos.y == master->pla.pos.y)
			{
				master->enemy.pos.y = master->enemy.last_pos.y;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
			else
			{
				master->enemy.pos.y = master->enemy.last_pos.y - 1;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
		}
		else
		{
			master->enemy.pos.x = master->enemy.last_pos.x;
			master->enemy.pos.y = master->enemy.last_pos.y;
		}
	}
	else if (key == MV_D)
	{
		
		master->pla.pos.y = master->pla.last_pos.y + 1;
		master->pla.pos.x = master->pla.last_pos.x;
		if (not_wall(master, master->enemy.last_pos.x, master->enemy.last_pos.y - 1))
		{
			if (master->enemy.last_pos.y > master->pla.last_pos.y)
			{
				master->enemy.pos.y = master->enemy.last_pos.y - 1;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
			else if (master->enemy.last_pos.y == master->pla.last_pos.y)
			{
				master->enemy.pos.y = master->enemy.last_pos.y;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
			else
			{
				master->enemy.pos.y = master->enemy.last_pos.y + 1;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
		}
		else
		{
			master->enemy.pos.y = master->enemy.last_pos.y;
			master->enemy.pos.x = master->enemy.last_pos.x;
		}
	}
	else if (key == MV_L)
	{
		master->pla.pos.x = master->pla.last_pos.x - 1;
		master->pla.pos.y = master->pla.last_pos.y;
		if (not_wall(master, master->enemy.last_pos.x - 1, master->enemy.last_pos.y))
		{
			if (master->enemy.last_pos.x < master->pla.last_pos.x)
			{
				master->enemy.pos.x = master->enemy.last_pos.x + 1;
				master->enemy.pos.y = master->enemy.last_pos.y;
			}
			else if (master->enemy.last_pos.x == master->pla.last_pos.x)
			{
				master->enemy.pos.y = master->enemy.last_pos.y;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
			else
			{
				master->enemy.pos.x = master->enemy.last_pos.x - 1;
				master->enemy.pos.y = master->enemy.last_pos.y;
			}
		}
		else
		{
			master->enemy.pos.x = master->enemy.last_pos.x;
			master->enemy.pos.y = master->enemy.last_pos.y;
		}
	}
	else if (key == MV_R)
	{
		master->pla.pos.x = master->pla.last_pos.x + 1;
		master->pla.pos.y = master->pla.last_pos.y;
		if (not_wall(master, master->enemy.last_pos.x + 1, master->enemy.last_pos.y))
		{
			if (master->enemy.last_pos.x > master->pla.last_pos.x)
			{
				master->enemy.pos.x = master->enemy.last_pos.x - 1;
				master->enemy.pos.y = master->enemy.last_pos.y;
			}
			else if (master->enemy.last_pos.x == master->pla.last_pos.x)
			{
				master->enemy.pos.y = master->enemy.last_pos.y;
				master->enemy.pos.x = master->enemy.last_pos.x;
			}
			else
			{
				master->enemy.pos.x = master->enemy.last_pos.x + 1;
				master->enemy.pos.y = master->enemy.last_pos.y;
			}
		}
		else
		{
			master->enemy.pos.x = master->enemy.last_pos.x;
			master->enemy.pos.y = master->enemy.last_pos.y;
		}
	}
}

int	not_wall(t_master *master, int x, int y)
{
	return (x < g_struct.width && y < g_struct.height \
		&& master->map->map2d[y][x] != WALL && (master->map->map2d[y][x] != E \
		||	master->col.number_of_c <= 0));
}

void	update_coll(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == C && master->col.number_of_c != 0)
		master->col.number_of_c--;
	master->player_moves++;
}

void	refresh_map(t_master *master, int newx, int newy)
{
	t_img	*img;
	int		x;
	int		y;

	x = master->pla.last_pos.x;
	y = master->pla.last_pos.y;
	if (master->map->map2d[y][x] == E)
		img = &master->rocket;
	else
		img = &master->floor;
	get_map_cordinates(master->map, x, y);
	put_img(master, img, master->map);
	if (master->map->map2d[newy][newx] == E)
		img = &master->rocket;
	else
		img = &master->pla.img;
	get_map_cordinates(master->map, newx, newy);
	put_img(master, img, master->map);
}


void	refresh_enemy(t_master *master, int newx, int newy)
{
	t_img	*img;
	int		x;
	int		y;

	x = master->enemy.last_pos.x;
	y = master->enemy.last_pos.y;
	get_map_cordinates(master->map, x, y);
	if (master->map->map2d[y][x] == WALL)
	{
		img = &master->lava_ground;
		put_img(master, img, master->map);
	}
	else
	{
		img = &master->floor;
		put_img(master, img, master->map);
	}
	if (master->map->map2d[y][x] == C)
	{
		img = &master->col.img;
		if (master->col.total != master->col.number_of_c)
			master->col.number_of_c++;
		put_img(master, img, master->map);
	}
	get_map_cordinates(master->map, newx, newy);
	img = &master->enemy.img;
	put_img(master, img, master->map);
}