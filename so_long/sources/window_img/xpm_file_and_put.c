/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_and_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 03:24:11 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:09:51 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	my_xpm_to_file(void *mlx, t_data *data)
{
	data->img.img_g = mlx_xpm_file_to_image(mlx, GROUND,
			&data->img.w, &data->img.h);
	data->img.img_c = mlx_xpm_file_to_image(mlx, COIN,
			&data->img.w, &data->img.h);
	data->img.img_e = mlx_xpm_file_to_image(mlx, EXIT,
			&data->img.w, &data->img.h);
	data->img.img_w = mlx_xpm_file_to_image(mlx, WALL,
			&data->img.w, &data->img.h);
	data->img.img_p = mlx_xpm_file_to_image(mlx, P_RIGHT,
			&data->img.w, &data->img.h);
}

void	my_xpm_put_window(t_data *data, int i, int column, int j)
{
	if (data->map_data.map[i][j] != '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_g, column, i * SIZE);
	if (i == data->e_i && j == data->e_j)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_e, column, i * SIZE);
	if (data->map_data.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_w, column, i * SIZE);
	if (data->map_data.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_p, column, i * SIZE);
	if (data->map_data.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.img_c, column, i * SIZE);
}

void	render_window(t_data *data)
{
	int	i;
	int	j;
	int	column;

	i = 0;
	j = 0;
	column = 0;
	while (i < data->map_data.line_count)
	{
		while (j < data->map_data.line_len)
		{
			my_xpm_put_window(data, i, column, j);
			column += SIZE;
			j++;
		}
		column = 0;
		j = 0;
		i++;
	}
}
