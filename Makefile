# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:26:20 by abelahce          #+#    #+#              #
#    Updated: 2023/01/14 19:50:52 by abelahce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: so_long

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

NAME=so_long

SRC := utils.c	\
		ft_strncmp.c	\
		ft_strdup.c	\
		ft_split.c	\
		parsing.c	\
		check_pnj.c	\
		starting_game.c	\
		create_universe.c	\
		start_moving.c	\
		move_D_R.c	\
		check_path.c \
		so_long.c
		

OBJ := $(SRC:.c=.o)

HDR := so_long.h

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  $(OBJ) -o $(NAME)

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf so_long

re: fclean all

