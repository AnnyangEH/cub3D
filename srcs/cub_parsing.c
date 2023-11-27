#include "../inc/cub3D.h"

int	cub_parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (ft_error(USAGE_ERROR));
	if (!cub_parsing_init(game))
		return (FAILURE);
	if (!cub_parsing_map(game, av[1]))
		return (FAILURE);
	return (SUCCESS);
}

int	cub_parsing_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error(MALLOC_ERROR));
	game->win = mlx_new_window(game->mlx, 640, 480, "cub3D");
	if (!game->win)
		return (ft_error(MALLOC_ERROR));
	game->win_width = 640;
	game->win_height = 480;
	game->map_width = 0;
	game->map_height = 0;
	return (SUCCESS);
}

int cub_parsing_map(t_game *game, char *path)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_ERROR));
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		printf("%s\n", line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		return (ft_error(READ_ERROR));
	if (close(fd) == -1)
		return (ft_error(CLOSE_ERROR));
	return (SUCCESS);
}
