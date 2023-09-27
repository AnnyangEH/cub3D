#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit(ft_error(USAGE_ERROR));
	init_game(&game, av);
}
