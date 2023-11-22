/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:50:14 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:07:44 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	close_window(t_data *data)
{
	mlx_clear_window (data->mlx, data->win);
	mlx_destroy_window (data->mlx, data->win);
	exit(0);
}

int	close_hook(t_data *data)
{
	close_window(data);
	return (0);
}
