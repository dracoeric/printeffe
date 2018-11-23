/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/23 12:47:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static	char	*make_str(t_format *format, unsigned long nb,
					unsigned long *pow, int *num_len)
{
	char	*str;
	int		len;

	*pow = 1;
	*num_len = 1;
	while (nb / *pow >= 16)
	{
		*pow *= 16;
		*num_len = *num_len + 1;
	}
	len = (format->precision > *num_len ? format->precision : *num_len);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1), 32)))
		return (0);
	str[len] = '\0';
	return (str);
}

static	char	*ft_itoa_long_long(t_format *format, unsigned long nb,
					char *base)
{
	int				num_len;
	unsigned long	pow;
	char			*str;
	int				i;
	int				len;

	if (!(str = make_str(format, nb, &pow, &num_len)))
		return (0);
	i = 0;
	len = ft_strlen(str);
	while (i < len - num_len)
	{
		str[i] = '0';
		i++;
	}
	while (pow != 0)
	{
		str[i] = base[nb / pow];
		nb = nb % pow;
		pow /= 16;
		i++;
	}
	return (str);
}

static	char	*add_width(const t_format *format, char **str)
{
	char	*str_add;
	int		nb_spaces;
	int		len;
	char	*sign;

	if (*str == NULL)
		return (0);
	nb_spaces = format->m_width - ft_strlen(*str) - 2;
	len = (nb_spaces < 0 ? 0 : nb_spaces);
	str_add = (char *)ft_memalloc(sizeof(char) * (len + 1), 32);
	if (str_add == NULL)
		return (0);
	str_add[len] = '\0';
	sign = "0x";
	if (!(*str = ft_strjoinfree(&sign, str, 2)))
		return (NULL);
	if (format->minus)
		*str = ft_strjoinfree(str, &str_add, 3);
	else
		*str = ft_strjoinfree(&str_add, str, 3);
	return (*str);
}

int				ft_conv_p(t_format *format, va_list ap)
{
	unsigned long	nb;
	char			*str;
	char			*old;

	nb = (unsigned long)va_arg(ap, void*);
	str = ft_itoa_long_long(format, nb, "0123456789abcdef");
	old = str;
	if (format->precision > 0 && format->precision > ft_strlen(str))
		str = ft_strsub(str, 0, format->precision - 1);
	else if (format->precision == 0)
		str = ft_memalloc(1, 0);
	else
		str = ft_strsub(str, 0, ft_strlen(str));
	free(old);
	if (!(str = add_width(format, &str)))
	{
		free_format(format);
		return (-1);
	}
	free_format(format);
	return (write_free(1, &str, ft_strlen(str)));
}
