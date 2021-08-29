#include "../includes/so_long.h"

void	init_collect(t_master *master)
{
	master->col->img = load_image(master->mlx, "pictures/apple.XPM");
	if (!(master->img.img_var))
	{
		printf("Error in getting collectable image\n");
		// free_all(master);
	}
}

void	init_floor(t_master *master)
{
	master->floor.img_var = mlx_xpm_file_to_image(master->mlx, "pictures/floor.XPM", &master->floor.width, &master->floor.height);
	master->floor.addr = mlx_get_data_addr(master->floor.img_var,
			&(master->floor.bits_per_pixel),
			&(master->floor.line_length), &(master->floor.endian));
}

void	init_exit(t_master *master)
{
	master->exit.img_var = mlx_xpm_file_to_image(master->mlx, "pictures/pacman.XPM", &master->exit.width, &master->exit.height);
	master->exit.addr = mlx_get_data_addr(master->exit.img_var,
			&(master->exit.bits_per_pixel),
			&(master->exit.line_length), &(master->exit.endian));
}


void	init_player(t_master *master)
{
	master->pla->img = load_image(master->mlx, "pictures/Mario.XPM");
	if (!(master->img.img_var))
	{
		printf("Error in getting player image\n");
		// free_all(master);
	}
}

void	init_walls(t_master *master)
{
	master->walls.img_var = mlx_xpm_file_to_image(master->mlx, "pictures/walls.XPM", &master->walls.width, &master->walls.height);
	master->walls.addr = mlx_get_data_addr(master->walls.img_var,
			&(master->walls.bits_per_pixel),
			&(master->walls.line_length), &(master->walls.endian));
}

void	init_avatars(t_master *master)
{
	init_player(master);
	init_collect(master);
	init_floor(master);
	init_walls(master);
	init_exit(master);
}
