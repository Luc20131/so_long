/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:11:53 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/29 14:36:11 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_pixel_img(t_data img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_data img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length) \
		+ (x * img.bits_per_pixel / 8))));
}

t_data	new_img(char *path, t_vars v)
{
	t_data	tile;

	tile.img = mlx_xpm_file_to_image(v.mlx, path, &v.w, &v.h);
	tile.addr = mlx_get_data_addr(tile.img, &tile.bits_per_pixel, \
		&tile.line_length, &tile.endian);
	tile.h = v.h;
	tile.w = v.w;
	return (tile);
}

void	free_img(t_vars *v)
{
	size_t	i;

	i = 0;
	while (i < 23)
	{
		mlx_destroy_image(v->mlx, v->tile[i].img);
		i++;
	}
}

void	ft_close(t_vars *vars)
{
	free_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map);
	exit (1);
}
