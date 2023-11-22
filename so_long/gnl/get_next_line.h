/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:36:44 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/05/22 18:33:19 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
int		ft_fnl(char *str);
char	*ft_strjjoin(char *str, char *buffer);
char	*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char	*next_line(char *str);
char	*read_line(char	*str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif
