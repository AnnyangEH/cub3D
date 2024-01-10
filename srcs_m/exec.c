/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:57:30 by hysung            #+#    #+#             */
/*   Updated: 2024/01/10 22:22:19 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	exec(t_game *game)
{
	int	x;

	x = 0;
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
