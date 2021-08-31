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


void	alloc_map(int **map2d, int size)
{
	int i;

	map2d = malloc(sizeof(int *) * size + 1);
	i = -1;
	while (++i < size)
		map2d[i] = malloc(sizeof(int) + 1);
	
}

void	get_array(t_map *map, char *fname, int buf_size, t_parse_info *info)
{
	int fd;
	int ret;
	char buffer[buf_size];
	int i;
	int x;

	open_file(&fd, fname, 0);
	alloc_map(map->map2d, map->height);
	i = 0;
	// printf("fd %d buf_size %d\n", fd, buf_size);
	while ((ret = read(fd, &buffer, buf_size) > 0))
	{
		buffer[buf_size] = 0;
		while (i < map->height)
		{
			x = 0;
			while (x < map->width && *buffer != '\n')
			{
				map->map2d[i][x] = check_elem(*buffer, info);
				if (map->map2d[i][x] == -1)
					error_msg("Invalid char at map %c\n");
				x++;
				(*buffer)++;
			}
			if (*buffer == '\n')
				(*buffer)++;
			i++;
		}
	}
	print_double_array(map->map2d, map->width, map->height);
}


void	init_parse_info(t_parse_info *info)
{
	info->collect_exist = 0;
	info->exit_exist = 0;
	info->player_exist = 0;
}

void	parse_file(int fd, t_map *map, char *file_name)
{
	int ret;
	char buffer[1024];
	int i;
	t_parse_info info;

	i = 0;
	ret = 0;
	init_parse_info(&info);
	while ((ret = read(fd, &buffer, 1024)) > 0)
	{
		buffer[1023] = 0;
		while (is_valid(*buffer))
		{
			if (i == 0)
			{
				while (buffer[map->width] != '\n')
				{
					(*buffer)++;
					map->width++;
				}
				i++;
			}
			if (*buffer == '\n')
				map->height++;
			(*buffer)++;
		}
		printf("\twidth %d\n", map->width);
		printf("\theight %d\n", map->height);
	}
	close(fd);
	map->total = map->width * map->height + 3;
	printf("total %d\n", map->total);
	get_array(map, file_name, map->total, &info);

}
