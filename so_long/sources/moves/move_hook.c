/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:13:28 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:08:41 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	moves_hook(int keycode, t_data *data)
{
	if (keycode == 2 || keycode == 124)
		move_control(data->p_i, data->p_j + 1, data);
	else if (keycode == 0 || keycode == 123)
		move_control (data->p_i, data->p_j - 1, data);
	else if (keycode == 1 || keycode == 125)
		move_control (data->p_i + 1, data->p_j, data);
	else if (keycode == 13 || keycode == 126)
		move_control (data->p_i - 1, data->p_j, data);
	else if (keycode == 53)
		close_window(data);
	return (0);
}

void	move_control(int x, int y, t_data *data)
{
	if (data->map_data.map[x][y] != '1')
	{
		if (data->map_data.map[x][y] == 'C')
			data->map_data.collect_count++;
		if (data->p_i == data->e_i && data->p_j == data->e_j)
			data->map_data.map[data->p_i][data->p_j] = 'E';
		else
			data->map_data.map[data->p_i][data->p_j] = '0';
		data->map_data.map[x][y] = 'P';
		data->p_i = x;
		data->p_j = y;
		data->step_count++;
		write_step(data);
		if (x == data->e_i && y == data->e_j)
		{
			if (data->map_data.collect_count == data->map_data.c_count)
				win_game (x, y, data);
		}
	}
	render_window(data);
}

void	win_game(int x, int y, t_data *data)
{
	data->map_data.map[data->p_i][data->p_j] = '0';
	data->map_data.map[x][y] = 'P';
	data->p_i = x;
	data->p_j = y;
	render_window(data);
	close_window(data);
}

void	write_step(t_data *data)
{
	data->step_c = ft_calloc(data->step_count + 1, sizeof(char));
	if (!data->step_c)
	{
		error_messages(ERRORALLOC);
		close_window(data);
	}
	data->step_c = ft_itoa(data->step_count);
	ft_printf("Your Step Count : %s\n", data->step_c);
	free(data->step_c);
}
