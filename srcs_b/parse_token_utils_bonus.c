/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:51:37 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 13:52:05 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	parse_sprite(t_game *game, int height, int width)
{
	if (game->s_cnt >= S_MAX)
		ft_free("Error\nToo many sprites in this map\n", game, -1);
	game->sprite[game->s_cnt].x = width + 0.5;
	game->sprite[game->s_cnt].y = height + 0.5;
	game->map->map[height][width] = game->map->line[width];
	game->s_cnt++;
}
