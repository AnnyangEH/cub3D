/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:45:27 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/10 20:11:30 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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

void	parse(t_game *game)
{
	game->map->fd = open(game->map->path, O_RDONLY);
	if (game->map->fd == -1)
		ft_error("Error\nFailed to open file\n", game);
	parse_token(game);
	parse_map(game);
	check_map(game);
	get_img(game);
	if (close(game->map->fd) == -1)
		ft_error("Error\nFailed to close file\n", game);
}
