/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:16:38 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 15:55:33 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	open_window_bonus(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			data->window_w, data->window_h, "NEW WINDOW");
	my_xpm_to_file_bonus(data->mlx, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.play_f = 0;
	if (ac == 2)
	{
		file_name_control_bonus (av[1]);
		create_map_bonus(av[1], &data);
		data_mapn_img_bonus(&data);
		control_count_bonus(&data);
		player_data_bonus(&data);
		foe_data_bonus(&data);
		valid_map_bonus(av[1], &data);
		xpm_control_bonus();
		xpm_control2_bonus();
		xpm_control3_bonus();
		open_window_bonus(&data);
		mlx_loop_hook(data.mlx, &render_window_bonus, &data);
		mlx_hook (data.win, 2, 1L << 0, moves_hook_bonus, &data);
		mlx_hook (data.win, 17, 0, close_hook_bonus, &data);
		mlx_loop(data.mlx);
	}
	else
		return (0);
}
