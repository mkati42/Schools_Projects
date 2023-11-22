/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:18:56 by mkati             #+#    #+#             */
/*   Updated: 2023/09/23 16:11:15 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	fork_create(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = data->philo;
	i = 0;
	while (i < data->philo_count)
	{
		data->ph_pid[i] = fork();
		if (data->ph_pid[i] < 0)
			return (print_error_bonus(FORKERR));
		if (data->ph_pid[i] == 0)
			if (fork_routine(&philo[i]) == 0)
				return (0);
		i += 2;
		usleep(100);
	}
	if (fork_create_2(data) == 0)
		return (0);
	return (1);
}

int	fork_create_2(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = data->philo;
	i = 1;
	while (i < data->philo_count)
	{
		data->ph_pid[i] = fork();
		if (data->ph_pid[i] < 0)
			return (print_error_bonus(FORKERR));
		if (data->ph_pid[i] == 0)
			if (fork_routine(&philo[i]) == 0)
				return (0);
		i += 2;
		usleep(100);
	}
	waiter_and_murder(data);
	return (1);
}

void	waiter_and_murder(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	while (++i < data->philo_count)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < data->philo_count)
				kill(data->ph_pid[i], 15);
			break ;
		}
	}
	sem_close(data->forks);
	sem_close(data->finish);
	sem_close(data->print);
	sem_unlink("/forks");
	sem_unlink("/finish");
	sem_unlink("/print");
	free(data->ph_pid);
	free(data->philo);
	free(data);
}
