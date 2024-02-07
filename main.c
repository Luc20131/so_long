
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
// #include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		h;
	int		w;
}	t_vars;

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	image;
	char	*rel_path;

	rel_path = "images.xpm";
	vars.h = 500;
	vars.w = 500;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "fenetre");
	image.img = mlx_xpm_file_to_image(vars.mlx, rel_path, &vars.w, &vars.h);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 50, 50);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
