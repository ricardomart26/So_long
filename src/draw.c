#include "../includes/so_long.h"

void	render_img(t_master *master, t_img *img, t_map *map)
{
	mlx_put_image_to_window(master->mlx, master->win, img->img_var, \
		map->pos_x_y.x, map->pos_x_y.y);
}

void	get_map_cordinates(t_map *map, int x, int y)
{
	map->pos_x_y.x = IMG_WIDTH * x;
	map->pos_x_y.y = IMG_HEIGHT * y;
}

void	draw(t_master *master)
{
	int y;
	int x;
	t_img *img;

	y = -1;
	while (++y < master->win_h)
	{
		x = -1;
		while (++x < master->win_w)
		{
			get_map_cordinates(&master->map, x, y);
			if (master->map.map2d[y][x] == WALL)
				img = &master->walls;
			else if (master->map.map2d[y][x] == FLOOR)
				img = &master->floor;
			else if (master->map.map2d[y][x] == C)
				img = &master->col->img;
			else if (master->map.map2d[y][x] == P)
				img = &master->pla->img;
			else if (master->map.map2d[y][x] == E)
				img = &master->exit;
			render_img(master, img, &master->map);
		}
	}
}
