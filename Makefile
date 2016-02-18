# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:24:47 by mdos-san          #+#    #+#              #
#    Updated: 2016/02/18 13:53:25 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

OS			= $(shell uname)

COMPILER	= gcc
FLAGS		= -Wall -Werror -Wextra -I./includes -g -fsanitize=address
LIBS		= -L./libs -lft -lmlx -framework OpenGL -framework AppKit

TMP_C		=\
			wolf3d_init.c\
			wolf3d_start.c\
			wolf3d_exit.c\
			wolf3d_map_load.c\
			wolf3d_map_del.c\
			wolf3d_map_draw.c\
			wolf3d_player_init.c\
			wolf3d_player_draw.c\
			img_putpixel.c\
			img_clear.c\
			event_key.c\
			hook_loop.c\
			hook_expose.c\
			main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all			: $(NAME)

$(NAME)		: objects libs/libft.a libs/libmlx.a $(SRC_O)
	@echo "Creating wolf3d... \c"
	@$(COMPILER) $(FLAGS)  $(LIBS) -o $(NAME) $(SRC_O)
	@echo "[ok]"

objects: 
	@echo "Creating the folder objects... \c"
	@mkdir objects
	@echo "[ok]"

libs/libft.a	:
	@echo "Making libft... \c"
	@make -C libs/libft
	@mv libs/libft/libft.a libs
	@make -C libs/libft/ fclean
	@echo "[ok]"

libs/libmlx.a	:
	@echo "Making libmlx... \c"
	@make -s -C libs/minilibx_macos/
	@mv libs/minilibx_macos/libmlx.a libs
	@make -s -C libs/minilibx_macos/ clean
	@echo "[ok]"

objects/%.o	: srcs/%.c
	@echo "Compiling $<... \c"
	@$(COMPILER) $(FLAGS) -c $<
	@mv $(notdir $@) objects
	@echo "[ok]"

clean		:
	@echo "Removing objects... \c"
	@rm -rf objects
	@echo "[ok]"

fclean		: clean
	@echo "Removing all compiled files... \c"
	@rm -rf $(NAME)
	@rm -rf libs/libft.a
	@rm -rf libs/libmlx.a
	@echo "[ok]"

re			: fclean all
