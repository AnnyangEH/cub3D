/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:58:11 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/23 15:41:52 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	close_win(t_game *game)
{
	ft_free(0, game, -1);
}

int	exit_hook(t_game *game)
{
	ft_free(0, game, -1);
	return (0);
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
