#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include "math.h"

# define SUCCESS 1
# define FAILURE 0

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
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
}				t_game;

#endif