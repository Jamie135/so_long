/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:48:18 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/10 00:48:18 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	message_error(char *str, t_data *data)
{
	if (data->map.map)
		free_tabs(data->map.map);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	write (2, "\n", 1);
	exit(1);
}
