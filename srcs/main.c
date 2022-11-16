/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:20:50 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/16 15:24:01 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"


void print_map(char **map)
{
	int i = 0;

	if (!map[i])
	{
		printf("(null)\n");
		return ;
	}
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	if (check_ber(argv[1]) == FAILURE)
		message_error(ERROR_BER, &data);
	create_map(&data, argv[1]);
	set_map(&data);
	check_map(&data);
	set_player(&data);
	print_map(data.map.map);
	new_window(&data);
	file_to_images(&data);
	write (2, "main\n", 5);
	render(&data);
	write (2, "main\n", 5);
	loop_images(data);
	destroy_images(data);
	free(data.mlx_ptr);
	if (data.map.map)
		free_tabs(data.map.map);
}
