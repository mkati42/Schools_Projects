/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:52:56 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:17:22 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	real_crtmap(char *path, t_data *data, int line_count, int column)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		error_messages(INVMAP);
	}
	while (line != NULL)
	{
		data->map_data.map[line_count]
			= ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[i] != '\0')
			data->map_data.map[line_count][column++] = line[i++];
		data->map_data.map[line_count++][column] = '\0';
		column = 0;
		i = 0;
		free (line);
		line = get_next_line(fd);
	}
	data->map_data.map[line_count] = NULL;
	close (fd);
}

int	map_line_count(char *path, int line_count)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_messages(ERRORFD);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (line_count);
}

void	create_map(char *path, t_data *data)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	data->map_data.line_count = map_line_count(path, line);
	data->map_data.map
		= ft_calloc((data->map_data.line_count + 1), sizeof(char *));
	if (!(data->map_data.map))
		error_messages(ERRORALLOC);
	real_crtmap(path, data, line, column);
}
