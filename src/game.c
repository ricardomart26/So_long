#include "../includes/so_long.h"

void	update_pos(t_master *master)
{
	master->pla.last.x = master->pla.pos.x;
	master->pla.last.y = master->pla.pos.y;
	master->enemy.last.x = master->enemy.pos.x;
	master->enemy.last.y = master->enemy.pos.y;
}

int	game_eng(int key, t_master *m)
{
	if (key == ESC)
		exit_hook(m);
	else if (key == MV_U || key == MV_D || key == MV_L || key == MV_R)
	{
		update_positions(m, key);
		if (not_wall(m, m->pla.pos.x, m->pla.pos.y))
		{
			update_coll(m, m->pla.pos.x, m->pla.pos.y);
			refresh_map(m, m->pla.pos.x, m->pla.pos.y);
			ft_putnbr_fd(m->player_moves, 1);
			ft_putchar_fd('\n', 1);
			if (game_finished(m, m->pla.pos.x, m->pla.pos.y))
				exit_win_hook(m);
			update_pos(m);
		}
	}
	return (0);
}

void	start_game(t_master *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->map->width * IMG_WIDTH, m->map->height * IMG_HEIGHT, "fds");
	init_images(m);
	draw(m);
	mlx_key_hook(m->win, game_eng, m);
	mlx_loop(m->mlx);
}
