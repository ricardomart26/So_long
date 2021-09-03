#include "../includes/so_long.h"

void	ft_putstr(const	char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
}

void	error_msg(const	char *str)
{
	ft_putstr(str);
	exit(0);
}
