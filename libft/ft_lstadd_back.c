/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:37:22 by mkati             #+#    #+#             */
/*   Updated: 2023/01/04 00:06:41 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		ft_lstlast((*lst))->next = NULL;
	}
	else
	{
		ft_lstlast((*lst))->next = new;
		ft_lstlast((*lst))->next = NULL;
	}
}
