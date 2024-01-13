/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:32:44 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 21:56:06 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	set_color(t_game *game)
{
	game->map->floor_color = create_trgb(0, game->map->color[0][0], \
	game->map->color[0][1], game->map->color[0][2]);
	game->map->ceiling_color = create_trgb(0, game->map->color[1][0], \
	game->map->color[1][1], game->map->color[1][2]);
}

static void	init_imgs(t_game *game, int i)
{
	game->imgs[i].ptr = mlx_xpm_file_to_image(game->ptr, \
	game->imgs[i].path, &game->imgs[i].width, &game->imgs[i].height);
	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].ptr, \
	&game->imgs[i].bpp, &game->imgs[i].size_l, &game->imgs[i].endian);
}

static void	get_img(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 4)
		init_imgs(game, i);
}

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
