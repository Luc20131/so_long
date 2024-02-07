/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:35 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/05 07:03:49 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct s_content
{
	int	coins;
	int	exit;
	int	carac;
}	t_content;

int	map_tester(char	*map_path);
int	wall_checker(int fd, int *nb_line, t_content *content);
int	way_checker(int fd, int nb_line);

#endif
