/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:39:14 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:39:15 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_file(int *fd, char *fname, int opt)
{
	if (opt == 0)
		*fd = open(fname, O_RDONLY);
	if (*fd < 3)
		error_msg("Error reading file\n");
}

void	width_map(int *width, char *buffer, int *counter, int *index)
{
	int	i;

	i = 0;
	while (buffer[*index] != '\n')
	{
		(*width)++;
		(*index)++;
	}
	*counter = 1;
}
