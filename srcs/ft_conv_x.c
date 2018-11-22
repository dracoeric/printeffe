/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 13:54:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static	char	*make_str(const t_format *format, unsigned long long nb,
					unsigned long long *pow, int *num_len)
{
	char	*str;
	int		str_len;

	*pow = 1;
	*num_len = 1;
	while (nb / *pow >= 16)
	{
		*pow *= 16;
		*num_len = *num_len + 1;
	}
	str_len = (format->precision > *num_len ? format->precision : *num_len);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (str_len + 1), 32)))
		return (0);
	str[str_len] = '\0';
	return (str);
}

static	char	*ft_itoa_long_long(const t_format *format,
					unsigned long long nb, char *base)
{
	int					num_len;
	unsigned long long	pow;
	char				*str;
	int					i;
	int					str_len;

	if (!(str = make_str(format, nb, &pow, &num_len)))
		return (0);
	i = 0;
	str_len = ft_strlen(str);
	while (i < str_len - num_len)
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
	str[i] = '\0';
	return (str);
}

static	char	*join_width(const t_format *format, char **str, char **str_add)
{
	char	*sign;

	sign = NULL;
	if (format->pound)
		sign = "0x";
	if ((*str_add)[0] == '0')
	{
		if (!(*str_add = ft_strjoinfree(&sign, str_add, 2)))
			return (NULL);
		*str = ft_strjoinfree(str_add, str, 3);
	}
	else
	{
		if (!(*str = ft_strjoinfree(&sign, str, 2)))
			return (NULL);
		if (format->minus)
			*str = ft_strjoinfree(str, str_add, 3);
		else
			*str = ft_strjoinfree(str_add, str, 3);
	}
	return (*str);
}

static	char	*add_width(const t_format *format, char **str)
{
	char	*str_add;
	int		nb_spaces;
	int		i;

	if (*str == NULL)
		return (0);
	nb_spaces = format->m_width - ft_strlen(*str) - 2 * (format->pound);
	if (nb_spaces > 0)
		str_add = (char *)malloc(sizeof(char) * (nb_spaces + 1));
	else
		str_add = (char *)ft_memalloc(sizeof(char) * 1, 0);
	if (str_add == NULL)
		return (0);
	i = 0;
	while (i < nb_spaces)
	{
		str_add[i] = ((10 * format->precision + format->zero == 1)
			? '0' : ' ');
		i++;
	}
	str_add[i] = '\0';
	*str = join_width(format, str, &str_add);
	return (*str);
}

int				ft_conv_x(t_format *format, va_list ap)
{
	unsigned long long	nb;
	char				*str;

	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		nb = (unsigned long long)va_arg(ap, long);
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		nb = (unsigned long long)va_arg(ap, long long);
	else if (!ft_strncmp(format->data_format_modifier, "h", 2))
		nb = (unsigned long long)va_arg(ap, int);
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		nb = (unsigned long long)va_arg(ap, int);
	else
		nb = (unsigned long long)va_arg(ap, int);
	str = ft_itoa_long_long(format, nb, "0123456789abcdef");
	if (!(str = add_width(format, &str)))
	{
		free_format(format);
		return (-1);
	}
	free_format(format);
	return (write_free(1, &str, ft_strlen(str)));
}