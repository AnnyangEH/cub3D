#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_exit("Error\nFailed to allocate game\n", game);
	init_game(ac, av, game);
	parse(game);
	for (int i = 0; i < game->map->height; i++)
		printf("%s\n", game->map->map[i]);
	printf("--------------------------------------------\n");
	printf("game->height : %d\n" , game->map->height);
	printf("--------------------------------------------\n");
	printf("game->height_cnt : %d\n" , game->map->height_cnt);
	printf("--------------------------------------------\n");
	for (int i = 0; i < game->map->height; i++)
		printf("%d width : %d\n", i, game->map->width[i]);
	free_game(game);
	return (SUCCESS);
}