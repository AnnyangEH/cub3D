#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (!cub_parsing(&game, ac, av))
		exit(FAILURE);
	return (SUCCESS);
}