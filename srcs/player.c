/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:53:49 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/13 10:02:56 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	rotate(t_player *player, int direction)
{
	double	old_dir;
	double	cos_val;
	double	sin_val;
	double	old_plane;

	old_dir = player->dir_x;
	cos_val = cos(ROT_SPEED * direction);
	sin_val = sin(ROT_SPEED * direction);

	player->dir_x = player->dir_x * cos_val - player->dir_y * sin_val;
	player->dir_y = old_dir * sin_val + player->dir_y * cos_val;

	old_plane = player->plane_x;
	player->plane_x = player->plane_x * cos_val - player->plane_y * sin_val;
	player->plane_y = old_plane * sin_val + player->plane_y * cos_val;
}

void	move_side(t_game *game, int key)
{
	if (key == KEY_D)
	{
		if (game->map->map[(int)game->player.y][(int)(game->player.x \
		- game->player.dir_y * MOVE_SPEED * 1.2)] == '0')
			game->player.x -= game->player.dir_y * MOVE_SPEED;
		if (game->map->map[(int)(game->player.y \
		+ game->player.dir_x * MOVE_SPEED * 1.2)][(int)game->player.x] == '0')
			game->player.y += game->player.dir_x * MOVE_SPEED;
	}
	if (key == KEY_A)
	{
		if (game->map->map[(int)game->player.y][(int)(game->player.x \
		+ game->player.dir_y * MOVE_SPEED * 1.2)] == '0')
			game->player.x += game->player.dir_y * MOVE_SPEED;
		if (game->map->map[(int)(game->player.y \
		- game->player.dir_x * MOVE_SPEED * 1.2)][(int)game->player.x] == '0')
			game->player.y -= game->player.dir_x * MOVE_SPEED;
	}
}

void	move_up_down(t_game *game, int key)
{
	if (key == KEY_W)
	{
		if (game->map->map[(int)game->player.y][(int)(game->player.x \
		+ game->player.dir_x * MOVE_SPEED * 1.2)] == '0')
			game->player.x += game->player.dir_x * MOVE_SPEED;
		if (game->map->map[(int)(game->player.y \
		+ game->player.dir_y * MOVE_SPEED * 1.2)][(int)game->player.x] == '0')
			game->player.y += game->player.dir_y * MOVE_SPEED;
	}
	if (key == KEY_S)
	{
		if (game->map->map[(int)game->player.y][(int)(game->player.x \
		- game->player.dir_x * MOVE_SPEED * 1.2)] == '0')
			game->player.x -= game->player.dir_x * MOVE_SPEED;
		if (game->map->map[(int)(game->player.y \
		- game->player.dir_y * MOVE_SPEED * 1.2)][(int)game->player.x] == '0')
			game->player.y -= game->player.dir_y * MOVE_SPEED;
	}
}


