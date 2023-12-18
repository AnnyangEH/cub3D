#include "../inc/cub3D.h"

static void	get_token_addr(t_game *game, char *line, int i, int flag)
{
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return ;
	ft_strdup(line + i, game->map->token_addr[flag]);
	if (!game->map->token_addr[flag])
		ft_exit_error("Error\nFailed to get img address\n", TOKEN_ERROR);
}

void	free_split(void **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	get_token_color(t_game *game, char *line, int i, int flag)
{
	char	**temp;

	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return ;
	temp = ft_split(line + i, ',');
	if (!temp)
		ft_exit_error("Error\nFailed to split string\n", SPLIT_ERROR);
	while (temp[j] && j < 3)
	{
		while (temp[j][k])
		{
			if (!ft_isdigit(temp[j][k]) || k > 3)
				ft_exit_error("Error\nInvalid color character\n", COLOR_ERROR);
			k++;
		}
		game->map.color[flag][j] = ft_catoi(temp[j]);
		j++;
	}
	if (line[i] != '\n')
		ft_exit_error("Error\nInvalid color range\n", COLOR_ERROR);
	split_free(temp);
}

static void	check_token_data(t_game *game, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		get_token_addr(game, line, i, 0);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		get_token_addr(game, line, i, 1);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		get_token_addr(game, line, i, 2);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		get_token_addr(game, line, i, 3);
	else if (line[i] == 'F')
		get_token_color(game, line, i, FLOOR);
	else if (line[i] == 'C')
		get_token_color(game, line, i, CEILING);
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

static void parse(t_game *game, char *file, int fd)
{
	char	*line;
	int		i;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit_error("Error\nFailed to read file\n", READ_ERROR);
		if (check_token(game, line))
			break ;
		free(line);
	}
	i = -1;
	while (++i < 4)
		if (game->map->token_addr[i] == NULL)
			ft_exit_error("Error\nFailed to get token address\n", TOKEN_ERROR);
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 3)
			if (game->map->color[i][j] == -1)
				ft_exit_error("Error\nFailed to get token color\n", TOKEN_ERROR);
	}
	return (SUCCESS);
}

void	parsing(t_game *game, char **av)
{
	int	fd;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FAILURE);
	parse(game, av[1], fd);
	if (close(fd) == -1)
		ft_error_exit("Error\nFailed to close file\n", TOKEN_ERROR);
}
