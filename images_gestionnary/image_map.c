/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:36:00 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/27 18:18:42 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_tile_to_image(t_vars *vars, int tile_x, int tile_y)
{
	size_t	y;
	size_t	x;
	int		tile_index;
	size_t	tile_size;
	size_t	sup;

	sup = 0;
	tile_size = 64;
	tile_index = tile_selector(vars->map, tile_y, tile_x);
	if (is_big_tree(tile_x, tile_y, vars->map))
	{
		tile_index = 13;
		tile_size = 128;
		sup = 1;
	}
	y = 0;
	while (y < tile_size)
	{
		x = -1;
		while (++x < tile_size)
			put_pixel_img(vars->tile[23], ((tile_x - sup) * 64) + x, ((tile_y \
			- sup) * 64) + y, get_pixel_img(vars->tile[tile_index], x, y));
		y++;
	}
	print_content(vars, tile_x, tile_y);
}

void	img_map_initializer(t_vars *vars, char ***map)
{
	size_t	x;
	size_t	y;
	t_pos	size_window;

	size_window = size_map(vars->map);
	vars->tile[23].img = mlx_new_image(vars->mlx, size_window.x, size_window.y);
	if (!vars->tile[23].img)
		ft_close(vars);
	vars->tile[23].addr = mlx_get_data_addr(vars->tile[23].img, \
		&vars->tile[23].bits_per_pixel, &vars->tile[23].line_length, \
		&vars->tile[23].endian);
	vars->tile[23].h = size_window.y;
	vars->tile[23].w = size_window.x;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][0][x])
		{
			if (map[y][0][x] != '\n')
				print_tile_to_image(vars, x, y);
			x++;
		}
		y++;
	}
}

int	tile_selector(char ***map, int y, int x)
{
	int	percent;

	percent = pseudo_random_percent(y, x);
	if (map[y][0][x] != '1')
	{
		if (map[y][0][x] != '\n' && abs(percent) % 6 == 0)
			return (11);
		else if (map[y][0][x] != '\n' && abs(percent) % 3 == 0)
			return (17);
		else if (map[y][0][x + 1] != '\n' && map[y][0][x + 2] && map[y + 1])
			return (12);
	}
	return (wall_selector(map, y, x));
}

void	print_content(t_vars *vars, int t_x, int t_y)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 40 && vars->map[t_y][0][t_x] == 'C')
	{
		x = -1;
		while (++x < 16)
			put_pixel_img(vars->tile[23], (t_x * 64) + x + 24, \
				(t_y * 64) + y + 24, get_pixel_img(vars->tile[14], x, y));
	}
	while (++y < 48 && vars->map[t_y][0][t_x] == 'P')
	{
		x = -1;
		while (++x < 32)
			put_pixel_img(vars->tile[23], (t_x * 64) + x + 16, (t_y * 64) \
			+ y + 8, get_pixel_img(vars->tile[19 + vars->link_side], x, y));
	}
	while (++y < 38 && vars->map[t_y][0][t_x] == 'E')
	{
		x = -1;
		while (++x < 32)
			put_pixel_img(vars->tile[23], (t_x * 64) + x + 16, \
				(t_y * 64) + y + 13, get_pixel_img(vars->tile[15], x, y));
	}
}
