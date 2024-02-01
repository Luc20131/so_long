/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:17:45 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/02 00:20:14 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../so_long.h"

typedef	struct s_content
{
	int	coins;
	int	exit;
	int	carac;
}	t_content;

int	wall_line(char *line);

int	map_tester(char	*map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (1);
	if (wall_checker(fd))
		return (1);
	return (0);
}

ssize_t	check_line(ssize_t last_size, char *line)
{
	int					size;
	size_t				i;
	static t_content	content;

	i = 0;
	content.carac = 0;
	content.coins = 0;
	content.exit = 0;
	size = ft_strlen(line);
	while (line[i] != '\0')
	{
		if (line[i] == 'C')
			content.coins++;
		if (line[i] == 'E')
			content.exit++;
		if (line[i] == 'P')
			content.carac++;
		i++;
	}
	if (size == last_size && line[0] == '1' && line[size - 2] == '1')
		return (size);
	else
		return (-1);
}

int	wall_checker(int fd)
{
	char	*line;
	char	*line_buffer;
	ssize_t	last_size;

	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	last_size = ft_strlen(line);
	if (wall_line(line))
		return (1);
	while (line != NULL)
	{
		line_buffer = ft_strdup(line);
		line = get_next_line(fd);
		if (line == NULL && wall_line(line_buffer))
			return (free(line_buffer), 1);
		if (line == NULL)
			return (free(line_buffer), 0);
		last_size = check_line(last_size, line);
		if (last_size == -1)
			return (free(line_buffer), 1);
	}
	return (0);
}

int	wall_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '1')
		i++;
	if (line[i] != '1' && line[i] != '\n')
		return (1);
	return (0);
}
