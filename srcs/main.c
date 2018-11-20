/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/20 18:06:46 by erli             ###   ########.fr       */
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
	unsigned long j = 81763482374LL;
	short	c;
	unsigned int u;

	a = -128;	
	b = 3;
	c = -1;
	i = 10;
	u = i;


	str = "ca\nca";
//	ret = printf("oellele %+07i fdsfds %++++3i dslkfdsf \n%#030lo\n", i, i, j);
//	printf("\nret = %d\n", ret);
	ret = ft_printf("oellele %+07wi fdsfds %++++3ji dslkfdsf \n%#030lko\n", i, i, j);
//	printf("\nret = %d\n", ret);
	return (0);
}
