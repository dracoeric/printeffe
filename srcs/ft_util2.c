/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:08:42 by erli              #+#    #+#             */
/*   Updated: 2018/11/20 18:08:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_memalloc(size_t n, int c)
{
	void			*ptr;
	size_t			i;
	unsigned char	*str;

	if (!(ptr = malloc(n)))
		return (0);
	i = 0;
	str = (unsigned char *)ptr;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (ptr);
}

int		write_free(int fd, char **str, size_t n)
{
	int ret;

	ret = write(fd, *str, n);
	free(*str);
	return (ret);
}
