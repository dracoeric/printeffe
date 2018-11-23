/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/23 12:55:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static	char	*add_width(t_format *format, char c, int *len)
{
	int		nb_spaces;
	int		i;
	char	*str;

	nb_spaces = format->m_width - 1;
	*len = (nb_spaces < 0 ? 0 : nb_spaces);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (*len + 2), 32)))
		return (NULL);
	i = 0;
	if (format->minus)
	{
		str[0] = c;
		i++;
	}
	else
		str[*len] = c;
	while (i < nb_spaces)
	{
		str[i] = (format->zero ? '0' : ' ');
		i++;
	}
	str[*len + 1] = '\0';
	return (str);
}

int				ft_conv_not(t_format *format, va_list ap)
{
	char	*str;
	char	c;
	int		len;

	if (ap != NULL)
		;
	c = format->conversion;
	str = add_width(format, c, &len);
	if (str == NULL)
	{
		free_format(format);
		return (-1);
	}
	free_format(format);
	return (write_free(1, &str, ft_strlen(str)));
}