/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:44:28 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 18:58:59 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strjoin(char const *src1, char const *src2)
{
	size_t	i;
	size_t	j;
	char	*a;

	if (!src1 || !src2)
		return (0);
	i = ft_strlen(src1);
	j = ft_strlen(src2);
	a = (char *)malloc((i + j + 1) * 1);
	if (!a)
		return (NULL);
	ft_memcpy(a, src1, i);
	ft_memcpy((a + i), src2, j);
	a[i + j] = '\0';
	return (a);
}
