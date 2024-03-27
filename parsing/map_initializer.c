/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:03:59 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/25 14:32:36 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	***map_creator(size_t nb_line);
static char	***map_filler(int fd, char ***map);

char	***map_initializer(int fd, int nb_line)
{
	char	***map;

	map = map_creator(nb_line);
	if (map == NULL)
		return (NULL);
	map = map_filler(fd, map);
	if (map == NULL)
		return (NULL);
	if (path_finder(map))
		return (print_map(map, 1), free_map(map), NULL);
	return (map);
}

void	free_map(char ***map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i][0]);
		free(map[i][1]);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	***map_creator(size_t nb_line)
{
	char	***map;
	size_t	i;

	i = 0;
	map = malloc((nb_line + 1) * sizeof(char **));
	if (map == NULL)
		return (NULL);
	map[nb_line] = NULL;
	while (i < nb_line)
	{
		map[i] = malloc(2 * sizeof(char *));
		if (map[i] == NULL)
			return (free_map(map), NULL);
		i++;
	}
	return (map);
}

static char	***map_filler(int fd, char ***map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (free_map(map), NULL);
	while (line != NULL)
	{
		map[i][0] = ft_strdup(line);
		map[i][1] = ft_strdup(line);
		free(line);
		if (map[i][0] == NULL)
			return (free_map(map), NULL);
		if (map[i][1] == NULL)
			return (free_map(map), NULL);
		line = get_next_line(fd);
		i++;
	}
	return (map);
}
