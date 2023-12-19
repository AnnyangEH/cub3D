#include "../inc/cub3D.h"

void	get_token_addr(t_game *game, char *line, int *i, int flag)
{
	while (ft_iswhitespace(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == '\n')
		return ;
	game->token_addr[flag] = ft_strdup(line + *i);
	if (!game->token_addr[flag])
		ft_error("Error\nFailed to get img address\n", game);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	get_token_color(t_game *game, char *line, int *i, int flag)
{
	int		j;
	char	**temp;

	j = 0;
	(*i)++;
	while (ft_iswhitespace(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == '\n')
		return ;
	temp = ft_split(line + *i, ',');
	if (!temp)
		ft_error("Error\nFailed to split string\n", game);
	while (temp[j] && j < 3)
	{
		game->map->color[flag][j] = ft_catoi(temp[j]);
		j++;
	}
	free_split(temp);
}

void	check_token_data(t_game *game, char *line, int *i)
{
	if (line[*i] == 'N' && line[*i + 1] == 'O' )
		get_token_addr(game, line, i, 0);
	else if (line[*i] == 'S' && line[*i + 1] == 'O')
		get_token_addr(game, line, i, 1);
	else if (line[*i] == 'W' && line[*i + 1] == 'E')
		get_token_addr(game, line, i, 2);
	else if (line[*i] == 'E' && line[*i + 1] == 'A')
		get_token_addr(game, line, i, 3);
	else if (line[*i] == 'F')
		get_token_color(game, line, i, FLOOR);
	else if (line[*i] == 'C')
		get_token_color(game, line, i, CEILING);
}

int check_token(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return (FALSE);
	else if (ft_strchr("NSWEFC", line[i]))
		check_token_data(game, line, &i);
	else if (ft_isdigit(line[i]))
		return (TRUE);
	else
		ft_error("Error\nInvalid token\n", game);
	return (FALSE);
}

void	parse_token(t_game *game)
{
	int		i;
	int		j;

	while (1)
	{
		game->map->line = get_next_line(game->map->fd);
		if (!game->map->line)
			ft_error("Error\nFailed to read file\n", game);
		game->map->height_cnt++;
		if (check_token(game, game->map->line) == TRUE)
			break ;
		free(game->map->line);
	}
	i = -1;
	while (game->token_addr[++i])
		if (game->token_addr == NULL)
			ft_error("Error\nFailed to get token address\n", game);
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 3)
			if (game->map->color[i][j] == -1)
				ft_error("Error\nFailed to get token color\n", game);
	}
}

static void	count_height(t_game *game, int fd)
{
	int		i;
	char	*line;

	fd = open(game->map->path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFailed to open file\n", game);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i >= game->map->height_cnt)
			game->map->height++;
		i++;
		free(line);
	}
	if (close(fd) == -1)
		ft_error("Error\nFailed to close file\n", game);
}

void init_map_two(t_game *game)
{
	count_height(game , 0);
	game->map->player_cnt = 0;
	game->map->map = malloc(sizeof(char *) * (game->map->height + 1));
	if (!game->map->map)
		ft_error("Error\nFailed to allocate map\n", game);
	game->map->width = malloc(sizeof(int) * game->map->height);
	if (!game->map->width)
		ft_error("Error\nFailed to allocate map\n", game);
	ft_memset(game->map->width, 0, sizeof(int) * game->map->height);
	ft_memset(game->map->map, 0, sizeof(char *) * (game->map->height + 1));
}

// void	parse_player(t_game *game, char c, int height, int width)
// {
// }

static void parse_map_line(t_game *game, int height)
{
	int	i;

	i = -1;
	if (ft_isempty(game->map->line))
	{
		game->map->map[height][0] = ' ';
		game->map->map[height][1] = '\0';
		return ;
	}
	while (game->map->line[++i] && game->map->line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEW", game->map->line[i]))
			ft_error("Error\nInvalid map\n", game);
		else if (ft_strchr("NSEW", game->map->line[i]))
		{
			game->map->map[height][i] = '0';
			game->map->player_cnt++;
			// parse_player(game, game->map->line[i], height, i);
		}
		else
			game->map->map[height][i] = game->map->line[i];
	}
	game->map->map[height][i] = '\0';
}
void	parse_map(t_game *game)
{
	int	height;
	int	width;

	init_map_two(game);
	height = -1;
	while (game->map->line)
	{
		width = 0;
		while (game->map->line[width] && game->map->line[width] != '\n')
			width++;
		if (ft_isempty(game->map->line))
			width = 1;
		++height;
		game->map->width[height] = width;
		game->map->map[height] = malloc(sizeof(char) * (width + 1));
		if (!game->map->map[height])
			ft_error("Error\nFailed to allocate map game\n", game);
		parse_map_line(game, height);
		free(game->map->line);
		game->map->line = get_next_line(game->map->fd);
	}
	game->map->height = ++height;
	game->map->map[height] = NULL;
}

void	parse(t_game *game)
{
	game->map->fd = open(game->map->path, O_RDONLY);
	if (game->map->fd == -1)
		ft_error("Error\nFailed to open file\n", game);
	parse_token(game);
	parse_map(game);
	// valid_map(game);
	// draw_map(game);
	if (close(game->map->fd) == -1)
		ft_error("Error\nFailed to close file\n", game);
}
