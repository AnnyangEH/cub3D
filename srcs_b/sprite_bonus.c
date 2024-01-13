/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysung <hysung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:21:00 by hysung            #+#    #+#             */
/*   Updated: 2024/01/13 23:23:23 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	sort_sprite(t_game *game)
{
	int			i;

	i = -1;
	while (++i < S_MAX && game->sprite[i])
	{
		game->s_dist[i] = ((game->player.x - game->sprite[i].x) * \
			(game->player.x - game->sprite[i].x) + \(game->player.y - \
			game->sprite[i].y) * (game->player.y - game->sprite[i].Y));
	}
	i = -1;
	while (++i < S_MAX && game->sprite[i])
	{
		game->say.s_x = game->sprite[i].x - game->player.x;
		game->say.s_y = game->sprite[i].y - game->player.y;
		game->say.inv_det = 1.0 / (game->player.plane_x * game->player.dir_y - \
				game->player.dir_x * game->player.plane_y);
		game->say.trans_x = game->say.inv_det * (game->player.dir_y * \
				game->say.s_x - game->player.dir_x * game->say.s_y);
		game->say.trans_y = game->say.inv_det * (-1 * game->player.plane_y * \
				game->say.s_x + game->player.plane_x * game->say.s_y);
		game->say.screen_x = (int)(500 * (1 + game->say.trans_x / \
					game->say.trans_y));
		game->say.s_height = abs((int)(1000 / game->say.trans_y));
		game->say.dy_start = -1 * game->say.s_height / 2 + 500;
		if (game->say.dy_start < 0)
			game->say.dy_start = 0;
		game->say.dy_end = game->say.s_height / 2 + 500;
		if (game->say.dy_end >= 1000)
			game->say.dy_end = 1000;
		game->say.s_width = abs((int)(1000 / game->say.trans_y));
		game->say.dx_start = -1 * game->say.s_width / 2 + game->say.screen_x;
		if (game->say.dx_start < 0)
			game->say.dx_start = 0;
		game->say.dx_end = game->say.s_width / 2 + game->say.screen_x;
		if (game->say.dx_end >= 1000)
			game->say.dx_end = 1000;
		for (int st = game->say.dx_start; st < game->say.dx_end; st++)
		{
			game->say.tex_x = (int)(256 * (st - (-1 * game->say.s_width / 2 + \
		game->say.screen_x)) * game->say.tex_width / game->say.s_width) / 256;
			if (game->say.trans_y > 0 && st > 0 && st < 1000 && \
					game->say.trans_y < game->z_buffer[st])
			{
				for (int y = game->say.dy_start; y < game->say.dy_end; y++)
				{
					game->say.d = y * 256 - 128000 + game->say.s_height * 128;
					game->say.tex_y = ((d * texHeight) / game->say.s_height) / 256;
					int	color = *(int *)(game->imgs[].addr + game->say.tex_y * game->imgs[].size_l + game->say.tex_x * (game->imgs[].bpp / 8));
					if ((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(game, st, y, color);;
				}
			}
		}
}
