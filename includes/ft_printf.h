/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 11:48:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

# define LEGAL_MOD "lhL"
# define LEGAL_CONV "diouxXcspfegbr"

typedef	struct	s_format
{
	unsigned char	pound;
	unsigned char	plus;
	unsigned char	minus;
	unsigned char	zero;
	unsigned char	space;
	int				m_width;
	int				precision;
	char			*data_format_modifier;
	char			conversion;
}				t_format;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
int				ft_conv_d(const t_format *format, va_list ap);
int				ft_usage(const t_format *foirmat, va_list ap);
int				ft_printf(const char *format_str, ...);
int				manage_format(const char *format_str, t_format *format, int *i);

typedef	int		(*t_converter)(const t_format *, va_list);
typedef struct	s_conv
{
	char		symbol;
	t_converter converter;
}				t_conv;

#endif
