#include "so_long.h"

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

int str_search(char *str, char c)
{
	(void)str;
	(void)c;
	return (0);
}

void	bigger_widht(int *big, int *width, int size)
{
	int i = -1;

	while (++i < size)
	{
		if (i == 0)
			*big = width[i];
		else if (width[i] > *big)
			*big = width[i];
	}
	printf("big widht %d\n", *big);
}

void	get_array(t_map *map, char *fname, int buf_size)
{
	int fd;
	int ret;
	char buffer[buf_size + 1];

	bigger_widht(&map->big_w, map->width, map->height);
	open_file(&fd, fname, 0);
	*map->array_of_map = malloc(sizeof(int) * map->big_w + 1);
	map->array_of_map = malloc(sizeof(int *) * map->height + 1);
	printf("fd %d buf_size %d\n", fd, buf_size);
	while ((ret = read(fd, &buffer, buf_size) > 0))
	{
		buffer[buf_size - 1] = 0;
		printf("buffer %s\n Acaba aqui\n", buffer);
	}
}

int	total_lines(int *widht)
{
	int total;
	int i;

	i = -1;
	total = 0;
	while (widht[++i])
		total += widht[i];
	printf("total %d\n") ;
	return (total);
}


void	parse_file(int fd, t_map *map, char *file_name)
{
	int ret;
	char buffer[1024];
	int i;
	int width;

	i = 0;
	ret = 0;
	while ((ret = read(fd, &buffer, 1024)) > 0)
	{
		buffer[1023] = 0;
		while (is_valid(buffer[i]))
		{
			while (buffer[width] != '\n')
				width++;
			if (buffer[i] == '\n')
				map->height++;			
			map->width[i] = width;
			i++;
		}
		printf("\twidth %d\n", map->width);
		printf("\theight %d\n", map->height);
	}
	close(fd);
	map->total = total_lines(map->width);
	get_array(map, file_name, map->total);
}