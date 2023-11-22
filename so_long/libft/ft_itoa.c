/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:41 by mkati             #+#    #+#             */
/*   Updated: 2023/01/04 02:08:40 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

int	len_size(int c)
{
	int		i;
	long	j;

	i = 0;
	j = c;
	if (j == 0)
		i++;
	if (j < 0)
	{
		i++;
		j *= -1;
	}
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

char	*c_inarray(char *dst, int n, int size)
{
	if (n == -2147483648)
	{
		dst[0] = '-';
		dst[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		dst[0] = '-';
		n *= -1;
	}
	if (n > 9)
	{
		c_inarray(dst, (n / 10), (size - 1));
		c_inarray(dst, (n % 10), size);
	}
	else
		dst[size] = (n + 48);
	return (dst);
}

char	*ft_itoa(int c)
{
	int		i;
	char	*a;

	i = len_size(c);
	a = (char *)malloc((i + 1) * sizeof(char));
	if (!a)
		return (0);
	c_inarray(a, c, (i - 1));
	a[i] = 0;
	return (a);
}
