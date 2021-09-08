/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:39:21 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:39:22 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid(char c, char after_c)
{
	if (c == '\n' && after_c == '\n')
		return (0);
	else if (c == '1' || c == '0' || c == 'C' || c == 'E' || \
		c == 'P' || c == '\n')
		return (1);
	return (0);
}

int	check_file(char *file, char *ext)
{
	while (*file != '\0')
	{
		if (*file == '.')
		{
			while (*file == *ext && (*file != '\0' || *ext != '\0'))
			{
				file++;
				ext++;
			}
			if (*file == '\0' && *ext == '\0')
				return (1);
		}
		file++;
	}
	return (0);
}
