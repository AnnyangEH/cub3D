#include "../inc/cub3D.h"

void	close_win(t_game *game)
{
	free_game_one(game);
	exit(0);
}

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	double	move_speed = 0.3;
	double	rot_speed = 0.2;

	if (key == KEY_W)
	{
		if (game->map->map[(int)game->player.y][(int)(game->player.x + game->player.dir_x * move_speed * 1.2)] == '0')
			game->player.x += game->player.dir_x * move_speed;
		if (game->map->map[(int)(game->player.y + game->player.dir_y * move_speed * 1.2)][(int)game->player.x] == '0')
			game->player.y += game->player.dir_y * move_speed;
	}

	if (key == KEY_S)
	{
		if (game->map->map[(int)game->player.y][(int)(game->player.x - game->player.dir_x * move_speed * 1.2)] == '0')
			game->player.x -= game->player.dir_x * move_speed;
		if (game->map->map[(int)(game->player.y - game->player.dir_y * move_speed * 1.2)][(int)game->player.x] == '0')
			game->player.y -= game->player.dir_y * move_speed;
	}

	if (key == KEY_D)
	{
		if (game->map->map[(int)(game->player.y + game->player.dir_x * move_speed * 1.2)][(int)game->player.x] == '0')
			game->player.y += game->player.dir_x * move_speed;
		if (game->map->map[(int)game->player.y][(int)(game->player.x - game->player.dir_y * move_speed * 1.2)] == '0')
			game->player.x -= game->player.dir_y * move_speed;
	}

	if (key == KEY_A)
	{
		if (game->map->map[(int)(game->player.y - game->player.dir_x * move_speed * 1.2)][(int)game->player.x] == '0')
			game->player.y -= game->player.dir_x * move_speed;
		if (game->map->map[(int)game->player.y][(int)(game->player.x + game->player.dir_y * move_speed * 1.2)] == '0')
			game->player.x += game->player.dir_y * move_speed;
	}


	if (key == KEY_LEFT)
	{
		double	oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed * -1) - game->player.dir_y * sin(rot_speed * -1);
		game->player.dir_y = oldDirX * sin(rot_speed * -1) + game->player.dir_y * cos(rot_speed * -1);
		double	oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_speed * -1) - game->player.plane_y * sin(rot_speed * -1);
		game->player.plane_y = oldPlaneX * sin(rot_speed * -1) + game->player.plane_y * cos(rot_speed * -1);
	}

	if (key == KEY_RIGHT)
	{
		double	oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
		game->player.dir_y = oldDirX * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
		double	oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
		game->player.plane_y = oldPlaneX * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
	}
	if (key == KEY_ESC)
		exit_hook(game);
	// reset_game(game);
	 exec(game);
	return (0);
}
