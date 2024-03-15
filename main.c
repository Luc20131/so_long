/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:57:53 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/15 16:17:50 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *v)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(v->mlx, v->tile[23].img);
		ft_close(v);
	}
	else if (keycode == 's' && move_down(v->map, &v->link_side))
		v->map = map_refresher(v);
	else if (keycode == 'd' && move_right(v->map, &v->link_side))
		v->map = map_refresher(v);
	else if (keycode == 'w' && move_up(v->map, &v->link_side))
		v->map = map_refresher(v);
	else if (keycode == 'a' && move_left(v->map, &v->link_side))
		v->map = map_refresher(v);
	return (0);
}

void	check_file_error(int argc, char *argv[])
{
	if (argc != 2 || argv[1] == NULL)
	{
		write(1, "Error\nArgs Error", 16);
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(argv[1], ".ber\0", ft_strlen(argv[1])))
	{
		write(1, "Error\nExtention Error\n", 21);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	v;
	t_pos	size_window;

	check_file_error(argc, argv);
	v.map = map_tester(argv[1]);
	if (v.map == NULL)
		return (EXIT_FAILURE);
	size_window = size_map(v.map);
	v.mlx = mlx_init();
	if (!v.mlx)
	{
		perror("Error Mlx Initialisation");
		ft_close(&v);
	}
	v.win = mlx_new_window(v.mlx, size_window.x, size_window.y, "So Long");
	images_for_map(&v);
	images_for_link(&v);
	if (checker_images(&v))
		ft_close(&v);
	img_map_initializer(&v, v.map);
	mlx_put_image_to_window(v.mlx, v.win, v.tile[23].img, 0, 0);
	mlx_key_hook(v.win, key_hook, &v);
	mlx_hook(v.win, DestroyNotify, StructureNotifyMask, &closer, &v);
	mlx_loop(v.mlx);
	return (0);
}

static void	chest_checker(t_vars *v, size_t checker)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (v->map[y])
	{
		x = -1;
		while (v->map[y][0][++x])
		{
			if (v->map[y][0][x] == 'P' && v->map[y][1][x] == 'E' && !checker)
			{
				write(1, "TU TU TU.....TUUUUUUUUUUUUUUUUU !\nYou win\n", 42);
				ft_close(v);
			}
		}
		y++;
	}
}

char	***map_refresher(t_vars *v)
{
	size_t	x;
	size_t	y;
	size_t	checker;

	checker = 0;
	y = -1;
	while (v->map[++y])
	{
		x = -1;
		while (v->map[y][0][++x])
		{
			if (v->map[y][1][x] == '3')
				v->map[y][1][x] = '2';
			else if (v->map[y][0][x] == 'C')
				checker = 1;
		}
	}
	mlx_destroy_image(v->mlx, v->tile[23].img);
	chest_checker(v, checker);
	img_map_initializer(v, v->map);
	mlx_put_image_to_window(v->mlx, v->win, v->tile[23].img, 0, 0);
	return (stepper(), v->map);
}
