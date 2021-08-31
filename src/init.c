#include "../includes/so_long.h"

void	init_master(t_master *master)
{
	master->win_h = 1000;
	master->win_w = 1000;
}

void	init_map(t_map *map)
{
	map->height = 0;
	map->total = 0;
	map->width = 0;
}
