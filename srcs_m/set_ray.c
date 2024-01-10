#include "../inc/cub3D.h"

void	set_value(t_game *game, int x)
{
	game->ray.cam = 2 * x / 1000.0 - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * game->ray.cam;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * game->ray.cam;
	game->ray.map_x = (int)game->player.x;
	game->ray.map_y = (int)game->player.y;
	game->ray.dx = fabs(1 / game->ray.dir_x);
	game->ray.dy = fabs(1 / game->ray.dir_y);
	game->ray.hit = 0;
}

void	set_step_side(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_x = (game->player.x - game->ray.map_x) * game->ray.dx;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_x = (game->ray.map_x + 1.0 - game->player.x) * \
						   game->ray.dx;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_y = (game->player.y - game->ray.map_y) * game->ray.dy;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_y = (game->ray.map_y + 1.0 - game->player.y) * \
						   game->ray.dy;
	}
}

void	hit_side(t_game *game)
{
	while (!game->ray.hit)
	{
		if (game->ray.side_x < game->ray.side_y)
		{
			game->ray.side_x += game->ray.dx;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_y += game->ray.dy;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map->map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
	if (!game->ray.side)
		game->ray.perp_wall = (game->ray.map_x - game->player.x + \
				(1 - game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->ray.perp_wall = (game->ray.map_y - game->player.y + \
				(1 - game->ray.step_y) / 2) / game->ray.dir_y;
}

void	set_wall_dir(t_game *game)
{
//ㅇㅔ러 고려해야 될까? ㄱㅣ본값?
	if (game->ray.side && (game->player.y - game->ray.map_y) < 0)//y, north
		game->ray.cps = 0;
	else if (game->ray.side && (game->player.y - game->ray.map_y) > 0)//y, south
		game->ray.cps = 1;
	if (!game->ray.side && (game->player.x - game->ray.map_x) < 0)//x, west
		game->ray.cps = 2;
	else if (!game->ray.side && (game->player.x - game->ray.map_x) > 0)//x, east
		game->ray.cps = 3;
}
