#include "../inc/cub3D.h"

static int	init_game(t_game *game, char *path);
static int	init_mlx(t_game *game);

void	ft_init(int ac, char **av, t_game *game)
{
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		ft_error("Error\nInvalid file extension\n", game);
	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments\n", game);
	if (init_game(game, av[1]))
		ft_error("Error\nFailed to initialize map\n", game);
	if (init_mlx(game))
		ft_error_exit("Error\nFailed to initialize mlx\n", game);
	// if (init_cast(game))
	// 	ft_error_exit("Error\nFailed to initialize raycasting\n", game);
}

static int	init_game(t_game *game, char *path)
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

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (FAILURE);
	game->win = mlx_new_window(game->mlx, 1280, 720, "cub3D");
	if (!game->win)
		return (FAILURE);
	game->img = mlx_new_image(game->mlx, 1280, 720);
	if (!game->img)
		return (FAILURE);
	game->ptr = mlx_get_data_addr(game->img, &game->bit_per_pixel, &game->size_l, &game->endian);
	if (!game->ptr)
		return (FAILURE);
	return (SUCCESS);
}

// static int	init_cast(t_game *game)
// {
// 	// raycasting variables initialization
// 	return (SUCCESS);
// }