/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:22:58 by mkati             #+#    #+#             */
/*   Updated: 2023/03/06 15:54:08 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

static int	ft_atoi(const char *str)
{
	int	z;
	int	j;

	j = 0;
	z = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			z *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		j *= 10;
		j += (*str - '0');
		str++;
	}
	if (z == -1)
		j = -j;
	return (j);
}

static void	go_to_bit(pid_t pid, unsigned char ch)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((ch & (1 << i)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("SERVER ACIK DEGIL");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("SERVER ACIK DEGIL");
				exit(0);
			}
		}
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi (av[1]);
		while (av[2][i])
		{
			go_to_bit (pid, av[2][i++]);
			usleep (100);
		}
		go_to_bit (pid, '\0');
		go_to_bit (pid, '\n');
	}
	else
	{
		ft_printf("3 ARG GIR: 1: DOSYA 2: PID 3: MESAJ");
		return (0);
	}
}
