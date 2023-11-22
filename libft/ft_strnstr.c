/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:59:32 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 19:08:47 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst && !n)
		return (0);
	if ((*src == 0))
		return ((char *)dst);
	if (ft_strlen(dst) < 1)
		return (0);
	while (i < n)
	{
		j = 0;
		while (dst[i + j] == src[j] && src[j] && (i + j) < n)
		{
			if (src[j + 1] == '\0')
				return ((char *)dst + i);
			j++;
		}
		i++;
	}
	return (0);
}
