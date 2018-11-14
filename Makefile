#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 17:45:59 by erli              #+#    #+#              #
#    Updated: 2018/11/14 18:47:22 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		test

SRCSDIR		=		srcs

OBJSDIR		=		objs

SRCS		=		$(shell find $(SRCSDIR) -name "*.c")

OBJS		=		$(patsubst $(SRCSDIR)/%.c,$(OBJSDIR)/%.o, $(SRCS))

CC			=		gcc

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/

RM			=		rm -f


all			:		$(NAME)

$(NAME)		:		$(OBJS) includes/ft_printf.h
					$(CC) $(CFLAG) $(OBJS) $(INCL) -o $(NAME)

$(OBJSDIR)/%.o			:		$(SRCSDIR)/%.c
					$(CC) $(CFLAG) $(INCL) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all

delsav		:
					$(RM) */*~
					$(RM) *~

reset		:		delsav fclean

.PHONY		:		clean delsav