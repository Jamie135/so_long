# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:22:42 by pbureera          #+#    #+#              #
#    Updated: 2022/11/15 14:37:16 by pbureera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS_DIR	=	./srcs/
SRCS		=	map/map.c \
				map/map_setup.c \
				map/map_check.c \
				map/utils.c \
				image/minilibx_utils.c \
				image/render.c \
				event/handler.c \
				event/moves.c \
				main.c
OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

LIBFT_DIR	=	libft
LIBFT_MAKE	= 	Makefile
LIBFT_PATH	=	$(LIBFT_DIR)/libft.a

GNL_DIR		=	./get_next_line/
GNL_SRCS	=	get_next_line.c \
				get_next_line_utils.c
GNL_OBJS	=	$(addprefix $(GNL_DIR), $(GNL_SRCS:.c=.o))

MLX_DIR		=	minilibx-linux
MLX_MAKE	=	Makefile
MLX_PATH	=	$(MLX_DIR)/libmlx.a

CC			=	clang
C_FLAGS		=	-Wall -Wextra -Werror -g
I_FLAGS		=	-I ./includes
LIBFT_FLAGS	=	-L $(LIBFT_DIR) -lft
MLX_FLAGS	=	-ldl -lmlx -L$(MLX_DIR) -lm -lXext -lX11 -Imlx $(MLX_PATH)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C $(MLX_DIR)
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(CC) $(C_FLAGS) $(OBJS) $(GNL_OBJS) $(I_FLAGS) $(LIBFT_FLAGS) -o $(NAME) $(MLX_FLAGS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(GNL_OBJS)
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) -f $(LIBFT_MAKE) clean
	@make -C $(MLX_DIR) -f $(MLX_MAKE) clean

fclean: clean
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re