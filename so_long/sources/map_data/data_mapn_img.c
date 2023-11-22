/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_mapn_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:43:29 by mkati             #+#    #+#             */
/*   Updated: 2023/05/22 13:43:29 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	data_mapn_img(t_data *data)
{
	data->map_data.e_count = 0;
	data->map_data.p_count = 0;
	data->map_data.c_count = 0;
	data->i = 0;
	data->j = 0;
	data->step_count = 0;
	data->map_data.collect_count = 0;
	data->map_data.exit_count = 0;
	data->window_w = ((ft_strlen(data->map_data.map[0]) - 1) * 128);
	data->window_h = data->map_data.line_count * 128;
	data->img.w = 128;
	data->img.h = 128;
}
