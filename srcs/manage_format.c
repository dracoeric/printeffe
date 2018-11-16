/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:33:20 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 11:34:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		char_in_str(char c, char *str)
{
	while (*str != '\0' && c != *str)
		str++;
	return (c == *str);
}

static	void	get_flags(const char *format_str, t_format *format, int *i)
{
	while (char_in_str(format_str[*i], "#0+- "))
	{
		if (format_str[*i] == '#')
			format->pound = 1;
		if (format_str[*i] == '+')
			format->plus = 1;
		if (format_str[*i] == '-')
			format->minus = 1;
		if (format_str[*i] == '0')
			format->zero = 1;
		if (format_str[*i] == ' ')
			format->space = 1;
		*i = *i + 1;
	}
}

static	int		ft_simple_atoi(const char *format_str, int *i, int j)
{
	int nb;

	nb = 0;
	while (format_str[*i] >= '0' && format_str[*i] <= '9' && *i < j)
	{
		nb = 10 * nb + (format_str[*i] + '0');
		*i = *i + 1;
	}
	return (nb);
}

static	void	get_len_modifier(const char *format_str, t_format *format, int *i)
{
	if (char_in_str(format_str[*i], LEGAL_MOD))
	{
		format->data_format_modifier[0] = format_str[*i];
		if (format_str[*i] == format_str[*i + 1] && (format_str[*i] == 'h'
			 || format_str[*i] == 'l'))
		{
			format->data_format_modifier[1] = format_str[*i];
			*i = *i + 1;
		}
		*i = *i + 1;
	}
}

int				manage_format(const char *format_str, t_format *format, int *i)
{
	int len;	
	int j;

	get_flags(format_str, format, i);
	j = *i;
	while (format_str[j] >= '0' && format_str[j] <= '9')
		j++;
	len = ft_simple_atoi(format_str, i, j);
	format->m_width = len;
	if (format_str[*i] == '.')
		*i = *i + 1;
	j = *i;
	while (format_str[j] >= '0' && format_str[j] <= '9')
		j++;
	len = ft_simple_atoi(format_str, i, j);
	format->precision = len;
	get_len_modifier(format_str, format, i);
	if (char_in_str(format_str[*i], LEGAL_CONV))
	{
		format->conversion = format_str[*i];
		*i = *i + 1;
	}
	else
		return (-1);
	return (0);
}
