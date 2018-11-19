/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/19 11:57:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static	char	*make_str(const t_format *format, long long nb, long long *pow,
					int *num_len)
{
	char	*str;
	int		str_len;

	*pow = 1;
	if (nb < 0)
		*pow = -1;
	*num_len = 0;
	if (nb <= -10)
	{
		*num_len =*num_len + 1;
		*pow = -10;
	}
	while (nb / *pow >= 10)
	{
		*pow *= 10;
		*num_len = *num_len +1;
	}
	str_len = (format->precision > *num_len ? format->precision : *num_len);
	if (nb < 0 || format->plus || format->space)
		str_len++;
	if (!(str = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	return (str);
}

static	char	*ft_itoa_long_long(const t_format *format, long long nb)
{
	int			num_len;
	long long	pow;
	char		*str;
	int 		i;
	int			str_len;

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
		str[i] = nb / pow + '0';
		nb = nb % pow;
		pow /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	char 	*add_width(const t_format *format, char **str)
{
	char	*str_add;
	char	*old;
	int		nb_spaces;
	int		i;

	if (*str == NULL)
		return (0);
	old = *str;
	nb_spaces = format->m_width - (ft_strlen(*str) +
		format->space + format->plus);
	printf("nb_spaces = %d\n", nb_spaces);
	if (nb_spaces > 0)
	{
		if (!(str_add = (char *)malloc(sizeof(char) * nb_spaces)))
			return (0);
		i = 0;
		while (i < nb_spaces)
		{
			str_add[i] = ((10 * format->precision + format->zero == 1) ? '0' : ' ');
			i++;
		}
		str_add[i] = '\0';
		if (format->minus)
			*str = ft_strjoin(*str, str_add);
		else
			*str = ft_strjoin(str_add, *str);
		if (*str == NULL)
			return (0);
		free(old);
		free(str_add);
	}
	return (*str);
}

int				ft_conv_d(const t_format *format, va_list ap)
{
	long long	nb;
	char		*str;

	if (!ft_strncmp(format->data_format_modifier, "l", 2))
		nb = (long long)va_arg(ap, long);
	else if (!ft_strncmp(format->data_format_modifier, "ll", 2))
		nb = va_arg(ap, long long);
	else if (!ft_strncmp(format->data_format_modifier, "h", 2))
		nb = (long long)va_arg(ap, int);
	else if (!ft_strncmp(format->data_format_modifier, "hh", 2))
		nb = (long long)va_arg(ap, int);
	else
		nb = (long long)va_arg(ap, int);
	str = ft_itoa_long_long(format, nb);
	str = add_width(format, &str);
	return (write(1, str, ft_strlen(str)));
}
