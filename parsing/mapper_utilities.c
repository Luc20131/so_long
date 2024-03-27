/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:55:38 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/23 17:21:38 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_selector(char ***map, int y, int x)
{
	if (y == 0 && x > 0 && map[y][0][x + 1] && map[y][0][x + 1] != '\n')
		return (1);
	else if (y == 0 && x == 0)
		return (0);
	else if (y == 0 && x > 0 && map[y][0][x + 1] == '\n')
		return (2);
	else if (y > 0 && x == 0 && !map[y + 1])
		return (6);
	else if (y > 0 && x == 0 && !map[y + 2])
		return (5);
	else if (x > 0 && y > 0 && \
		(map[y][0][x + 1] == '\n' || map[y][0][x + 1] == '\0') \
			&& map[y + 1] == NULL)
		return (10);
	else if (y > 0 && map[y][0][x + 1] == '\n' && map[y + 2] == NULL)
		return (9);
	else if (y > 0 && x > 0 && !map[y + 1])
		return (7);
	else if (y > 0 && x == 0)
		return (4);
	else if (y > 0 && map[y][0][x + 1] == '\n')
		return (8);
	else
		return (random_tree(y, x));
}

int	random_tree(int y, int x)
{
	int	percent;

	percent = pseudo_random_percent(y, x);
	if (abs(percent) % 24 == 0 && x % 5 == 0)
		return (18);
	else if (percent % 2 == 0)
		return (16);
	else
		return (3);
}

int	is_big_tree(int tile_x, int tile_y, char ***map)
{
	if (tile_y > 1 && tile_x > 1 && map[tile_y][1][tile_x - 1] == '2' \
	&& map[tile_y - 1][1][tile_x] == '2' && map[tile_y][1][tile_x] == '2' \
	&& map[tile_y - 1][1][tile_x - 1] == '2' && map[tile_y + 1] \
	&& map[tile_y][0][tile_x + 1] != '\n')
	{
		map[tile_y - 1][1][tile_x] = '3';
		map[tile_y - 1][1][tile_x - 1] = '3';
		map[tile_y][1][tile_x - 1] = '3';
		map[tile_y][1][tile_x] = '3';
		return (1);
	}
	return (0);
}

int	pseudo_random_percent(int y, int x)
{
	return (cos((pow(cos(x), 2) / sin(cos(cos(x * FT_PI) * sin(y)))) \
		- ((int) cos(y * FT_PI)) * sin(x)) * 100);
}

t_pos	size_map(char ***map)
{
	t_pos	size;
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	size.y = i * 64;
	size.x = (ft_strlen(map[0][0]) - 1) * 64;
	return (size);
}
