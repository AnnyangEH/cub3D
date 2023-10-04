#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "fcntl.h"
# include "stdlib.h"

enum e_key {
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
};

enum e_event_key {
	EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_EXIT = 17,
};

enum e_error{
	USAGE_ERROR = 1,
	OPEN_ERROR,
	READ_ERROR,
	CLOSE_ERROR,
	EMPTY_ERROR,
	MAP_EX_ERROR,
};

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_img;

typedef struct s_vector
{
	double	x_pos;
	double	y_pos;
	double	plane;
	double	dir;
	double	b_spot;
	double	r_b_spot;
	double	l_b_spot;
	double	ray_dir;
	double	fov;
}	t_vector;


typedef struct s_game
{
	int			map_size;
	char		*dir;
	int			floor[3];
	int			ceiling[3];
	char		**map;
	int			err;
	t_img		img;
	t_vector	vector;
}	t_game;

#endif