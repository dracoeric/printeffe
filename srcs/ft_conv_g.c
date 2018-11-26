/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:28:08 by erli              #+#    #+#             */
/*   Updated: 2018/11/26 17:41:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static	int		find_expo(long double nb)
{
	double long	pow;
	int			expo;

	pow = 1;
	expo = 0;
	if (nb < 0)
		pow = -1;
	if (nb < -10 && expo++ == 0)
		pow = -10;
	while ((pow * nb < 1 || nb / pow > 10) && nb != 0)
	{
		pow *= 10;
		expo++;
	}
	if (nb < 1 && nb > -1)
		expo *= -1;
	return (expo);
}

static	void	remove_zeros(t_list **list, char c)
{
	t_list	*bubble;
	int		len;
	int		offset;
	int		i;

	if (list == NULL || *list == NULL)
		return ;
	bubble = *list;
	while (bubble->next != NULL)
		bubble = bubble->next;
	len = bubble->len;
	offset = (c == 'e' ? 5 : 1);
	while ((bubble->content)[len - offset] == '0' && len - offset > 0)
		len--;
	i = 1;
	if ((bubble->content)[len - offset] == '.')
		len--;
	while (i <= offset)
	{
		(bubble->content)[len - offset + i] = (bubble->content)
			[ft_strlen((bubble->content)) - offset + i];
		i++;
	}
	bubble->len = len;
}

int				ft_conv_g(t_format *format, va_list ap, t_list **list)
{
	long double	nb;
	int			expo;
	va_list		copy;
	int			ret;

	va_copy(copy, ap);
	if (!ft_strncmp(format->data_format_modifier, "L", 2))
		nb = va_arg(copy, long double);
	else
		nb = (long double)va_arg(copy, double);
	expo = find_expo(nb);
	va_end(copy);
	if (expo < -4 || expo >= (format->precision == -1 ? 6 : format->precision))
	{
		format->precision = (format->precision == 0 ? 0
			: format->precision - 1);
		ret = ft_conv_e(format, ap, list);
		remove_zeros(list, 'e');
		return (ret);
	}
	format->precision = (format->precision == 0 ? 0 : format->precision - 1);
	ret = ft_conv_f(format, ap, list);
	remove_zeros(list, 'f');
	return (ret);
}
