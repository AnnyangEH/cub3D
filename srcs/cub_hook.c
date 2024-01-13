/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:58:11 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/13 10:03:01 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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

int	press_key(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_S)
		move_up_down(game, key);
	if (key == KEY_D || key == KEY_A)
		move_side(game, key);
	if (key == KEY_LEFT)
		rotate(&game->player, -1);
	if (key == KEY_RIGHT)
		rotate(&game->player, 1);
	if (key == KEY_ESC)
		exit_hook(game);
	return (0);
}
