#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(USAGE_ERROR));
	if (cub_parsing(&game, av))
		exit(FAILURE);
	// for (int i = 0; i < 22; i++)
	printf("\n--------------------------------------------------------------------------\n\n");
	printf("%d\n", game.flags[0]);
	printf("%d\n", game.flags[1]);
	printf("%d\n", game.flags[2]);
	printf("%d\n", game.flags[3]);
	printf("%d\n", game.flags[4]);
	printf("%d\n", game.flags[5]);
	return (SUCCESS);
}