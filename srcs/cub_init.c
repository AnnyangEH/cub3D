#include "../inc/cub3D.h"

int	cub_parsing_init(t_game *game)
{
	game->win_width = 640;
	game->win_height = 480;
	ft_memset(game, 0, sizeof(t_game));
	game->token[0] = "NO ";
	game->token[1] = "SO ";
	game->token[2] = "WE ";
	game->token[3] = "EA ";
	game->token[4] = "C ";
	game->token[5] = "F ";
	game->token_flag = FALSE;
	return (SUCCESS);
}
