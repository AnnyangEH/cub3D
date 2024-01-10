/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:57:30 by hysung            #+#    #+#             */
/*   Updated: 2024/01/10 16:05:41 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	exec(t_game *game)
{
	for (int x = 0; x < 1000; x++)
	{
		set_value(game, x);
		set_step_side(game);
		hit_side(game);
		draw_point(game);
		texture(game);
		draw(game, x);
	}
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}
