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

#include    "../../../so_long_bonus.h"

void	player_data_bonus(t_data *data)
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

void	foe_data_bonus(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == 'F')
			{
				data->f_i = i;
				data->f_j = j;
			}
			j++;
		}
		i++;
	}
}
