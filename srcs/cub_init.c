#include "../inc/cub3D.h"

static int	init_map_one(t_game *game, char *path);

void	init_game(int ac, char **av, t_game *game)
{
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		ft_error("Error\nInvalid file extension\n", game);
	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments\n", game);
	if (init_map_one(game, av[1]))
		ft_error("Error\nFailed to initialize map\n", game);
	// if (init_mlx(game))
	// 	ft_error_exit("Error\nFailed to initialize mlx\n", MLX_ERROR);
	// if (init_cast(game))
	// 	ft_error_exit("Error\nFailed to initialize raycasting\n", CAST_ERROR);
}

static int	init_map_one(t_game *game, char *path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_memset(game->map, 0, sizeof(t_map));
	if (!game->map)
		return (FAILURE);
	game->map->path = ft_strdup(path);
	if (!game->map->path)
		return (FAILURE);
	return (SUCCESS);
}

// static int	init_mlx(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "cub3D");
// 	game->img.img = mlx_new_image(game->mlx, game->win_width, game->win_height);
// 	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
// 	if (!game->mlx || !game->win || !game->img.img || !game->img.addr)
// 		return (FAILURE);
// 	return (SUCCESS);
// }

// static int	init_cast(t_game *game)
// {
// 	// raycasting variables initialization
// 	return (SUCCESS);
// }