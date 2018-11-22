/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:09:57 by erli              #+#    #+#             */
/*   Updated: 2018/11/22 17:51:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_con_tab.h"
#include <unistd.h>
#include <stdlib.h>

static	int		init_format(t_format **format)
{
	if (!(*format = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	(*format)->pound = 0;
	(*format)->plus = 0;
	(*format)->minus = 0;
	(*format)->zero = 0;
	(*format)->space = 0;
	(*format)->m_width = 0;
	(*format)->precision = -1;
	if (!((*format)->data_format_modifier = (char *)malloc(sizeof(char) * 3)))
		return (-1);
	(*format)->data_format_modifier[0] = '\0';
	(*format)->data_format_modifier[1] = '\0';
	(*format)->data_format_modifier[2] = '\0';
	(*format)->conversion = '\0';
	return (1);
}

static	int		get_converter(t_format *format, t_converter *fun)
{
	int		i;

	i = 0;
	while (g_conv_tab[i].symbol != 0)
	{
		if (g_conv_tab[i].symbol == format->conversion)
		{
			*fun = g_conv_tab[i].converter;
			return (1);
		}
		i++;
	}
	*fun = g_conv_tab[i].converter;
	return (1);
}

static	int		manage_dir(const char *format_str, int *i, va_list ap)
{
	t_format	*format;
	t_converter	fun;
	int			is_err;

	is_err = 0;
	format = NULL;
	is_err = init_format(&format);
	if (is_err == -1)
		return (-1);
	is_err = manage_format(format_str, &format, i);
	if (is_err == -1)
	{
		free_format(format);
		return (-1);
	}
	is_err = get_converter(format, &fun);
	if (is_err == -1)
		return (-1);
	return (fun(format, ap));
}

static	int		read_format_str(const char *format_str, va_list ap)
{
	int		i;
	int		ret;
	int		is_err;

	i = 0;
	ret = 0;
	is_err = 0;
	while (format_str[i] != '\0' && is_err >= 0)
	{
		while (format_str[i] != '%' && format_str[i] != '\0' && is_err >= 0)
		{
			is_err = write(1, &(format_str[i]), 1);
			ret += is_err;
			i++;
		}
		if (format_str[i] == '%' && is_err >= 0)
		{
			i++;
			is_err = manage_dir(format_str, &i, ap);
			ret += is_err;
		}
	}
	if (is_err < 0)
		return (-1);
	return (ret);
}

int				ft_printf(const char *format_str, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format_str);
	ret = read_format_str(format_str, ap);
	va_end(ap);
	return (ret);
}
