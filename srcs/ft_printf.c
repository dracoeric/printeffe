/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:09:57 by erli              #+#    #+#             */
/*   Updated: 2018/11/14 18:45:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		manage_dir(const char *restrict format_str, va_list ap, int *i)
{
	t_format *format;

	format = manage_format(format_str, &i);
	
	return (0);
}

int		ft_printf(const char *restrict format_str, ...)
{
	int i;
	int ret;
	int is_err;
	va_list ap;

	i = 0;
	ret = 0;
	is_err = 0;
	va_start(ap, format);
	while (format_str[i] != '\0' && is_err >= 0)
	{
		while (format_str[i] != '%' && format_str[i] = '\0'	&& is_err >= 0)
		{
			is_err = write(1, &(format_str[i]), 1);
			ret += is_err;
			i++;
		}
		is_err = manage_dir(format, ap, &i);
		ret += is_err;
	}
	va_end(ap);
	if (is_err < 0)
		return (-1);
	return (ret);
}
