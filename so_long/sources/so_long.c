/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:27:52 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:11:01 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	open_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			data->window_w, data->window_h, "NEW WINDOW");
	my_xpm_to_file(data->mlx, data);
	render_window(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		file_name_control (av[1]);
		create_map(av[1], &data);
		data_mapn_img(&data);
		control_count(&data);
		player_data(&data);
		valid_map(av[1], &data);
		xpm_control();
		open_window(&data);
		mlx_hook (data.win, 2, 1L << 0, moves_hook, &data);
		mlx_hook (data.win, 17, 0, close_hook, &data);
		mlx_loop (data.mlx);
	}
	else
		return (0);
}
