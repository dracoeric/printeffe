/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2018/11/14 18:42:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct	s_format
{
	unsigned char	pound;
	unsigned char	plus;
	unsigned char	minus;
	unsigned char	zero;
	int				m_width;
	unsigned char	precision;
	char			*data_format_modifier;
	char			conversion;
}				t_format;

int				ft_conv_d(const t_format *format, va_list ap);
void			ft_printf(const char *restrict format, ...);

typedef	int		(*t_converter)(const t_format *, va_list);
typedef struct	s_conv
{
	char		*symbol;
	t_converter converter;
}				t_conv;

t_conv			conv_tab[] =
{
	{"d", &ft_conv_d}
};
#endif
