NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror -O2 -g -fsanitize=address

MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz

DIR_M = ./srcs_m/

SRCS =	$(DIR_M)main.c			\
		$(DIR_M)cub_parsing.c		\
		$(DIR_M)cub_utils.c		\
		$(DIR_M)ft_error.c 		\
		$(DIR_M)get_next_line.c	\
		$(DIR_M)cub_init.c 		\
		$(DIR_M)ft_split.c		\
		$(DIR_M)check_map.c		\
		$(DIR_M)exec.c			\
		$(DIR_M)time.c			\
		$(DIR_M)cub_mlx.c		\
		$(DIR_M)cub_hook.c		\
		$(DIR_M)set_ray.c		\
		$(DIR_M)draw.c			


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
