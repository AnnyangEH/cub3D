/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysung <hysung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:48:34 by hysung            #+#    #+#             */
/*   Updated: 2024/01/10 23:19:58 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	mouse_hook(int button, int x, int y, t_game *game)
{
	if (button == 1) //mouse mode on
	{
		mlx_mouse_hide();
		mlx_mouse_move(game->win, game->map->width / 2, game->map->height / 2);
		//mouse 구조체 추가:
		game->mouse.mode = 1;
		mlx_mouse_get_pos(game->win, &game->mouse.x, &game->mouse.y);
	}
	if (button == 2) //off
	{
		mlx_mouse_show();
		game->mouse.mode = 0;
	}
}
