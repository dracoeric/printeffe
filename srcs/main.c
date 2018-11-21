/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 13:46:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char	*str;
	int		i;
	int		ret;
	char	a;
	long	b;
//	unsigned char x = 0x64;
//	unsigned long j = 81763482374LL;
	short	c;
	unsigned int u;
	
	a = 'h';	
	b = 3;
	c = 1;
	i = 500;
	u = i;

	str = ft_memalloc(10, 48);
	str[9] = 0;
	ret = printf("\ns: %11.5s\n", str);
	printf("\nret = %d\n", ret);
	ret = ft_printf("\nu: %20.5s%-20.5s\n", str, str);
	printf("\nret = %d\n", ret);
	return (0);
}
