/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:34:17 by erli              #+#    #+#             */
/*   Updated: 2018/11/22 13:33:04 by erli             ###   ########.fr       */
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
	int		len;

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

void	ft_round_up(char **str, int rest)
{
	int		i;
	int		done;
	char	*add;

	add = "1";
	done = 0;
	if (*str == NULL)
		return ;
	i = ft_strlen(*str) - 1;
	if (rest >= 5)
	{
		while (i >= 0 && done == 0)
		{
			if ((*str)[i] == '9')
				(*str)[i] = '0';
			else if ((*str)[i] >= '0' && (*str)[i] <= '8')
			{
				(*str)[i]++;
				done = 1;
			}
			i--;
		}
		if (done == 0 && (*str)[0] == '0')
			*str = ft_strjoinfree(&add, str, 2);
	}
}
