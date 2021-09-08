/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:38:48 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:38:49 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_master(t_master *master)
{
	master->mlx = NULL;
	master->win = NULL;
	master->player_moves = 0;
	master->lives = 3;
}

void	init_map(t_map **map)
{
	*map = malloc(sizeof(t_map) + 1);
	(*map)->h = 1;
	(*map)->total = 0;
	(*map)->w = 0;
	(*map)->pos_x_y.x = 0;
	(*map)->pos_x_y.y = 0;
	(*map)->map2d = NULL;
}

void	init_parse_info(t_parse_info *info)
{
	info->c_exists = 0;
	info->e_exists = 0;
	info->p_exists = 0;
}

int	main(int ac, char **av)
{
	int				fd;
	t_master		master;
	t_parse_info	info;

	if (ac != 2)
		return (-1);
	if (!check_file(av[1], ".ber"))
		return (-1);
	init_map(&master.map);
	init_master(&master);
	fd = open(av[1], O_RDONLY);
	init_parse_info(&info);
	parse_file(fd, master.map, av[1], &info);
	master.col.number_of_c = info.c_exists;
	master.col.total = info.c_exists;
	close(fd);
	start_game(&master);
	return (0);
}
