/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/17 18:46:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static	int		max_power(long long nb, long long *pow)
{
	int i;

	i = 0;
	if (nb < 0)
		i++;
	if (nb <= -10)
	{
		i++;
		*pow = -10;
	}
	while (nb / *pow >= 10)
	{
		*pow *= 10;
		i++;
	}
	return (i);
}

static	char	*ft_itoa_long_long(long long nb)
{
	int			len;
	long long	pow;
	char		*str;

	pow = 1;
	if (nb < 0)
		pow = -1;
	len = max_power(nb, &pow);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	if (nb < 0)
	{
		str[0] = '-';
		len++;
	}
	while (pow != 0)
	{
		str[len] = nb / pow + '0';
		nb = nb % pow;
		pow /= 10;
		len++;
	}
	str[len] = '\0';
	return (str);
}

static	void	manage_width(t_format *format, char **str)
{



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
	if (!(str = ft_itoa_long_long(nb)))
		return (-1);
	return (write(1, str, ft_strlen(str)));
}
