/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:53:54 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/10 00:53:54 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_ber(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_RDONLY);
		close(fd);
		if ((path[len - 4] != '.' && path[len - 3] != 'b'
				&& path[len - 2] != 'e'
				&& path[len - 1] != 'r') || fd < 0)
			return (FAILURE);
		else
			return (SUCCESS);
	}
}
