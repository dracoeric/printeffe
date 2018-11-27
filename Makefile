#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 17:45:59 by erli              #+#    #+#              #
#    Updated: 2018/11/27 18:40:01 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		test

SRCSDIR		=		srcs

OBJSDIR		=		objs

SRCS		=		ft_printf.c		ft_conv_d.c		ft_put_format.c		\
					ft_conv_not.c	ft_util.c		ft_list_manip.c		\
					manage_format.c	ft_conv_o.c		ft_free_format.c	\
					ft_util2.c		ft_conv_u.c		ft_conv_x.c			\
					ft_conv_big_x.c	ft_conv_c.c		ft_conv_s.c			\
					ft_conv_p.c		ft_conv_f.c		ft_conv_percent.c	\
					ft_conv_e.c		ft_conv_big_e.c	ft_conv_g.c			\
					ft_conv_tab.c	ft_strdup.c		init_format.c		\
					get_converter.c	ft_conv_d_ptrd.c					\
					ft_loophole.c	ft_conv_d_ptrdhh.c					\
					ft_conv_d_ptrdl.c				ft_conv_d_ptrdll.c	\
					ft_conv_d_ptrdh.c				ft_conv_o_ptro.c	\
					ft_conv_o_ptroh.c				ft_conv_o_ptrol.c	\
					ft_conv_o_ptrohh.c				ft_conv_o_ptroll.c	\
					ft_conv_f_ptrfl.c				ft_conv_f_ptrfbigl.c\
					ft_conv_e_ptrel.c				ft_conv_e_ptrebigl.c\
					ft_conv_g_ptrgl.c				ft_conv_g_ptrgbigl.c\
					ft_conv_s_ptrs.c				ft_conv_p_ptrp.c	\
					ft_conv_c_ptrc.c	\
					main.c

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/

RM			=		rm -f


all			:		$(NAME)

$(NAME)		:		$(OBJS) includes/ft_printf.h includes/ft_con_tab.h
					$(CC) $(CFLAG) $(INCL) -o  $(NAME) $(OBJS)

$(OBJSDIR)/%.o			:		$(SRCSDIR)/%.c
					@mkdir -p $(OBJSDIR)
					$(CC) $(CFLAG) $(INCL) -c $< -o $@

val			:		$(OBJS) includes/ft_printf.h
					$(CC) -g $(CFLAG) $(INCL) -o  $(NAME) $(OBJS)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all

delsav		:
					$(RM) */*~
					$(RM) *~
					$(RM) \#*\#
					$(RM) */\#*\#

reset		:		delsav fclean

.PHONY		:		clean delsav