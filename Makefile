# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:24:47 by mdos-san          #+#    #+#              #
#    Updated: 2016/02/18 08:12:35 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

OS			= $(shell uname)

COMPILER	= gcc
FLAGS		= -Wall -Werror -Wextra -I./includes
LIBS		= -L./libs -lft

TMP_C		=\
			wolf3d_init.c\
			wolf3d_exit.c\
			main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all			: $(NAME)

$(NAME)		: objects libs/libft.a $(SRC_O)
	@echo "Creating wolf3d... \c"
	@$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_O) $(LIBS)
	@echo "[ok]"

objects: 
	@echo "Creating the folder objects... \c"
	@mkdir objects
	@echo "[ok]"

libs/libft.a	:
	@echo "Making libft... \c"
	@make --silent -C libs/libft
	@mv libs/libft/libft.a libs
	@make -C libs/libft/ fclean
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
	@echo "[ok]"

re			: fclean all
