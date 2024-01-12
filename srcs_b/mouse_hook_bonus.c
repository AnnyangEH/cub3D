/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:48:34 by hysung            #+#    #+#             */
/*   Updated: 2024/01/12 20:03:48 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

int	mouse_hook(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_move(game->win, 500, 500);
		game->mouse.mode = 1;
	}
	if (button == 2)
	{
		mlx_mouse_show();
		game->mouse.mode = 0;
	}
	return (0);
}
