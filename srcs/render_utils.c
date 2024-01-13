/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:55:21 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/13 13:13:13 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw(t_game *game, t_ray *ray, int x, int y)
{
	double	step;
	double	tex_pos;

	step = (double)game->imgs[ray->tex_num].height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	while (y < HEIGHT)
	{
		if (y < ray->draw_start)
			my_mlx_pixel_put(game, x, y, game->map->ceiling_color);
		else if (y > ray->draw_end)
			my_mlx_pixel_put(game, x, y, game->map->floor_color);
		else
		{
			ray->tex_y = (int)tex_pos & (game->imgs[ray->tex_num].height - 1);
			tex_pos += step;
			ray->color = *(int *)(game->imgs[ray->tex_num].addr + \
					(ray->tex_y * game->imgs[ray->tex_num].size_l + \
					ray->tex_x * (game->imgs[ray->tex_num].bpp / 8)));
			if (ray->side == 1)
				ray->color = (ray->color >> 1) & 8355711;
			my_mlx_pixel_put(game, x, y, ray->color);
		}
		y++;
	}
}

void	set_wall(t_game *game, t_ray *ray)
{
	double	wall;

	if (!ray->side)
		wall = game->player.y + ray->perpwalldist * ray->raydir_y;
	else
		wall = game->player.x + ray->perpwalldist * ray->raydir_x;
	wall -= floor(wall);
	ray->tex_x = (int)(wall * (double)game->imgs[ray->tex_num].width);
	if (!ray->side && ray->raydir_x > 0)
		ray->tex_x = game->imgs[ray->tex_num].width \
		- ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = game->imgs[ray->tex_num].width \
		- ray->tex_x - 1;
}

void	set_nsew(t_game *game, t_ray *ray)
{
	if (ray->side && game->player.y - ray->map_y > 0)
		ray->tex_num = 0;
	else if (ray->side && game->player.y - ray->map_y < 0)
		ray->tex_num = 1;
	else if (!ray->side && game->player.x - ray->map_x > 0)
		ray->tex_num = 2;
	else if (!ray->side && game->player.x - ray->map_x < 0)
		ray->tex_num = 3;
}
