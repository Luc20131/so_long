/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:17:45 by lrichaud          #+#    #+#             */
/*   Updated: 2024/02/28 22:57:06 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_line(char *line);

char	***map_tester(char	*map_path)
{
	int			fd;
	int			nb_line;
	t_content	content;
	char		***map;

	content.carac = 0;
	content.coins = 0;
	content.exit = 0;
	nb_line = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (wall_checker(fd, &nb_line, &content))
		return (NULL);
	close(fd);
	if (content.carac != 1 || content.coins < 1 || content.exit != 1)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	map = map_initializer(fd, nb_line);
	close(fd);
	if (map == NULL)
		return (NULL);
	return (map);
}

ssize_t	check_line(ssize_t check, char *line, t_content *content)
{
	int		size;
	size_t	i;

	i = 0;
	size = ft_strlen(line);
	while (line[i] != '\n')
	{
		if (line[i] == 'C')
			content->coins += 1;
		else if (line[i] == 'E')
			content->exit += 1;
		else if (line[i] == 'P')
			content->carac += 1;
		else if (line[i] != '1' && line[i] != '0')
			return (1);
		i++;
	}
	if (size == check && line[0] == '1' && line[size - 2] == '1')
		return (size);
	else
		return (-1);
}

int	wall_checker(int fd, int *nb_line, t_content *content)
{
	char	*line;
	char	*line_buffer;
	ssize_t	check;

	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	*nb_line += 1;
	check = ft_strlen(line);
	if (wall_line(line))
		return (free(line), 1);
	while (line != NULL)
	{
		line_buffer = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (check = wall_line(line_buffer), free(line_buffer), check);
		*nb_line += 1;
		check = check_line(check, line, content);
		if (check == -1)
			return (free(line), free(line_buffer), 1);
		free(line_buffer);
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
