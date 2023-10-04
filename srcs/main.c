#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit(ft_error(USAGE_ERROR));
	if (init_game(&game, av))
		exit(ft_error(game.err));
}
