/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:43:21 by mkati             #+#    #+#             */
/*   Updated: 2023/05/22 13:43:21 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	control_topn_bot(int line, char **map)
{
	int	i;

	i = 0;
	while (map[line][i] != '\n' && map[line][i])
	{
		if (map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_control(int line_count, char **map)
{
	int	i;

	i = 1;
	if (control_topn_bot(0, map) == 0
		|| control_topn_bot (line_count - 1, map) == 0)
		return (0);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	all_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map_data.line_len = ft_strlen(data->map_data.map[i]) - 1;
	while (data->map_data.map[i])
	{
		while (data->map_data.map[i][j]
			&& data->map_data.map[i][j] != '\n')
			j++;
		if (j != data->map_data.line_len)
			return (0);
		i++;
	}
	return (1);
}

int	count_char(t_data *data)
{
	while (data->map_data.map[data->i] != NULL)
	{
		while (data->map_data.map[data->i][data->j])
		{
			if (data->map_data.map[data->i][data->j] == 'P')
				data->map_data.p_count++;
			else if (data->map_data.map[data->i][data->j] == 'E')
				data->map_data.e_count++;
			else if (data->map_data.map[data->i][data->j] == 'C')
				data->map_data.c_count++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	data->i = 0;
	if (data->map_data.p_count != 1
		|| data->map_data.e_count != 1 || !data->map_data.c_count)
		return (0);
	else
		return (1);
}

void	control_count(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map_data.map[i] != NULL)
	{
		while (j < ft_strlen(data->map_data.map[i]) - 1)
		{
			if (ft_strchr("PEC01", data->map_data.map[i][j]) == NULL)
				error_messages(INVMAP);
			j++;
		}
		j = 0;
		i++;
	}
	if (count_char(data) == 0)
		error_messages(INVCHAR);
	if (data->map_data.p_count > 1 || data->map_data.e_count > 1)
		error_messages(INVPLAYER);
	if (all_line(data) == 0)
		error_messages(ROWSERROR);
	if (wall_control(data->map_data.line_count, data->map_data.map) == 0)
		error_messages(WALLERROR);
}
