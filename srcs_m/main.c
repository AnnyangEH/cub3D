/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:32:44 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 22:26:37 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	leak(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_game	*game;

	atexit(leak);
	game = malloc(sizeof(t_game));
	if (!game)
		exit(FAILURE);
	ft_init(ac, av, game);
	parse(game);
	init_mlx(game);
	get_img(game);
	set_color(game);
	mlx_hook(game->win, 17, 0, exit_hook, game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0, press_key, game);
	mlx_loop_hook(game->ptr, exec, game);
	mlx_loop(game->ptr);
	ft_free(0, game, 0);
	return (SUCCESS);
}
