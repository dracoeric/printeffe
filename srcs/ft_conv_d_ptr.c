/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_prt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/27 15:31:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int				max_width(const t_format *format, long long *tab, int len)
{
	int			width;
	long long	pow;
	int			i;
	int			max;

	i = 0;
	max = 0;
	while (i < len)
	{
		pow = 1;
		width = 0;
		while (tab[i] / pow != 0)
		{
			pow *= 10;
			width++;
		}
		if (width > max)
			max = width;
		i++;
	}
	return (format->m_width > max ? format->m_width : max);
}

int				ft_loophole(t_format *format, t_list **list, ...)
{
	va_list		ap;
	t_converter	fun;
	int			is_error;

	va_start(ap, list);
	is_error = 0;
	is_error = get_converter(format, &fun);
	if (is_error == -1)
	{
		free_format(format);
		return (lst_dellall(list));
	}
	is_error = fun(format, ap, list);
	return (is_error);
}

int				make_list_tmp(t_format *format, long long *tab, int len,
					t_list **list_tmp)
{
	t_format	*format_tab;
	int			i;

	i = 0;
	if (len < 0 || !(copy_format(&format_tab, format) == -1))
	{
		free_format(format);
		return (lst_dellall(list_tmp));
	}
	format_tab->pointer = 0;
	format_tab->data_format_modifier[0] = 'l';
	format_tab->data_format_modifier[1] = 'l';
	format_tab->m_width = max_width(format, tab, len);
	while (i < len)
	{
		if (ft_loophole(format_tab, list_tmp, tab[i]) == -1)
		{
			free_format(format);
			return (lst_dellall(list_tmp));
		}
	}
	free_format(format_tab);
	return (1);
}

int				add_list_tmp(t_list **list_tmp, t_list **list)
{
	int		n_per_line;
	char	*str;
	int		is_err;
	t_list	*bubble;
	int		i;

	n_per_line = (80 / (*list_tmp)->len == 0 ? 1 : 80 / (*list_tmp)->len);
	if (!(str = ft_strdup("\n{")))
		return (lst_dellall(list_tmp));
	is_err = lst_addback(list, &str, ft_strlen(str));
	if (is_err == -1)
		return (lst_dellall(list_tmp));
	bubble = *list_tmp;
	i = 0;
	while (bubble != NULL && is_err != -1)
	{
		is_err = lst_addback(list, &(bubble->content), bubble->len);
		i++;
		if (is_err == -1 || !(str = (i % n_per_line == 0 ? ft_strdup(", ") : ft_strdup(",\n "))))
			return (lst_dellall(list_tmp));
		if (bubble->next == NULL)
		{
			str[0] = '}';
			str[1] = '\n';
		}
		is_err = lst_addback(list, &str, ft_strlen(str));
		bubble = bubble->next;
	}
	if (is_err == -1)
		return (lst_dellall(list_tmp));
	lst_dellall(list_tmp);
	return (1);
}

int				ft_conv_d_ptr(t_format *format, va_list ap, t_list **list)
{
	long long	*nb_tab;
	int			len;
	t_list		*list_tmp;

	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		nb_tab = (long long *)va_arg(ap, long*);
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		nb_tab = va_arg(ap, long long*);
	else if (!ft_strncmp(format->data_format_modifier, "h", 2))
		nb_tab = (long long*)(short*)va_arg(ap, int*);
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		nb_tab = (long long*)(char*)va_arg(ap, int*);
	else
		nb_tab = (long long*)va_arg(ap, int*);
	len = va_arg(ap, int);
	list_tmp = NULL;
	if (make_list_tmp(format, nb_tab, len, &list_tmp) == -1)
		return (lst_dellall(list));
	free_format(format);
	if (add_list_tmp(&list_tmp, list) == -1)
		return (lst_dellall(list));
	return (1);
}
