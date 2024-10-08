/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:35:32 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/12 17:57:45 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_door
{
	int	x;
	int	y;
	int	is_open;
}				t_door;

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
	t_map			*map;
	t_player		player;
	t_imgs			imgs[9];
	t_door			doors[20];
	t_ray			ray;
	t_time			time;
}					t_game;

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
double	ft_min(double a, double b);
void	free_split(char **split);

void	ft_init(int ac, char **av, t_game *game);

void	ft_error(char *str, t_game *game);
void	ft_error_exit(char *str, t_game *game);
void	free_game_one(t_game *game);

void	parse(t_game *game);
void	parse_token(t_game *game);
void	parse_map(t_game *game);

void	check_map(t_game *game);

int		press_key(int key, t_game *game, double move_speed, double rot_speed);
void	set_hook(t_game *game);
void	close_win(t_game *game);
int		exit_hook(t_game *game);

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

long long	get_time(void);

int		exec(t_game *game);

void	draw_point(t_game *game);
void	texture(t_game *game);
void	draw(t_game *game, int x, int y, int color);

void	set_value(t_game *game, int x);
void	set_step_side(t_game *game);
void	hit_side(t_game *game);
void	set_wall_dir(t_game *game);

void	go_up(t_game *game, double move_speed);
void	go_down(t_game *game, double move_speed);
void	go_right(t_game *game, double move_speed);
void	go_left(t_game *game, double move_speed);
void	turn_right(t_game *game, double rot_speed);
void	turn_left(t_game *game, double rot_speed);

#endif