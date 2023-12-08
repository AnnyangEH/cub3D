#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(USAGE_ERROR));
	if (cub_parsing_init(&game))
		return (FAILURE);
	if (cub_parsing(&game, av))
		exit(FAILURE);
	return (SUCCESS);
}