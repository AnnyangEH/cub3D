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

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	game->time->old_time = game->time->curr_time;
	game->time->curr_time = get_time();
	double	fr_time = (game->time->curr_time - game->time->old_time) / 1000.0;

	double	move_speed = fr_time * 3.0;
	double	rot_speed = fr_time;

	if (key == KEY_UP)
	{
		if (game->map->map[(int)(game->player->x + game->player->dir_x * move_speed)][(int)game->player->y] == 0)
			game->player->x += game->player->dir_x * move_speed;
		if (game->map->map[(int)game->player->x][(int)(game->player->y + game->player->dir_y * move_speed)] == 0)
			game->player->y += game->player->dir_y * move_speed;
	}

	if (key == KEY_DOWN)
	{
		if (game->map->map[(int)(game->player->x - game->player->dir_x * move_speed)][(int)game->player->y] == FALSE)
			game->player->x -= game->player->dir_x * move_speed;
		if (game->map->map[(int)game->player->x][(int)(game->player->y - game->player->dir_y * move_speed)] == FALSE)
			game->player->y -= game->player->dir_y * move_speed;
	}

	if (key == KEY_RIGHT)
	{
		double	oldDirX = game->player->dir_x;
		game->player->dir_x = game->player->dir_x * cos(rot_speed * -1) - game->player->dir_y * sin(rot_speed * -1);
		game->player->dir_y = oldDirX * sin(rot_speed * -1) + game->player->dir_y * cos(rot_speed * -1);
		double	oldPlaneX = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(rot_speed * -1) - game->player->plane_y * sin(rot_speed * -1);
		game->player->plane_y = oldPlaneX * sin(rot_speed * -1) + game->player->plane_y * cos(rot_speed * -1);
	}

	if (key == KEY_LEFT)
	{
		double	oldDirX = game->player->dir_x;
		game->player->dir_x = game->player->dir_x * cos(rot_speed) - game->player->dir_y * sin(rot_speed);
		game->player->dir_y = oldDirX * sin(rot_speed) + game->player->dir_y * cos(rot_speed);
		double	oldPlaneX = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(rot_speed) - game->player->plane_y * sin(rot_speed);
		game->player->plane_y = oldPlaneX * sin(rot_speed) + game->player->plane_y * cos(rot_speed);
	}
	if (key == KEY_ESC)
		exit_hook(game);
	return (0);
}
