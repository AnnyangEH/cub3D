# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 08:50:40 by seungjki          #+#    #+#              #
#    Updated: 2024/01/04 08:25:42 by suhbaek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Werror -Wall -Wextra
LFLAGS =  -L ./mlx -lmlx -framework OpenGL -framework Appkit

SRCS = arg_check_and_malloc.c free_alls.c get_next_line.c\
	   gnl_until_fail.c parsing.c arg_name_check.c\
	   ftnewform.c get_next_line_utils.c main.c\
	   parse_check_nswe.c parse_ceiling.c parse_floor.c\
	   parse_check_map_validity_turn_element.c\
	   parse_until_space_only.c parsing_fake_map_give_map.c\
	   for_lldb.c init.c\
	   
RM = rm -rf

SRCS_DIR = src/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# MLX
MLX_DIR = mlx/
MLX_PATH = $(addprefix, $(MLX_DIR), libmlx.a)

INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)

ifdef sanitize
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

%.o:		%.c
			@$(CC) $(CFLAGS) -c $^ -o $@
			@echo "$(YELLOW)	Compiling		$< $(DEF_COLOR)"

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(YELLOW)	Compiling 		Cub3D..	$(DEF_COLOR)"
	@echo "$(YELLOW)	Compiling 		Mlx..	$(DEF_COLOR)"
	@make -C mlx
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)	     ✨ Cub3D Compiled! ✨ $(DEF_COLOR)"

clean :
	@make -C $(MLX_DIR) clean
	@echo "$(CYAN)	🧹 Minilibx Object Files Cleaned 🧹	$(DEF_COLOR)"	
	@echo "$(CYAN)	🧹 Cub3D Object Files Cleaned 🧹	$(DEF_COLOR)"
	@$(RM) $(OBJS) $(B_OBJS)


fclean : clean
	@echo "$(CYAN)	🧹 Cub3D Executable Files Cleaned 🧹	$(DEF_COLOR)"
	@$(RM) $(MLX)
	@echo "$(CYAN)	🧹 Libmlx.a Cleaned 🧹	$(DEF_COLOR)"
	@$(RM) $(NAME)

re :
	@echo "$(YELLOW)	Cleaning And Rebuilting Files..	$(DEF_COLOR)"
	@make fclean
	@make all
	@echo "$(GREEN)	🤖 Cleaned And Rebuilt Done! 🤖	$(DEF_COLOR)"

# bonus : 
# 	@echo "$(GREEN) *** Bonus Compiling ... *** $(DEF_COLOR)"
# 	@make all

sanitize :
	@make sanitize=1 re

.PHONY: all clean fclean re bonus

#COLORS
CYAN = \033[0;96m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEF_COLOR = \033[0m