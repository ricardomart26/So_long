#include "../includes/so_long.h"


void	draw(t_master *master)
{
	int		y;
	int		x;
	t_img	*img;

	y = -1;
	while (++y < master->map->height)
	{
		x = -1;
		while (++x < master->map->width)
		{
			get_map_cordinates(master->map, x, y);
			if (master->map->map2d[y][x] == WALL)
				img = &master->walls;
			else if (master->map->map2d[y][x] == FLOOR)
				img = &master->floor;
			else if (master->map->map2d[y][x] == C)
			{
				put_img(master, &master->floor, master->map);
				img = &master->col.img;
			}
			else if (master->map->map2d[y][x] == P)
			{
				put_img(master, &master->floor, master->map);
				img = &master->pla.img;
			}
			else if (master->map->map2d[y][x] == E)
			{
				put_img(master, &master->floor, master->map);
				img = &master->exit;
			}
			put_img(master, img, master->map);
		}
	}
}
