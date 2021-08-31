#include "../includes/so_long.h"

int	exit_hook(t_master *master)
{
	int	i;

	i = -1;
	while (++i < master->win_w)
		free(master->map.map2d[i]);
	free(master->map.map2d);
	mlx_destroy_image(master->mlx, master->floor.img_var);
	mlx_destroy_image(master->mlx, master->exit.img_var);
	mlx_destroy_image(master->mlx, master->col->img.img_var);
	mlx_destroy_image(master->mlx, master->walls.img_var);
	mlx_destroy_image(master->mlx, master->pla->img.img_var);
	mlx_destroy_window(master->mlx, master->win);
	exit(0);
	return (1);
}

void	my_mlx_pixel_put(t_master *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	walk(t_master *master)
{
	master->img.img_var = mlx_new_image(master->mlx, master->win_w, master->win_h);
	master->img.addr = mlx_get_data_addr(master->img.img_var, &master->img.bits_per_pixel, &master->img.line_length, &master->img.endian);
	my_mlx_pixel_put(master, master->pla->pos.x, master->pla->pos.y, 0x00FF0000);
	mlx_put_image_to_window(master->mlx, master->win, master->img.img_var, 0, 0);
	return (0);
}

void	update_positions(t_master *master, int key)
{
	if (key == MV_U)
	{
		master->pla->pos.y = master->pla->last_pos.y - 1;
		master->pla->pos.x = master->pla->last_pos.x;
	}
	else if (key == MV_D)
	{
		master->pla->pos.y = master->pla->last_pos.y + 1;
		master->pla->pos.x = master->pla->last_pos.x;
	}
	else if (key == MV_L)
	{
		master->pla->pos.x = master->pla->last_pos.x - 1;
		master->pla->pos.y = master->pla->last_pos.y;
	}
	else if (key == MV_R)
	{
		master->pla->pos.x = master->pla->last_pos.x + 1;
		master->pla->pos.y = master->pla->last_pos.y;
	}
}

int not_wall(t_master *master, int x, int y)
{
	return (x < master->win_h && y < master->win_w \
		&& master->map.map2d[y][x] != WALL);
}

void update_coll(t_master *master, int x, int y)
{
	if (master->map.map2d[y][x] == C)
		master->col->number_of_c--;
	master->player_moves++;
}

void	refresh_map(t_master *master, int newx, int newy)
{
	t_img *img;
	int x;
	int y;

	x = master->pla->last_pos.x;
	y = master->pla->last_pos.y;
	if (master->map.map2d[y][x] == E)
		img = &master->exit;
	else
		img = &master->floor;
	get_map_cordinates(&master->map, x, y);
	render_img(master, img, &master->map);
	if (master->map.map2d[newy][newx] == E)
		img = &master->exit;
	else
		img = &master->pla->img;
	get_map_cordinates(&master->map, newx, newy);
	render_img(master, img, &master->map);
}

int	game_finished(t_master *master, int x, int y)
{
	if (master->map.map2d[y][x] == 'N' && master->col->number_of_c == 0)
		return (1);
	else
		return (0);
}

int	player_mov(int key, t_master *master)
{
	int x;
	int y;

	x = master->pla->last_pos.x;
	y = master->pla->last_pos.y;
	if (key == ESC)
		exit_hook(master);
	else if (key == MV_U || key == MV_D || key == MV_L || key == MV_R)
	{
		update_positions(master, key);
		if (not_wall(master, master->pla->pos.x, master->pla->pos.y))
		{
			update_coll(master, master->pla->pos.x, master->pla->pos.y);
			refresh_map(master, master->pla->pos.x, master->pla->pos.y);
			// update_map_pos(master, master->pla->pos.x, master->pla->pos.y);
			if (game_finished(master, master->pla->pos.x, master->pla->pos.y))
				exit(0);
		}
	}
	return (0);
}

void	start_game(t_master *master)
{
	master->mlx = mlx_init();
	master->win = mlx_new_window(master->mlx, master->win_w, master->win_h, "fds");
	init_avatars(master);
	mlx_key_hook(master->win, player_mov, &master);
	mlx_hook(master->win, 02, 1L << 2, player_mov, &master);
	mlx_loop(master->mlx);
}

int main(int ac, char **av)
{
	int			fd;
	t_master	master;

	if (ac != 2)
		return (-1);
	if (!check_file(av[1], ".ber"))
		return (-1);
	
	init_map(&master.map);
	init_master(&master);
	fd = open(av[1], O_RDONLY);
	parse_file(fd, &master.map, av[1]);
	print_double_array(master.map.map2d, master.map.width, master.map.height);
	close(fd);
	start_game(&master);
}
