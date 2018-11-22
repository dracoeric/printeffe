/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:03:26 by erli              #+#    #+#             */
/*   Updated: 2018/11/22 16:31:00 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_conv_not(t_format *format, va_list ap)
{
	char c;

	if (ap == NULL)
		;
	c = format->conversion;
	free_format(format);
	return (write(1, &c, 1));
}
