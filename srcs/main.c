/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/27 17:33:30 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		main(void)
{
	char	*str;
	char *str2;
	int		i;
	int		ret;
	char	a;
	long	b;
//	unsigned char x = 0x64;
//	unsigned long j = 81763482374LL;
	short	c;
	unsigned int u;
	double f;
	int fd;
	int prec;
	int width;
	unsigned short tab[4];


	tab[0] = 10;
	tab[1] = 20;
	tab[2] = 30;
	tab[3] = 40;
	fd = open("/Users/erli/HolyGraph/MyRepo/ft_printf/deg.txt", O_WRONLY, O_APPEND);
	printf("fd = %d\n", fd);
	write(fd, "caca\n", 5);
	write(fd, "caca\n", 5);
	close(fd);
	f = -170000;
	a = 'h';
	b = 3;
	c = 1;
	i = 500;
	u = i;
	prec = 6;
	width = 20;

	str = ft_memalloc(10, 48);
	str2 = "caca";
	str[9] = 0;
	ret = printf("\ns: '%*.*o\n", width, prec, tab[1] );
	printf("\nret = %d\n", ret);
	ret = ft_printf("\ns: '%t*.*ho\n", width, prec, tab, 4);
	printf("\nret = %d\n", ret);
	free(str);
	return (0);
}
