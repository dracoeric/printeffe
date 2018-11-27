/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_prt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/27 17:17:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_d_ptr(t_format *format, va_list ap, t_list **list)
{
	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		return (ft_conv_d_ptrdl(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		return (ft_conv_d_ptrdll(format, ap, list));
	if (!ft_strncmp(format->data_format_modifier, "h", 2))
		return (ft_conv_d_ptrdh(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		return (ft_conv_d_ptrdhh(format, ap, list));
	else
		return (ft_conv_d_ptrd(format, ap, list));
	return (0);
}

int				ft_conv_o_ptr(t_format *format, va_list ap, t_list **list)
{
	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		return (ft_conv_d_ptrdl(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		return (ft_conv_d_ptrdll(format, ap, list));
	if (!ft_strncmp(format->data_format_modifier, "h", 2))
		return (ft_conv_d_ptrdh(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		return (ft_conv_d_ptrdhh(format, ap, list));
	else
		return (ft_conv_d_ptrd(format, ap, list));
	return (0);
}
/*
int				ft_conv_u_ptr(t_format *format, va_list ap, t_list **list)
{
	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		return (ft_conv_d_ptrdl(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		return (ft_conv_d_ptrdll(format, ap, list));
	if (!ft_strncmp(format->data_format_modifier, "h", 2))
		return (ft_conv_d_ptrdh(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		return (ft_conv_d_ptrdhh(format, ap, list));
	else
		return (ft_conv_d_ptrd(format, ap, list));
	return (0);
}

int				ft_conv_x_ptr(t_format *format, va_list ap, t_list **list)
{
	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		return (ft_conv_d_ptrdl(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		return (ft_conv_d_ptrdll(format, ap, list));
	if (!ft_strncmp(format->data_format_modifier, "h", 2))
		return (ft_conv_d_ptrdh(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		return (ft_conv_d_ptrdhh(format, ap, list));
	else
		return (ft_conv_d_ptrd(format, ap, list));
	return (0);
}

int				ft_conv_big_x_ptr(t_format *format, va_list ap, t_list **list)
{
	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		return (ft_conv_d_ptrdl(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		return (ft_conv_d_ptrdll(format, ap, list));
	if (!ft_strncmp(format->data_format_modifier, "h", 2))
		return (ft_conv_d_ptrdh(format, ap, list));
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		return (ft_conv_d_ptrdhh(format, ap, list));
	else
		return (ft_conv_d_ptrd(format, ap, list));
	return (0);
}
*/
