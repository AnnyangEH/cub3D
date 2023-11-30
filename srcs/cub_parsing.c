#include "../inc/cub3D.h"

static int	cub_parsing_init(t_game *game)
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
	game->map = NULL;
	game->mapfile = NULL;
	game->token[0] = "NO ";
	game->token[1] = "SO ";
	game->token[2] = "WE ";
	game->token[3] = "EA ";
	game->token[4] = "S ";
	game->token[5] = "F ";
	game->token[6] = "C ";
	return (SUCCESS);
}

int	cub_check_map_line(t_game *game, char *line)
{
	if (ft_strncmp(game->token[0], line, 3))
		return (ft_error(TEXTURE_ERROR));
	else if (ft_strncmp(game->token[1], line, 3))
		return (ft_error(TEXTURE_ERROR));
	else if (ft_strncmp(game->token[2], line, 3))
		return (ft_error(TEXTURE_ERROR));
	else if (ft_strncmp(game->token[3], line, 3))
		return (ft_error(TEXTURE_ERROR));
	else if (ft_strncmp(game->token[4], line, 3))
		return (ft_error(TEXTURE_ERROR));
	else if (ft_strncmp(game->token[5], line, 2))
		return (ft_error(COLOR_ERROR));
	else if (ft_strncmp(game->token[6], line, 2))
		return (ft_error(COLOR_ERROR));
	else if (line[0] == '\n')
		return (SUCCESS);
}

int	cub_check_map(t_game *game, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cub_check_map_line(game, line))
			exit(FAILURE);
		free(line);
	}
}

static int cub_parsing_map(t_game *game, char *path)
{
	int		fd;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4) != 0)
		return (ft_error(FORMAT_ERROR));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_ERROR));
	if (cub_check_map(game, fd))
		return (FAILURE);
	if (close(fd) == -1)
		return (ft_error(CLOSE_ERROR));
	return (SUCCESS);
}

int	cub_parsing(t_game *game, char **av)
{
	if (cub_parsing_init(game))
		return (FAILURE);
	if (cub_parsing_map(game, av[1]))
		return (FAILURE);
	return (SUCCESS);
}
