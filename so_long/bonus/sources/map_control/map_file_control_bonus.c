/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_control_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:20:37 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 15:30:31 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../so_long_bonus.h"

void	file_name_control_bonus(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 1] != 'r' && path[i - 2] != 'e'
			&& path[i - 3] != 'b' && path[i - 4] != '.')
		|| i <= 4)
		error_messages_bonus(ERRORPATH);
}
