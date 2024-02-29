/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:01:57 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/29 14:22:43 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "../so_long.h"
// #include <sys/stat.h>

// int	map_opener(void)
// {
// 	ssize_t	fd;

// 	remove("map.ber");
// 	fd = open("map.ber", O_CREAT, S_IRWXU);
// 	while (get_next_line(fd))
// 	{
// 		write(fd, "hm", 2);
// 	}
// 	write(fd, "yo\n", 3);
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	map_opener();
// 	return (0);
// }
