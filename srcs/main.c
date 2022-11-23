/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:20:50 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/23 12:50:39 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
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
	char	**copy;

	if (argc != 2)
		return (0);
	if (check_ber(argv[1]) == FAILURE)
		message_error(ERROR_BER, &data);
	create_map(&data, argv[1]);
	set_map(&data);
	check_map(&data);
	set_player_exit(&data);
	copy = map_copy(data.map.map, &data);
	flood_fill(copy, data, data.player_i, data.player_j);
	if (path_check(copy, data) == FAILURE)
		message_error(ERROR_PATH, &data);
	new_window(&data);
	file_to_images(&data);
	render(&data);
	loop_images(data);
	destroy_images(data);
	free(data.mlx_ptr);
	if (data.map.map)
		free_tabs(data.map.map);
}
