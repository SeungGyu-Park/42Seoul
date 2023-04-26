# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mojo <mojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 10:54:39 by mojo              #+#    #+#              #
#    Updated: 2022/08/04 11:03:21 by mojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC_FILE = so_long \
			read_file \
			check_map \
			init_game \
			put_elements \
			put_character \
			exec_game \
			free_game
B_SRC_FILE = so_long \
			read_file \
			check_map \
			init_game \
			put_elements \
			put_character \
			exec_game \
			free_game \
			put_enemy \
			print_movements
SRC = $(addprefix mandatory/, $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix mandatory/, $(addsuffix .o, $(SRC_FILE)))
B_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, $(B_SRC_FILE)))
B_OBJ = $(addprefix bonus/, $(addsuffix _bonus.o, $(B_SRC_FILE)))
MLX = minilibx_opengl_20191021
LIBFT = libft

ifdef WITH_BONUS
	OBJ_FILES = $(B_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(FLAGS) -I $(MLX) -L $(LIBFT) -lft -L $(MLX) -lmlx -framework OpenGL -framework AppKit $^ -o $@

bonus : $(B_OBJ)
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	make fclean -C $(LIBFT)
	make clean -C $(MLX)
	rm -f $(MLX)/libmlx

fclean : clean
	rm -f $(NAME)

re : fclean all
