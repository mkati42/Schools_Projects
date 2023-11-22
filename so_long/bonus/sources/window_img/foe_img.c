/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:06:48 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 15:48:13 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../so_long_bonus.h"

void	foe_put_img_bonus2(t_data *data, int column, int i)
{
	if (data->f_flag == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.foe_r, column, i * SIZE);
	else if (data->f_flag == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.foe_l, data->f_j * SIZE, data->f_i * SIZE);
}

void	foe_put_img_bonus(t_data *data)
{
	if (data->map_data.map[data->f_i][data->f_j + 1] != '1' \
		&& data->map_data.map[data->f_i][data->f_j + 1] != 'E' \
			&& data->map_data.map[data->f_i][data->f_j + 1] != 'C'\
				&& data->f_flag == 1)
	{
		data->map_data.map[data->f_i][data->f_j + 1] = 'F';
		data->map_data.map[data->f_i][data->f_j] = '0';
		data->f_j++;
	}
	else
		data->f_flag = 0;
	if (data->map_data.map[data->f_i][data->f_j - 1] != '1' \
		&& data->map_data.map[data->f_i][data->f_j - 1] != 'E' \
			&& data->map_data.map[data->f_i][data->f_j - 1] != 'C'\
				&& data->f_flag == 0)
	{
		data->map_data.map[data->f_i][data->f_j - 1] = 'F';
		data->map_data.map[data->f_i][data->f_j] = '0';
		data->f_j--;
	}
	else
		data->f_flag = 1;
	if (data->f_i == data->p_i && data->f_j == data->p_j)
		close_window_bonus(data);
}

void	lose_control(t_data *data)
{
	if (data->map_data.map[data->p_i][data->p_j] == 'F')
		close_window_bonus(data);
}
