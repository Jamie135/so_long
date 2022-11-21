/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:16:11 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/19 19:36:18 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

char	**malloc_copy(t_data *data)
{
	char	**copy;
	int		c;

	copy = malloc(sizeof(char *) * data->win_height);
	if (!copy)
		return (NULL);
	c = 0;
	while (c <= data->win_height)
	{
		copy[c] = malloc(sizeof(char *) * data->win_width);
		if (!copy[c])
			return (NULL);
		c++;
	}
	return (copy);
}

char	**map_copy(char **map, t_data *data)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc_copy(data);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C')
				copy[i][j] = '0';
			else
				copy[i][j] = data->map.map[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

void	flood_fill(char **map, t_data data, int x, int y, char key)
{
	if (x < 0 || y < 0 || x >= (data.win_width / 48) - 1 || y >= (data.win_height / 48) - 1
		|| map[y][x] != key)
		return ;
	map[y][x] = 'F';
	flood_fill(map, data, x, y + 1, key);
	flood_fill(map, data, x, y - 1, key);
	flood_fill(map, data, x + 1, y, key);
	flood_fill(map, data, x - 1, y, key);
}
