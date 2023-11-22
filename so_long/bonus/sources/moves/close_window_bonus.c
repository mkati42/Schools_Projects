/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:50:14 by mkati             #+#    #+#             */
/*   Updated: 2023/05/31 03:58:47 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../so_long_bonus.h"

void	close_window_bonus(t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	mlx_destroy_window (data->mlx, data->win);
	exit(0);
}

int	close_hook_bonus(t_data *data)
{
	close_window_bonus(data);
	return (0);
}
