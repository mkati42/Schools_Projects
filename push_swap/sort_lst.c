/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:06:22 by mkati             #+#    #+#             */
/*   Updated: 2023/08/05 02:09:22 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		swap_a(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

void	sort_3(t_list **stack)
{
	t_list	*head_a;

	head_a = *stack;
	if (head_a->index == 1 && head_a->next->index != 2)
	{
		r_reverse_a(stack);
		swap_a(stack);
	}
	else if (head_a->index == 2)
	{
		if (head_a->next->index == 1)
			swap_a(stack);
		else if (head_a->next->index == 3)
			r_reverse_a(stack);
	}
	else if (head_a->index == 3)
	{
		if (head_a->next->index == 1)
			reverse_a(stack);
		else if (head_a->next->index == 2)
		{
			swap_a(stack);
			r_reverse_a(stack);
		}
	}
}

void	sort_4(t_list **a, t_list **b)
{
	t_list	*head_a;
	t_list	*tmp;

	tmp = ft_lstlast(*a);
	if (tmp->index == 4)
		r_reverse_a(a);
	head_a = *a;
	while (head_a->index != 4)
	{
		reverse_a(a);
		head_a = *a;
	}
	push_b(a, b);
	sort_3(a);
	push_a(b, a);
	reverse_a(a);
}

void	sort_5(t_list **a, t_list **b)
{
	t_list	*head_a;
	t_list	*tmp;

	tmp = ft_lstlast(*a);
	if (tmp->index == 5)
		r_reverse_a(a);
	tmp = *a;
	if (tmp->next->next->next->index == 5)
	{
		r_reverse_a(a);
		r_reverse_a(a);
	}
	head_a = *a;
	while (head_a->index != 5)
	{
		reverse_a(a);
		head_a = *a;
	}
	push_b(a, b);
	sort_4(a, b);
	push_a(b, a);
	reverse_a(a);
}
