#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_exit("Error\nFailed to allocate game\n", game);
	ft_init(ac, av, game);
	parse(game);
	for (int i = 0; i < 4; i++)
		printf("token[%d] : %s\n", i, game->token[i].path);
	printf("color[%d] : %d %d %d\n", 0, game->map->color[0][0], game->map->color[0][1], game->map->color[0][2]);
	printf("color[%d] : %d %d %d\n", 1, game->map->color[1][0], game->map->color[1][1], game->map->color[1][2]);
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("game->height : %d\n", game->map->height);
	for (int i = 0; i < game->map->height; i++)
		printf("game->width[%d] : %d\n", i, game->map->width[i]);
	for (int i = 0; i < game->map->height; i++)
		printf("game->map[%d] : %s\n", i, game->map->map[i]);
	free_game(game);
	return (SUCCESS);
}