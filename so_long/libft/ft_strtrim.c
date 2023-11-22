/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:21:18 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 19:11:34 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	char	*a;

	if (!s || !set)
		return (0);
	while (*s && ft_strchr(set, *s) != 0)
		s++;
	i = ft_strlen(s);
	while (s[i - 1] && i && ft_strchr(set, s[i - 1]) != 0)
		i--;
	a = (char *)malloc((i + 1) * 1);
	if (!a)
		return (0);
	ft_memcpy(a, s, i);
	a[i] = '\0';
	return (a);
}
