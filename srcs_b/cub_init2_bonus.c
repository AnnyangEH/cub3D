/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:25:25 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 19:13:52 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	set_color(t_game *game)
{
	game->map->floor_color = create_trgb(0, game->map->color[0][0], \
	game->map->color[0][1], game->map->color[0][2]);
	game->map->ceiling_color = create_trgb(0, game->map->color[1][0], \
	game->map->color[1][1], game->map->color[1][2]);
}

void	init_imgs(t_game *game, int i)
{
	game->imgs[i].ptr = mlx_xpm_file_to_image(game->ptr, \
	game->imgs[i].path, &game->imgs[i].width, &game->imgs[i].height);
	if (game->imgs[i].ptr == NULL)
		ft_free("Error\nInvalid texture path\n", game, -1);
	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].ptr, \
	&game->imgs[i].bpp, &game->imgs[i].size_l, &game->imgs[i].endian);
}

void	get_img(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 9)
		init_imgs(game, i);
}
