/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 03:31:11 by mkati             #+#    #+#             */
/*   Updated: 2023/08/12 15:08:20 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	j;
	int			z;

	j = 0;
	z = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			z *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		j *= 10;
		j += (*str - '0');
		str++;
	}
	if (z == -1)
		j = -j;
	if (!(j >= -2147483648 && j <= 2147483647))
		ft_error("Error\n");
	return (j);
}

int	string_len(char const *str, char c)
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

int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		next;
	int		i;

	i = 0;
	next = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	while (count_word(s, c))
	{
		while (*s == c)
			s++;
		while (s[next] != c && s[next])
			next++;
		result[i++] = ft_substr(s, 0, next);
		s = s + next + (s[next] != 0);
		next = 0;
	}
	result[i] = 0;
	return (result);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
