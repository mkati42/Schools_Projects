/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:43:46 by mkati             #+#    #+#             */
/*   Updated: 2023/01/18 03:57:49 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

char	*text_newline(char *left)
{
	char	*buff;
	int		i;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	i++;
	buff = ft_substr(left, i, (ft_strlen(left) - i));
	if (!buff)
		return (NULL);
	free(left);
	return (buff);
}

char	*readn_write_fd(char *text2, int fd)
{
	int		lenread;
	char	*readtext;

	readtext = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readtext)
		return (0);
	lenread = 1;
	while (!(ft_strchr(text2, '\n')) && lenread != 0)
	{
		lenread = read(fd, readtext, BUFFER_SIZE);
		if (lenread == -1)
		{
			free (text2);
			free (readtext);
			return (0);
		}
		readtext[lenread] = '\0';
		text2 = ft_strjoin(text2, readtext);
	}
	free (readtext);
	return (text2);
}

char	*pump_function(char *text1)
{
	int		i;
	char	*line;

	i = 0;
	if (!(text1[i]))
		return (0);
	while (text1[i] != '\n' && text1[i] != '\0')
		i++;
	if (text1[i] == '\n')
		line = ft_substr(text1, 0, i + 1);
	else
		line = ft_substr(text1, 0, i);
	if (!line)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	text = readn_write_fd(text, fd);
	if (!text)
		return (0);
	ret = pump_function(text);
	text = text_newline(text);
	return (ret);
}
