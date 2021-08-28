#include "so_long.h"

t_master	draw(t_master *master, int x, int y, int color)
{
	int i;
	int x;

	i = 0;
	while (i < master->win_h)
	{
		x = 0;
		while (x < master->win_w)
		{
			if (master->map.array_of_map[i][x] == '1')
				do_walls();
			else if (master->map.array_of_map[i][x] == '0')
				do_floor();
			else if (master->)
			x++;
		}
		i++;
	}
}
