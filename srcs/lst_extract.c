/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:51 by erli              #+#    #+#             */
/*   Updated: 2018/11/27 13:49:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*lst_extract(t_list **list, int n)
{
	int		i;
	t_list *bubble;

	i = 0;
	if (list == NULL || *list == NULL)
		return (NULL);
	bubble = *list;
	while (i <= n && bubble != NULL)
	{
		bubble = bubble->next;
		i++;
	}
	if (i != n || bubble == NULL)
		return (NULL);
	if (bubble->prev == NULL)
		*list = bubble->next;
	else
	{
		(bubble->prev)->next = bubble->next;
		if (bubble->next != NULL)
			(bubble->next)->prev = bubble->prev;
	}
	return (bubble);
}
