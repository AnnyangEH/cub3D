/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:45:27 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 22:18:31 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	parse(t_game *game)
{
	game->map->fd = open(game->map->path, O_RDONLY);
	if (game->map->fd == -1)
		ft_free("Error\nFailed to open file\n", game, -1);
	parse_token(game);
	parse_map(game);
	check_map(game);
	if (close(game->map->fd) == -1)
		ft_free("Error\nFailed to close file\n", game, -1);
}
