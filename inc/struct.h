/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:16:01 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/09 22:38:51 by suhbaek          ###   ########.fr       */
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
	char		**temp;
	char		*path; //map file path
	char		*line;
	int			color[2][3]; //floor, color rgb
	int			*width; //map width
	int			height; //map height
	int			player_cnt;
	int			fd;
}				t_map;

typedef struct s_imgs
{
	void	*ptr;	//image identifier 
	void	*addr;	//image address
	char	*path;	//image path(file name)
	int		bpp;	//bit per pixel
	int		size_l;
	int		endian;
}				t_imgs;

typedef struct s_time
{
	long long	curr_time;
	long long	old_time;
}				t_time;

typedef struct s_ray
{
	double	cameraX;//calculate ray position and direction
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;//length of ray from current position to next x or y-side
	double	sideDistY;
	double	deltaDistX;//length of ray from one x or y-side to next x or y-side
	double	deltaDistY;
	double	perpWallDist;
    
	int		mapX;//which box of the map we're in
	int		mapY;
          
	int		stepX;//what direction to step in x or y-direction (either +1 or -1)
	int		stepY;
    
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
}				t_ray;

typedef struct s_game
{
	char			*ptr;
	void			*img_ptr;// game img ptr
	void			*win;
	void			*addr;
	int				bpp;
	int				endian;
	int				size_l;
	t_time			time;
	t_map			*map;
	t_player		player;
	t_imgs			imgs[4]; // 0 : north, 1 : south, 2 : west, 3 : east
	t_imgs			img; //sprite
    t_ray           *ray;
}					t_game;

#endif