/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 05:17:15 by mkati             #+#    #+#             */
/*   Updated: 2023/01/04 11:57:41 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

static int	string_len(char const *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str && *str != c)
		{
			i++;
			while (*str && *str != c)
			{
				str++;
			}
		}
		str++;
	}
	return (i);
}

static char	*pump_function(const char *t, char d)
{
	int		i;
	int		j;
	char	**b;

	i = 0;
	j = 0;
	while (t[j] != d && t[j])
		j++;
	b = (char **)malloc((i + 1) * sizeof(char *));
	if (!b)
		return (0);
	while (t[i] != d && j > 0)
	{
		*((char *) b + i) = *((char *) t + i);
		i++;
		j--;
	}
	*((char *)b + i) = 0;
	return ((char *)b);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**a;

	if (!s)
		return (0);
	a = (char **)malloc((string_len(s, c) + 1) * sizeof(char *));
	if (!a)
		return (0);
	j = 0;
	if (*s && *s != c)
		a[j++] = pump_function(s, c);
	while (*s)
	{
		if (*s++ == c && *s)
		{
			if (*s != c && *s)
				a[j++] = pump_function(s, c);
			while (*s != c && *s)
				s++;
		}
	}
	a[j] = 0;
	return (a);
}
