/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:14:54 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/05 00:00:40 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char ***map, size_t layer)
{
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	ft_printf("\033[H");
	while (map[i])
	{
		while (map[i][layer][y])
		{
			if (map[i][layer][y] == 'V')
				ft_printf("\033[32m");
			else if (map[i][layer][y] == 'P' || map[i][layer][y] == 'E')
				ft_printf("\033[33m");
			else if (map[i][layer][y] == 'C')
				ft_printf("\033[31m");
			ft_printf("%c", map[i][layer][y]);
			ft_printf("\033[0m");
			y++;
		}
		y = 0;
		i++;
	}
}
