/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/28 12:07:57 by erli             ###   ########.fr       */
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
	short **tab;

	tab = malloc(sizeof(int*) * 2);
	tab[0] = malloc(sizeof(int) * 3);	
	tab[1] = malloc(sizeof(int) * 3);	
	tab[0][0] = 123;
	tab[0][1] = 232;
	tab[0][2] = 443;
	tab[1][0] = 1244;
	tab[1][1] = 3425;
	tab[1][2] = 613;
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
	prec = 1;
	width = 5;

	str = ft_memalloc(10, 48);
	str2 = "caca";
	str[9] = 0;
	ret = printf("\ns: %*d\n", width, 0);
	printf("\nret = %d\n", ret);
	ret = ft_printf("\ns: %m*.*hd\n", width, prec, tab, 2,3);
	printf("\nret = %d\n", ret);
	free(str);
	free(tab[1]);
	free(tab[0]);
	free(tab);
	return (0);
}
