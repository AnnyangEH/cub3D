#include "../inc/cub3D.h"

void	init(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments\n", ARGUMENT_ERROR);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		ft_error_exit("Error\nInvalid file extension\n", EXTENSION_ERROR);
	if (init_map(game, av[1]))
		ft_error_exit("Error\nFailed to initialize map\n", MAP_ERROR);
	if (init_mlx(game))
		ft_error_exit("Error\nFailed to initialize mlx\n", MLX_ERROR);
}

static int	init_map(t_game *game, char *file)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (FAILURE);
	ft_memset(game, 0, sizeof(t_game));
	game->map.atoken[0] = "NO ";
	game->map.atoken[1] = "SO ";
	game->map.atoken[2] = "WE ";
	game->map.atoken[3] = "EA ";
	game->map.ctoken[0] = "C ";
	game->map.ctoken[1] = "F ";
	return (SUCCESS);
}

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "cub3D");
	game->img.img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
	if (!game->mlx || !game->win || !game->img.img || !game->img.addr)
		return (FAILURE);
	return (SUCCESS);
}

static int	init_cast(t_game *game)
{
	// raycasting variables initialization
	return (SUCCESS);
}