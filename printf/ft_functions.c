/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:30:14 by mkati             #+#    #+#             */
/*   Updated: 2023/01/11 15:46:12 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_putchar(char c, int i)
{
	i += write (1, &c, 1);
	return (i);
}

int	ft_printstr(char *c, int i)
{
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int i)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		i = 11;
	}
	else if (n < 0)
	{
		i = ft_putchar('-', i);
		i = ft_putnbr(-n, i);
	}
	else if (n > 9)
	{
		i = ft_putnbr(n / 10, i);
		i = ft_putnbr(n % 10, i);
	}
	else
	{
		i = ft_putchar(n + 48, i);
	}
	return (i);
}

int	ft_printhexa(unsigned int n, int i)
{
	if (n < 0)
	{
		return (0);
	}
	else if (n >= 16)
	{
		i = ft_printhexa(n / 16, i);
		i = ft_printhexa(n % 16, i);
	}
	else
	{
		i = ft_putchar("0123456789abcdef"[n], i);
	}
	return (i);
}

int	ft_printhexab(unsigned int n, int i)
{
	if (n < 0)
	{
		return (0);
	}
	else if (n >= 16)
	{
		i = ft_printhexab(n / 16, i);
		i = ft_printhexab(n % 16, i);
	}
	else
	{
		i = ft_putchar("0123456789ABCDEF"[n], i);
	}
	return (i);
}
