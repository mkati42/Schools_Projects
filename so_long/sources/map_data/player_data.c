/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:43:34 by mkati             #+#    #+#             */
/*   Updated: 2023/05/22 13:43:34 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../so_long.h"

void	player_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			else if (data->map_data.map[i][j] == 'E')
			{
				data->e_i = i;
				data->e_j = j;
			}
			j++;
		}
		i++;
	}
}
