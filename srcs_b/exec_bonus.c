/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:13 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/12 21:19:08 by hysung           ###   ########.fr       */
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
		if (game->mouse.x > 500)
			turn_right(game, 0.05);
		else if (game->mouse.x < 500)
			turn_left(game, 0.05);
		mlx_mouse_move(game->win, 500, 500);
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
	minimap(game, 0, 0);
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}
