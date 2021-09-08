/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:39:06 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:39:07 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_master *master, t_img *img, t_map *map)
{
	mlx_put_image_to_window(master->mlx, master->win, img->img_var, \
		map->pos_x_y.x, map->pos_x_y.y);
}

void	get_map_cordinates(t_map *map, int x, int y)
{
	map->pos_x_y.x = IMG_W * x;
	map->pos_x_y.y = IMG_H * y;
}

void	add_position(t_player *player, int x, int y)
{
	player->pos.x = x;
	player->pos.y = y;
}

void	update_positions(t_master *m, int key)
{
	if (key == MV_U)
		add_position(&m->pla, m->pla.last.x, m->pla.last.y - 1);
	else if (key == MV_D)
		add_position(&m->pla, m->pla.last.x, m->pla.last.y + 1);
	else if (key == MV_L)
		add_position(&m->pla, m->pla.last.x - 1, m->pla.last.y);
	else if (key == MV_R)
		add_position(&m->pla, m->pla.last.x + 1, m->pla.last.y);
}
