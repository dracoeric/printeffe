/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/22 16:23:35 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_conv_c(t_format *format, va_list ap)
{
	unsigned char	*str;
	int				nb_spaces;
	int				len;
	char			c;

	c = (unsigned char)va_arg(ap, int);
	nb_spaces = format->m_width - 1;
	len = (nb_spaces < 0 ? 0 : nb_spaces);
	if (!(str = (unsigned char *)ft_memalloc(sizeof(unsigned char)
		* (len + 2), 32)))
	{
		free_format(format);
		return (-1);
	}
	if (format->minus)
		str[0] = c;
	else
		str[len] = c;
	str[len + 1] = '\0';
	free_format(format);
	if (c == 0)
		return (1 + write_free(1, (char **)(&str), ft_strlen((char *)str)));
	return (write_free(1, (char **)(&str), ft_strlen((char *)str)));
}
