/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/19 16:42:33 by erli             ###   ########.fr       */
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
	long long j = -9223372036854775807LL;
	short	c;

	a = -128;	
	b = 3;
	c = -1;
	i = -11312;
	str = "ca\nca";
	printf("%020.3d\n", i);
	ret = ft_printf("%23lld\n", j);
	printf("\nret = %d\n", ret);
	return (0);
}
