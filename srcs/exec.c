#include "../inc/cub3D.h"

int	set_wall_dir(t_game *game, int side, int mapX, int mapY);

void	set_value(t_game *game)
{
	game->ray.camera = 2 * x / 1000.0 - 1;
	game->ray.ray_x = game->player.dir_x + game->player.plane_x * game->ray.camera;
	game->ray.ray_y = game->player.dir_y + game->player.plane_y * game->ray.camera;
	game->ray.map_x = (int)game->player.x;
	game->ray.map_y = (int)game->player.y;
	game->ray.delta_x = fabs(1 / game->ray.ray_x);
	game->ray.delta_y = fabs(1 / game->ray.ray_y);
	game->ray.hit = 0;
}
void	set_step_side(t_game *game)
{
	if (game->ray.ray_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_x = (game->player.x - game->ray.map_x) * game->ray.delta_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_x = (game->ray.map_x + 1.0 - game->player.x) * game->ray.delta_x;
	}
	if (game->ray.ray_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_y = (game->player.y - game->ray.map_y) * game->ray.delta_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_y = (game->ray.map_y + 1.0 - game->player.y) * game->ray.delta_y;
	}
}

void	hit_side(t_game *game)
{
	while (!game->ray.hit)
	{
		if (game->ray.side_x < game->ray.side_y)
		{
			game->ray.side_x += game->ray.delta_x;
			game->ray.map_x += game->ray.step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray.side_y += game->ray.delt_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}

		if (game->map->map[mapY][mapX] == '1')
			game->ray.hit = 1;
	}
	if (!game->ray.side)
		game->ray.perp_wall = (game->ray.map_x - game->player.x + (1 - game->ray.step_x) / 2) / game->ray.ray_x;
	else
		game->ray.perp_wall = (game->ray.map_y - game->player.y + (1 - game->ray.step_y) / 2) / game->ray.ray_y;
}

void	draw_point(t_game *game)
{
	game->ray.line_h = (int)(1000 / game->ray.perp_wall);

	game->ray.d_start = (game->ray.line_h * -1) / 2 + 1000 / 2;
	if (game->ray.d_start < 0)
		game->ray.d_start = 0;
	game->ray.d_end = game->ray.line_h / 2 + 1000 / 2;
	if (game->ray.d_end >= 1000)
		game->ray.d_end = 1000;
}

void	texture(t_game *game)
{
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
}

void	draw(t_game *game)
{
	for (int y = drawStart; y < drawEnd; y++)
	{
		int texY = (int)texPos & (game->imgs[cps].height - 1);
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

int	exec(t_game *game)
{
	set_value(game);
	hit_wall(game);
	draw_wall(game);
	for (int x = 0; x < 1000; x++)
	{
		set_value(game);
		set_step_side(game);
		hit_side(game);
		draw_point(game);
		texture(game);
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
	if (!side && (game->player.x - mapX) < 0) //x, west
		cps = 2;
	else if (!side && (game->player.x - mapX) > 0)//x, east
		cps = 3;
	return (cps);
}
