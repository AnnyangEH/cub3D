/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:32:44 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 21:03:22 by eunhcho          ###   ########.fr       */
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
		ft_free("Error\nFailed to allocate game\n", game, -1);
	ft_init(ac, av, game);
	parse(game);
	if (init_mlx(game))
		ft_free("Error\nFailed to initialize mlx\n", game, -1);
	mlx_hook(game->win, 17, 0, exit_hook, game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0, press_key, game);
	mlx_loop_hook(game->ptr, exec, game);
	mlx_loop(game->ptr);
	ft_free(0, game, 0);
	return (SUCCESS);
}
