/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 15:33:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_conv_s(t_format *format, va_list ap)
{
	char	*str;
	char	*str_arg;
	int		nb_spaces;
	int		len;

	str_arg = va_arg(ap, char*);
	if (format->precision > 0)
		str_arg = ft_strsub(str_arg, 0, format->precision - 1);
	else
		str_arg = ft_strsub(str_arg, 0, ft_strlen(str_arg));
	nb_spaces = format->m_width - ft_strlen(str_arg);
	len = (nb_spaces < 0 ? 0 : nb_spaces);
	if (!(str = (char *)ft_memalloc(sizeof(unsigned char) * (len + 1), 32)))
		return (-1);
	str[len] = '\0';
	if (format->minus)
		str = ft_strjoinfree(&str_arg, &str, 3);
	else
		str = ft_strjoinfree(&str, &str_arg, 3);
	free_format(format);
	if (str == NULL)
		return (0);
	return (write_free(1, (char **)(&str), ft_strlen((char *)str)));
}
