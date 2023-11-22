/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:38:50 by mkati             #+#    #+#             */
/*   Updated: 2023/09/12 23:38:50 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int	ft_atol(const char *str)
{
	unsigned long	i;
	unsigned long	result;
	unsigned long	sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	result = result * sign;
	return (result);
}

t_time	ft_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_sleep(t_data *philo, int i)
{
	unsigned long	time;
	unsigned long	tmp_time;

	time = 0;
	tmp_time = ft_time();
	if (i == 1)
		time = philo->eat_time;
	else if (i == 2)
		time = philo->sleep_time;
	else if (i == 3)
		time = philo->die_time;
	while (1)
	{
		if (ft_time() - tmp_time >= time)
			break ;
		usleep(100);
	}
	return (1);
}

void	ft_free(t_data *philo)
{
	int	i;

	i = philo[0].ph_count;
	while (i-- > 0)
	{
		pthread_mutex_destroy(philo[i].fork_l);
		pthread_mutex_destroy(philo[i].fork_r);
		pthread_mutex_destroy(philo[i].finish);
		pthread_mutex_destroy(&philo[i].last_time_m);
		pthread_mutex_destroy(&philo[i].max_eat);
	}
}
