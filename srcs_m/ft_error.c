/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:22:40 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/10 20:22:41 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	free_game_two(t_game *game, int i);
static void	free_mlx(t_game *game);

void	ft_error_exit(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	if (game)
		free(game);
	exit(FAILURE);
}

void	ft_error(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	free_game_one(game);
	exit(FAILURE);
}

void	free_game_one(t_game *game)
{
	if (game->map->line)
		free(game->map->line);
	if (game->map->path)
		free(game->map->path);
	if (game->map->width)
		free(game->map->width);
	free_game_two(game, -1);
	free_mlx(game);
	free(game);
}

static void	free_game_two(t_game *game, int i)
{
	while (++i < 4)
	{
		if (game->imgs[i].path)
			free(game->imgs[i].path);
		if (game->imgs[i].ptr)
			mlx_destroy_image(game->ptr, game->imgs[i].ptr);
	}
	if (game->map->map)
	{
		i = -1;
		while (++i < game->map->height)
			if (game->map->map[i])
				free(game->map->map[i]);
		free(game->map->map);
	}
	free(game->map);
}

static void	free_mlx(t_game *game)
{
	if (game->ptr)
	{
		if (game->win)
			mlx_destroy_window(game->ptr, game->win);
		free(game->ptr);
	}
}
