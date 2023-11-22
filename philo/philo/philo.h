/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:35:58 by jdecorte          #+#    #+#             */
/*   Updated: 2023/09/23 16:28:18 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INV_ARG "There is invalid argument!\n"
# define ARG_COUNT "Number of argument is wrong!\n"
# define ALLOC "Allocation error!\n"
# define FORK "  has taken a fork\n"
# define EAT "  is eating\n"
# define SLEEP "  is sleeping\n"
# define THINK "  is thinking\n"
# define DEAD "  is dead\n"

typedef unsigned long long	t_time;

typedef struct s_data
{
	t_time			die_time;
	t_time			eat_time;
	t_time			sleep_time;
	t_time			start_time;
	t_time			last_time;
	int				ph_id;
	int				max_eat_count;
	int				total_eat_count;
	int				ph_count;
	int				*finish_f;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*finish;
	pthread_mutex_t	last_time_m;
	pthread_mutex_t	max_eat;
}					t_data;

//~~~~~checking~~~~~~
void				check_finish(t_data *philo);
int					dead_control(t_data *philo);
int					max_eat_control(t_data *philo);

//~~~~~creating~~~~~~
void				thread_create(t_data *philo);
void				*philo_routine(void *tmp);
int					one_philo_routine(t_data *philo);

//~~~~~routine~~~~~~
void				leave_fork(t_data *philo);
int					eating(t_data *philo);
int					sleeping(t_data *philo);
int					print(t_data *philo, char *str, int f, int id);

//~~~~~utils~~~~~~
int					print_error(char *str);
int					ft_atol(const char *str);
t_time				ft_time(void);
int					ft_sleep(t_data *philo, int i);
void				ft_free(t_data *data);

#endif