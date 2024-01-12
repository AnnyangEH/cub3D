/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:57:34 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/10 21:53:16 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

static void	check_boundary(t_game *game, int x, int y, char **map)
{
	if (y == 0 || y == game->map->height - 1)
	{
		if (map[y][x] == '0')
			ft_error("Error\nInvalid map\n", game);
	}
	else if (x == 0 || x == game->map->width[y] - 1)
	{
		if (map[y][x] == '0')
			ft_error("Error\nInvalid map\n", game);
	}
}

static void	check_adjacent(t_game *game, int x, int y, char **map)
{
	if (map[y][x] == '0')
	{
		if (y - 1 >= 0 && y + 1 <= game->map->height - 1 && \
			x - 1 >= 0 && x + 1 <= game->map->width[y])
		{
			if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' || \
				map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
				ft_error("Error\nInvalid map\n", game);
		}
	}
}

void	check_cell(t_game *game, int x, int y, char **map)
{
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width[y])
		{
			check_boundary(game, x, y, map);
			check_adjacent(game, x, y, map);
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	char	**map;

	map = game->map->map;
	check_cell(game, 0, 0, map);
}
