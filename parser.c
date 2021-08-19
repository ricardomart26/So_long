#include "so_long.h"

int	is_valid(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || \
		c == 'P' || c == '\n')
		return (1);
	return (0);
}

int str_search(char *str, char c)
{
	(void)str;
	(void)c;
	return (0);
}

void	parse_file(int fd, t_map *map)
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
			width = 0;
			while (buffer[width] != '\n')
				width++;
			if (buffer[i] == '\n')
				map->height++;
			if (map->width < width)
				map->width = width;
			i++;
		}
		printf("\twidth %d\n", map->width);
		printf("\theight %d\n", map->height);
	}
}