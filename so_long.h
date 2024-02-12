/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:35 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/12 18:21:55 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_content
{
	int	coins;
	int	exit;
	int	carac;
}	t_content;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

int	map_tester(char	*map_path);
int	wall_checker(int fd, int *nb_line, t_content *content);
int	map_generator(int fd, int nb_line);
int	path_finder(char ***map);


#endif
