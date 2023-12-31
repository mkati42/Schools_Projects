/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:11:31 by mkati             #+#    #+#             */
/*   Updated: 2023/01/03 18:47:45 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

void	ft_putstr_fd(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (c, &s[i], 1);
		i++;
	}
}
