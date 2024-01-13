NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address

MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz

DIR = ./srcs/

SRCS =	$(DIR)main.c			\
		$(DIR)cub_utils1.c		\
		$(DIR)cub_utils2.c		\
		$(DIR)cub_utils3.c		\
		$(DIR)parse.c			\
		$(DIR)parse_map.c		\
		$(DIR)parse_token.c		\
		$(DIR)ft_error.c 		\
		$(DIR)get_next_line.c	\
		$(DIR)cub_init.c 		\
		$(DIR)ft_split.c		\
		$(DIR)check_map.c		\
		$(DIR)exec.c			\
		$(DIR)time.c			\
		$(DIR)cub_mlx.c			\
		$(DIR)cub_hook.c		\
		$(DIR)player.c			\
		$(DIR)render_utils.c	\
		$(DIR)perform_utils.c	\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC) $(CFLAG) -I./inc $(OBJS) -o $(NAME) $(MLX_FLAG)

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
