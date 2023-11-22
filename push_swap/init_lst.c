/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 03:06:03 by mkati             #+#    #+#             */
/*   Updated: 2023/08/05 18:32:27 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int ac, char **av, t_list **a)
{
	int		i;
	int		j;
	char	**argv;

	j = 1;
	i = 0;
	while (j < ac)
	{
		argv = ft_split(av[j], ' ');
		i = 0;
		while (argv[i])
		{
			ft_lst_addback(a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		j++;
		ft_free_2d(argv);
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->index = -1;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lst_addback(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
