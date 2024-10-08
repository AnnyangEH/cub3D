/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysung <hysung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:42:31 by hysung            #+#    #+#             */
/*   Updated: 2024/01/10 21:55:02 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
	if (!game->ray.side && game->ray.dir_x > 0)
		game->ray.tex_x = game->imgs[game->ray.cps].width - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
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
