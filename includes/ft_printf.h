/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2018/11/26 16:18:35 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

# include <stdio.h>

# define LEGAL_MOD "jzlhL"
# define LEGAL_CONV "diouxXcspf%egbr"

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

typedef	struct	s_list
{
	char			*content;
	int				len;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list			*lst_create(char **cont, int len);
int				lst_addback(t_list **list, char **cont, int len);
int				lst_dellall(t_list **list);
int				lst_len(t_list *list);
int				lst_unload(t_list **list);
int				char_in_str(char c, char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinfree(char **s1, char **s2, int n);
void			*ft_memalloc(size_t n, int c);
int				write_free(int fd, char **str, size_t n);
void			free_format(t_format *format);
char			*ft_strsub(char *str, size_t begin, size_t end);
void			ft_round_up(char **str, int rest, char c, int i);
void			ft_round_up_slide(char **str);
int				ft_conv_d(t_format *format, va_list ap, t_list **list);
int				ft_conv_o(t_format *format, va_list ap, t_list **list);
int				ft_conv_u(t_format *format, va_list ap, t_list **list);
int				ft_conv_x(t_format *format, va_list ap, t_list **list);
int				ft_conv_big_x(t_format *format, va_list ap, t_list **list);
int				ft_conv_c(t_format *format, va_list ap, t_list **list);
int				ft_conv_s(t_format *format, va_list ap, t_list **list);
int				ft_conv_p(t_format *format, va_list ap, t_list **list);
int				ft_conv_f(t_format *format, va_list ap, t_list **list);
int				ft_conv_e(t_format *format, va_list ap, t_list **list);
int				ft_conv_percent(t_format *format, va_list ap, t_list **list);
int				ft_conv_not(t_format *format, va_list ap, t_list **list);
int				ft_printf(const char *format_str, ...);
int				manage_format(const char *format_str, t_format **format,
					int *i);

void			ft_put_format(t_format *format);

typedef	int		(*t_converter)(t_format *, va_list, t_list **);
typedef struct	s_conv
{
	char		symbol;
	t_converter converter;
}				t_conv;

#endif
