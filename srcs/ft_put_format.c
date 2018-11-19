/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:02:39 by erli              #+#    #+#             */
/*   Updated: 2018/11/19 17:08:52 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_put_format(t_format *format)
{
	printf("%-15s%-15hhu\n", "pound :", format->pound);
	printf("%-15s%-15hhu\n", "plus :", format->plus);
	printf("%-15s%-15hhu\n", "minus :", format->minus);
	printf("%-15s%-15hhu\n", "zero :", format->zero);
	printf("%-15s%-15hhu\n", "space :", format->space);
	printf("%-15s%-15d\n", "m_width :", format->m_width);
	printf("%-15s%-15d\n", "precision :", format->precision);
	printf("%-15s%-15s\n", "Len mod :", format->data_format_modifier);
	printf("%-15s%-15c\n", "conversion :", format->conversion);
}
