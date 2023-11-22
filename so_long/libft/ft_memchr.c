/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:17:06 by mkati             #+#    #+#             */
/*   Updated: 2023/01/04 02:17:06 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

void	*ft_memchr(const void *dst, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)dst;
	while (n-- > 0)
	{
		if (*a == (unsigned char)c)
			return (a);
		a++;
	}
	return (0);
}
