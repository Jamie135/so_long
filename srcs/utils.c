/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:48:18 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/13 14:17:35 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_ber(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	if (len < 4)
		return (FAILURE);
	if (open(path, O_DIRECTORY || __O_NOFOLLOW) >= 0)
	{
		fd = open(path, O_DIRECTORY || __O_NOFOLLOW);
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_RDONLY || __O_NOFOLLOW);
		close(fd);
		if ((path[len - 4] != '.' && path[len - 3] != 'b'
				&& path[len - 2] != 'e'
				&& path[len - 1] != 'r') || fd < 0)
			return (FAILURE);
		else
			return (SUCCESS);
	}
}

void	message_error(char *str, t_data *data)
{
	if (data->map.map)
		free_tabs(data->map.map);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

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
