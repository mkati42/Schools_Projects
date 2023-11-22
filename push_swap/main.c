/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:39:08 by mkati             #+#    #+#             */
/*   Updated: 2023/08/11 01:38:05 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero_control(int ac, char **av)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	while (i < ac)
	{
		j = 0;
		z = 0;
		while (av[i][j])
		{
			if (av[i][j] == '0')
				z++;
			j++;
		}
		if (z == j)
		{
			av[i][0] = '0';
			av[i][1] = '\0';
		}
		i++;
	}
}

void	sneaky_control(int ac, char **av)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	while (i < ac)
	{
		j = 0;
		z = 0;
		while (av[i][j])
		{
			valid_char_control(av[i][j]);
			if ((av[i][j] >= '0' && av[i][j] <= '9') ||
				av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' ')
			{
				if (av[i][j++] == ' ')
					z++;
			}
		}
		if (z == j)
			ft_error("Error\n");
		i++;
	}
}

int	same_nbr_control(t_list **av)
{
	t_list	*tmp;
	t_list	*head;

	tmp = (*av)->next;
	head = *av;
	while (head)
	{
		if (head->next == NULL)
			return (1);
		while (tmp)
		{
			if (head->value == tmp->value)
				ft_error("Error\n");
			tmp = tmp->next;
		}
		head = head->next;
		tmp = head->next;
	}
	return (1);
}

void	list_creating(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list **));
	stack_b = (t_list **)malloc(sizeof(t_list **));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(ac, av, stack_a);
	index_lst(stack_a);
	if (same_nbr_control(stack_a) == 0 || (sort_control(stack_a)) == 1)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		exit(0);
	}
	sort_stack(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (-1);
	i = 0;
	while (av[++i])
	{
		if (av[i][0] == 0)
			ft_error("Error\n");
	}
	zero_control(ac, av);
	sneaky_control(ac, av);
	check_control(ac, av);
	list_creating(ac, av);
}
