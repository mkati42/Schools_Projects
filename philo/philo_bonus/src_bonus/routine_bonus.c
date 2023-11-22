/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:30:22 by mkati             #+#    #+#             */
/*   Updated: 2023/09/23 15:04:35 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	take_fork_bonus(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	if (print_bonus(philo, FORK, 0) == 0)
		return (0);
	if (print_bonus(philo, FORK, 0) == 0)
		return (0);
	return (1);
}

int	sleeping_bonus(t_philo *philo)
{
	if (print_bonus(philo, SLEEP, 0) == 0)
		return (0);
	if (ft_sleep_bonus(philo, 2) == 0)
		return (0);
	if (print_bonus(philo, THINK, 0) == 0)
		return (0);
	return (1);
}

int	eating_bonus(t_philo *philo)
{
	if (take_fork_bonus(philo) == 0)
		return (0);
	if (print_bonus(philo, EAT, 0) == 0)
		return (0);
	if (ft_sleep_bonus(philo, 1) == 0)
		return (0);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->last_time = ft_time_bonus();
	philo->total_eat_count++;
	return (1);
}

int	dead_full_control(t_philo *philo)
{
	sem_wait(philo->data->finish);
	if (ft_time_bonus() > (philo->last_time + philo->die_time))
	{
		philo->fin_flag = 1;
		print_bonus(philo, DEAD, 1);
		kill(getpid(), 15);
	}
	if (philo->total_eat_count == philo->max_eat_count)
	{
		sem_post(philo->data->finish);
		return (0);
	}
	sem_post(philo->data->finish);
	return (1);
}

void	*fork_routine(t_philo *philo)
{
	philo->start_time = ft_time_bonus();
	philo->last_time = ft_time_bonus();
	if (philo->ph_count == 1)
	{
		sem_wait(philo->data->forks);
		print_bonus(philo, FORK, 0);
		ft_sleep_bonus(philo, 3);
		usleep(1000);
		print_bonus(philo, DEAD, 1);
		kill(getpid(), 15);
	}
	while (1)
	{
		if (dead_full_control(philo) == 0)
			return (0);
		if (eating_bonus(philo) == 0)
			return (0);
		if (sleeping_bonus(philo) == 0)
			return (0);
	}
}
