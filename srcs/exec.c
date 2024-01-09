#include "../inc/cub3D.h"

int	set_wall_dir(t_game *game, int side, int mapX, int mapY);
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
 //여기부터 텍스
		double	wallX;
		int		cps = set_wall_dir(game, side, mapX, mapY);

		if (!side)
			wallX = game->player.y + (perpWallDist * rayDirY);
		else
			wallX = game->player.x + (perpWallDist * rayDirX);
		wallX -= floor((wallX));
		int	texX = (int)(wallX * (double)game->imgs[cps].width);
		
		if (!side && rayDirX > 0)
			texX = game->imgs[cps].width - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = game->imgs[cps].width - texX - 1;
		
		double	step = (double)game->imgs[cps].height / lineHeight;
		double	texPos = (drawStart - 1000 / 2 + lineHeight / 2) * step;

		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos;
			// int	texY = (y - drawStart) * game->imgs[cps].height / (drawEnd - drawStart);
			texPos += step;
			int	color = *(int *)(game->imgs[cps].addr + (texY * game->imgs[cps].size_l + \
			texX * (game->imgs[cps].bpp / 8)));
			if (side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(game, x, y, color);
		}
		for (int y = 0; y < drawStart; y++)
			my_mlx_pixel_put(game, x, y, create_trgb(0, game->map->color[1][0], game->map->color[1][1], game->map->color[1][2]));
		for (int y = drawEnd; y <= 1000; y++)
			my_mlx_pixel_put(game, x, y, create_trgb(0, game->map->color[0][0], game->map->color[0][1], game->map->color[0][2]));
	}
	mlx_put_image_to_window(game->ptr, game->win, game->img_ptr, 0, 0);
	return (0);
}

int	set_wall_dir(t_game *game, int side, int mapX, int mapY)
{
	int	cps = 0;
//ㅇㅔ러 고려해야 될까?
	if (side && (game->player.y - mapY) < 0)//y, north
		cps = 0;
	else if (side && (game->player.y - mapY) > 0)//y, south
		cps = 1;
if (!side && (game->player.x - mapX) < 0) //x, east
		cps = 2;
	else if (!side && (game->player.x - mapX) > 0)//x, west
		cps = 3;
	return (cps);
}
