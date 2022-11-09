/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:10:53 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/09 21:10:53 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tabs(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

int	get_row(char *path)
{
	int		fd;
	int		row_count;
	char	*row;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Error: open failed\n");
	row_count = 0;
	else
	{
		row = get_next_line(fd);
		while (row != NULL)
		{
			row_count++;
			free(row);
			row = get_next_line(fd);
		}
		close(fd);
	}
	return (row_count);
}

void	input_map(int row, int col, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd)
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return (free_tabs(data->map.map));
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}

void	create_map(t_data *data, char *path)
{
	int		i;
	int		row;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	data->map.line_count = get_row(path);
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		return;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		printf("Error: open failed\n");
	else
	{
		input_map(row, col, i, data);
		close(data->map.fd);
	}
}