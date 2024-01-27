
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

typedef	s_data_mlx {
	void	*win;
}	
int	main(void)
{
	void *window;
	void *display;
	int i;
	int	height;
	int	width;

	height = 2000;
	width = 2000;
	i = 0;
	display = mlx_init();
	window = mlx_new_window(display, width, height, "fenetre");

	mlx_loop(mlx.win);
	mlx_destroy_window(display, window);
	free(display);
}
