/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 09:31:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>



#include <stdio.h>



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

int				char_in_str(char c, char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinfree(char **s1, char **s2, int n);
void			*ft_memalloc(size_t n, int c);
int				write_free(int fd, char **str, size_t n);
void			free_format(t_format *format);
int				ft_conv_d(t_format *format, va_list ap);
int				ft_conv_o(t_format *format, va_list ap);
int				ft_conv_u(t_format *format, va_list ap);
int				ft_usage(t_format *format, va_list ap);
int				ft_printf(const char *format_str, ...);
int				manage_format(const char *format_str, t_format **format, int *i);


void			ft_put_format(t_format *format);


typedef	int		(*t_converter)(t_format *, va_list);
typedef struct	s_conv
{
	char		symbol;
	t_converter converter;
}				t_conv;

#endif
