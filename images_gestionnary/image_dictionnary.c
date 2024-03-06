/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_dictionnary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 04:59:59 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/05 02:28:09 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	images_for_map(t_vars *v)
{
	v->h = TILE_SIZE;
	v->w = TILE_SIZE;
	v->tile[0] = new_img("img/corner_top_left.xpm", *v);
	v->tile[1] = new_img("img/top.xpm", *v);
	v->tile[2] = new_img("img/corner_top_right.xpm", *v);
	v->tile[3] = new_img("img/tree.xpm", *v);
	v->tile[4] = new_img("img/left_side.xpm", *v);
	v->tile[5] = new_img("img/left_side_shadow.xpm", *v);
	v->tile[6] = new_img("img/corner_bottom_left.xpm", *v);
	v->tile[7] = new_img("img/bottom.xpm", *v);
	v->tile[8] = new_img("img/right_side.xpm", *v);
	v->tile[9] = new_img("img/right_side_shadow.xpm", *v);
	v->tile[10] = new_img("img/corner_bottom_right.xpm", *v);
	v->tile[11] = new_img("img/flowers.xpm", *v);
	v->tile[12] = new_img("img/grass.xpm", *v);
	v->tile[13] = new_img("img/big_tree.xpm", *v);
	v->tile[16] = new_img("img/tree2.xpm", *v);
	v->tile[17] = new_img("img/grass2.xpm", *v);
	v->tile[18] = new_img("img/tree3.xpm", *v);
	v->w = 16;
	v->h = 40;
	v->tile[14] = new_img("img/key.xpm", *v);
	v->h = 38;
	v->w = 32;
	v->tile[15] = new_img("img/chest.xpm", *v);
}

void	images_for_link(t_vars *v)
{
	v->h = 48;
	v->w = 32;
	v->tile[19] = new_img("img/link_face.xpm", *v);
	v->h = 48;
	v->w = 32;
	v->tile[21] = new_img("img/link_back.xpm", *v);
	v->h = 48;
	v->w = 32;
	v->tile[22] = new_img("img/link_left.xpm", *v);
	v->h = 48;
	v->w = 32;
	v->tile[20] = new_img("img/link_right.xpm", *v);
}
