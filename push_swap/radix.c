/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 01:14:18 by mkati             #+#    #+#             */
/*   Updated: 2023/08/05 02:10:12 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **a, t_list **b)
{
	t_list	*head;
	int		max_bit;
	int		max_value;

	head = *a;
	max_value = ft_lstsize(head);
	max_bit = init_max_bit(max_value);
	bit_sort(a, b, max_bit);
}

int	init_max_bit(int value)
{
	int	i;

	i = 0;
	while ((value >> i) != 0)
		i++;
	return (i);
}

void	bit_sort(t_list **a, t_list **b, int max_bit)
{
	int		bit;

	bit = 0;
	while (bit < max_bit)
	{
		bit_control_a(a, b, bit, 0);
		bit++;
		bit_control_b(b, a, bit, 1);
	}
	if ((*b) != NULL)
		bit_control_b(b, a, bit, 0);
}

void	bit_control_a(t_list **a, t_list **b, int bit, int value)
{
	t_list	*head;
	int		size;

	head = *a;
	size = ft_lstsize(head);
	while (size-- > 0)
	{
		head = *a;
		if (((head->index >> bit) & 1) == value)
			push_b(a, b);
		else
			reverse_a(a);
	}
}

void	bit_control_b(t_list **b, t_list **a, int bit, int value)
{
	t_list	*head;
	int		size;

	head = *b;
	size = ft_lstsize(head);
	while (size-- > 0)
	{
		head = *b;
		if (((head->index >> bit) & 1) == value)
			push_a(b, a);
		else
			reverse_b(b);
	}
}
