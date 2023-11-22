/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:20:37 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:00:50 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	file_name_control(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 1] != 'r' && path[i - 2] != 'e'
			&& path[i - 3] != 'b' && path[i - 4] != '.')
		|| i <= 4)
		error_messages(ERRORPATH);
}

void	xpm_control(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	fd5;

	fd1 = open(GROUND, O_RDONLY);
	fd2 = open(COIN, O_RDONLY);
	fd3 = open(EXIT, O_RDONLY);
	fd4 = open(P_RIGHT, O_RDONLY);
	fd5 = open(WALL, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0 || fd5 < 0)
	{
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		close(fd5);
		error_messages(NOXPM);
	}
}
