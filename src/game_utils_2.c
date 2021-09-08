/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:38:30 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:38:32 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_finished(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == E && master->col.number_of_c <= 0)
		return (1);
	else
		return (0);
}

int	exit_hook(t_master *master)
{
	int	i;

	i = -1;
	while (++i < g_struct.height - 1)
		free(master->map->map2d[i]);
	free(master->map->map2d);
	free(master->map);
	mlx_destroy_image(master->mlx, master->floor.img_var);
	mlx_destroy_image(master->mlx, master->rocket.img_var);
	mlx_destroy_image(master->mlx, master->col.img.img_var);
	mlx_destroy_image(master->mlx, master->lava_ground.img_var);
	mlx_destroy_image(master->mlx, master->pla.img.img_var);
	mlx_destroy_image(master->mlx, master->final.img_var);
	mlx_destroy_image(master->mlx, master->moon.img_var);
	mlx_destroy_window(master->mlx, master->win);
	exit(0);
	return (1);
}

int	winner(int keycode, t_master *master)
{
	master->map->pos_x_y.y = WIN_HEIGHT / 4 - 200;
	master->map->pos_x_y.x = WIN_WIDTH / 4 - 250;
	put_img(master, &master->final, master->map);
	if (keycode == ENTER || keycode == ESC)
		exit_hook(master);
	return (1);
}

int	exit_win_hook(t_master *master)
{
	mlx_key_hook(master->win, winner, master);
	mlx_loop(master->mlx);
	return (0);
}

void	error_msg(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}
