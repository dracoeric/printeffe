/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:14:42 by erli              #+#    #+#             */
/*   Updated: 2018/11/28 14:57:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_list	*lst_create(char **cont, int len)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
	{
		free(*cont);
		return (NULL);
	}
	new->content = *cont;
	new->len = len;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int		lst_addback(t_list **list, char **cont, int len)
{
	t_list *elem;
	t_list *bubble;

	if (list == NULL)
	{
		free(*cont);
		return (lst_dellall(list));
	}
	if (!(elem = lst_create(cont, len)))
		return (lst_dellall(list));
	if (*list == NULL)
		*list = elem;
	else
	{
		bubble = *list;
		while (bubble->next != NULL)
			bubble = bubble->next;
		bubble->next = elem;
		elem->prev = bubble;
	}
	return (1);
}

int		lst_dellall(t_list **list)
{
	t_list *bubble;
	t_list *prev;

	if (list != NULL && *list != NULL)
	{
		bubble = *list;
		while (bubble->next != NULL)
			bubble = bubble->next;
		while (bubble != NULL)
		{
			prev = bubble->prev;
			free(bubble->content);
			free(bubble);
			bubble = prev;
		}
		*list = NULL;
	}
	return (-1);
}

int		lst_len(t_list *list)
{
	int len;

	len = 0;
	while (list != NULL)
	{
		len += list->len;
		list = list->next;
	}
	return (len);
}

int		lst_unload(t_list **list)
{
	int		len;
	char	*str;
	int		i;
	int		j;
	t_list	*bubble;

	if (list == NULL || *list == NULL)
		return (0);
	len = lst_len(*list);
	bubble = *list;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1), 0)))
		return (-1);
	i = 0;
	while (bubble != NULL)
	{
		j = 0;
		while (j < bubble->len && bubble->content != NULL)
			str[i++] = bubble->content[j++];
		bubble = bubble->next;
	}
	lst_dellall(list);
	return (write_free(1, &str, len));
}
