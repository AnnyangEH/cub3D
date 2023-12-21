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

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
}				t_player;

typedef struct s_map
{
	char		**map;
	char		*path; //map file path
	char		*line;
	int			color[2][3]; //floor, color rgb
	int			*width; //map width
	int			height; //map height
	int			player_cnt;
	int			fd;
}				t_map;

typedef struct s_token
{
	void	*ptr;	//image identifier
	void	*addr;	//image address
	char	*path;	//image path(file name)
	int		bpp;	//bit per pixel
	int		width;
	int		height;
	int		*size_l;
	int		endian;
}				t_token;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*ptr;
	int				bit_per_pixel;
	int				endian;
	int				size_l;
	t_map			*map;
	t_player		player;
	t_token			token[4];
}					t_game;

//util functions
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, int len);
void	ft_memset(void *b, int c, size_t len);
int		ft_strchr(char *s, int c);
int		ft_iswhitespace(char c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_catoi(const char *str);
int		ft_isempty(char *line);

//init functions
void	ft_init(int ac, char **av, t_game *game);

//error handling function
void	ft_error(char *str, t_game *game);
void	ft_error_exit(char *str, t_game *game);
void	free_game_one(t_game *game);

//parsing functions
void	parse(t_game *game);

//checking functions
void	check_map(t_game *game);

#endif