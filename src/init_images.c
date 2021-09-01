#include "../includes/so_long.h"

int	xmp_to_image(t_master *master, t_img *image, char *xpm_path)
{
	image->img_var = mlx_xpm_file_to_image(master->mlx, xpm_path, \
		&image->width, &image->height);
	image->width = 50;
	if (!image->img_var)
		return (0);
	return (1);
}

void	init_images(t_master *master)
{
	xmp_to_image(master, &master->pla.img, "pictures/Mario.XPM");
	xmp_to_image(master, &master->col.img, "pictures/apple.XPM");
	xmp_to_image(master, &master->floor, "pictures/floor.XPM");
	xmp_to_image(master, &master->walls, "pictures/walls.XPM");
	xmp_to_image(master, &master->exit, "pictures/pacman.XPM");
}
