/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:19:46 by mkati             #+#    #+#             */
/*   Updated: 2023/01/07 20:42:37 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		j;
	int		i;
	char	*a;

	if (!str || !f)
		return (0);
	j = 0;
	i = ft_strlen(str);
	a = (char *)malloc((i + 1) * 1);
	if (!a)
		return (0);
	while (str[j] != 0)
	{
		a[j] = f(j, str[j]);
		j++;
	}
	a[j] = 0;
	return (a);
}
