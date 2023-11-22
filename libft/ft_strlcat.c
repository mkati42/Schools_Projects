/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:18:24 by mkati             #+#    #+#             */
/*   Updated: 2023/01/04 02:18:24 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!n && !dest)
		return (0);
	j = ft_strlen(src);
	i = ft_strlen(dest);
	if (i >= n)
	{
		i = n;
		return (n + j);
	}
	if (j < n - i)
	{
		ft_memcpy(dest + i, src, j);
		dest[i + j] = '\0';
	}
	else
	{
		ft_memcpy(dest + i, src, n - i - 1);
		dest[n - 1] = '\0';
	}
	return (i + j);
}
