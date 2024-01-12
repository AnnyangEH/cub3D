/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:42:31 by hysung            #+#    #+#             */
/*   Updated: 2024/01/12 22:21:26 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	draw_point(t_game *game)
{
	game->ray.line_h = (int)(1000 / game->ray.perp_wall);
	game->ray.d_start = (game->ray.line_h * -1) / 2 + 1000 / 2;
	if (game->ray.d_start < 0)
		game->ray.d_start = 0;
	game->ray.d_end = game->ray.line_h / 2 + 1000 / 2;
	if (game->ray.d_end >= 1000)
		game->ray.d_end = 1000;
}

void	texture(t_game *game)
{
	double	wall;

	set_wall_dir(game);
	if (!game->ray.side)
		wall = game->player.y + (game->ray.perp_wall * game->ray.dir_y);
	else
		wall = game->player.x + (game->ray.perp_wall * game->ray.dir_x);
	wall -= floor((wall));
	game->ray.tex_x = (int)(wall * (double)game->imgs[game->ray.cps].width);
	game->ray.tex_x = game->imgs[game->ray.cps].width - game->ray.tex_x - 1;
}

void	draw(t_game *game, int x, int y, int color)
{
	double	step;
	double	t_pos;

	step = (double)game->imgs[game->ray.cps].height / game->ray.line_h;
	t_pos = (game->ray.d_start - 1000 / 2 + game->ray.line_h / 2) * step;
	while (y < 1000)
	{
		if (y < game->ray.d_start)
			my_mlx_pixel_put(game, x, y, game->map->ceiling_color);
		else if (y > game->ray.d_end)
			my_mlx_pixel_put(game, x, y, game->map->floor_color);
		else
		{
			game->ray.tex_y = (int)t_pos & \
								(game->imgs[game->ray.cps].height - 1);
			t_pos += step;
			color = *(int *)(game->imgs[game->ray.cps].addr + \
					(game->ray.tex_y * game->imgs[game->ray.cps].size_l + \
					game->ray.tex_x * (game->imgs[game->ray.cps].bpp / 8)));
			if (game->ray.side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(game, x, y, color);
		}
		y++;
	}
}

void	minimap(t_game *game, int x, int y)
{
	int	xx;
	int	yy;

	x = -1;
	while (++x < 300)
	{
		y = -1;
		while (++y < 300)
		{
			yy = y * game->map->height / 300;
			xx = x * game->map->width[yy] / 300;
			if (game->map->map[yy][xx] == '0')
				my_mlx_pixel_put(game, x, y, create_trgb(0, 255, 255, 255));
			else if (xx >= game->map->width[yy] || \
				game->map->map[yy][xx] == ' ' || game->map->map[yy][xx] == '1')
				my_mlx_pixel_put(game, x, y, create_trgb(0, 0, 0, 0));
			else if (game->map->map[yy][xx] == '2')
				my_mlx_pixel_put(game, x, y, create_trgb(0, 15, 20, 210));
			else if (game->map->map[yy][xx] == '4')
				my_mlx_pixel_put(game, x, y, create_trgb(0, 200, 50, 200));
			if (xx == (int)game->player.x && yy == (int)game->player.y)
				my_mlx_pixel_put(game, x, y, create_trgb(0, 10, 230, 10));
		}
	}
}
