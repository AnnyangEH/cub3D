#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(USAGE_ERROR));
	if (!cub_parsing(&game, av))
		exit(FAILURE);
	// for (int i = 0; i < 22; i++)
	// 	printf("gamefile[%d]: %s\n", i, game.mapfile[i]);
	printf("--------------------------------------------------\n--------------------------------------------------\n");
	printf("gamefile[0]: %s\n", game.mapfile[0]);
	return (SUCCESS);
}