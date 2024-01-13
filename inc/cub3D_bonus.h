#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "time.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include "math.h"
# include <sys/time.h>

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

# define OPEN 1
# define CLOSE 0

# define S_MAX 10

enum e_key {
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_ESC = 53,
	KEY_PRESS = 2,
	KEY_SPACE = 49,
};

typedef struct s_time
{
	long long	curr_time;
	long long	old_time;
}				t_time;

typedef struct s_player
{
	int		dir;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_map
{
	char		**map;
	char		*path;
	char		*line;
	int			color[2][3];
	int			floor_color;
	int			ceiling_color;
	int			*width;
	int			height;
	int			player_cnt;
	int			fd;
}				t_map;

typedef struct s_imgs
{
	void	*ptr;
	char	*addr;
	char	*path;
	int		bpp;
	int		width;
	int		height;
	int		size_l;
	int		endian;
	int		cnt;
}				t_imgs;

typedef struct s_ray
{
	double	cam;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	dx;
	double	dy;
	double	perp_wall;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		d_start;
	int		d_end;
	int		cps;
	int		tex_x;
	int		tex_y;
}				t_ray;

typedef struct s_mouse
{
	int	x;
	int	y;
	int	mode;
}				t_mouse;

typedef struct s_sprite
{
	int		x;
	int		y;
	int		tex;
}			t_sprite;

typedef struct s_say
{
	double	s_x;
	double	s_y;
	double	inv_det;
	double	trans_x;
	double	trans_y;
	int		screen_x;
	int		dy_start;
	int		dy_end;
	int		dx_start;
	int		dx_end;
	int		s_width;
	int		s_height;
	int		tex_x;
	int		tex_y;
	int		d;
}				t_say;

typedef struct s_game
{
	char			*ptr;
	void			*img_ptr;
	void			*win;
	char			*addr;
	int				bpp;
	int				endian;
	int				size_l;
	int				door_cnt;
	double			z_buffer[1000];
	t_sprite		sprite[S_MAX];
	t_say			say;
	int				s_order[S_MAX];
	double			s_dist[S_MAX];
	t_map			*map;
	t_player		player;
	t_imgs			imgs[9];
	t_ray			ray;
	t_mouse			mouse;
	t_time			time;
}					t_game;

int			ft_strlen(char *s);
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(char *str);
char		*ft_substr(char *s, unsigned int start, int len);
void		ft_memset(void *b, int c, size_t len);
int			ft_strchr(char *s, int c);
int			ft_iswhitespace(char c);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
int			ft_catoi(const char *str);
int			ft_isempty(char *line);
double		ft_min(double a, double b);
void		free_split(char **split);

void		ft_init(int ac, char **av, t_game *game);
int			init_mlx(t_game *game);
void		set_color(t_game *game);
void		init_imgs(t_game *game, int i);
void		get_img(t_game *game);

void		ft_free(char *str, t_game *game, int i);

void		parse(t_game *game);
void		parse_token(t_game *game);
void		parse_map(t_game *game);

void		check_map(t_game *game);

int			press_key(int key, t_game *game, double move_speed, double rot_speed);
void		set_hook(t_game *game);
void		close_win(t_game *game);
int			exit_hook(t_game *game);
int			mouse_hook(int button, int x, int y, t_game *game);

void		go_up(t_game *game, double move_speed);
void		go_down(t_game *game, double move_speed);
void		go_right(t_game *game, double move_speed);
void		go_left(t_game *game, double move_speed);
void		turn_left(t_game *game, double rot_speed);
void		turn_right(t_game *game, double rot_speed);

void		my_mlx_pixel_put(t_game *game, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);

long long	get_time(void);

int			exec(t_game *game);

void		draw_point(t_game *game);
void		texture(t_game *game);
void		draw(t_game *game, int x, int y, int color);
void		minimap(t_game *game, int x, int y);

void		set_value(t_game *game, int x);
void		set_step_side(t_game *game);
void		hit_side(t_game *game);
void		set_wall_dir(t_game *game);

void		go_up(t_game *game, double move_speed);
void		go_down(t_game *game, double move_speed);
void		go_right(t_game *game, double move_speed);
void		go_left(t_game *game, double move_speed);
void		turn_right(t_game *game, double rot_speed);
void		turn_left(t_game *game, double rot_speed);

void		sort_sprite(t_game *game);
void		set_sprite(t_game *game, int i);
void		draw_sprite(t_game *game, int i);
#endif
