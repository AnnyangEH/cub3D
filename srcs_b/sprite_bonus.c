/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:21:00 by hysung            #+#    #+#             */
/*   Updated: 2024/01/15 17:04:31 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	sort_sprite(t_game *game)
{
	int				i;
	struct timeval	time;
	t_imgs			*sp_img;

	i = -1;
	while (++i < game->s_cnt)
	{
		game->s_dist[i] = ((game->player.x - game->sprite[i].x) * \
			(game->player.x - game->sprite[i].x) + (game->player.y - \
			game->sprite[i].y) * (game->player.y - game->sprite[i].y));
	}
	i = -1;
	gettimeofday(&time, 0);
	sp_img = &(game->imgs[5 + (time.tv_usec % 0x80000) / 0x20000]);
	while (++i < game->s_cnt)
	{
		set_sprite(game, i);
		draw_sprite(game, sp_img, game->say.dx_start, game->say.dy_start);
	}
}

void	draw_sprite(t_game *game, t_imgs *sp_img, int x, int y)
{
	int	color;

	while (x < game->say.dx_end)
	{
		game->say.tex_x = (int)(256 * (x - (-game->say.s_width / 2 + \
	game->say.screen_x)) * sp_img->width / game->say.s_width) / 256;
		if (game->say.trans_y > 0 && x > 0 && x < 1000 && \
				game->say.trans_y < game->z_buffer[x])
		{
			y = game->say.dy_start;
			while (y < game->say.dy_end)
			{
				game->say.d = y * 256 - 128000 + game->say.s_height * 128;
				game->say.tex_y = ((game->say.d * sp_img->height) / \
						game->say.s_height) / 256;
				color = *(int *)(sp_img->addr + game->say.tex_y * \
				sp_img->size_l + game->say.tex_x * (sp_img->bpp / 8));
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(game, x, y, color);
				y++;
			}
		}
		x++;
	}
}

void	set_sprite(t_game *game, int i)
{
	game->say.s_x = game->sprite[i].x - game->player.x;
	game->say.s_y = game->sprite[i].y - game->player.y;
	game->say.inv_det = 1.0 / (game->player.plane_x * game->player.dir_y - \
			game->player.dir_x * game->player.plane_y);
	game->say.trans_x = game->say.inv_det * (game->player.dir_y * \
			game->say.s_x - game->player.dir_x * game->say.s_y);
	game->say.trans_y = game->say.inv_det * (-game->player.plane_y * \
			game->say.s_x + game->player.plane_x * game->say.s_y);
	game->say.screen_x = (int)(500 * (1 + game->say.trans_x / \
				game->say.trans_y));
	game->say.s_height = abs((int)(1000 / game->say.trans_y));
	game->say.dy_start = -game->say.s_height / 2 + 500;
	if (game->say.dy_start < 0)
		game->say.dy_start = 0;
	game->say.dy_end = game->say.s_height / 2 + 500;
	if (game->say.dy_end >= 1000)
		game->say.dy_end = 1000;
	game->say.s_width = abs((int)(1000 / game->say.trans_y));
	game->say.dx_start = -game->say.s_width / 2 + game->say.screen_x;
	if (game->say.dx_start < 0)
		game->say.dx_start = 0;
	game->say.dx_end = game->say.s_width / 2 + game->say.screen_x;
	if (game->say.dx_end >= 1000)
		game->say.dx_end = 1000;
}
