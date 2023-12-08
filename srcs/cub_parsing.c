#include "../inc/cub3D.h"

void	cub_token_count(t_game *game, char *line)
{
	int	i;

	i = 0;
	if (!ft_strncmp("\n", line, 1))
		return ;
	while (i < 6)
	{
		if (!ft_strncmp(game->token[i], line, ft_strlen(game->token[i])))
			game->token_flags[i]++;
		i++;
	}
	if (game->token_flags[0] == 1 && game->token_flags[1] == 1 && game->token_flags[2] == 1 && game->token_flags[3] == 1 && game->token_flags[4] == 1 && game->token_flags[5] == 1)
		game->token_flag = TRUE;
}

int	cub_check_token(t_game *game, char *file, int fd)
{
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_ERROR));
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
			game->map_height++;
		free(line);
	}
	return (SUCCESS);
}

int	cub_make_map(t_game *game, char *line)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(line);
	game->map[game->map_height] = malloc(sizeof(char) * (game->map_width + 1));
	if (!game->map[game->map_height])
		return (ft_error(MALLOC_ERROR));
	while (line[i])
	{
		if (line[i] == '0' && line[i] == '1' && line[i] == 32)
			game->map[game->map_height][i] = line[i];
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			game->map[game->map_height][i] = '0';
			game->player.x = i + 0.0;
			game->player.y = game->map_height + 0.0;
			game->player.dir = game->player.x + game->player.y;
		}
		else
			return (printf("%s", line), ft_error(CHAR_ERROR));
		i++;
	}
	return (SUCCESS);
}

int	cub_parsing_map(t_game *game, char *file, int fd, int i)
{
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_ERROR));
	if (!(game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1))))
		return (ft_error(MALLOC_ERROR));
	while (1)
	{
		line = get_next_line(fd);
		if (line && (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == 'C' || line[0] == 'F' || line[0] == '\n'))
		{
			free(line);
			continue ;
		}
		if (!line)
		{
			if (close(fd) == -1)
				return (ft_error(CLOSE_ERROR));
			break ;
		}
		else if (game->token_flag == TRUE)
		{
			if (cub_make_map(game, line))
				return (FAILURE);
		}
		free(line);
	}
	game->map[i] = NULL;
	return (SUCCESS);
}

int	cub_parsing(t_game *game, char **av)
{
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (ft_error(EXTENSION_ERROR));
	if (cub_check_token(game, av[1], 0))
		return (FAILURE);
	if (cub_parsing_map(game, av[1], 0, 0))
		return (FAILURE);
	return (SUCCESS);
}
