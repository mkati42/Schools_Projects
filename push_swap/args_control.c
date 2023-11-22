/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:41:05 by mkati             #+#    #+#             */
/*   Updated: 2023/08/12 15:24:54 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_control(int ac, char **str)
{
	long	value;
	int		i;
	int		j;
	char	**av;

	i = 0;
	j = 0;
	while (++j < ac)
	{
		av = ft_split(str[j], ' ');
		i = -1;
		while (av[++i])
		{
			if (l_long_control(av[i]) == 0)
				ft_error("Error\n");
			value = ft_atoi(av[i]);
			if (number_control(av[i]) == 0)
				ft_error("Error\n");
		}
		ft_free_2d(av);
	}
}

int	number_control(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') \
			&& (av[i + 1] == '-' || av[i + 1] == '+'))
			ft_error("Error\n");
		if ((av[i] >= '0' && av[i] <= '9') \
			|| av[i] == ' ' || av[i] == '-' || av[i] == '+')
		{
			if ((av[i] == '-' || av[i] == '+') \
				&& !(av[i + 1] >= '0' && av[i + 1] <= '9'))
				ft_error ("Error\n");
			i++;
		}
		else
			ft_error ("Error\n");
	}
	return (1);
}

void	valid_char_control(char a)
{
	if (!(a >= '0' && a <= '9'))
	{
		if (a != ' ' && a != '+' && a != '-')
			ft_error("Error\n");
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	l_long_control(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			flag = 1;
		if (flag == 1)
			j++;
		i++;
	}
	if (j > 11)
		return (0);
	return (1);
}
