#include "../inc/cub3D.h"

static int	init_game(t_game *game, char *path);
static int	init_mlx(t_game *game);
static int	init_img(t_game *game, t_imgs *img, int width, int height);
// static int	init_cast(t_game *game);

void	ft_init(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error_exit("Error\nInvalid number of arguments\n", game);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		ft_error_exit("Error\nInvalid file extension\n", game);
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
	int	i;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (FAILURE);
	game->win = mlx_new_window(game->mlx, 1280, 720, "cub3D");
	if (!game->win)
		return (FAILURE);
	init_img(game, &game->img, 64, 64);
	i = -1;
	while (++i < 4)
		if (init_img(game, &game->imgs[i], 64, 64))
			return (FAILURE);
	return (SUCCESS);
}

static int	init_img(t_game *game, t_imgs *img, int width, int height)
{
	img->ptr = mlx_new_image(game->mlx, width, height);
	if (!img->ptr)
		return (FAILURE);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l,
			&img->endian);	
	if (!img->addr)
		return (FAILURE);
	return (SUCCESS);
}

// static int	init_cast(t_game *game)
// {
// 	// raycasting variables initialization
// 	return (SUCCESS);
// }