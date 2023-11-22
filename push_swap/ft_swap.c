/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:32:05 by mkati             #+#    #+#             */
/*   Updated: 2023/08/04 05:57:27 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_s(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (0);
}

int	swap_a(t_list **a)
{
	if (swap_s(a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	swap_b(t_list **b)
{
	if (swap_s(b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	swap_ab(t_list **a, t_list **b)
{
	if ((swap_s(a) == -1) || swap_s(b) == -1)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}
