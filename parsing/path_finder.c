/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:10:18 by lrichaud          #+#    #+#             */
/*   Updated: 2024/05/11 09:53:54 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char ***map, size_t layer);
int		path_filler(t_pos pos_carac, char ***map);
void	neighbour_checker(char ***map, size_t x, size_t y);
void	setup_final_wall(char ***map);

int	path_finder(char ***map)
{
	t_pos	pos_carac;

	pos_carac.x = 0;
	pos_carac.y = 0;
	pos_carac = carac_finder(pos_carac, map);
	return (path_filler(pos_carac, map));
}

t_pos	carac_finder(t_pos	pos_carac, char ***map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][0][x] && map[y][0][x] != 'P')
			x++;
		if (map[y][0][x] == 'P')
			break ;
	}
	pos_carac.x = x;
	pos_carac.y = y;
	return (pos_carac);
}

int	path_filler(t_pos pos_carac, char ***map)
{
	size_t	y;
	size_t	i;

	i = 1;
	neighbour_checker(map, pos_carac.x, pos_carac.y);
	while (map[i])
	{
		y = 1;
		while (map[i][1][y])
		{
			if (map[i][1][y] == 'C' || map[i][1][y] == 'E')
				return (42);
			map_formating(map, i, y);
			if (map[i][0][y] == 'E')
				map[i][1][y] = 'E';
			y++;
		}
		i++;
	}
	return (0);
}

void	neighbour_checker(char ***map, size_t x, size_t y)
{
	if (map[y][1][x] == 'A' || map[y][1][x] == 'P')
	{
		if (map[y][1][x] == 'A')
			map[y][1][x] = 'V';
		if (map[y][1][x - 1] != '1' && \
			map[y][1][x - 1] != 'V' && map[y][1][x - 1] != 'P')
			map[y][1][x - 1] = 'A';
		if (map[y][1][x + 1] != '1' && \
			map[y][1][x + 1] != 'V' && map[y][1][x + 1] != 'P')
			map[y][1][x + 1] = 'A';
		if (map[y - 1][1][x] != '1' && \
			map[y - 1][1][x] != 'V' && map[y - 1][1][x] != 'P')
			map[y - 1][1][x] = 'A';
		if (map[y + 1][1][x] != '1' && \
			map[y + 1][1][x] != 'V' && map[y + 1][1][x] != 'P')
			map[y + 1][1][x] = 'A';
	}
	if (map[y - 1][1][x] == 'A')
		neighbour_checker(map, x, y - 1);
	if (map[y][1][x + 1] == 'A')
		neighbour_checker(map, x + 1, y);
	if (map[y + 1][1][x] == 'A')
		neighbour_checker(map, x, y + 1);
	if (map[y][1][x - 1] == 'A')
		neighbour_checker(map, x - 1, y);
}

void	setup_final_wall(char ***map)
{
	ssize_t	y;
	ssize_t	x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][0][x])
		{
			if (map[y][0][x] == '1')
			{
				if (x - 1 >= 0 && map[y][0][x - 1] != 'V')
					map[y][0][x] += 2;
				if (y - 1 >= 0 && map[y - 1][0][x] != 'V')
					map[y][0][x] += 4;
				if (map[y + 1] && map[y + 1][0][x] == '1')
					map[y][0][x] += 8;
				if (map[y][0][x + 1] == '1')
					map[y][0][x] += 16;
				if (map[y][0][x] != '1')
					map[y][0][x]--;
			}
			x++;
		}
	}
}
