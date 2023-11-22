/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:26:53 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:03:07 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	valid_map(char *path, t_data *data)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	data->c_map = ft_calloc((data->map_data.line_count + 1), sizeof(char *));
	if (!(data->c_map))
		error_messages(ERRORALLOC);
	c_map_create(path, data, line, column);
	point_put(data, data->p_i, data->p_j);
	cmap_count_control(data, line, column);
}

void	c_map_create(char *path, t_data *data, int line_count, int column)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_messages(ERRORFD);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->c_map[line_count] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[i] != '\0')
			data->c_map[line_count][column++] = line[i++];
		data->c_map[line_count++][column] = '\0';
		column = 0;
		i = 0;
		free (line);
		line = get_next_line(fd);
	}
	data->c_map[line_count] = NULL;
	close (fd);
}

void	point_put(t_data *data, int i, int j)
{
	data->c_map[i][j] = '.';
	if (data->c_map[i][j + 1] != '1' && data->c_map[i][j + 1] != '.')
		point_put(data, i, j + 1);
	if (data->c_map[i + 1][j] != '1' && data->c_map[i + 1][j] != '.')
		point_put(data, i + 1, j);
	if (data->c_map[i][j - 1] != '1' && data->c_map[i][j - 1] != '.')
		point_put(data, i, j - 1);
	if (data->c_map[i - 1][j] != '1' && data->c_map[i - 1][j] != '.')
		point_put(data, i - 1, j);
}

void	cmap_count_control(t_data *data, int i, int j)
{
	int	count;

	count = 0;
	while (data->c_map[i])
	{
		while (data->c_map[i][j])
		{
			if (data->c_map[i][j] == 'C' || data->c_map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count > 0)
		error_messages(VALIDERROR);
}
