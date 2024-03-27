/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:11:53 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/27 18:09:29 by lrichaud         ###   ########lyon.fr   */
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

t_data	new_img(char *path, t_vars *vars)
{
	t_data	tile;

	tile.h = vars->h;
	tile.w = vars->w;
	tile.img = mlx_xpm_file_to_image(vars->mlx, path, &tile.w, &tile.h);
	if (!tile.img)
	{
		tile.addr = NULL;
		return (tile);
	}
	tile.addr = mlx_get_data_addr(tile.img, &tile.bits_per_pixel, \
		&tile.line_length, &tile.endian);
	return (tile);
}

void	free_img(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < 23)
	{
		if (vars->tile[i].addr)
			mlx_destroy_image(vars->mlx, vars->tile[i].img);
		i++;
	}
}

int	ft_close(t_vars *vars)
{
	free_img(vars);
	if (vars->tile[23].addr)
		mlx_destroy_image(vars->mlx, vars->tile[23].img);
	if (vars->win && vars->mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free_map(vars->map);
	exit(EXIT_SUCCESS);
	return (0);
}
