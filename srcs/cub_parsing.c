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
	ft_memset(game, 0, sizeof(t_game));
	game->token[0] = "NO ";
	game->token[1] = "SO ";
	game->token[2] = "WE ";
	game->token[3] = "EA ";
	game->token[4] = "C ";
	game->token[5] = "F ";
	return (SUCCESS);
}



void	cub_token_count(t_game *game, char *line)
{
	if (!ft_strncmp(game->token[0], line, 3))
		game->flags[0]++;
	else if (!ft_strncmp(game->token[1], line, 3))
		game->flags[1]++;
	else if (!ft_strncmp(game->token[2], line, 3))
		game->flags[2]++;
	else if (!ft_strncmp(game->token[3], line, 3))
		game->flags[3]++;
	else if (!ft_strncmp(game->token[4], line, 2))
		game->flags[4]++;
	else if (!ft_strncmp(game->token[5], line, 2))
		game->flags[5]++;
	else
		return ;
}

int	cub_parsing_file(t_game *game, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		cub_token_count(game, line);
		if (!line)
		{
			if (close(fd) == -1)
				return (ft_error(CLOSE_ERROR));
			if (game->flags[0] != 1 || game->flags[1] != 1 || game->flags[2] != 1
				|| game->flags[3] != 1 || game->flags[4] != 1 || game->flags[5] != 1)
				return (ft_error(FORMAT_ERROR));
			break ;
		}
		free(line);
		game->file_height++;
	}
	return (SUCCESS);
}

static int cub_parsing_map(t_game *game, char *path)
{
	int		fd;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4) != 0) // .cub로 끝나지 않으면
		return (ft_error(FORMAT_ERROR));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_ERROR));
	if (cub_parsing_file(game, fd))
		return (FAILURE);

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
