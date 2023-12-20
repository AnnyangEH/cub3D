#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_exit("Error\nFailed to allocate game\n", game);
	init_game(ac, av, game);
	parse(game);
	printf("addr[%d] : %s\n", 0, game->token_addr[0]);
	printf("addr[%d] : %s\n", 1, game->token_addr[1]);
	printf("addr[%d] : %s\n", 2, game->token_addr[2]);
	printf("addr[%d] : %s\n", 3, game->token_addr[3]);
	printf("color[%d] : %d %d %d\n", 0, game->map->color[0][0], game->map->color[0][1], game->map->color[0][2]);
	printf("color[%d] : %d %d %d\n", 1, game->map->color[1][0], game->map->color[1][1], game->map->color[1][2]);
	free_game(game);
	return (SUCCESS);
}