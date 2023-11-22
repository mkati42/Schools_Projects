/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:41:16 by mkati             #+#    #+#             */
/*   Updated: 2023/03/01 22:52:54 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_pointhead(unsigned long long n, int i)
{
	write (1, "0x", 2);
	i = 2;
	i = ft_printpoint(n, i);
	return (i);
}

int	ft_printpoint(unsigned long long n, int i)
{
	if (n < 0)
	{
		return (0);
	}
	if (n >= 16)
	{
		i = ft_printpoint(n / 16, i);
		i = ft_printpoint(n % 16, i);
	}
	else if (n < 16)
	{
		i = ft_putchar("0123456789abcdef"[n], i);
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n, int i)
{
	if (n < 0)
		return (0);
	else if (n > 9)
	{
		i = ft_putnbr_u(n / 10, i);
		i = ft_putnbr_u(n % 10, i);
	}
	else
	{
		i = ft_putchar(n + 48, i);
	}
	return (i);
}
