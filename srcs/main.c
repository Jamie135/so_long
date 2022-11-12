/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:20:50 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/10 16:43:25 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	if (check_extension(argv[1]) == FAILURE)
		message_error(ERROR_BER, &data);
	create_map(argv[1], &data);
	set_map(&data);
	check_map(&data);
	set_player(&data);
	new_window(&data);
	file_to_images(&data);
	render(&data);
	loop_images(data);
	destroy_images(data);
	free(data.mlx_ptr);
	if (data.map.map)
		free_tabs(data.map.map);
}
