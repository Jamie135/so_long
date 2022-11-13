# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:22:42 by pbureera          #+#    #+#              #
#    Updated: 2022/11/13 17:22:10 by pbureera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS_DIR	=	./srcs/
SRCS		=	main.c \
				map.c \
				map_setup.c \
				map_check.c \
				minilibx_utils.c \
				events.c \
				render.c \
				moves.c \
				utils.c					
OBJS		=	$(addprefix $(SRCS_DIR), $(SRC:.c=.o))

LIBFT_DIR	=	libft
LIBFT_MAKE	= 	Makefile
LIBFT_PATH	=	$(LIBFT_DIR)/libft.a

MLX_DIR		=	minilibx-linux
MLX_MAKE	=	Makefile
MLX_PATH	=	$(MLX_DIR)/libmlx.a

CC			=	clang
C_FLAGS		=	-Wall -Wextra -Werror -g
I_FLAGS		=	-I ./includes
LIBFT_FLAGS	=	-L $(LIBFT_DIR) -lft
MLX_FLAGS	=	-ldl -lmlx -L$(MLX_DIR) -lm -lXext -Imlx $(MLX_PATH)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(CC) $(C_FLAGS) $(OBJS) $(I_FLAGS) $(LIBFT_FLAGS) -o $(NAME) $(MLX_FLAGS)

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) -f $(LIBFT_MAKE) clean

fclean: clean
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re