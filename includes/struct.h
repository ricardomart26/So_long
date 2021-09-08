/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:42:55 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/08 03:42:59 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define BUF_SIZE 5000

typedef struct s_img
{
	void	*img_var;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_file
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		ret;
	int		index;
	int		total;
}		t_file;

#endif
