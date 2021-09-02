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
	mlx_destroy_image(master->mlx, master->exit.img_var);
	mlx_destroy_image(master->mlx, master->col.img.img_var);
	mlx_destroy_image(master->mlx, master->walls.img_var);
	mlx_destroy_image(master->mlx, master->pla.img.img_var);
	mlx_destroy_window(master->mlx, master->win);
	exit(0);
	return (1);
}

void	update_positions(t_master *master, int key)
{
	if (key == MV_U)
	{
		master->pla.pos.y = master->pla.last_pos.y - 1;
		master->pla.pos.x = master->pla.last_pos.x;
	}
	else if (key == MV_D)
	{
		master->pla.pos.y = master->pla.last_pos.y + 1;
		master->pla.pos.x = master->pla.last_pos.x;
	}
	else if (key == MV_L)
	{
		master->pla.pos.x = master->pla.last_pos.x - 1;
		master->pla.pos.y = master->pla.last_pos.y;
	}
	else if (key == MV_R)
	{
		master->pla.pos.x = master->pla.last_pos.x + 1;
		master->pla.pos.y = master->pla.last_pos.y;
	}
}

int	not_wall(t_master *master, int x, int y)
{
	printf("map width %d map height %d\n", master->map->width, master->map->height);
	return (x < master->map->width && y < master->map->height \
		&& master->map->map2d[y][x] != WALL);
}

void	update_coll(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == C)
		master->col.number_of_c--;
	master->player_moves++;
}

void	refresh_map(t_master *master, int newx, int newy)
{
	t_img	*img;
	int		x;
	int		y;

	printf("REFRESHED THE MAP\n");
	x = master->pla.last_pos.x;
	y = master->pla.last_pos.y;
	if (master->map->map2d[y][x] == E)
		img = &master->exit;
	else
		img = &master->floor;
	get_map_cordinates(master->map, x, y);
	put_img(master, img, master->map);
	if (master->map->map2d[newy][newx] == E)
		img = &master->exit;
	else
		img = &master->pla.img;
	get_map_cordinates(master->map, newx, newy);
	put_img(master, img, master->map);
}
