#include "../includes/so_long.h"

t_img	*fuck_norm3(t_master *m, t_vector vec, t_img my_img, int option)
{
	t_img	*img;

	put_img(m, &m->moon, m->map);
	img = &my_img;
	if (option == P)
		add_last_position(&m->pla, vec.x, vec.y);
	return (img);
}

void	add_last_position(t_player *player, int x, int y)
{
	player->last.x = x;
	player->last.y = y;
}

void	draw(t_master *m)
{
	t_vector	vec;
	t_img		*img;

	vec.y = -1;
	while (++vec.y < m->map->h)
	{
		vec.x = -1;
		while (++vec.x < m->map->w)
		{
			get_map_cordinates(m->map, vec.x, vec.y);
			if (m->map->map2d[vec.y][vec.x] == WALL)
				img = &m->lava_ground;
			else if (m->map->map2d[vec.y][vec.x] == FLOOR)
				img = &m->moon;
			else if (m->map->map2d[vec.y][vec.x] == C)
				img = fuck_norm3(m, vec, m->col.img, C);
			if (m->map->map2d[vec.y][vec.x] == P)
				img = fuck_norm3(m, vec, m->pla.img, P);
			else if (m->map->map2d[vec.y][vec.x] == E)
				img = fuck_norm3(m, vec, m->rocket, E);
			put_img(m, img, m->map);
		}
	}
}
