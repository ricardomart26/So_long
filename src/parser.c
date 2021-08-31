#include "../includes/so_long.h"

void	open_file(int *fd, char *fname,int opt)
{
	if (opt == 0)
		*fd = open(fname, O_RDONLY);
	if (*fd < 3)
	{
		printf("Error reading the file\n");
		exit(0);
	}
}

int	check_elem(char c, t_parse_info *info)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (c == 'P' || c == 'p')
	{
		info->player_exist++;
		return (2);
	}
	else if (c == 'c' || c == 'C')
	{
		info->collect_exist++;
		return (3);
	}
	else if (c == 'e' || c == 'E')
	{
		info->exit_exist++;
		return (4);
	}
	return (-1);
}


int	**alloc_map(int size, int size2)
{
	int i;
	int **map2d;
	printf("size %d size2 %d\n", size, size2);
	
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
	t_file f;
	int x;
	int total;

	open_file(&f.fd, fname, 0);
	map->map2d = alloc_map(map->height, map->width);
	f.index = 0;
	total = 0;
	while ((f.ret = read(f.fd, &f.buffer, BUF_SIZE - 1) > 0))
	{
		f.buffer[BUF_SIZE - 1] = 0;
		while (f.index < map->height)
		{
			x = 0;
			while (x < map->width && f.buffer[total] != '\n')
			{
				map->map2d[f.index][x] = check_elem(f.buffer[total], info);
				if (map->map2d[f.index][x] == -1)
				{
					printf("buffer %c\n", f.buffer[total]);
					error_msg("Invalid char at map\n");
				}
				x++;
				total++;
			}
			total++;
			f.index++;
		}
	}
}


void	init_parse_info(t_parse_info *info)
{
	info->collect_exist = 0;
	info->exit_exist = 0;
	info->player_exist = 0;
}


int width_map(int *width, char *buffer)
{
	int i = 0;
	while (buffer[i] != '\n')
	{
		(*width)++;
		i++;
	}
	return (i);
}

int	validate_array(t_map *map)
{
	(void)map;
	return (1);
}


void	parse_file(int fd, t_map *map, char *file_name)
{
	t_file f;
	t_parse_info info;

	f.index = 0;
	init_parse_info(&info);
	while ((f.ret = read(fd, &f.buffer, BUF_SIZE - 1)) > 0)
	{
		f.buffer[1023] = 0;
		while (is_valid(f.buffer[f.index]))
		{
			// Se nao comecar com o mapa
			if (f.index == 0)
				f.index = width_map(&map->width, f.buffer);
			if (f.buffer[f.index] == '\n')
				map->height++;
			f.index++;
		}
		printf("\twidth %d\n", map->width);
		printf("\theight %d\n", map->height);
	}
	close(fd);
	map->total = map->width * map->height;
	printf("total %d\n", map->total);
	get_array(map, file_name, &info);

	if (!validate_array(map))
		error_msg("Something wrong with the map");
}
