#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int			fd;
	t_master	master;
	t_parse_info info;
	
	if (ac != 2)
		return (-1);
	if (!check_file(av[1], ".ber"))
		return (-1);
	init_map(&master.map);
	init_master(&master);
	fd = open(av[1], O_RDONLY);
	info = parse_file(fd, master.map, av[1]);
	master.col.number_of_c = info.c_exists;
	master.col.total = info.c_exists;
	close(fd);
	start_game(&master);

	return (0);
}
