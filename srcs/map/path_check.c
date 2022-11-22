/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:16:11 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/22 17:05:49 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

int	path_check_right_bot(char **map, t_data data)
{
	int	y;
	int	x;

	y = data.exit_i;
	while (y && y < (data.win_height / 48) - 1)
	{
		x = data.exit_j;
		while (x && map[y][x])
		{
			if (map[y][x] == 'C')
				return (FAILURE);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	path_check_right_top(char **map, t_data data)
{
	int	y;
	int	x;

	y = data.exit_i;
	while (y && y < (data.win_height / 48) - 1)
	{
		x = data.exit_j;
		while (x && map[y][x])
		{
			if (map[y][x] == 'C')
				return (FAILURE);
			x++;
		}
		y--;
	}
	return (SUCCESS);
}

int	path_check_left_bot(char **map, t_data data)
{
	int	y;
	int	x;

	y = data.exit_i;
	while (y && y < (data.win_height / 48) - 1)
	{
		x = data.exit_j;
		while (x && map[y][x])
		{
			if (map[y][x] == 'C')
				return (FAILURE);
			x--;
		}
		y++;
	}
	return (SUCCESS);
}

int	path_check_left_top(char **map, t_data data)
{
	int	y;
	int	x;

	y = data.exit_i;
	while (y && y < (data.win_height / 48) - 1)
	{
		x = data.exit_j;
		while (x && map[y][x])
		{
			if (map[y][x] == 'C')
				return (FAILURE);
			x--;
		}
		y--;
	}
	return (SUCCESS);
}

int	path_check(char **map, t_data data)
{
	if (path_check_left_bot(map, data) == FAILURE
		|| path_check_left_top(map, data) == FAILURE
		|| path_check_right_bot(map, data) == FAILURE
		|| path_check_right_top(map, data) == FAILURE)
		return (FAILURE);
	else if (map[data.exit_i][data.exit_j + 1] == 'F'
		|| map[data.exit_i][data.exit_j - 1] == 'F'
		|| map[data.exit_i + 1][data.exit_j] == 'F'
		|| map[data.exit_i - 1][data.exit_j] == 'F')
		return (SUCCESS);
	else
		return (FAILURE);
}
