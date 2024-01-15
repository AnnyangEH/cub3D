/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:22:40 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 20:06:32 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	ft_free_exit(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	free(game);
	exit(FAILURE);
}

void	ft_free(char *str, t_game *game, int i)
{
	if (game->map->fd > 0)
		if (close(game->map->fd) == -1)
			exit(FAILURE);
	if (game->map->width)
		free(game->map->width);
	if (game->map->line)
		free(game->map->line);
	if (game->map->path)
		free(game->map->path);
	while (++i < 9)
		free(game->imgs[i].path);
	if (game->map->map)
	{
		i = -1;
		while (++i < game->map->height)
			if (game->map->map[i])
				free(game->map->map[i]);
		free(game->map->map);
	}
	free(game->map);
	if (str)
		ft_putstr_fd(str, 2);
	exit(FAILURE);
}
