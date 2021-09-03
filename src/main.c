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

void	lost_life(t_master *master)
{
	master->lives--;
	draw(master);
}

int	player_mov(int key, t_master *master)
{
	if (key == ESC)
		exit_hook(master);
	else if (key == MV_U || key == MV_D || key == MV_L || key == MV_R)
	{
		update_positions(master, key);
		if (not_wall(master, master->pla.pos.x, master->pla.pos.y))
		{
			update_coll(master, master->pla.pos.x, master->pla.pos.y);
			refresh_map(master, master->pla.pos.x, master->pla.pos.y);
			refresh_enemy(master, master->enemy.pos.x, master->enemy.pos.y);
			if (enemy_touch(master, master->pla.pos.x, master->pla.pos.y))
				lost_life(master);
			ft_putnbr_fd(master->player_moves, 1);
			ft_putchar_fd('\n', 1);
			printf("teste 1\n");
			if (game_finished(master, master->pla.pos.x, master->pla.pos.y))
				exit_win_hook(master);
			printf("teste 2\n");
			
			master->pla.last_pos.x = master->pla.pos.x;
			master->pla.last_pos.y = master->pla.pos.y;
			master->enemy.last_pos.x = master->enemy.pos.x;
			master->enemy.last_pos.y = master->enemy.pos.y;
		}
	}
	return (0);
}

void	put_lives(t_master *master)
{
	int lives;
	t_master fake_master;

	init_map(&fake_master.map);
	init_master(&fake_master);
	fake_master.map->pos_x_y.x = master->map->width * IMG_WIDTH + 100;
	fake_master.map->pos_x_y.y = 0;
	lives = master->lives;
	while (lives != 0)
	{
		fake_master.map->pos_x_y.y += 50;
		put_img(master, &master->life, fake_master.map);
		lives--;
	}
}

void	start_game(t_master *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "fds");

	init_images(m);
	draw(m);
	mlx_key_hook(m->win, player_mov, m);
	mlx_loop(m->mlx);
}

int	main(int ac, char **av)
{
	int			fd;
	t_master	master;
	t_parse_info info;
	
	if (ac != 2)
		return (-1);
	if (!check_file(av[1], ".ber"))
		return (-1);
	init_map(&master.map);
	init_master(&master);
	fd = open(av[1], O_RDONLY);
	info = parse_file(fd, master.map, av[1]);
	master.col.number_of_c = info.c_exists;
	close(fd);
	start_game(&master);

	return (0);
}
