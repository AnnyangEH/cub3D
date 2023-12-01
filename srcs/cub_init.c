#include "../inc/cub3D.h"

int	cub_parsing_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error(MALLOC_ERROR));
	game->win = mlx_new_window(game->mlx, 640, 480, "cub3D");
	if (!game->win)
		return (ft_error(MALLOC_ERROR));
	game->win_width = 640;
	game->win_height = 480;
	ft_memset(game, 0, sizeof(t_game));
	game->token[0] = "NO ";
	game->token[1] = "SO ";
	game->token[2] = "WE ";
	game->token[3] = "EA ";
	game->token[4] = "C ";
	game->token[5] = "F ";
	return (SUCCESS);
}
