/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:44:53 by erli              #+#    #+#             */
/*   Updated: 2018/11/20 13:59:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int		ft_strlen(const char *s1)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

int		char_in_str(char c, char *str)
{
	if (str == 0)
		return (0);
	while (*str != '\0' && c != *str)
		str++;
	return (c == *str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		l1;
	int		l2;
	int		i;
	char	*str;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (0);
	i = 0;
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i <= l1 + l2)
	{
		str[i] = s2[i - l1];
		i++;
	}
	return (str);
}

char	*ft_strjoinfree(char **s1, char **s2, int n)
{
	char	*str;

	if (!(str = ft_strjoin(*s1, *s2)))
	{
		if (n == 1 || n == 3)
			free(*s1);
		if (n == 2 || n == 3)
			free(*s2);
		return (NULL);
	}
	if (*s2 != NULL && (n == 1 || n == 3))
		free(*s1);
	if (*s1 != NULL && (n == 2 || n == 3))
		free(*s2);
	return (str);
}
