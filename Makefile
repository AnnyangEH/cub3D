# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 18:41:44 by eunhcho           #+#    #+#              #
#    Updated: 2023/12/01 20:34:08 by eunhcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address #remove this

MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz

DIR = ./srcs/

SRCS =	$(DIR)main.c		\
		$(DIR)cub_parsing.c	\
		$(DIR)cub_utils.c	\
		$(DIR)ft_error.c \
		$(DIR)get_next_line.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(CFLAG) -I./inc $(MLX_FLAG) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re