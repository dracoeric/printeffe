/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 12:11:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		print_d_int(const t_format *format, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if (format != 0)
		return (-1);
	return (n);
}

int		ft_conv_d(const t_format *format, va_list ap)
{
/*	if (ft_strncmp(format->data_format_modifier, "l", 2))
		return (print_d_long(format, ap));
	if (ft_strncmp(format->data_format_modifier, "ll", 2))
		return (print_d_longlong(format, ap));
	if (ft_strncmp(format->data_format_modifier, "h", 2))
		return (print_d_shot(format, ap));
	if (ft_strncmp(format->data_format_modifier, "hh", 2))
	return (print_d_signed_char(format, ap));*/
	if (ft_strncmp(format->data_format_modifier, "\0\0", 2))
		return (print_d_int(format, ap));
	return (-1);
}
