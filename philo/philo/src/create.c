/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:38:25 by mkati             #+#    #+#             */
/*   Updated: 2023/09/12 23:38:25 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thread_create(t_data *philo)
{
	int	i;

	i = -1;
	while (++i < philo->ph_count)
	{
		philo[i].last_time = ft_time();
		pthread_create(&(philo[i].thread), NULL, &philo_routine, &philo[i]);
		usleep(100);
	}
	check_finish(philo);
	i = -1;
	while (++i < philo->ph_count)
		pthread_join(philo[i].thread, 0);
}

void	*philo_routine(void *tmp)
{
	t_data	*philo;

	philo = (t_data *)tmp;
	philo->start_time = ft_time();
	while (1)
	{
		pthread_mutex_lock(philo->finish);
		if (*philo->finish_f == 1)
		{
			pthread_mutex_unlock(philo->finish);
			return (0);
		}
		pthread_mutex_unlock(philo->finish);
		if (eating(philo) == 0)
			return (0);
		pthread_mutex_lock(&philo->max_eat);
		if (philo->total_eat_count == philo->max_eat_count)
		{
			pthread_mutex_unlock(&philo->max_eat);
			return (0);
		}
		pthread_mutex_unlock(&philo->max_eat);
	}
}

int	one_philo_routine(t_data *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print(philo, FORK, 0, -1);
	ft_sleep(philo, 3);
	pthread_mutex_unlock(philo->fork_l);
	return (0);
}
