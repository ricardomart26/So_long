#include "../includes/so_long.h"

void	ft_putstr(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
}

void	error_msg(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	print_double_array(int	**array, int width, int height)
{
	int	x;
	int	i;

	x = 0;
	while (x < height)
	{
		i = 0;
		while (i < width)
		{
			printf("%d ", array[x][i]);
			i++;
		}
		printf("\n");
		x++;
	}
}
