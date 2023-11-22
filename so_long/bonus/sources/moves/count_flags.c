/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:40:11 by mkati             #+#    #+#             */
/*   Updated: 2023/06/05 15:00:49 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../so_long_bonus.h"

void	count_flag_second(t_data *data)
{
	data->coin_s++;
	data->play_s++;
	if (data->coin_s == 70)
		data->coin_s = 0;
	if (data->play_s == 100)
		data->play_s = 0;
}
