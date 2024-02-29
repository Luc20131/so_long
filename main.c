/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:57:53 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/29 17:28:42 by lrichaud         ###   ########lyon.fr   */
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
		perror("Args Error");
		exit(1);
	}
	if (!ft_strnstr(argv[1], ".ber\0", ft_strlen(argv[1])))
	{
		perror("Extention Error");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	v;
	t_pos	size_window;

	check_file_error(argc, argv);
	v.map = map_tester(argv[1]);
	if (v.map == NULL)
	{
		perror("Map error");
		exit(1);
	}
	size_window = size_map(v.map);
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, size_window.x, size_window.y, "fenetre");
	v.link_side = 0;
	images_for_map(&v);
	images_for_link(&v);
	img_map_initializer(&v, v.map);
	mlx_put_image_to_window(v.mlx, v.win, v.tile[23].img, 0, 0);
	mlx_key_hook(v.win, key_hook, &v);
	mlx_loop(v.mlx);
}

int	chest_checker(t_vars *v, size_t checker)
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
				write(1, "Win\n", 4);
				ft_close(v);
			}
		}
		y++;
	}
	return (0);
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
