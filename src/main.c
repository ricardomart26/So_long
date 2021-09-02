#include "../includes/so_long.h"

int	game_finished(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == E && master->col.number_of_c == 0)
		return (1);
	else
		return (0);
}

// void	width_and_height(t_map **map, int **map2d)
// {
// 	int width;
// 	int height;
	
// 	printf("Teste\n");
// 	width = sizeof(map2d) / sizeof(map2d[0]);
// 	height = sizeof(map2d[0]) / sizeof(map2d[0][0]);
	
// 	printf("widht %d heigth %d teste\n", width, height);
	

// }

int	player_mov(int key, t_master *master)
{
	int	x;
	int	y;

	// width_and_height(&master->map, master->map->map2d);
	printf("widht %d heigth %d teste\n", g_struct.width, g_struct.height);

	x = master->pla.last_pos.x;
	y = master->pla.last_pos.y;

	if (key == ESC)
		exit_hook(master);
	else if (key == MV_U || key == MV_D || key == MV_L || key == MV_R)
	{
		update_positions(master, key);
		if (not_wall(master, master->pla.pos.x, master->pla.pos.y))
		{
			printf("teste 2\n");
			update_coll(master, master->pla.pos.x, master->pla.pos.y);
			refresh_map(master, master->pla.pos.x, master->pla.pos.y);
			ft_putnbr_fd(master->player_moves, 1);
			ft_putchar_fd('\n', 1);
			if (game_finished(master, master->pla.pos.x, master->pla.pos.y))
				exit_hook(master);
		}
	}
	return (0);
}

void	start_game(t_master *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "fds");

	init_images(m);
	draw(m);
	printf("widht %d heigth %d map2d %d\n", m->map->width, m->map->height, m->map->map2d[1][0]);
	mlx_key_hook(m->win, player_mov, m);
	mlx_loop(m->mlx);
}

int	main(int ac, char **av)
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
	parse_file(fd, master.map, av[1]);
	close(fd);
	start_game(&master);
}
