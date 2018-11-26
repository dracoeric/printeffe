#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 17:45:59 by erli              #+#    #+#              #
#    Updated: 2018/11/26 16:29:02 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		libftprintf.a

SRCSDIR		=		srcs

OBJSDIR		=		objs

SRCS		=		ft_printf.c		ft_conv_d.c		ft_put_format.c		\
					ft_conv_not.c	ft_util.c		ft_list_manip.c		\
					manage_format.c	ft_conv_o.c		ft_free_format.c	\
					ft_util2.c		ft_conv_u.c		ft_conv_x.c			\
					ft_conv_big_x.c	ft_conv_c.c		ft_conv_s.c			\
					ft_conv_p.c		ft_conv_f.c		ft_conv_percent.c	\
					ft_conv_e.c

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/

RM			=		rm -f


all			:		$(NAME)

$(NAME)		:		$(OBJS) includes/ft_printf.h
					ar rucs $(NAME) $(OBJS)

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