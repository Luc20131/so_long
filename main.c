/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:57:53 by lrichaud          #+#    #+#             */
/*   Updated: 2024/05/16 01:19:02 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	else if (keycode == 's' && move_down(vars->map, &vars->link_side))
		vars->map = map_refresher(vars);
	else if (keycode == 'd' && move_right(vars->map, &vars->link_side))
		vars->map = map_refresher(vars);
	else if (keycode == 'w' && move_up(vars->map, &vars->link_side))
		vars->map = map_refresher(vars);
	else if (keycode == 'a' && move_left(vars->map, &vars->link_side))
		vars->map = map_refresher(vars);
	return (0);
}

void	check_file_error(int argc, char *argv[])
{
	char	*dot_ptr;

	if (argc != 2 || argv[1] == NULL)
	{
		write(1, "Error\nArgs Error", 16);
		exit(EXIT_FAILURE);
	}
	dot_ptr = ft_strrchr(argv[1], '.');
	if (!dot_ptr || ft_strncmp(dot_ptr, ".ber", 5))
	{
		write(1, "Error\nExtension Error\n", 21);
		exit(EXIT_FAILURE);
	}
}

int	auto_refresh(t_vars *vars)
{
	static int	frame = 0;

	if (frame <= 1000000)
	{
		map_refresher(vars);
		frame = 0;
	}
	usleep(1000);
	frame++;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_pos	size_win;

	check_file_error(argc, argv);
	vars.map = map_tester(argv[1]);
	if (vars.map == NULL)
		return (EXIT_FAILURE);
	size_win = size_map(vars.map);
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		perror("Error Mlx Initialisation");
		ft_close(&vars);
	}
	vars.win = mlx_new_window(vars.mlx, size_win.x, size_win.y, "So Long");
	images_for_map(&vars);
	images_for_link(&vars);
	if (checker_images(&vars))
		ft_close(&vars);
	img_map_initializer(&vars, vars.map);
	map_refresher(&vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_hook(vars.win, KeyRelease, KeyReleaseMask, key_hook, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &ft_close, &vars);
	//mlx_loop_hook(vars.mlx, &auto_refresh, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

static void	chest_checker(t_vars *vars, size_t checker)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (vars->map[y])
	{
		x = -1;
		while (vars->map[y][0][++x])
		{
			if (vars->map[y][0][x] == 'P' \
				&& vars->map[y][1][x] == 'E' && !checker)
			{
				write(1, "TU TU TU.....TUUUUUUUUUUUUUUUUU !\nYou win\n", 42);
				ft_close(vars);
			}
		}
		y++;
	}
}

char	***map_refresher(t_vars *vars)
{
	size_t			x;
	size_t			y;
	size_t			checker;
	static t_pos	pos = {0, 0};
	t_pos			previous;

	previous = pos;
	pos = carac_finder(pos, vars->map);
	checker = 0;
	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][0][++x])
			if (vars->map[y][0][x] == 'C')
				checker = 1;
	}
	chest_checker(vars, checker);
	print_content(vars, pos.x, pos.y);
	print_tile_to_image(vars, previous.x, previous.y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tile[23].img, 0, 0);
	return (vars->map);
}
