#include "../includes/so_long.h"

// int	total_lines(int *widht)
// {
// 	int total;
// 	int i;

// 	i = -1;
// 	total = 0;
// 	while (widht[++i])
// 		total += widht[i];
// 	printf("total %d\n") ;
// 	return (total);
// }

// void	bigger_widht(int *big, int width, int size)
// {
// 	int i = -1;

// 	while (++i < size)
// 	{
// 		if (i == 0)
// 			*big = width[i];
// 		else if (width[i] > *big)
// 			*big = width[i];
// 	}
// 	printf("big widht %d\n", *big);
// }


// int str_search(char *str, char c)
// {
// 	(void)str;
// 	(void)c;
// 	return (0);
// }


// void	put_color_on_panel(t_panel *panel, int sizeX, int sizeY)
// {
// 	int x;
// 	int y;
	
// 	y = 0;
// 	while (y < sizeX)
// 	{
// 		x = 0;
// 		while (x < sizeY)
// 		{
// 			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
// 			panel->pixels[(x * 4 + panel->line_size * y) + 1] = color.g;
// 			panel->pixels[(x * 4 + panel->line_size * y) + 2] = color.r;
// 			panel->pixels[(x * 4 + panel->line_size * y) + 3] = color.a;
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	do_panel(t_master *master)
// {
// 	t_panel panel;

// 	panel.panel = mlx_new_image(master->mlx, master->win_w, master->win_h);
// 	put_color_on_panel(master, master->win_h, master->win_w);

// 	master->img.addr = mlx_get_data_addr(master->img.img_var, \
// 	&master->img.bits_per_pixel, &master->img.line_length, &master->img.endian);

// }


// int	*init_array(int size)
// {
// 	int i;
// 	int arr[size];

// 	i = -1;
// 	while (++i < size)
// 		arr[i] = 0;

// 	return (arr);
// }

// typedef struct	s_pos
// {
// 	int	collect_x;
// 	int	collect_y;
// 	int	exit_x;
// 	int	exit_y;
// 	int	player_x;
// 	int	player_y;
// 	bool	is_alloc;
// }	t_pos;

// typedef struct	s_panel
// {
// 	void	*panel;
// 	char	*pixels;
// 	t_vector size;
// 	int	bpp;
// 	int	line_size;
// 	int	endian;
// }	t_panel;