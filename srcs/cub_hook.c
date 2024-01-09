#include "../inc/cub3D.h"

//void	set_hooks(t_game *game)
//{
//	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
//	mlx_hook(game->win, 17, 0, &close_win, game);
//}

void	close_win(t_game *game)
{
	free_game_one(game);
	exit(0);
}

// void	reset_game(t_game *game)
// {
// 	// mlx_destroy_image(game->ptr, game->img_ptr);
// 	game->img.ptr = mlx_new_image(game->ptr, WIDTH, HEIGHT);
// 	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp, \
// 	&game->img.size_l, &game->img.endian);
// }

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	game->time.old_time = game->time.curr_time;
	game->time.curr_time = get_time();
	double	fr_time = (game->time.curr_time - game->time.old_time) / 1000.0;

	double	move_speed = fr_time * 5.0;
	double	rot_speed = fr_time * 3.0;

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
