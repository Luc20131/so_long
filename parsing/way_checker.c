/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:03:59 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/07 13:14:56 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../so_long.h"

char	**map_to_array(int fd, size_t nb_line);
void	free_map(char ***map);
char ***map_creator(size_t nb_line);

int	way_checker(int fd, int nb_line)
{
	char	***map;
	// size_t	i;
	printf("%d", fd);
	// i = 0;
	// map = map_to_array(fd, nb_line);
	map = map_creator(nb_line);
	if (map == NULL)
		return (1);
	free_map(map);
	return (0);
}

// char	**map_to_array(int fd, size_t nb_line)
// {
// 	char	*line;
// 	char	**map;
// 	ssize_t	i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	if (line == NULL)
// 		return (NULL);
// 	map = malloc((nb_line + 1) * sizeof(char *));
// 	if (map == NULL)
// 		return (free(line), NULL);
// 	map[nb_line] = NULL;
// 	while (line != NULL)
// 	{
// 		map[i] = ft_strdup(line);
// 		free(line);
// 		if (map[i] == NULL)
// 			return (free_map(map), NULL);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free(line);
// 	return (map);
// }

void	free_map(char ***map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i][0]);
		free(map[i][1]);
		free(map[i]);
		i++;
	}
	free(map);
}

char	***map_creator(size_t nb_line)
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
		map[i] = malloc( 2 * sizeof(char *));
		if (map[i] == NULL)
			return (free_map(map), NULL);
		i++;
	}
	return (map);
}

char	***map_filler()
{
	
}
