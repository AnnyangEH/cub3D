# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 18:41:44 by eunhcho           #+#    #+#              #
#    Updated: 2023/10/04 12:42:53 by eunhcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror

MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz

DIR = ./srcs/

SRCS =	main.c		\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(CFLAG) -I./inc $(MLX_FLAG) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(MAKE) -C ./mlx/ clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./mlx/ fclean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re