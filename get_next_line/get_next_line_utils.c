/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:04:20 by lrichaud          #+#    #+#             */
/*   Updated: 2024/01/15 10:24:18 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string;

	string = s;
	while (n > 0)
	{
		*string = '\0';
		string++;
		n--;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	char	*str_joined;
	size_t	y;

	i = 0;
	y = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str_joined = malloc((size + 1) * sizeof(char));
	if (str_joined == NULL)
		return (NULL);
	while (i < size && i < ft_strlen(s1))
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (i + y < size)
	{
		str_joined[i + y] = s2[y];
		y++;
	}
	str_joined[size] = '\0';
	return (str_joined);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*char_ptr;

	i = 0;
	while (s[i] != (unsigned char) c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (unsigned char) c)
	{
		char_ptr = (char *) s + i;
	}
	else
		char_ptr = 0;
	return (char_ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dup;

	dup = NULL;
	i = 0;
	while (src[i])
		i++;
	dup = malloc(i + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
