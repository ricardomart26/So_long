#include "../includes/so_long.h"

int	xmp_to_image(t_master *master, t_img *image, char *xpm_path)
{
	image->img_var = mlx_xpm_file_to_image(master->mlx, xpm_path, \
		&image->width, &image->height);
	if (!image->img_var)
		return (0);
	return (1);
}

void	init_images(t_master *master)
{
	xmp_to_image(master, &master->pla.img, "pictures/astronaut.XPM");
	xmp_to_image(master, &master->col.img, "pictures/gasoline.XPM");
	xmp_to_image(master, &master->enemy.img, "pictures/cthulhu.XPM");
	xmp_to_image(master, &master->floor, "pictures/lunar2.XPM");
	xmp_to_image(master, &master->rocket, "pictures/space-ship2.XPM");
	xmp_to_image(master, &master->final, "pictures/you-win-text.XPM");
	xmp_to_image(master, &master->lava_ground, "pictures/lava.XPM");
	xmp_to_image(master, &master->moon, "pictures/lunar.XPM");
	xmp_to_image(master, &master->life, "pictures/lives.XPM");
	xmp_to_image(master, &master->black, "pictures/black.XPM");
}
