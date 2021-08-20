#include "so_long.h"

void	init_collect(t_master *master)
{
	master->col->img = load_image(master->mlx, "Mario.XPM");
	if (!(master->img.img_var))
	{
		printf("Error in getting collectable image\n");
		free_all(master);
	}
}

void	init_floor(t_master *master)
{
	master->floor = (t_img *)malloc(sizeof(t_img) + 1);
	if (!(master->img.img_var))
	{
		printf("Error memory allocate\n");
		free_all(master);
	}
	master->floor->img_var = mlx_xpm_file_to_image(mlx, "floorExample.xpm", &master->floor->width, &master->floor->height);
	master->floor->addr = mlx_get_data_addr(master->floor->img,
			&(master->floor->bits_per_pixel),
			&(master->floor->line_length), &(master->floor->endian));
}

void	init_player(t_master *master)
{
	master->pla->img = load_image(master->mlx, "Mario.XPM");
	if (!(master->img.img_var))
	{
		printf("Error in getting player image\n");
		free_all(master);
	}
}

void	init_walls(t_master *master)
{
	master->walls = (t_img *)malloc(sizeof(t_img) + 1);
	if (!(master->img.img_var))
	{
		printf("Error memory allocate\n");
		free_all(master);
	}
	master->walls->img_var = mlx_xpm_file_to_image(mlx, "wallsExample.xpm", &master->walls->width, &master->walls->height);
	master->walls->addr = mlx_get_data_addr(master->walls->img,
			&(master->walls->bits_per_pixel),
			&(master->walls->line_length), &(master->walls->endian));
}

void	init_avatars(t_master *master)
{
	init_player(master);
	init_collect(master);
	init_floor(master);
	init_walls(master);
}
