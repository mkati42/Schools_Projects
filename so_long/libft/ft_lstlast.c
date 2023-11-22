/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:14:59 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 18:26:42 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*a;
	int		i;

	a = lst;
	i = ft_lstsize(a);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}
