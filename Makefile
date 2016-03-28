# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:24:47 by mdos-san          #+#    #+#              #
#    Updated: 2016/03/28 13:50:11 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

OS			= $(shell uname)

COMPILER	= gcc
FLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address -I./includes
LIBS		= -L./libs -lm -lft -lcolor -lmlx -framework OpenGL -framework AppKit
MLX_DIR		= minilibx_macos

ifeq ($(OS), Linux)
LIBS		= -L./libs -lm -lft -lcolor -lmlx -lX11 -lXext
MLX_DIR		= minilibx_linux
endif

TMP_C		=\
			wolf3d_init.c\
			wolf3d_start.c\
			wolf3d_exit.c\
			wolf3d_map_load.c\
			wolf3d_map_del.c\
			wolf3d_map_draw.c\
			wolf3d_map_is_wall.c\
			wolf3d_player_init.c\
			wolf3d_player_draw.c\
			wolf3d_player_move.c\
			wolf3d_ray_draw.c\
			wolf3d_render.c\
			img_putpixel.c\
			img_putline.c\
			img_fill.c\
			img_clear.c\
			event_key.c\
			hook_loop.c\
			hook_expose.c\
			vec_rotate_2d.c\
			pnt_2d_new.c\
			pnt_2d_del.c\
			player_new.c\
			player_del.c\
			textures_load.c\
			check_full_line.c\
			main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_H		=\
			wolf3d.h\
			libft.h\
			mlx.h

SRC_H		= $(TMP_H:%=includes/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all			: $(NAME)

$(NAME)		: objects libs/libft.a libs/libcolor.a libs/libmlx.a $(SRC_O) $(SRC_H)
	@echo "Creating wolf3d... \c"
	@$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_O) $(LIBS)
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

libs/libcolor.a	:
	@echo "Making libcolor... \c"
	@make -C libs/libcolor
	@mv libs/libcolor/libcolor.a libs
	@make -C libs/libcolor fclean
	@echo "[ok]"

libs/libmlx.a	:
	@echo "Making libmlx... \c"
	@echo $(MLX_DIR)
	@make -s -C libs/$(MLX_DIR)/
	@mv libs/$(MLX_DIR)/libmlx.a libs
	@make -s -C libs/$(MLX_DIR)/ clean
	@echo "[ok]"

gupdate	:
	git add srcs includes Makefile
	git commit -m "update"
	git push origin dev

objects/%.o	: srcs/%.c
	@echo "Compiling $<... \c"
	@$(COMPILER) $(FLAGS) -c $<
	@mv $(notdir $@) objects
	@echo "[ok]"

clean		:
	@echo "Removing objects... \c"
	@rm -rf objects
	@echo "[ok]"

norme		:
	norminette srcs includes

fclean		: clean
	@echo "Removing all compiled files... \c"
	@rm -rf $(NAME)
	@rm -rf libs/libft.a
	@rm -rf libs/libcolor.a
	@rm -rf libs/libmlx.a
	@echo "[ok]"

re			: fclean all

norm		:
	@norminette srcs includes

.PHONY: re fclean clean all
