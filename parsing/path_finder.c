/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:10:18 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/11 12:28:39 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	carac_finder(t_pos pos_carac, char ***map);
int		path_filler(t_pos pos_carac, char ***map);

int	path_finder(char ***map)
{
	t_pos	pos_carac;

	pos_carac = carac_finder(pos_carac, map);
	path_filler(pos_carac, map);
	return (0);
}

t_pos	carac_finder(t_pos	pos_carac, char ***map)
{
	size_t	i;
	size_t	y;

	i = -1;
	while (map[++i])
	{
		y = 0;
		while (map[i][1][y] && map[i][1][y] != 'P')
			y++;
		if (map[i][1][y] == 'P')
			break ;
	}
	pos_carac.x = y;
	pos_carac.y = i;
	return (pos_carac);
}

int	path_filler(t_pos pos_carac, char ***map)
{
	size_t	i;
	size_t	y;

	i = pos_carac.y;
	y = pos_carac.x;
	while (/* condition */)
	{
		/* code */
	}

	// while (map[i])
	// {
	// 	while (map[i][0][y])
	// 	{
	// 		printf("%c", map[i][0][y]);
	// 		y++;
	// 	}
	// 	y = 0;
	// 	i++;
	// }
	return (0);
}
