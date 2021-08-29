#include "../includes/so_long.h"

int	is_valid(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || \
		c == 'P' || c == '\n')
		return (1);
	return (0);
}

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

void	print_double_array(int	**array, int width, int height)
{
	int x = 0;

	while (x < height)
	{
		int i = 0;
		while (i < width)
		{
			printf("%d ", array[x][i]);
			i++;
		}
		printf("\n");
		x++;
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	ft_atoi(char *str)
{
	int i;
	int size;
	int ret;

	size = ft_strlen(str);
	i = 0;
	ret = 0;
	if (*str == '0' && size == 1)
		return (0);
	while (i < size)
	{
		ret += str[i] - 48;
		i++;
		if (i == size)
			return (ret);
		ret *= 10;
	}
	exit(0);
	return (-1);
}

int	check_elem(char c)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (c == 'P' || c == 'p')
		return (2);
	else if (c == 'c' || c == 'C')
		return (3);
	else if (c == 'e' || c == 'E')
		return (4);
	return (-1);
}

void	get_array(t_map *map, char *fname, int buf_size)
{
	int fd;
	int ret;
	char buffer[buf_size];
	int i;
	int x;
	int y;

	y = 0;
	i = -1;
	open_file(&fd, fname, 0);
	// printf("width %d height %d\n", map->width, map->height);
	map->array_of_map = malloc(sizeof(int *) * map->height + 1);
	while (++i < map->height)
		map->array_of_map[i] = malloc(sizeof(int));
	i = 0;
	printf("fd %d buf_size %d\n", fd, buf_size);
	x = 0;
	while ((ret = read(fd, &buffer, buf_size) > 0))
	{
		buffer[buf_size] = 0;
		while (i < map->height)
		{
			x = 0;
			while (x < map->width)
			{
				if (buffer[y] == '\n')
					y++;
				map->array_of_map[i][x] = check_elem(buffer[y]);
				if (map->array_of_map[i][y] == -1)
				{
					printf("Invalid char at map %c\n", map->array_of_map[i][y]);
					exit(0);
				}
				y++;
				x++;
			}
			i++;
		}
		break;
	}
	print_double_array(map->array_of_map, map->width, map->height);
}


void	init_parse_info(t_parse_info *info)
{
	info->collect_exist = false;
	info->exit_exist = false;
	info->player_exist = false;
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
		while (is_valid(buffer[i]))
		{
			if (i == 0)
			{
				while (buffer[map->width] != '\n')
				{
					i++;
					map->width++;
				}
			}
			if (buffer[i] == '\n')
				map->height++;
			i++;
		}
		printf("\twidth %d\n", map->width);
		printf("\theight %d\n", map->height);
	}
	close(fd);
	map->total = map->width * map->height + 3;
	printf("total %d\n", map->total);
	get_array(map, file_name, map->total);
}