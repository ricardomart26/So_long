#include "../includes/so_long.h"

int	game_finished(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == E && master->col.number_of_c <= 0)
		return (1);
	else
		return (0);
}

int	enemy_touch(t_master *master, int x, int y)
{
	if (master->enemy.pos.x == x && master->enemy.pos.y == y)
		return (1);
	else
		return (0);
}
