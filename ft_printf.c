/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:09:57 by erli              #+#    #+#             */
/*   Updated: 2018/11/14 17:27:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		manage_dir(const restrict char *format, va_arg ap, int *i)
{
	


}

int		ft_printf(const restrict char *format, ...)
{
	int i;
	int ret;
	int is_err;
	va_arg ap;

	i = 0;
	ret = 0;
	is_err = 0;
	va_start(ap, format);
	while (format[i] != '\0' && is_err >= 0)
	{
		while (format[i] != '%' && format[i] = '\0'	&& is_err >= 0)
		{
			is_err = write(1, &(format[i]), 1);
			ret += is_err;
			i++;
		}
		is_err = manage_dir(format, ap, &i);
		ret += is_err;
	}
	va_end(ap);
	if (is_err < 0)
		return (-1);
	return (ret);
}
