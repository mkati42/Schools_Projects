/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:32:00 by mkati             #+#    #+#             */
/*   Updated: 2023/01/11 16:44:13 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include    <unistd.h>
# include    <stdarg.h>
# include    <stdlib.h>

int	ft_putchar(char c, int i);
int	ft_printstr(char *c, int i);
int	ft_putnbr(int n, int i);
int	ft_printhexa(unsigned int n, int i);
int	ft_printhexab(unsigned int n, int i);
int	ft_printpoint(unsigned long long n, int i);
int	ft_pointhead(unsigned long long n, int i);
int	ft_putnbr_u(unsigned int n, int i);
int	ft_check(va_list args, char a);
int	pointer(va_list args, char a);
int	ft_printf(const char *n, ...);

#endif
