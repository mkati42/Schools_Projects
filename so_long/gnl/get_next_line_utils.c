/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:51:55 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/06/06 15:57:17 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fnl(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strjjoin(char *str, char *buffer)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = -1;
	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	result
		= malloc(sizeof(char) * ft_strlen_gnl(str) + ft_strlen_gnl(buffer) + 1);
	if (!result)
		return (NULL);
	while (str[++i])
		result[i] = str[i];
	while (buffer[j])
		result[i++] = buffer[j++];
	free(str);
	result[i] = '\0';
	return (result);
}

char	*read_line(char	*str)
{
	size_t	i;
	char	*result;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	result = ft_substr_gnl(str, 0, i + 1);
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
		return (0);
	if (ft_strlen_gnl(s) < len)
		len = ft_strlen_gnl(s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*next_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!*str)
	{
		free(str);
		return (0);
	}
	if (str[i] == '\n')
		i++;
	result = ft_substr_gnl(str, i, ft_strlen_gnl(str) - i);
	free(str);
	return (result);
}
