#include "../includes/so_long.h"


void	ft_putstr(char *str)
{
	int size;

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
