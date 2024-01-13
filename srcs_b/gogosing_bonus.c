/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gogosing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:17:11 by hysung            #+#    #+#             */
/*   Updated: 2024/01/13 18:16:47 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	go_up(t_game *game, double move_speed)
{
	if (game->map->map[(int)game->player.y][(int)(game->player.x + \
				game->player.dir_x * move_speed * 1.3)] == '0' || \
			game->map->map[(int)game->player.y][(int)(game->player.x + \
				game->player.dir_x * move_speed * 1.3)] == '3')
		game->player.x += game->player.dir_x * move_speed;
	if (game->map->map[(int)(game->player.y + game->player.dir_y * \
				move_speed * 1.3)][(int)game->player.x] == '0' || \
			game->map->map[(int)(game->player.y + game->player.dir_y * \
				move_speed * 1.3)][(int)game->player.x] == '3')
		game->player.y += game->player.dir_y * move_speed;
}

void	go_down(t_game *game, double move_speed)
{
	if (game->map->map[(int)game->player.y][(int)(game->player.x - \
				game->player.dir_x * move_speed * 1.3)] == '0' || 
			game->map->map[(int)game->player.y][(int)(game->player.x - \
				game->player.dir_x * move_speed * 1.3)] == '3')
		game->player.x -= game->player.dir_x * move_speed;
	if (game->map->map[(int)(game->player.y - game->player.dir_y * \
				move_speed * 1.3)][(int)game->player.x] == '0' || \
			game->map->map[(int)(game->player.y - game->player.dir_y * \
				move_speed * 1.3)][(int)game->player.x] == '3')
		game->player.y -= game->player.dir_y * move_speed;
}

void	go_right(t_game *game, double move_speed)
{
	if (game->map->map[(int)(game->player.y + game->player.dir_x * \
				move_speed * 1.3)][(int)game->player.x] == '0' || \
			game->map->map[(int)(game->player.y + game->player.dir_x * \
				move_speed * 1.3)][(int)game->player.x] == '3')
		game->player.y += game->player.dir_x * move_speed;
	if (game->map->map[(int)game->player.y][(int)(game->player.x - \
				game->player.dir_y * move_speed * 1.3)] == '0' || \
			game->map->map[(int)game->player.y][(int)(game->player.x - \
				game->player.dir_y * move_speed * 1.3)] == '3')
		game->player.x -= game->player.dir_y * move_speed;
}

void	go_left(t_game *game, double move_speed)
{
	if (game->map->map[(int)(game->player.y - game->player.dir_x * \
				move_speed * 1.3)][(int)game->player.x] == '0' || \
			game->map->map[(int)(game->player.y - game->player.dir_x * \
				move_speed * 1.3)][(int)game->player.x] == '3')
		game->player.y -= game->player.dir_x * move_speed;
	if (game->map->map[(int)game->player.y][(int)(game->player.x + \
				game->player.dir_y * move_speed * 1.3)] == '0' ||
			game->map->map[(int)game->player.y][(int)(game->player.x + \
				game->player.dir_y * move_speed * 1.3)] == '3')
		game->player.x += game->player.dir_y * move_speed;
}
