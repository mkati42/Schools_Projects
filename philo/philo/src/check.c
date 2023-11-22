/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:06:35 by mkati             #+#    #+#             */
/*   Updated: 2023/09/23 19:05:35 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_finish(t_data *philo)
{
	int	i;
	int	j;

	i = 0;
	j = philo[0].ph_count;
	while (1)
	{
		if (i == j)
			i = 0;
		if ((dead_control(&philo[i]) == 0) \
			|| (max_eat_control(&philo[i]) == 0))
			break ;
		usleep(100);
		i++;
	}
}

int	dead_control(t_data *philo)
{
	pthread_mutex_lock(&philo->last_time_m);
	if ((ft_time() - philo->last_time) > philo->die_time)
	{
		pthread_mutex_unlock(&philo->last_time_m);
		print(philo, DEAD, 1, philo->ph_id);
		return (0);
	}
	pthread_mutex_unlock(&philo->last_time_m);
	return (1);
}

int	max_eat_control(t_data *philo)
{
	if (philo->max_eat_count >= 0)
	{
		pthread_mutex_lock(&philo->max_eat);
		if (philo->total_eat_count == philo->max_eat_count)
		{
			pthread_mutex_unlock(&philo->max_eat);
			return (0);
		}
		pthread_mutex_unlock(&philo->max_eat);
	}
	return (1);
}
