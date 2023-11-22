/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:41:50 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 18:56:21 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	i;

	i = ft_strlen(s1) + 1;
	a = (char *)malloc(i * 1);
	if (!a)
		return (0);
	ft_memcpy(a, s1, i);
	return (a);
}
