/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:58:05 by mkati             #+#    #+#             */
/*   Updated: 2023/07/31 12:58:05 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr (str);
	exit (0);
}

void	ft_free_stack(t_list **clear)
{
	t_list	*head;
	t_list	*tmp;

	head = *clear;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(clear);
}

void	ft_free_2d(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}
