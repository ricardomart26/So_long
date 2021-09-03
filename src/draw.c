#include "../includes/so_long.h"

void	erase_lives(t_master *master)
{
	t_master fake_master;
	int counter;

	counter = 0;
	init_map(&fake_master.map);
	init_master(&fake_master);

	fake_master.map->pos_x_y.x = master->map->width * IMG_WIDTH + 100;
	fake_master.map->pos_x_y.y = 0;
	printf("erase lifes %d\n\n", master->lives);
	master->player_moves = 0;
	while (counter < 3)
	{
		fake_master.map->pos_x_y.y += 50;
		put_img(master, &master->black, fake_master.map);
		counter++;
	}
}

void	draw(t_master *master)
{
	int		y;
	int		x;
	t_img	*img;

	y = -1;
	erase_lives(master);
	put_lives(master);
	if (master->lives == 0)
		exit_hook(master);
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
				master->pla.pos.x = x;
				master->pla.pos.y = y;
				master->pla.last_pos.x = x;
				master->pla.last_pos.y = y;
				img = &master->pla.img;
			}
			else if (master->map->map2d[y][x] == E)
			{
				put_img(master, &master->moon, master->map);
				img = &master->rocket;
			}
			else if (master->map->map2d[y][x] == D)
			{
				put_img(master, &master->moon, master->map);
				master->enemy.pos.x = x;
				master->enemy.pos.y = y;
				master->enemy.last_pos.x = x;
				master->enemy.last_pos.y = y;
				img = &master->enemy.img;
			}
			put_img(master, img, master->map);
		}
	}
}
