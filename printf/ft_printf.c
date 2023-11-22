/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:00:55 by mkati             #+#    #+#             */
/*   Updated: 2023/01/11 16:30:05 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_check(va_list args, char a)
{
	int	put;

	put = 0;
	if (a == 'c')
		put += ft_putchar(va_arg(args, int), 0);
	else if (a == 's')
		put += ft_printstr(va_arg(args, char *), 0);
	else if (a == 'd' || a == 'i')
		put += ft_putnbr(va_arg(args, int), 0);
	else if (a == 'x')
		put += ft_printhexa(va_arg(args, unsigned int), 0);
	else if (a == 'X')
		put += ft_printhexab(va_arg(args, unsigned int), 0);
	else if (a == '%')
		put += ft_putchar('%', 0);
	else if (a == 'u')
		put += ft_putnbr_u(va_arg(args, unsigned int), 0);
	else
		return (0);
	return (put);
}

int	pointer(va_list args, char a)
{
	unsigned long long	p;
	int					put;

	put = 0;
	if (a == 'p')
	{
		p = (unsigned long long)va_arg(args, void *);
		put += ft_pointhead(p, 0);
	}
	return (put);
}

int	ft_printf(const char *n, ...)
{
	va_list	arg;
	int		idx;
	int		put;

	idx = 0;
	put = 0;
	va_start(arg, n);
	while (n[idx])
	{
		if (n[idx] == '%')
		{
			if (n[idx + 1] == 'p')
				put += pointer(arg, n[idx +1]);
			put += ft_check(arg, n[idx + 1]);
			idx++;
		}
		else
		{
			put += ft_putchar(n[idx], 0);
		}
		idx++;
	}
	va_end(arg);
	return (put);
}
