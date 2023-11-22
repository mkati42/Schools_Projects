/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:10:33 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 15:52:45 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../so_long_bonus.h"

void	my_xpm_put_window_bonus(t_data *data, int i, int column, int j)
{
	if (data->map_data.map[i][j] != '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_g, column, i * SIZE);
	if (data->map_data.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_w, column, i * SIZE);
	if (i == data->e_i && j == data->e_j)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_e, column, i * SIZE);
	if (data->map_data.map[i][j] == 'C')
		coin_put_img_bonus(data, column, i);
	if (data->map_data.map[i][j] == 'F')
		foe_put_img_bonus2(data, column, i);
	if (data->map_data.map[i][j] == 'P')
		player_put_img_bonus(data, column, i);
	write_step_bonus(data);
}

int	render_window_bonus(t_data *data)
{
	int	i;
	int	j;
	int	column;

	i = 0;
	j = 0;
	column = 0;
	data->map_data.map[data->p_i][data->p_j] = 'P';
	mlx_clear_window(data->mlx, data->win);
	count_flag_second(data);
	if (data->play_s % 5 == 0)
		foe_put_img_bonus(data);
	while (i < data->map_data.line_count)
	{
		while (j < data->map_data.line_len)
		{
			my_xpm_put_window_bonus(data, i, column, j);
			column += SIZE;
			j++;
		}
		column = 0;
		j = 0;
		i++;
	}
	return (0);
}

void	coin_put_img_bonus(t_data *data, int column, int i)
{
	if (data->coin_s < 35)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.knife1, column, i * SIZE);
	else if (data->coin_s >= 35 && data->coin_s <= 70)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.knife2, column, i * SIZE);
		if (data->coin_s == 70)
			data->coin_s = 0;
	}
}

void	player_put_img_bonus(t_data *data, int column, int i)
{
	if (data->play_f == 0)
	{
		if (data->play_s < 50)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.p_right, column, i * SIZE);
		else if (data->play_s >= 50 && data->play_s <= 100)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.p_rightb, column, i * SIZE);
		}
	}
	else if (data->play_f == 1)
	{
		if (data->play_s < 50)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.p_left, column, i * SIZE);
		else if (data->play_s >= 50 && data->play_s <= 100)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.p_leftb, column, i * SIZE);
		}
	}
}
