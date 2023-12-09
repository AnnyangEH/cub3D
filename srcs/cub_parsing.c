#include "../inc/cub3D.h"

static void	get_token_addr(t_game *game, char *line, int i, int flag)
{
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (flag < 5)
		game->map->token_addr[flag] = ft_strdup(line + i);
	else if (flag == 5)
		game->map->color[0].r = ft_atoi(line + i);
	else
}
//////// need more work

static void	check_token_data(t_game *game, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		get_token_addr(game, line, i, 0);
	else if (line[i] == 'S' && line[i + 1] == 'O')
	else if (line[i] == 'W' && line[i + 1] == 'E')
	else if (line[i] == 'E' && line[i + 1] == 'A')
		game->map->token_addr[3] = line + i + 2;
	else if (line[i] == 'S')
		game->map->token_addr[4] = line + i + 1;
	else if (line[i] == 'C')
		game->map->token_addr[5] = line + i + 1;
	else if (line[i] == 'F')
		game->map->token_addr[6] = line + i + 1;
}

static void	get_token_color(t_game *game, char c)
{
	if (c == 'F')
		game->map->token_color[0] = TRUE;
	else if (c == 'C')
		game->map->token_color[1] = TRUE;
}

static int check_token(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return (FALSE);
	else if (ft_strchr("NSWE", line[i]))
		check_token_data(game, line);
	else if (ft_strchr("FC", line[i]))
		get_token_color(game, line[i]);
	else if (ft_isdigit(line[i]))
		return (TRUE);
	else
		ft_exit_error("Error\nInvalid token\n", TOKEN_ERROR);
	return (FALSE);
}

static int parse_token(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit_error("Error\nFailed to read file\n", READ_ERROR);
		if (check_token(game, line))
			break ;
	}
	close(fd);
	return (SUCCESS);
}

void	parsing(t_game *game, char **av)
{
	if (parse_token(game, av[1]))
		ft_error_exit("Error\nFailed to parse token\n", TOKEN_ERROR);
}
