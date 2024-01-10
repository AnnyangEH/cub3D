/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:18:48 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/10 22:18:38 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render(t_game *game, int x)
{
	t_ray	ray;
	int		i;

	i = 0;
	if (game->map->map[ray.mapY][ray.mapX] == '1')
		ray.color = create_trgb(0, 200, 120, 255);
	else
		ray.color = create_trgb(0, 0, 0, 0);
	if (ray.side == 1)
		ray.color /= 2;
	while (i <= WIDTH)
	{
		if (i >= ray.drawStart && i <= ray.drawEnd)
			my_mlx_pixel_put(game, x, i, ray.color);
		else if (i < ray.drawStart)
			my_mlx_pixel_put(game, x, i, create_trgb(0, game->map->color[1][0], \
			game->map->color[1][1], game->map->color[1][2]));
		else if (i > ray.drawEnd)
			my_mlx_pixel_put(game, x, i, create_trgb(0, game->map->color[0][0], \
			game->map->color[0][1], game->map->color[0][2]));
		i++;
	}
}

void	dda(t_game *game, int x)
{
	t_ray	ray;

	init_ray(&ray, game, x);
	cal_step_and_sidedist(&ray, game);
	perform_dda(&ray, game);
	cal_perpwalldist(&ray, game);
	cal_lineheight(&ray);
}

void	set_game(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		dda(game, x);
		render(game, x);
		x++;
	}
}

int	exec(t_game *game)
{
	set_game(game);
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}
