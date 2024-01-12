/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:13 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/12 18:37:55 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

int	exec(t_game *game)
{
	int	x;

	x = 0;
	if (game->mouse.mode)
	{
		mlx_mouse_get_pos(game->win, &game->mouse.x, &game->mouse.y);
		if (game->mouse.x > *game->map->width / 2)
		{
			turn_right(game, 0.07);
		}
		else if (game->mouse.x < *game->map->width / 2)
		{
			turn_left(game, 0.07);
		}
		mlx_mouse_move(game->win, *game->map->width / 2, game->map->height / 2);
	}
	while (x < 1000)
	{
		set_value(game, x);
		set_step_side(game);
		hit_side(game);
		draw_point(game);
		texture(game);
		draw(game, x, 0, 0);
		x++;
	}
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}
