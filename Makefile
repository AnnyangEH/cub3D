NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address

#MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz

DIR = ./srcs/

SRCS =	$(DIR)main.c			\
		$(DIR)cub_parsing.c		\
		$(DIR)cub_utils.c		\
		$(DIR)ft_error.c 		\
		$(DIR)get_next_line.c	\
		$(DIR)cub_init.c 		\
		$(DIR)ft_split.c		\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(CFLAG) -I./inc $(OBJS) -o $(NAME) 
#(MLX_FLAG)

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