/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:04:05 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 19:09:49 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	while (i >= 0)
	{
		if (*((char *) str + i) == (unsigned char) c)
			return ((char *) str + i);
		i--;
	}
	return (0);
}
