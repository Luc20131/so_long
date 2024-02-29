/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:31:30 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/29 18:00:53 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_down(char ***map, size_t *side)
{
	size_t	x;
	size_t	y;

	if (*side != 0)
		*side = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][0][++x])
		{
			if (map[y][0][x] == 'P')
			{
				if (map[y + 1][0][x] == '1')
					return (0);
				if (map[y][1][x] == 'E')
					map[y][0][x] = 'E';
				else
					map[y][0][x] = '0';
				map[y + 1][0][x] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

int	move_right(char ***map, size_t *side)
{
	size_t	x;
	size_t	y;

	if (*side != 1)
		*side = 1;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][0][++x])
		{
			if (map[y][0][x] == 'P')
			{
				if (map[y][0][x + 1] == '1')
					return (0);
				if (map[y][1][x] == 'E')
					map[y][0][x] = 'E';
				else
					map[y][0][x] = '0';
				map[y][0][x + 1] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

int	move_up(char ***map, size_t *side)
{
	size_t	x;
	size_t	y;

	if (*side != 2)
		*side = 2;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][0][++x])
		{
			if (map[y][0][x] == 'P')
			{
				if (map[y - 1][0][x] == '1')
					return (0);
				if (map[y][1][x] == 'E')
					map[y][0][x] = 'E';
				else
					map[y][0][x] = '0';
				map[y - 1][0][x] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

int	move_left(char ***map, size_t *side)
{
	size_t	x;
	size_t	y;

	if (*side != 3)
		*side = 3;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][0][++x])
		{
			if (map[y][0][x] == 'P')
			{
				if (map[y][0][x - 1] == '1')
					return (0);
				if (map[y][1][x] == 'E')
					map[y][0][x] = 'E';
				else
					map[y][0][x] = '0';
				map[y][0][x - 1] = 'P';
				return (1);
			}
		}
	}
	return (0);
}
