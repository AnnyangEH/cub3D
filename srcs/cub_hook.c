#include "../inc/cub3D.h"

void	set_hooks(t_game *game)
{
	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, 17, 0, &close_win, game);
}

void	close_win(t_game *game)
{
	free_game_one(game);
	exit(0);
}
