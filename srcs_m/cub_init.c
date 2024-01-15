/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:32:56 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 18:06:43 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	init_game(t_game *game, char *path);
static int	init_time(t_game *game);

void	ft_init(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_free_exit("Error\nInvalid number of arguments\n", game);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		ft_free_exit("Error\nInvalid file extension\n", game);
	if (init_game(game, av[1]))
		ft_free("Error\nFailed to initialize map\n", game, -1);
	if (init_time(game))
		ft_free("Error\nFailed to initalize time\n", game, -1);
}

static int	init_game(t_game *game, char *path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_memset(game->map, 0, sizeof(t_map));
	ft_memset(game->imgs, 0, sizeof(t_imgs) * 4);
	game->map->path = ft_strdup(path);
	if (!game->map->path)
		return (FAILURE);
	return (SUCCESS);
}

void	init_mlx(t_game *game)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		ft_free("Error\nFailed to initialize mlx\n", game, -1);
	game->win = mlx_new_window(game->ptr, 1000, 1000, "cub3D");
	if (!game->win)
		ft_free("Error\nFailed to initialize mlx\n", game, -1);
	game->img_ptr = mlx_new_image(game->ptr, 1000, 1000);
	game->addr = mlx_get_data_addr(game->img_ptr, &game->bpp, &game->size_l,
			&game->endian);
}

static int	init_time(t_game *game)
{
	game->time.curr_time = get_time();
	game->time.old_time = game->time.curr_time;
	return (SUCCESS);
}
