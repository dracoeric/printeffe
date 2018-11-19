#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 17:45:59 by erli              #+#    #+#              #
#    Updated: 2018/11/19 15:15:49 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		test

SRCSDIR		=		srcs

OBJSDIR		=		objs

SRCS		=		ft_printf.c		ft_conv_d.c		ft_put_format.c		\
					ft_usage.c		ft_util.c		main.c				\
					manage_format.c	

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/

RM			=		rm -f


all			:		$(NAME)

$(NAME)		:		$(OBJS) includes/ft_printf.h
					$(CC) $(CFLAG) $(OBJS) $(INCL) -o $(NAME)

$(OBJSDIR)/%.o			:		$(SRCSDIR)/%.c
					@mkdir -p $(OBJSDIR)
					$(CC) $(CFLAG) $(INCL) -c $< -o $@

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