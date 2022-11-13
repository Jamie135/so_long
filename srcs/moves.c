/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:18:50 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/13 16:10:42 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_direction(t_data *data, char direction, char key)
{
	if ((direction == 'd'
			&& data->map.map[data->player_i][data->player_j + 1] == key)
			|| (direction == 'a'
			&& data->map.map[data->player_i][data->player_j - 1] == key)
			|| (direction == 's'
			&& data->map.map[data->player_i + 1][data->player_j] == key)
			|| (direction == 'w'
			&& data->map.map[data->player_i - 1][data->player_j] == key))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	is_item(t_data *data, char direction)
{
	if ((direction == 'd'
			&& data->map.map[data->player_i][data->player_j + 1] == 'C')
			|| (direction == 'a'
			&& data->map.map[data->player_i][data->player_j - 1] == 'C')
			|| (direction == 's'
			&& data->map.map[data->player_i + 1][data->player_j] == 'C')
			|| (direction == 'w'
			&& data->map.map[data->player_i - 1][data->player_j] == 'C'))
		data->map.collected++;
}

void	move_message(t_data *data)
{
	printf("Moves counter: %d\n", data->steps);
}

int	winner(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void	move_player(t_data *data, char direction)
{
	if (next_direction(data, direction, '1') == SUCCESS
		|| (data->map.can_exit == 0
			&& next_direction(data, direction, 'E') == SUCCESS))
		return ;
	data->steps++;
	is_item(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->player_i][data->player_j] = '0';
	if (direction == 'd')
		data->player_j++;
	else if (direction == 'a')
		data->player_j--;
	else if (direction == 's')
		data->player_i++;
	else if (direction == 'w')
		data->player_i--;
	move_message(data);
	if (data->map.can_exit == 1
		&& data->map.map[data->player_i][data->player_j] == 'E')
		winner(data);
	data->map.map[data->player_i][data->player_j] = 'P';
}
