/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:10:18 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/12 15:52:52 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char ***map, size_t layer);
t_pos	carac_finder(t_pos pos_carac, char ***map);
int		path_filler(t_pos pos_carac, char ***map);
void	neighbour_checker(char ***map, size_t x, size_t y);

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
		while (map[y][1][x] && map[y][1][x] != 'P')
			x++;
		if (map[y][1][x] == 'P')
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

	i = 0;
	y = 0;
	neighbour_checker(map, pos_carac.x, pos_carac.y);
	while (map[i])
	{
		while (map[i][1][y])
		{
			if (map[i][1][y] == 'C' || map[i][1][y] == 'E')
				return (1);
			if (map[i][1][y] == '0')
			{
				map[i][1][y] = '1';
				map[i][0][y] = '1';
			}
			y++;
		}
		y = 0;
		i++;
	}
	print_map(map, 1);
	return (0);
}

void	neighbour_checker(char ***map, size_t x, size_t y)
{
	if (map[y][1][x] == 'A' || map[y][1][x] == 'P')
	{
		if (map[y][1][x] == 'A')
			map[y][1][x] = 'V';
		if (map[y][1][x - 1] != '1' && map[y][1][x - 1] != 'V' && map[y][1][x - 1] != 'P')
			map[y][1][x - 1] = 'A';
		if (map[y - 1][1][x] != '1' && map[y - 1][1][x] != 'V' && map[y - 1][1][x] != 'P')
			map[y - 1][1][x] = 'A';
		if (map[y + 1][1][x] != '1' && map[y + 1][1][x] != 'V' && map[y + 1][1][x] != 'P')
			map[y + 1][1][x] = 'A';
		if (map[y][1][x + 1] != '1' && map[y][1][x + 1] != 'V' && map[y][1][x + 1] != 'P')
			map[y][1][x + 1] = 'A';
	}
	print_map(map, 1);
	if (map[y - 1][1][x] == 'A')
		neighbour_checker(map, x, y - 1);
	if (map[y][1][x + 1] == 'A')
		neighbour_checker(map, x + 1, y);
	if (map[y + 1][1][x] == 'A')
		neighbour_checker(map, x, y + 1);
	if (map[y][1][x - 1] == 'A')
		neighbour_checker(map, x - 1, y);
}

void	print_map(char ***map, size_t layer)
{
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	printf("\033\033[H");
	while (map[i])
	{
		while (map[i][layer][y])
		{
			if (map[i][layer][y] == 'V')
				printf("\033[0;32m");
			else if (map[i][layer][y] == 'P')
				printf("\033[0;33m");
			else if (map[i][layer][y] == '0')
				printf("\033[0;35m");
			else if (map[i][layer][y] == 'C')
				printf("\033[0;31m");
			printf("%c", map[i][layer][y]);
			printf("\033[0m");
			y++;
		}
		y = 0;
		i++;
	}
}
