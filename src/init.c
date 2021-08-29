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
	// map->pos.player_x = 0;
	// map->pos.player_y = 0;
	// map->pos.collect_x = 0;
	// map->pos.collect_y = 0;
	// map->pos.exit_x = 0;
	// map->pos.exit_y = 0;
}
