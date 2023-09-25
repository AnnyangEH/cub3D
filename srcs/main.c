#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		exit(ft_error(USAGE_ERROR));
	game = ft_malloc(sizeof(t_game));
	init_game(t_game, av);
}
