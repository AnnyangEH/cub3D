/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:18:48 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/10 04:02:57 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void dda(t_game *game, int x)
{
		t_ray ray;
		
		ray.cameraX = 2 * x / (double)WIDTH - 1;
		ray.rayDirX = game->player.dir_x + game->player.plane_x * ray.cameraX;
		ray.rayDirY = game->player.dir_y + game->player.plane_y * ray.cameraX;
		ray.mapX = (int)game->player.x;
		ray.mapY = (int)game->player.y;
		ray.deltaDistX = fabs(1 / ray.rayDirX);
		ray.deltaDistY = fabs(1 / ray.rayDirY);
		ray.hit = 0;
      //calculate step and initial sideDist
		if (ray.rayDirX < 0)
		{
			ray.stepX = -1;
			ray.sideDistX = (game->player.x - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (ray.mapX + 1.0 - game->player.x) * ray.deltaDistX;
		}
		if (ray.rayDirY < 0)
		{
			ray.stepY = -1;
			ray.sideDistY = (game->player.y - ray.mapY) * ray.deltaDistY;
		}
		else
		{
			ray.stepY = 1;
			ray.sideDistY = (ray.mapY + 1.0 - game->player.y) * ray.deltaDistY;
		}
		// DDA SETTING TILL HERE.

		while (!ray.hit)
		{
			if (ray.sideDistX < ray.sideDistY)
			{
				ray.sideDistX += ray.deltaDistX;
				ray.mapX += ray.stepX;
				ray.side = 0;
			}
			else
			{
				ray.sideDistY += ray.deltaDistY;
				ray.mapY += ray.stepY;
				ray.side = 1;
			}

			if (game->map->map[ray.mapY][ray.mapX] == '1')
				ray.hit = 1;
		}

		if (!ray.side)
			ray.perpWallDist = (ray.mapX - game->player.x + (1 - ray.stepX) / 2) / ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - game->player.y + (1 - ray.stepY) / 2) / ray.rayDirY;
		ray.lineHeight = (int)(WIDTH / ray.perpWallDist);
		ray.drawStart = (ray.lineHeight * -1) / 2 + WIDTH / 2;
		if (ray.drawStart < 0)
			ray.drawStart = 0;
		ray.drawEnd = ray.lineHeight / 2 + WIDTH / 2;
		if (ray.drawEnd >= WIDTH)
			ray.drawEnd = WIDTH - 1;
}

void render(t_game *game, int x)
{
	t_ray ray;

		if (game->map->map[ray.mapY][ray.mapX] == '1')
			ray.color = create_trgb(0, 200, 120, 255);
		else
			ray.color = create_trgb(0, 0, 0, 0);
		if (ray.side == 1)
			ray.color /= 2;
		for (int i = 0; i <= WIDTH; i++)
		{
			if (i >= ray.drawStart && i <= ray.drawEnd)
				my_mlx_pixel_put(game, x, i, ray.color);
			else if (i < ray.drawStart)
				my_mlx_pixel_put(game, x, i, create_trgb(0, game->map->color[1][0], game->map->color[1][1], game->map->color[1][2]));
			else if (i > ray.drawEnd)
				my_mlx_pixel_put(game, x, i, create_trgb(0, game->map->color[0][0], game->map->color[0][1], game->map->color[0][2]));
		}
}

void start_game(t_game *game)
{
	int x;

	x = 0;
	// copy_map(game->map);
	while (x < WIDTH)
	{
		dda(game, x);
		render(game, x);
		x++;
	}
}

int	 exec(t_game *game)
{
	// mlx_clear_window(game->ptr, game->win);
	start_game(game);
	mlx_put_image_to_window(game->ptr, game->win, game->img.ptr, 0, 0);
	return (0);
}
