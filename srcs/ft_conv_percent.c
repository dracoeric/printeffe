/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:29:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/23 16:50:00 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static	char	**join_width(const t_format *format, char **str, char **str_add)
{
	if (format->minus)
		*str = ft_strjoinfree(str, str_add, 3);
	else
		*str = ft_strjoinfree(str_add, str, 3);
	return (str);
}

static	char	*add_width(const t_format *format, char **str)
{
	char	*str_add;
	int		nb_spaces;
	int		i;

	if (*str == NULL)
		return (0);
	nb_spaces = format->m_width - ft_strlen(*str);
	if (nb_spaces > 0)
		str_add = (char *)malloc(sizeof(char) * (nb_spaces + 1));
	else
		str_add = (char *)ft_memalloc(sizeof(char) * 1, 0);
	if (str_add == NULL)
		return (0);
	i = 0;
	while (i < nb_spaces)
	{
		str_add[i] = (((10 * format->precision + format->zero == -9)
			|| (10 * format->precision + format->zero == 1)) ? '0' : ' ');
		i++;
	}
	str_add[i] = '\0';
	str = join_width(format, str, &str_add);
	return (*str);
}

int				ft_conv_percent(t_format *format, va_list ap, t_list **list)
{
	char	*str;

	if (ap == NULL)
		return (0);
	if (!(str = ft_memalloc(2, 0)))
		return (lst_dellall(list));
	str[0] = '%';
	if (!(str = add_width(format, &str)))
	{
		free_format(format);
		return (lst_dellall(list));
	}
	free_format(format);
	return (lst_addback(list, &str, ft_strlen(str)));
}
