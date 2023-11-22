/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:57:47 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 19:13:36 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_substr(char const *s, unsigned int pos, size_t size)
{
	char	*a;

	if (!s)
		return (ft_strdup(""));
	if (!pos && !size)
		return (ft_strdup(""));
	if (size > ft_strlen(s))
		size = ft_strlen(s);
	if (pos >= ft_strlen(s))
		return (ft_strdup(""));
	a = (char *)malloc((size + 1) * 1);
	if (!a)
		return (0);
	ft_memcpy(a, s + pos, size);
	a[size] = '\0';
	return (a);
}
