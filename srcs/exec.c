#include "../inc/cub3D.h"

int	exec(t_game *game)
{
	for (int x = 0; x < 1000; x++)
	{
		double	cameraX = 2 * x / 1000.0 - 1;
		double	rayDirX = game->player.dir_x + game->player.plane_x * cameraX;
		double	rayDirY = game->player.dir_y + game->player.plane_y * cameraX;

		int	mapX = (int)game->player.x;
		int	mapY = (int)game->player.y;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);
		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player.y) * deltaDistY;
		}

		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}

			if (game->map->map[mapY][mapX] == '1')
				hit = 1;
		}

		if (!side)
			perpWallDist = (mapX - game->player.x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - game->player.y + (1 - stepY) / 2) / rayDirY;

		int	lineHeight = (int)(1000 / perpWallDist);

		int	drawStart = (lineHeight * -1) / 2 + 1000 / 2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd = lineHeight / 2 + 1000 / 2;
		if (drawEnd >= 1000)
			drawEnd = 1000;

		int	color;
		if (game->map->map[mapY][mapX] == '1')
			color = create_trgb(0, 200, 120, 255);
		else if (game->map->map[mapY][mapX] == '0')
			color = create_trgb(0, 1000, 2000, 3000);
		else
			color = create_trgb(0, 0, 0, 0);

		if (side == 1)
			color = color / 2;

		for (int i = 0; i <= 1000; i++)
		{
			if (i >= drawStart && i <= drawEnd)
				my_mlx_pixel_put(game, x, i, color);
			else if (i < drawStart)
				my_mlx_pixel_put(game, x, i, create_trgb(200, 12, 125, 255));
			else if (i > drawEnd)
				my_mlx_pixel_put(game, x, i, create_trgb(0, 48, 85, 2));
		}
	}
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}
