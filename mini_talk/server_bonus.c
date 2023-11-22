/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:22:09 by mkati             #+#    #+#             */
/*   Updated: 2023/03/06 15:41:46 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

static void	result_o(int *i, int *pid)
{
	kill (*pid, SIGUSR2);
	*i = 0;
	*pid = 0;
	ft_printf("\n");
}

static void	handler(int signum)
{
	static int		bit;
	static char		result;
	static int		pid_client;
	static int		i;

	if (bit == 8)
		bit = 0;
	if (i < 32 && signum == SIGUSR1)
		pid_client |= (1 << i);
	i++;
	if (signum == SIGUSR1 && i > 32)
		result |= (1 << bit);
	bit++;
	if (bit == 8 && i > 32)
	{
		ft_printf("%c", result);
		bit = 0;
		if (result == 0)
			result_o(&i, &pid_client);
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
