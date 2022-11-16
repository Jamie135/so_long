/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:53:54 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/16 18:14:34 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

int	check_pec(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'P')
				data->map.count_p++;
			else if (data->map.map[data->i][data->j] == 'E')
				data->map.count_e++;
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.count_c++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (!data->map.count_c || !data->map.count_e || !data->map.count_p)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	check_topbot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_sides(int row_count, char **map)
{
	int	i;

	i = 1;
	if (check_topbot(0, map) == FAILURE
		|| check_topbot(row_count, map) == FAILURE)
		return (FAILURE);
	while (i < row_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (FAILURE);
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (ft_strchr("01CEP", data->map.map[i][j]) == NULL)
				message_error(ERROR_OTHER, data);
			j++;
		}
		j = 0;
		i++;
	}
	//write(2, "check_map\n", 10);
	if (check_pec(data) == FAILURE)
		message_error(ERROR_CHAR, data);
	//write(2, "check_map\n", 10);
	if (data->map.count_p != 1)
		message_error(ERROR_PLAYER, data);
	if (check_rectangle(data) == FAILURE)
		message_error(ERROR_REC, data);
	if (check_sides(data->map.line_count - 1, data->map.map) == FAILURE)
		message_error(ERROR_SIDES, data);
	return (SUCCESS);
}
