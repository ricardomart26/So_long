#include "../includes/so_long.h"

int	check_elem(char c, t_parse_info *info)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (c == 'P' || c == 'p')
	{
		info->p_exists++;
		return (2);
	}
	else if (c == 'c' || c == 'C')
	{
		info->c_exists++;
		return (3);
	}
	else if (c == 'e' || c == 'E')
	{
		info->e_exists++;
		return (4);
	}
	return (-1);
}

int	**alloc_map(int size, int size2)
{
	int	i;
	int	**map2d;

	map2d = (int **)malloc(sizeof(int *) * size + 1);
	if (!map2d)
		return (0);
	i = -1;
	while (++i < size)
	{
		map2d[i] = malloc(sizeof(int) * size2 + 1);
		if (!map2d[i])
			return (0);
	}
	return (map2d);
}

void	get_array(t_map **map, char *fname, t_parse_info *info)
{
	t_file	f;
	int		x;

	open_file(&f.fd, fname, 0);
	(*map)->map2d = alloc_map((*map)->h, (*map)->w);
	f.index = 0;
	f.total = 0;
	while ((read(f.fd, &f.buffer, BUF_SIZE - 1) > 0))
	{
		f.buffer[BUF_SIZE - 1] = 0;
		while (f.index < (*map)->h)
		{
			x = 0;
			while (x < (*map)->w && f.buffer[f.total] != '\n')
			{
				(*map)->map2d[f.index][x] = check_elem(f.buffer[f.total], info);
				// printf("map2d[%d][%d] %d \n", f.index, x, (*map)->map2d[f.index][x]);
				if ((*map)->map2d[f.index][x] == -1)
					error_msg("Invalid char at map\n");
				x++;
				f.total++;
			}
			f.total++;
			f.index++;
		}
	}
}

int	validate_array(t_map *map, int widht, int height, t_parse_info info)
{
	int	i;

	i = -1;
	printf("teste \n");
	while (++i < widht - 1)
	{
		printf("heigth %d\n", height);
		printf("bottom map %d\n", map->map2d[height - 1][i]);
		if (map->map2d[0][i] != 1)
			error_msg("Top wall not closed\n");
		if (map->map2d[height - 1][i] != 1)
			error_msg("Bottom wall not closed\n");
	}
	i = -1;
	while (++i < height - 1)
	{
		if (map->map2d[i][0] != 1)
			error_msg("Left wall not closed\n");
		if (map->map2d[i][widht - 1] != 1)
			error_msg("Rigth wall not closed\n");
	}
	if (info.c_exists == 0 || info.e_exists == 0 || info.p_exists != 1)
		error_msg("NOT A COLECT OR EXIT OR NO OR MORE THAN ONE PLAYER");
	return (1);
}

void	print_array(t_map *map)
{
	int x;
	int i;
	
	i = 0;
	while (i < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			printf("%d", map->map2d[i][x]);
			x++;
		}
		printf("\n");
		i++;
	}
}

void	parse_file(int fd, t_map *map, char *file_name, t_parse_info *info)
{
	t_file			f;
	int				counter;

	f.index = 0;
	counter = 0;
	while (read(fd, &f.buffer, BUF_SIZE - 1) > 0)
	{
		f.buffer[4999] = 0;
		while (is_valid(f.buffer[f.index], f.buffer[f.index + 1]))
		{
			while (f.buffer[f.index] != '1' && counter == 0)
				f.index++;
			if (counter == 0)
				f.index = width_map(&map->w, f.buffer, &counter);
			if (f.buffer[f.index] == '\n' )
				map->h++;
			f.index++;
		}
		g_struct.width = map->w;
		g_struct.height = map->h;
	}
	printf("height %d width %d\n", g_struct.height, g_struct.width);
	close(fd);
	get_array(&map, file_name, info);
	print_array(map);
	if (!validate_array(map, g_struct.width, g_struct.height, *info))
		error_msg("Something wrong with the map");
}
