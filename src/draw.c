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
				img = &master->lava_ground;
			else if (master->map->map2d[y][x] == FLOOR)
				img = &master->moon;
			else if (master->map->map2d[y][x] == C)
			{
				put_img(master, &master->moon, master->map);
				img = &master->col.img;
			}
			else if (master->map->map2d[y][x] == P)
			{
				put_img(master, &master->moon, master->map);
				master->pla.last_pos.x = x;
				master->pla.last_pos.y = y;
				master->pla.last_pos.x = x;
				master->pla.last_pos.y = y;
				img = &master->pla.img;
			}
			else if (master->map->map2d[y][x] == E)
			{
				put_img(master, &master->moon, master->map);
				img = &master->rocket;
			}
			put_img(master, img, master->map);
		}
	}
}
