/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:57:34 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 15:25:10 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_zero(t_game *game, int x, int y, char **map)
{
	if (x == 0 || y == 0 || x == game->map->width[y] - 1 \
	|| y == game->map->height - 1)
		ft_free("Error\nMap is not surrounded by wall 1\n", game, -1);
	if (y - 1 >= 0 && x > game->map->width[y - 1] - 1)
		ft_free("Error\nMap is not surrounded by wall 2\n", game, -1);
	if (y + 1 < game->map->height && x > game->map->width[y + 1] - 1)
		ft_free("Error\nMap is not surrounded by wall 3\n", game, -1);
	if (x - 1 >= 0 && y - 1 >= 0)
	{
		if (map[y][x - 1] == ' ' || map[y - 1][x] == ' ')
			ft_free("Error\nMap is not surrounded by wall 4\n", game, -1);
	}
	if (x + 1 < game->map->width[y] && y + 1 < game->map->height)
	{
		if (map[y][x + 1] == ' ' || map[y + 1][x] == ' ')
			ft_free("Error\nMap is not surrounded by wall 5\n", game, -1);
	}
}

static void	check_cell(t_game *game, int x, int y, char **map)
{
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width[y])
		{
			if (map[y][x] == '0')
				check_zero(game, x, y, map);
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	char	**map;

	map = game->map->map;
	if (game->map->player_cnt != 1)
		ft_free("Error\nInvalid player count\n", game, -1);
	check_cell(game, 0, 0, map);
}
