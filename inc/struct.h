/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:16:01 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/13 15:11:33 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int			*width;
	int			height;
	int			player_cnt;
	int			floor_color;
	int			ceiling_color;
	int			fd;
}				t_map;

typedef struct s_imgs
{
	void	*ptr;
	void	*addr;
	char	*path;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
	int		cnt;
}				t_imgs;

typedef struct s_time
{
	long long	curr_time;
	long long	old_time;
}				t_time;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;

	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	int		tex_num;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
}				t_ray;

typedef struct s_game
{
	char			*ptr;
	void			*img_ptr;
	void			*win;
	void			*addr;
	int				bpp;
	int				endian;
	int				size_l;
	t_time			time;
	t_map			*map;
	t_player		player;
	t_imgs			imgs[4];
	t_ray			ray;
}					t_game;

#endif