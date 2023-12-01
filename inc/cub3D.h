#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include "math.h"

# define SUCCESS 0
# define FAILURE 1

# define TRUE 1
# define FALSE 0

enum e_key {
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	EVENT_KEY_PRESS = 2,
};

enum e_error {
	USAGE_ERROR = 1,
	OPEN_ERROR,
	READ_ERROR,
	CLOSE_ERROR,
	MALLOC_ERROR,
	FORMAT_ERROR,
	RESOLUTION_ERROR,
	TEXTURE_ERROR,
	COLOR_ERROR,
	MAP_ERROR,
};

typedef struct s_game
{
	char	**map;
	char	*token[6];
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
	int		file_height;
	int		token_flags[6];
	int		token_flag;
	int		error_code; // 전부 이거로 exit할때 쓰고 싶음.
}				t_game;

//libft functions
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, int len);
void	ft_memset(void *b, int c, size_t len);
char	*ft_strchr(char *s, int c);

//error handling function
int		ft_error(int error);

//cub_parsing functions
int		cub_parsing(t_game *game, char **av);
int		cub_parsing_init(t_game *game);
#endif