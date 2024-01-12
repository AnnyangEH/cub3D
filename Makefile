NAME = cub3D
BONUS_NAME = cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -g -fsanitize=address

MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz

DIR_M = ./srcs_m/
DIR_B = ./srcs_b/

SRCS_M =	$(DIR_M)main.c		\
		$(DIR_M)parse.c			\
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
		$(DIR_M)draw.c			\
		$(DIR_M)parse_token.c	\
		$(DIR_M)parse_map.c		\
		$(DIR_M)cub_utils1.c	\
		$(DIR_M)cub_utils2.c	\
		$(DIR_M)cub_utils3.c	\
		$(DIR_M)gogosing.c		\
		$(DIR_M)turn.c			\

SRCS_B =	$(DIR_B)main_bonus.c		\
		$(DIR_M)parse_bonus.c			\
		$(DIR_B)ft_error_bonus.c 		\
		$(DIR_B)get_next_line_bonus.c	\
		$(DIR_B)cub_init_bonus.c 		\
		$(DIR_B)ft_split_bonus.c		\
		$(DIR_B)check_map_bonus.c		\
		$(DIR_B)exec_bonus.c			\
		$(DIR_B)time_bonus.c			\
		$(DIR_B)cub_mlx_bonus.c			\
		$(DIR_B)cub_hook_bonus.c		\
		$(DIR_B)set_ray_bonus.c			\
		$(DIR_B)draw_bonus.c			\
		$(DIR_B)parse_token_bonus.c		\
		$(DIR_B)parse_map_bonus.c		\
		$(DIR_B)cub_utils1_bonus.c		\
		$(DIR_B)cub_utils2_bonus.c		\
		$(DIR_B)cub_utils3_bonus.c		\

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(BONUS_NAME)

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
$(BONUS_NAME): $(OBJS_B)
	$(MAKE) -C ./mlx/
	$(CC) $(CFLAGS) -I./inc $(OBJS_B) -o $(BONUS_NAME) $(MLX_FLAG)
else
$(NAME): $(OBJS_M)
	$(MAKE) -C ./mlx/
	$(CC) $(CFLAGS) -I./inc $(OBJS_M) -o $(NAME) $(MLX_FLAG)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

clean:
	rm -f $(OBJS_M) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re:
	make fclean
	make all