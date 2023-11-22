/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:27:38 by mkati             #+#    #+#             */
/*   Updated: 2023/08/04 20:26:03 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_reverse_s(t_list **stack)
{
	t_list	*last_one;
	t_list	*last_sec;
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	last_one = *stack;
	last_sec = *stack;
	tmp = *stack;
	while (tmp)
	{
		last_one = last_sec;
		last_sec = tmp;
		tmp = tmp->next;
	}
	last_one->next = NULL;
	last_sec->next = *stack;
	*stack = last_sec;
	return (0);
}

int	r_reverse_a(t_list **a)
{
	if (r_reverse_s(a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	r_reverse_b(t_list **b)
{
	if (r_reverse_s(b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	r_reverse_ab(t_list **a, t_list **b)
{
	if ((r_reverse_s(a) == -1) || r_reverse_s(b) == -1)
		return (-1);
	write(1, "rrs\n", 4);
	return (0);
}
