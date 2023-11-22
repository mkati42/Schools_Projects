/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:57:26 by mkati             #+#    #+#             */
/*   Updated: 2023/09/13 13:57:26 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_data *philo, int ac, char **av, int *finish_f)
{
	int	i;

	i = -1;
	while (++i < ft_atol(av[1]))
	{
		philo[i].ph_count = ft_atol(av[1]);
		philo[i].ph_id = i + 1;
		philo[i].die_time = ft_atol(av[2]);
		philo[i].eat_time = ft_atol(av[3]);
		philo[i].sleep_time = ft_atol(av[4]);
		philo[i].max_eat_count = -1;
		philo[i].total_eat_count = 0;
		philo[i].finish_f = finish_f;
		philo[i].start_time = 0;
		philo[i].last_time = 3;
		if (ac == 6)
			philo[i].max_eat_count = ft_atol(av[5]);
		if (!philo[i].die_time || !philo[i].eat_time \
			|| !philo[i].sleep_time || !philo[i].max_eat_count)
			return (0);
	}
	return (1);
}

void	init_mutex(t_data *philo, pthread_mutex_t *forks, \
	pthread_mutex_t *finish)
{
	int	i;

	i = -1;
	while (++i < (int)philo->ph_count)
	{
		philo[i].fork_l = &forks[i];
		philo[i].fork_r = &forks[(i + 1) % philo->ph_count];
	}
	i = -1;
	while (++i < (int)philo->ph_count)
	{
		pthread_mutex_init(philo[i].fork_l, NULL);
		pthread_mutex_init(philo[i].fork_r, NULL);
		pthread_mutex_init(&philo[i].last_time_m, NULL);
		pthread_mutex_init(&philo[i].max_eat, NULL);
		philo[i].finish = finish;
	}
	pthread_mutex_init(philo->finish, NULL);
}

int	arg_control(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		if (ft_atol(av[i]) == 0 && i != 5)
		{
			print_error(INV_ARG);
			return (0);
		}
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				print_error(INV_ARG);
				return (0);
			}
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish;
	int				finish_f;

	if (ac == 5 || ac == 6)
	{
		if (ft_atol(av[1]) == 0)
			return (0);
		finish_f = 0;
		forks = malloc(sizeof(pthread_mutex_t) * ft_atol(av[1]));
		philo = (t_data *)malloc(sizeof(t_data) * ft_atol(av[1]));
		if (!philo || !forks)
			return (0);
		if (arg_control(ac, av) == 0)
			return (0);
		if (init_philo(philo, ac, av, &finish_f) == 0)
			return (0);
		init_mutex(philo, forks, &finish);
		thread_create(philo);
		ft_free(philo);
	}
	else
		return (print_error(ARG_COUNT));
}
