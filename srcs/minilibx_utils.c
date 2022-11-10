/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:44:19 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/10 16:59:43 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, TITLE);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (ERROR);
	}
	return (SUCCESS);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx_ptr, GROUND,
			&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx_ptr, LOCKED,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, W_RAND,
			&data->img.width, &data->img.height);
	data->img.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM,
			&data->img.width, &data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &data);
	mlx_loop(data.mlx_ptr);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx_ptr, data.img.wall);
	mlx_destroy_image(data.mlx_ptr, data.img.ground);
	mlx_destroy_image(data.mlx_ptr, data.img.player);
	mlx_destroy_image(data.mlx_ptr, data.img.exit_l);
	mlx_destroy_image(data.mlx_ptr, data.img.item);
	mlx_destroy_display(data.mlx_ptr);
}
