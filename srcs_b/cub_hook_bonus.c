/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:35:22 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 17:58:25 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	close_win(t_game *game)
{
	ft_free(0, game, -1);
}

int	exit_hook(t_game *game)
{
	ft_free(0, game, -1);
	return (0);
}

void	open_door(t_game *game)
{
	if (game->map->map[(int)(game->player.y + game->player.dir_y)] \
			[(int)(game->player.x + game->player.dir_x)] == '2')
		game->map->map[(int)(game->player.y + game->player.dir_y)] \
				[(int)(game->player.x + game->player.dir_x)] = '3';
	else if (game->map->map[(int)(game->player.y + game->player.dir_y)] \
			[(int)(game->player.x + game->player.dir_x)] == '3')
		game->map->map[(int)(game->player.y + game->player.dir_y)] \
				[(int)(game->player.x + game->player.dir_x)] = '2';
}

int	press_key(int key, t_game *game, double move_speed, double rot_speed)
{
	rot_speed = 0.05;
	move_speed = 0.2;
	if (key == KEY_W)
		go_up(game, move_speed);
	if (key == KEY_S)
		go_down(game, move_speed);
	if (key == KEY_D)
		go_right(game, move_speed);
	if (key == KEY_A)
		go_left(game, move_speed);
	if (key == KEY_LEFT)
		turn_left(game, rot_speed);
	if (key == KEY_RIGHT)
		turn_right(game, rot_speed);
	if (key == KEY_ESC)
		exit_hook(game);
	if (key == KEY_SPACE)
		open_door(game);
	return (0);
}
