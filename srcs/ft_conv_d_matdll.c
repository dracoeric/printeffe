/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_prt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/28 12:12:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static	int		make_list_tmp(t_format *format, long long **tab, int *dim,
					t_list **list_tmp)
{
	t_format	*format_tab;
	t_format	*copy;
	int			i;

	i = 0;
	if (dim[0] < 0 || (copy_format(&format_tab, format) == -1))
	{
		free_format(format);
		return (lst_dellall(list_tmp));
	}
	format_tab->pointer = 1;
	while (i < dim[0])
	{
		copy_format(&copy, format_tab);
		if (ft_loophole(copy, list_tmp, tab[i], dim[1]) == -1)
		{
			free_format(format);
			return (lst_dellall(list_tmp));
		}
		i++;
	}
	free_format(format_tab);
	return (1);
}

static	int		add_list_tmp(t_list **list_tmp, t_list **list)
{
	int		is_err;
	t_list	*bubble;
	char	*str;

	bubble = *list_tmp;
	while (bubble != NULL && is_err != -1)
	{
		str = ft_strdup(bubble->content);
		is_err = lst_addback(list, &str, bubble->len);
		if (is_err == -1)
			return (-1);
		bubble = bubble->next;
	}
	if (is_err == -1)
		return (lst_dellall(list_tmp));
	lst_dellall(list_tmp);
	return (1);
}

int				ft_conv_d_matdll(t_format *format, va_list ap, t_list **list)
{
	long long	**nb_tab;
	int			dim[2];
	t_list		*list_tmp;

	nb_tab = va_arg(ap, long long **);
	dim[0] = va_arg(ap, int);
	dim[1] = va_arg(ap, int);
	list_tmp = NULL;
	if (make_list_tmp(format, nb_tab, dim, &list_tmp) == -1)
		return (lst_dellall(list));
	free_format(format);
	if (add_list_tmp(&list_tmp, list) == -1)
		return (lst_dellall(list));
	return (1);
}
