/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:22:09 by mkati             #+#    #+#             */
/*   Updated: 2023/03/06 15:56:21 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "minitalk.h"

static void	handler(int signum)
{
	static int		bit;
	static char		result;

	if (signum == SIGUSR1)
		result += (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", result);
		bit = 0;
		result = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("EK ARGUMAN GIRME");
		return (0);
	}
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
