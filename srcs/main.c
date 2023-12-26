#include "../inc/cub3D.h"

// void	print_all(t_game *game)
// {
// 	for (int i = 0; i < 4; i++)
// 		printf("imgs[%d] : %s\n", i, game->imgs[i].path);
// 	printf("color[%d] : %d %d %d\n", 0, game->map->color[0][0], game->map->color[0][1], game->map->color[0][2]);
// 	printf("color[%d] : %d %d %d\n", 1, game->map->color[1][0], game->map->color[1][1], game->map->color[1][2]);
// 	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
// 	printf("game->height : %d\n", game->map->height);
// 	for (int i = 0; i < game->map->height; i++)
// 		printf("game->width[%d] : %d\n", i, game->map->width[i]);
// 	for (int i = 0; i < game->map->height; i++)
// 		printf("game->map[%d] : %s\n", i, game->map->map[i]);
// }

// void	check_leak(void)
// {
// 		system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	t_game	*game;

	//atexit(check_leak);
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_exit("Error\nFailed to allocate game\n", game);
	ft_init(ac, av, game);
	parse(game);
	//print_all(game); // for debug
	game->player = malloc(sizeof(t_player));
	game->player->x = 22;
	game->player->y = 12;
	game->player->dir_x = -1;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 1000, "cub3D");
	game->img.ptr = mlx_new_image(game->mlx, 1000, 1000);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_hook(game->win, 17, 0, exit_hook, game);
	mlx_key_hook(game->win, press_key, game);
	mlx_loop_hook(game->win, exec, game);
	mlx_loop(game->mlx);
	free_game_one(game); // free all
	return (SUCCESS);
}
	
