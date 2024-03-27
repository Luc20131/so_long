/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_dictionnary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 04:59:59 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/27 18:08:13 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	images_for_map(t_vars *vars)
{
	vars->h = TILE_SIZE;
	vars->w = TILE_SIZE;
	vars->tile[0] = new_img("img/corner_top_left.xpm", vars);
	vars->tile[1] = new_img("img/top.xpm", vars);
	vars->tile[2] = new_img("img/corner_top_right.xpm", vars);
	vars->tile[3] = new_img("img/tree.xpm", vars);
	vars->tile[4] = new_img("img/left_side.xpm", vars);
	vars->tile[5] = new_img("img/left_side_shadow.xpm", vars);
	vars->tile[6] = new_img("img/corner_bottom_left.xpm", vars);
	vars->tile[7] = new_img("img/bottom.xpm", vars);
	vars->tile[8] = new_img("img/right_side.xpm", vars);
	vars->tile[9] = new_img("img/right_side_shadow.xpm", vars);
	vars->tile[10] = new_img("img/corner_bottom_right.xpm", vars);
	vars->tile[11] = new_img("img/flowers.xpm", vars);
	vars->tile[12] = new_img("img/grass.xpm", vars);
	vars->tile[13] = new_img("img/big_tree.xpm", vars);
	vars->tile[16] = new_img("img/tree2.xpm", vars);
	vars->tile[17] = new_img("img/grass2.xpm", vars);
	vars->tile[18] = new_img("img/tree3.xpm", vars);
	vars->w = 16;
	vars->h = 40;
	vars->tile[14] = new_img("img/key.xpm", vars);
	vars->h = 38;
	vars->w = 32;
	vars->tile[15] = new_img("img/chest.xpm", vars);
}

void	images_for_link(t_vars *vars)
{
	vars->h = 48;
	vars->w = 32;
	vars->tile[19] = new_img("img/link_face.xpm", vars);
	vars->h = 48;
	vars->w = 32;
	vars->tile[21] = new_img("img/link_back.xpm", vars);
	vars->h = 48;
	vars->w = 32;
	vars->tile[22] = new_img("img/link_left.xpm", vars);
	vars->h = 48;
	vars->w = 32;
	vars->tile[20] = new_img("img/link_right.xpm", vars);
	vars->link_side = 0;
}

int	checker_images(t_vars *vars)
{
	size_t	i;

	i = 0;
	if (!vars->win)
	{
		perror("Error Window Initialisation");
		return (1);
	}
	while (i < 23)
	{
		if (vars->tile[i].addr == NULL)
		{
			perror("Error Images Initialisation");
			return (1);
		}
		i++;
	}
	return (0);
}
