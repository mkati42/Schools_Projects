/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:30:48 by mkati             #+#    #+#             */
/*   Updated: 2023/08/04 05:57:43 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_s(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack = second;
	return (0);
}

int	reverse_a(t_list **a)
{
	if (reverse_s(a) == -1)
		return (-1);
	write (1, "ra\n", 3);
	return (0);
}

int	reverse_b(t_list **b)
{
	if (reverse_s(b) == -1)
		return (-1);
	write (1, "rb\n", 3);
	return (0);
}

int	reverse_ab(t_list **a, t_list **b)
{
	if ((reverse_s(a) == -1) || (reverse_s(b) == -1))
		return (-1);
	write(1, "rs\n", 3);
	return (0);
}
