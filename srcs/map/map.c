/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:10:53 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/14 17:15:22 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_row(char *path)
{
	int		row_count;
	int		fd;
	char	*row;

	row_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_putendl_fd("Error: Open failed.", 2);
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

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return (free_tabs(data->map.map));
		while (line[i] != '\0')
			data->map.map[row][col++] = line[i++];
		data->map.map[row++][col] = '\0';
		col = 0;
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
		return ;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		message_error(ERROR_INFILE, data);
	else
	{
		input_map(row, col, i, data);
		close(data->map.fd);
	}
}
