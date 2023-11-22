/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:26:23 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 15:54:21 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../so_long_bonus.h"

void	my_xpm_to_file_bonus(void *mlx, t_data *data)
{
	data->img.img_g = mlx_xpm_file_to_image(mlx, GROUND,
			&data->img.w, &data->img.h);
	data->img.knife1 = mlx_xpm_file_to_image(mlx, COIN,
			&data->img.w, &data->img.h);
	data->img.knife2 = mlx_xpm_file_to_image(mlx, COIN2,
			&data->img.w, &data->img.h);
	data->img.p_right = mlx_xpm_file_to_image(mlx, P_RIGHT,
			&data->img.w, &data->img.h);
	data->img.p_rightb = mlx_xpm_file_to_image(mlx, P_RIGHTB,
			&data->img.w, &data->img.h);
	data->img.p_left = mlx_xpm_file_to_image(mlx, P_LEFT,
			&data->img.w, &data->img.h);
	data->img.p_leftb = mlx_xpm_file_to_image(mlx, P_LEFTB,
			&data->img.w, &data->img.h);
	data->img.img_e = mlx_xpm_file_to_image(mlx, EXIT,
			&data->img.w, &data->img.h);
	data->img.img_w = mlx_xpm_file_to_image(mlx, WALL,
			&data->img.w, &data->img.h);
	data->img.foe_r = mlx_xpm_file_to_image(mlx, FOE_R,
			&data->img.w, &data->img.h);
	data->img.foe_l = mlx_xpm_file_to_image(mlx, FOE_L,
			&data->img.w, &data->img.h);
}

void	xpm_control_bonus(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(GROUND, O_RDONLY);
	fd2 = open(COIN, O_RDONLY);
	fd3 = open(EXIT, O_RDONLY);
	fd4 = open(WALL, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		error_messages_bonus(NOXPM);
	}
}

void	xpm_control2_bonus(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(COIN2, O_RDONLY);
	fd2 = open(FOE_R, O_RDONLY);
	fd3 = open(FOE_L, O_RDONLY);
	fd4 = open(P_RIGHT, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		error_messages_bonus(NOXPM);
	}
}

void	xpm_control3_bonus(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open(P_RIGHTB, O_RDONLY);
	fd2 = open(P_LEFT, O_RDONLY);
	fd3 = open(P_LEFTB, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		close(fd1);
		close(fd2);
		close(fd3);
		error_messages_bonus(NOXPM);
	}
}
