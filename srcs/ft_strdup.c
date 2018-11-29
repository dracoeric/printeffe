/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:51:02 by erli              #+#    #+#             */
/*   Updated: 2018/11/27 13:53:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len;
	int		i;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	if (!(cpy = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}
