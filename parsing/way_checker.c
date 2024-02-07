/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:03:59 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/07 06:56:26 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../so_long.h"

char	**map_to_array(int fd, size_t nb_line);
void	free_map(char **map);

int	way_checker(int fd, int nb_line)
{
	char	**map;
	// size_t	i;

	// i = 0;
	map = map_to_array(fd, nb_line);
	if (map == NULL)
		return (1);
	free_map(map);
	return (0);
}

char	**map_to_array(int fd, size_t nb_line)
{
	char	*line;
	char	**map;
	ssize_t	i;

	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	map = malloc((nb_line + 1) * sizeof(char *));
	if (map == NULL)
		return (free(line), NULL);
	map[nb_line] = NULL;
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		if (map[i] == NULL)
			return (free_map(map), NULL);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (map);
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
