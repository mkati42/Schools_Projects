/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:42:37 by mkati             #+#    #+#             */
/*   Updated: 2023/05/22 13:42:37 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../so_long.h"

void	error_messages(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(0);
}