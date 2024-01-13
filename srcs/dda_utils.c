/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:05:29 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/12 18:08:33 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	cal_lineheight(t_ray *ray)
{
	ray->lineHeight = (int)(HEIGHT / ray->perpWallDist);
	ray->drawStart = (int)(HEIGHT / 2) - (int)(ray->lineHeight / 2);
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->drawEnd >= HEIGHT)
		ray->drawEnd = HEIGHT - 1;
}

void	cal_perpwalldist(t_ray *ray, t_game *game)
{
	if (!ray->side)
		ray->perpWallDist = (ray->mapX - game->player.x \
		+ (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - game->player.y \
		+ (1 - ray->stepY) / 2) / ray->rayDirY;
}

void	perform_dda(t_ray *ray, t_game *game)
{
	while (!ray->hit)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (game->map->map[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
	}
}

void	cal_step_and_sidedist(t_ray *ray, t_game *game)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->player.x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - game->player.x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->player.y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - game->player.y) * ray->deltaDistY;
	}
}

void	init_ray(t_ray *ray, t_game *game, int x)
{
	ray->cameraX = 2 * x / (double)WIDTH - 1;
	ray->rayDirX = game->player.dir_x + game->player.plane_x * ray->cameraX;
	ray->rayDirY = game->player.dir_y + game->player.plane_y * ray->cameraX;
	ray->mapX = (int)game->player.x;
	ray->mapY = (int)game->player.y;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}
