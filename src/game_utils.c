/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:38:35 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/14 20:53:43 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	not_wall(t_master *master, int x, int y)
{
	return (x < g_struct.width && y < g_struct.height \
		&& master->map->map2d[y][x] != WALL && (master->map->map2d[y][x] != E \
			|| master->col.number_of_c <= 0));
}

void	update_coll(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == C && master->col.number_of_c != 0)
	{
		master->col.number_of_c--;
		master->map->map2d[y][x] = 0;
	}
	if (master->player_moves >= 50)
		exit_hook(master);
	master->player_moves++;
}

void	refresh_map(t_master *master, int newx, int newy)
{
	t_img	*img;
	int		x;
	int		y;

	x = master->pla.last.x;
	y = master->pla.last.y;
	if (master->map->map2d[y][x] == E)
		img = &master->rocket;
	else
		img = &master->floor;
	get_map_cordinates(master->map, x, y);
	put_img(master, img, master->map);
	if (master->map->map2d[newy][newx] == E)
		img = &master->rocket;
	else
		img = &master->pla.img;
	get_map_cordinates(master->map, newx, newy);
	put_img(master, img, master->map);
}
