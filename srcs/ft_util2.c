
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:08:42 by erli              #+#    #+#             */
/*   Updated: 2018/11/21 13:39:17 by erli             ###   ########.fr       */
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

char	*ft_strsub(char *str, size_t begin, size_t end)
{
	char	*sub;
	size_t	i;
	int 	len;

	if (end < begin)
		return (NULL);
	len = end - begin + 1;
	if (!(sub = (char *)ft_memalloc(sizeof(char) * (len + 1), 0)))
		return (NULL);
	i = begin;
	while (i <= end && str[i] != '\0')
	{
		sub[i - begin] = str[i];
		i++;
	}
	return (sub);
}
