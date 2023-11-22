/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:49:39 by mkati             #+#    #+#             */
/*   Updated: 2023/09/14 23:49:39 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	leave_fork(t_data *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

int	eating(t_data *philo)
{
	if (philo->ph_count == 1)
		return (one_philo_routine(philo));
	pthread_mutex_lock(philo->fork_l);
	print(philo, FORK, 0, -1);
	pthread_mutex_lock(philo->fork_r);
	print(philo, FORK, 0, -1);
	print(philo, EAT, 0, -1);
	ft_sleep(philo, 1);
	pthread_mutex_lock(&philo->last_time_m);
	philo->last_time = ft_time();
	pthread_mutex_unlock(&philo->last_time_m);
	pthread_mutex_lock(&philo->max_eat);
	philo->total_eat_count++;
	pthread_mutex_unlock(&philo->max_eat);
	leave_fork(philo);
	sleeping(philo);
	return (1);
}

int	sleeping(t_data *philo)
{
	if (print(philo, SLEEP, 0, -1) == 0)
		return (0);
	ft_sleep(philo, 2);
	if (print(philo, THINK, 0, -1) == 0)
		return (0);
	return (1);
}

int	print(t_data *philo, char *str, int f, int id)
{
	pthread_mutex_lock(philo->finish);
	if (f == 1)
	{
		printf("%llu %d %s", (ft_time() - philo->start_time), \
			id, str);
		*philo->finish_f = 1;
		pthread_mutex_unlock(philo->finish);
		return (0);
	}
	else if (*philo->finish_f == 0 && f == 0)
		printf("%llu %d %s", (ft_time() - philo->start_time), \
			philo->ph_id, str);
	pthread_mutex_unlock(philo->finish);
	return (1);
}
