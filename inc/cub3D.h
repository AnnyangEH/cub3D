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

# define FLOOR 0
# define CEILING 1

# define NO 0
# define SO 1
# define WE 2
# define EA 3

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
	EXTENSION_ERROR,
	CHAR_ERROR,
	SPLIT_ERROR,
	C_C_ERROR,
	C_F_ERROR,
	C_R_ERROR,
	C_N_ERROR,
	IMG_ADDR_ERROR,
};

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			color[2][3];
	int			width;
	int			height;
}				t_map;

typedef struct s_img
{
	void	*img;	//image identifier
	char	*path;	//image address
	int		bpp;	//bit per pixel
	int		size_l;
	int		endian;
}				t_img;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	int				error_code;
	char			*token_addr[4];
	t_map			map;
	t_player		player;
	t_img			img;
}					t_game;

//util functions
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, int len);
void	ft_memset(void *b, int c, size_t len);
char	*ft_strchr(char *s, int c);
int		ft_iswhitespace(char c)
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_catoi(const char *str);

//error handling function
int	ft_error_exit(char *s, int error_code);

//parsing functions

#endif