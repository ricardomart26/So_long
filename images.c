#include "so_long.h"

t_img	load_image(void	*mlx, char *path)
{
	t_img	img;

	img.img_var = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.img_var)
		return (img);
	img.addr = mlx_get_data_addr(img.img_var, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}
