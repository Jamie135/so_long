/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:25:31 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/12 19:25:31 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_char(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.wall, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.ground, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.exit_l, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.item, width, i * IMG_SIZE);
}

int	render(t_data *data)
{
	int		width;
	int		i;
	size_t	j;

	if (data->win_ptr == NULL)
		return (FAILURE);
	width = 0;
	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			parse_char(data, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		i++;
		j = 0;
		width = 0;
	}
	return (SUCCESS);
}
