#include "../inc/cub3D.h"

void	cub_token_count(t_game *game, char *line)
{
	if (!ft_strncmp(game->token[0], line, 3))
		game->token_flags[0]++;
	else if (!ft_strncmp(game->token[1], line, 3))
		game->token_flags[1]++;
	else if (!ft_strncmp(game->token[2], line, 3))
		game->token_flags[2]++;
	else if (!ft_strncmp(game->token[3], line, 3))
		game->token_flags[3]++;
	else if (!ft_strncmp(game->token[4], line, 2))
		game->token_flags[4]++;
	else if (!ft_strncmp(game->token[5], line, 2))
		game->token_flags[5]++;
	else if (game->token_flags[0] == 1 && game->token_flags[1] == 1 && game->token_flags[2] == 1 && \
	game->token_flags[3] == 1 && game->token_flags[4] == 1 && game->token_flags[5] == 1)
		game->token_flag = TRUE;
		return ;
}

int	cub_map_parsing(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' && line[i] != ' ')
			return (ft_error(MAP_ERROR));
		game->map[game->map_height][i] = line[i];
		// mlx put function
		i++;
	}
	game->map_height++;
	return (SUCCESS);
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
			if (game->token_flag == FALSE)
				return (ft_error(FORMAT_ERROR));
			break ;
		}
		else if (game->token_flag == TRUE)
		{
			if (cub_map_parsing(game, line))
				return (FAILURE);
		}
		free(line);
		game->file_height++;
	}
	return (SUCCESS);
}

int cub_parsing(t_game *game, char **av)
{
	int		fd;

	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0) // .cub로 끝나지 않으면
		return (ft_error(FORMAT_ERROR));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_ERROR));
	if (cub_parsing_file(game, fd))
		return (FAILURE);
	return (SUCCESS);
}
