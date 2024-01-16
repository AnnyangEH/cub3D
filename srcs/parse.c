/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:45:27 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/16 15:33:26 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	parse(t_game *game)
{
	game->map->fd = open(game->map->path, O_RDONLY);
	if (game->map->fd == -1)
		ft_free("Error\nFailed to open file\n", game, -1);
	parse_token(game);
	parse_map(game);
	check_map(game);
	init_mlx(game);
	get_img(game);
	set_color(game);
	if (close(game->map->fd) == -1)
		ft_free("Error\nFailed to close file\n", game, -1);
}
