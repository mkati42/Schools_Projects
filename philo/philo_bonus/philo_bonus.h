/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:24:19 by mkati             #+#    #+#             */
/*   Updated: 2023/09/23 09:35:44 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INV_ARG "There is invalid argument!\n"
# define ARG_COUNT "Number of argument is wrong!\n"
# define ALLOC "Allocation error!\n"
# define SEMERR "Semaphore init failed!\n"
# define FORKERR "Fork opening is failed!\n"
# define FORK "  has taken a fork\n"
# define EAT "  is eating\n"
# define SLEEP "  is sleeping\n"
# define THINK "  is thinking\n"
# define DEAD "  is dead\n"

typedef struct s_philo
{
	int						fin_flag;
	int						ph_count;
	int						max_eat_count;
	int						total_eat_count;
	int						ph_num;
	unsigned long long		die_time;
	unsigned long long		eat_time;
	unsigned long long		sleep_time;
	unsigned long long		start_time;
	unsigned long long		last_time;
	struct s_data			*data;
}			t_philo;

typedef struct s_data
{
	int					philo_count;
	int					*ph_pid;
	sem_t				*forks;
	sem_t				*finish;
	sem_t				*print;
	t_philo				*philo;
}						t_data;

//#####~~~~~creating~~~~~~#####
int					fork_create(t_data *data);
int					fork_create_2(t_data *data);
void				waiter_and_murder(t_data *data);

//#####~~~~~routine~~~~~~~#####
void				*fork_routine(t_philo *philo);
int					dead_full_control(t_philo *philo);
int					eating_bonus(t_philo *philo);
int					sleeping_bonus(t_philo *philo);
int					take_fork_bonus(t_philo *philo);

//#####~~~~~~utils~~~~~~~~#####
int					print_error_bonus(char *str);
int					ft_atol_bonus(const char *str);
unsigned long long	ft_time_bonus(void);
int					ft_sleep_bonus(t_philo *philo, int i);
int					print_bonus(t_philo *philo, char *str, int f);

#endif