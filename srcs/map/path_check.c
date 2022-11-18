/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:16:11 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/18 15:07:43 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

void	fill(t_img **map, t_img size, t_data *data , char key)
{
	data->map.map[data->player_i][data->player_j] = 'F';
	
}

void	flood_fill(t_data *data)
{
	fill(data->map, '0');
}