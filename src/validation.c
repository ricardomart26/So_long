#include "../includes/so_long.h"

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