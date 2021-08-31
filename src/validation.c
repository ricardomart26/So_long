#include "../includes/so_long.h"

int	is_valid(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || \
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
