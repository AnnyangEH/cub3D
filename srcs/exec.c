/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:18:48 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/13 13:11:21 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render(t_game *game, t_ray *ray, int x)
{
	set_nsew(game, ray);
	set_wall(game, ray);
	draw(game, ray, x, 0);
}

void	perform(t_game *game, int x)
{
	t_ray	ray;

	init_ray(&ray, game, x);
	cal_step_and_sidedist(&ray, game);
	perform_dda(&ray, game);
	cal_perpwalldist(&ray, game);
	cal_line_height(&ray);
	render(game, &ray, x);
}

void	set_game(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		perform(game, x);
		x++;
	}
}

int	exec(t_game *game)
{
	set_game(game);
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}
