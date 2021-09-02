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

void	get_array(t_map *map, char *fname, t_parse_info *info)
{
	t_file	f;
	int		x;

	open_file(&f.fd, fname, 0);
	map->map2d = alloc_map(map->height, map->width);
	f.index = 0;
	f.total = 0;
	while ((read(f.fd, &f.buffer, BUF_SIZE - 1) > 0))
	{
		f.buffer[BUF_SIZE - 1] = 0;
		while (f.index < map->height)
		{
			x = 0;
			while (x < map->width && f.buffer[f.total] != '\n')
			{
				map->map2d[f.index][x] = check_elem(f.buffer[f.total], info);
				if (map->map2d[f.index][x] == -1)
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
	while (++i < widht - 1)
	{
		if (map->map2d[0][i] != 1)
			error_msg("Top wall not closed\n");
		if (map->map2d[height - 1][i] != 1)
			error_msg("Bottom wall not closed\n");
	}
	i = -1;
	while (++i < height - 1)
	{
		if (map->map2d[i][0] != 1)
		{
			printf("map2d %d i %d\n", map->map2d[i - 1][0], i);
			error_msg("Left wall not closed\n");
		}
		if (map->map2d[i][widht - 1] != 1)
			error_msg("Rigth wall not closed\n");
	}
	if (info.c_exists != 0 && info.e_exists != 0 && info.p_exists != 1)
		error_msg("NOT A COLECT OR EXIT OR NO OR MORE THAN ONE PLAYER");
	return (1);
}

void	parse_file(int fd, t_map *map, char *file_name)
{
	t_file			f;
	t_parse_info	info;
	int	g_counter;

	f.index = 0;
	g_counter = 0;
	printf("teste 3\n");
	init_parse_info(&info);
	while (read(fd, &f.buffer, BUF_SIZE - 1) > 0)
	{
		f.buffer[1023] = 0;
		while (is_valid(f.buffer[f.index]))
		{
			while (f.buffer[f.index] != '1' && g_counter == 0)
				f.index++;
			if (g_counter == 0)
				f.index = width_map(&map->width, f.buffer, &g_counter);
			if (f.buffer[f.index] == '\n')
				map->height++;
			f.index++;
		}
		g_struct.width = map->width;
		g_struct.height = map->height;
		printf("widht %d heigth %d\n", map->width, map->height);
	}
	printf("teste 4\n");
	close(fd);
	map->total = map->width * map->height;
	get_array(map, file_name, &info);
	if (!validate_array(map, map->width, map->height, info))
		error_msg("Something wrong with the map");
}
