/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:32:44 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 21:34:14 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_init(ac, av, &game);
	parse(&game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_hook(game.win, KEY_PRESS, 1L << 0, press_key, &game);
	mlx_loop_hook(game.ptr, exec, &game);
	mlx_loop(game.ptr);
	exit(SUCCESS);
}
