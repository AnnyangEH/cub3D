/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:17:50 by hysung            #+#    #+#             */
/*   Updated: 2024/01/13 18:16:54 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	turn_left(t_game *game, double rot_speed)
{
	double	old_dir;
	double	old_plane;

	old_dir = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed * -1) - \
							game->player.dir_y * sin(rot_speed * -1);
	game->player.dir_y = old_dir * sin(rot_speed * -1) + game->player.dir_y * \
							cos(rot_speed * -1);
	old_plane = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed * -1) - \
							game->player.plane_y * sin(rot_speed * -1);
	game->player.plane_y = old_plane * sin(rot_speed * -1) + \
							game->player.plane_y * cos(rot_speed * -1);
}

void	turn_right(t_game *game, double rot_speed)
{
	double	old_dir;
	double	old_plane;

	old_dir = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - \
							game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir * sin(rot_speed) + game->player.dir_y * \
							cos(rot_speed);
	old_plane = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed) - \
							game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane * sin(rot_speed) + \
							game->player.plane_y * cos(rot_speed);
}
