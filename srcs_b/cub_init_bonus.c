/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:32:56 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/10 21:17:58 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

static int	init_game(t_game *game, char *path);
static int	init_mlx(t_game *game);
static int	init_time(t_game *game);

void	ft_init(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments\n", game);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		ft_error_exit("Error\nInvalid file extension\n", game);
	if (init_game(game, av[1]))
		ft_error("Error\nFailed to initialize map\n", game);
	if (init_mlx(game))
		ft_error_exit("Error\nFailed to initialize mlx\n", game);
	if (init_time(game))
		ft_error_exit("Error\nFailed to initalize time\n", game);
}

static int	init_game(t_game *game, char *path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_memset(game->map, 0, sizeof(t_map));
	if (!game->map)
		return (FAILURE);
	game->map->path = ft_strdup(path);
	if (!game->map->path)
		return (FAILURE);
	return (SUCCESS);
}

static int	init_mlx(t_game *game)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (FAILURE);
	game->win = mlx_new_window(game->ptr, 1000, 1000, "cub3D");
	if (!game->win)
		return (FAILURE);
	game->img_ptr = mlx_new_image(game->ptr, 1000, 1000);
	game->addr = mlx_get_data_addr(game->img_ptr, &game->bpp, &game->size_l,
			&game->endian);
	return (SUCCESS);
}

static int	init_time(t_game *game)
{
	game->time.curr_time = get_time();
	game->time.old_time = game->time.curr_time;
	return (SUCCESS);
}
