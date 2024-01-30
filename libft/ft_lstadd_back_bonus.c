/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:03:49 by lrichaud          #+#    #+#             */
/*   Updated: 2023/11/18 04:58:34 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
// #include <stdio.h>
// int	main(void)
// {
// 	char i = 'i';
// 	t_list *test = ft_lstnew(&i);
// 	i++;
// 	ft_lstadd_back(&test,ft_lstnew(&i));
// 	printf("%c", (*test).content);
// }
