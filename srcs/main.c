/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 17:04:40 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

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
	float f;

	f = 2.2;
	a = 'h';	
	b = 3;
	c = 1;
	i = 500;
	u = i;

	str = ft_memalloc(10, 48);
	str2 = "caca";
	str[9] = 0;
	ret = printf("\ns: %.26f\n",f);
	printf("\nret = %d\n", ret);
	ret = ft_printf("\nu: %20p\n", str2);
	printf("\nret = %d\n", ret);
	return (0);
}
