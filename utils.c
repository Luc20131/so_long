/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:09:18 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/15 06:53:06 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closer(t_vars *v)
{
	ft_close(v);
	return (0);
}

void	print_map(char ***map, size_t layer)
{
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
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

void	stepper(void)
{
	static int	step = 0;

	step++;
	ft_printf("Step : %d\n", step);
}
