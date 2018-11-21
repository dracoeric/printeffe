/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 15:33:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_conv_c(t_format *format, va_list ap)
{
	unsigned char	*str;
	int				nb_spaces;
	int				len;

	nb_spaces = format->m_width - 1;
	len = (nb_spaces < 0 ? 0 : nb_spaces);
	if (!(str = (unsigned char *)ft_memalloc(sizeof(unsigned char)
		* (len + 2), 32)))
		return (-1);
	if (format->minus)
		str[0] = (unsigned char)va_arg(ap, int);
	else
		str[len] = (unsigned char)va_arg(ap, int);
	str[len + 1] = '\0';
	free_format(format);
	return (write_free(1, (char **)(&str), ft_strlen((char *)str)));
}
