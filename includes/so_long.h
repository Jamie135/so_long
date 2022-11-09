/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:31 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/08 17:12:55 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

# define IMG_SIZE 48
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define A 97
# define D 100
# define S 115
# define W 119

# define ERROR_BER "Argument is not a correct .ber file.\n"
# define ERROR_OTHER "At least one character of the map is not valid.\n"
# define ERROR_CHAR "One of the characters \"0, 1, P, C, E\" is missing.\n"
# define ERROR_PLAYER "This is a solo campaign...\n"
# define ERROR_PLAYERB "There can be only one player on each side...\n"
# define ERROR_REC "The map is not a rectangle.\n"
# define ERROR_EDGES "The edges of the map are invalid (must be walls -1-)\n"

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
	char	*addr;
	int		height;
	int		width;
	void	*wall;
	void	*exit_1;
	void	*ground;
	void	*player;
	void	*item;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
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
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

void	free_tabs(char **tab);
int		get_row(char *path);
void	input_map(int row, int col, int i, t_data *data);
void	create_map(t_data *data, char *path);
void	set_map(t_data *data);
void	set_player(t_data *data);

void	message_error(char *str, t_data *data);
int		check_ber(char *path);

#endif