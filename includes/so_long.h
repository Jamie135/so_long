/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:31 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/23 14:29:34 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

# define IMG_SIZE 48

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define A 97
# define D 100
# define S 115
# define W 119

# define TITLE "so_long"
# define PLAYER "images/set2/player.xpm"
# define EXIT "images/set2/exit.xpm"
# define ROCK "images/set2/rock.xpm"
# define GRASS "images/set2/grass.xpm"
# define ITEM "images/set2/item.xpm"

# define ERROR_ARG "Invalid number of argument."
# define ERROR_BER "Invalid .ber file."
# define ERROR_FAKE ".ber file is empty."
# define ERROR_OTHER "Invalid characters on the map."
# define ERROR_CHAR "Some characters are missing: 0, 1, P, E, C."
# define ERROR_PLAYER_EXIT "There must be one player and one exit."
# define ERROR_REC "The map is not a rectangle."
# define ERROR_SIDES "Invalid walls on the map."
# define ERROR_INFILE "Open failed."
# define ERROR_PATH "The exit is unreachable."

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		height;
	int		width;
	void	*wall;
	void	*exit_way;
	void	*ground;
	void	*player;
	int		line_len;
	void	*item;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		steps;
	int		i;
	int		j;
	int		player_i;
	int		player_j;
	int		exit_i;
	int		exit_j;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
}	t_data;

//	map.c
int		get_row(char *path);
void	input_map(int row, int col, t_data *data);
void	create_map(t_data *data, char *path);
//	map_setup.c
void	set_map(t_data *data);
void	set_player_exit(t_data *data);
//	map_check.c
int		check_pec(t_data *data);
int		check_topbot(int row, char **map);
int		check_sides(int row_count, char **map);
int		check_rectangle(t_data *data);
int		check_map(t_data *data);
//	path_fill.c
char	**malloc_copy(t_data *data);
char	**map_copy(char **map, t_data *data);
void	flood_fill(char **map, t_data data, int y, int x);
//	path_check.c
int		path_check_right_bot(char **map, t_data data);
int		path_check_right_top(char **map, t_data data);
int		path_check_left_bot(char **map, t_data data);
int		path_check_left_top(char **map, t_data data);
int		path_check(char **map, t_data data);
//	minilibx_utils.c
int		new_window(t_data *data);
void	file_to_images(t_data *data);
void	loop_images(t_data data);
void	destroy_images(t_data data);
//	handler.c
int		handle_resize(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrealease(t_data *data);
//	render.c
void	parse_char(t_data *data, int width, int i, int j);
int		render(t_data *data);
//	moves.c
int		next_direction(t_data *data, char direction, char key);
void	is_item(t_data *data, char direction);
void	move_message(t_data *data);
int		winner(t_data *data);
void	move_player(t_data *data, char direction);
//	utils.c
int		check_ber(char *path);
void	free_tabs(char **tab);
void	message_error(char *str, t_data *data);

#endif