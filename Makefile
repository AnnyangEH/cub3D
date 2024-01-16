NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O2

MLX_FLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz
DIR = ./srcs/

RM = rm -f

SRCS =	$(DIR)main.c			\
		$(DIR)cub_utils1.c		\
		$(DIR)cub_utils2.c		\
		$(DIR)cub_utils3.c		\
		$(DIR)parse.c			\
		$(DIR)parse_map.c		\
		$(DIR)parse_token.c		\
		$(DIR)parse_token_utils.c		\
		$(DIR)get_next_line.c	\
		$(DIR)cub_init.c 		\
		$(DIR)cub_init2.C		\
		$(DIR)ft_split.c		\
		$(DIR)check_map.c		\
		$(DIR)exec.c			\
		$(DIR)time.c			\
		$(DIR)cub_mlx.c			\
		$(DIR)cub_hook.c		\
		$(DIR)player.c			\
		$(DIR)render_utils.c	\
		$(DIR)perform_utils.c	\
		$(DIR)ft_free.c			\


OBJS = $(SRCS:.c=.o)
all : $(NAME)

INC		= inc

MLX_DIR	= mlx

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I./inc -c $^ -o $@
			@echo "$(YELLOW)	Compiling		$< $(DEF_COLOR)"

$(NAME):	$(OBJS) $(MLX)
		@echo "$(YELLOW)	Compiling 		Cub3D..	$(DEF_COLOR)"
		@$(CC) $(CFLAGS) -I./inc $(MLX_FLAG) $(OBJS) -o $@
		@echo "$(GREEN)	     ✨ Cub3D Compiled! ✨ $(DEF_COLOR)"

$(MLX) :
		@echo "$(YELLOW)	Compiling 		Mlx..	$(DEF_COLOR)"
		@make -C $(MLX_FLAG)

clean:
			@make clean -C $(MLX_DIR)
			@echo "$(CYAN)	🧹 Minilibx Object Files Cleaned 🧹	$(DEF_COLOR)"	
			@$(RM) $(OBJS)
			@echo "$(CYAN)	🧹 Cub3D Object Files Cleaned 🧹	$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME) 
			@echo "$(CYAN)	🧹 Cub3D Executable Files Cleaned 🧹	$(DEF_COLOR)"
			@$(RM) $(MLX)
			@echo "$(CYAN)	🧹 Libmlx.a Cleaned 🧹	$(DEF_COLOR)"
re:
		@echo "$(YELLOW)	Cleaning And Rebuilting Files..	$(DEF_COLOR)"
		@make fclean
		@make all
		@echo "$(GREEN)	🤖 Cleaned And Rebuilt Done! 🤖	$(DEF_COLOR)"

.PHONY : all clean fclean re