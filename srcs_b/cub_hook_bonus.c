/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:35:22 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/12 23:57:34 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	close_win(t_game *game)
{
	free_game_one(game);
	exit(0);
}

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win);
	exit(0);
}

void	open_door(t_game *game)
{
	if (game->map->map[(int)(game->player.y + game->player.dir_y)]\
			[(int)(game->player.x + game->player.dir_x)] == '2')
		game->map->map[(int)(game->player.y + game->player.dir_y)]\
				[(int)(game->player.x + game->player.dir_x)] = '3';
	if (game->map->map[(int)(game->player.y + game->player.dir_y)]\
			[(int)(game->player.x + game->player.dir_x)] == '3')
		game->map->map[(int)(game->player.y + game->player.dir_y)]\
				[(int)(game->player.x + game->player.dir_x)] = '2';
	printf("asdfa");
	printf("%c ", game->map->map[(int)(game->player.y + game->player.dir_y)][(int)(game->player.x + game->player.dir_x)]);
}

int	press_key(int key, t_game *game, double move_speed, double rot_speed)
{
	rot_speed = 0.07;
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
