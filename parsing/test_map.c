/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:17:45 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/17 15:30:23 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	wall_line(char *line, int nb_line);

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
		return (write(1 ,"Error\nFile reading error", 24), NULL);
	if (wall_checker(fd, &nb_line, &content))
		return (write(1, "Error\nWall error\n", 17), NULL);
	close(fd);
	if (content.carac != 1 || content.coins < 1 || content.exit != 1)
		return (write(1, "Error\nContent Error\n", 20), NULL);
	fd = open(map_path, O_RDONLY);
	map = map_initializer(fd, nb_line);
	close(fd);
	if (map == NULL)
		return (write(1, "Error\nMap Initialisation Failed\n", 32), NULL);
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
	free(line);
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
	if (wall_line(line, *nb_line))
		return (1);
	while (line != NULL)
	{
		line_buffer = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (wall_line(line_buffer, *nb_line));
		free(line_buffer);
		*nb_line += 1;
		check = check_line(check, line, content);
		if (check == -1)
			return (1);
	}
	return (0);
}

static int	wall_line(char *line, int nb_line)
{
	int	i;

	i = 0;
	while (line[i] == '1')
		i++;
	if (line[i] != '1' && line[i] != '\n')
	{
		free(line);
		return (1);
	}
	if (nb_line > 1)
		free(line);
	return (0);
}
