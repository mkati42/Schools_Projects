/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:26:35 by mkati             #+#    #+#             */
/*   Updated: 2023/08/04 22:12:30 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_s(t_list **from, t_list **to)
{
	t_list	*head_from;
	t_list	*head_to;
	t_list	*tmp;

	if (ft_lstsize(*from) == 0)
		return (-1);
	head_from = *from;
	tmp = *from;
	head_to = *to;
	*from = head_from->next;
	head_from->next = NULL;
	if (head_to == NULL)
		*to = tmp;
	else
	{
		tmp->next = head_to;
		*to = tmp;
	}
	return (0);
}

int	push_a(t_list **b, t_list **a)
{
	if (push_s(b, a) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(t_list **a, t_list **b)
{
	if (push_s(a, b) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
