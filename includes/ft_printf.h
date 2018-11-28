/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2018/11/28 13:15:38 by erli             ###   ########.fr       */
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
	unsigned char	pointer;
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

typedef	int		(*t_converter)(t_format *, va_list, t_list **);

typedef struct	s_conv
{
	char		symbol;
	t_converter converter;
}				t_conv;

int				init_format(t_format **format);
int				copy_format(t_format **format, t_format *source);
int				get_converter(t_format *format, t_converter *fun);
t_list			*lst_create(char **cont, int len);
int				lst_addback(t_list **list, char **cont, int len);
int				lst_dellall(t_list **list);
int				lst_len(t_list *list);
t_list			*lst_extract(t_list **list, int n);
int				lst_unload(t_list **list);
int				char_in_str(char c, char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinfree(char **s1, char **s2, int n);
void			*ft_memalloc(size_t n, int c);
int				write_free(int fd, char **str, size_t n);
char			*ft_strdup(char *src);
void			free_format(t_format *format);
char			*ft_strsub(char *str, size_t begin, size_t end);
void			ft_round_up(char **str, int rest, char c, int i);
void			ft_round_up_slide(char **str);
int				ft_loophole(t_format *format, t_list **list, ...);
int				ft_conv_d(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_ptr(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_ptrd(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_ptrdh(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_ptrdhh(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_ptrdl(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_ptrdll(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_ptroll(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_ptrol(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_ptrohh(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_ptroh(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_ptro(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_ptr(t_format *format, va_list ap, t_list **list);
int				ft_conv_f_ptr(t_format *format, va_list ap, t_list **list);
int				ft_conv_f_ptrfl(t_format *format, va_list ap, t_list **list);
int				ft_conv_f_ptrfbigl(t_format *format, va_list ap, t_list **list);
int				ft_conv_e_ptr(t_format *format, va_list ap, t_list **list);
int				ft_conv_e_ptrel(t_format *format, va_list ap, t_list **list);
int				ft_conv_e_ptrebigl(t_format *format, va_list ap, t_list **list);
int				ft_conv_g_ptr(t_format *format, va_list ap, t_list **list);
int				ft_conv_g_ptrgl(t_format *format, va_list ap, t_list **list);
int				ft_conv_g_ptrgbigl(t_format *format, va_list ap, t_list **list);
int				ft_conv_c_ptrc(t_format *format, va_list ap, t_list **list);
int				ft_conv_s_ptrs(t_format *format, va_list ap, t_list **list);
int				ft_conv_p_ptrp(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_mat(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_matd(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_matdh(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_matdhh(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_matdl(t_format *format, va_list ap, t_list **list);
int				ft_conv_d_matdll(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_mat(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_mato(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_matoh(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_matohh(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_matol(t_format *format, va_list ap, t_list **list);
int				ft_conv_o_matoll(t_format *format, va_list ap, t_list **list);
int				ft_conv_f_mat(t_format *format, va_list ap, t_list **list);
int				ft_conv_f_matfl(t_format *format, va_list ap, t_list **list);
int				ft_conv_f_matfbigl(t_format *format, va_list ap, t_list **list);
int				ft_conv_c_matc(t_format *format, va_list ap, t_list **list);
int				ft_conv_s_mats(t_format *format, va_list ap, t_list **list);
int				ft_conv_p_matp(t_format *format, va_list ap, t_list **list);
int				ft_conv_o(t_format *format, va_list ap, t_list **list);
int				ft_conv_u(t_format *format, va_list ap, t_list **list);
int				ft_conv_x(t_format *format, va_list ap, t_list **list);
int				ft_conv_big_x(t_format *format, va_list ap, t_list **list);
int				ft_conv_c(t_format *format, va_list ap, t_list **list);
int				ft_conv_s(t_format *format, va_list ap, t_list **list);
int				ft_conv_p(t_format *format, va_list ap, t_list **list);
int				ft_conv_f(t_format *format, va_list ap, t_list **list);
int				ft_conv_e(t_format *format, va_list ap, t_list **list);
int				ft_conv_big_e(t_format *format, va_list ap, t_list **list);
int				ft_conv_g(t_format *format, va_list ap, t_list **list);
int				ft_conv_percent(t_format *format, va_list ap, t_list **list);
int				ft_conv_not(t_format *format, va_list ap, t_list **list);
int				ft_printf(const char *format_str, ...);
int				manage_format(const char *format_str, t_format **format,
					int *i, va_list ap);
void			ft_put_format(t_format *format);

#endif
