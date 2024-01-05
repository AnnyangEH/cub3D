#include "../inc/cub3D.h"

void	get_img_path(t_game *game, char *line, int *i, int flag)
{
	int	size;

	size = 64;
	(*i) += 3; // skip imgs
	while (ft_iswhitespace(line[*i]) && line[*i]) // skip whitespace
		(*i)++;
	if (line[*i] == '\n')
		return ;
	game->imgs[flag].path = ft_strdup(line + *i);
	if (!game->imgs[flag].path)
		ft_error("Error\nFailed to allocate imgs path\n", game);
	if (game->imgs[flag].path[ft_strlen(game->imgs[flag].path) - 1] == '\n')
		game->imgs[flag].path[ft_strlen(game->imgs[flag].path) - 1] = '\0';
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	is_valid_color(t_game *game, int flag)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->map->color[flag][i] < 0 || game->map->color[flag][i] > 255)
			ft_error("Error\nInvalid color value\n", game);
		i++;
	}
}

static void	count_comma(t_game *game, char *line, int *i)
{
	int	j;
	int	cnt;

	cnt = 0;
	j = *i;
	while (line[j])
	{
		if (line[j] == ',')
			cnt++;
		j++;
	}
	if (cnt != 2)
		ft_error("Error\nInvalid color count\n", game);
}

void	get_img_color(t_game *game, char *line, int *i, int flag)
{
	int		j;
	char	**temp;

	j = 0;
	(*i)++;
	while (ft_iswhitespace(line[*i]) && line[*i])
		(*i)++;
	count_comma(game, line, i);
	if (line[*i] == '\n')
		return ;
	temp = ft_split(line + *i, ',');
	if (!temp)
		ft_error("Error\nFailed to split color string\n", game);
	while (temp[j] && j < 3)
	{
		game->map->color[flag][j] = ft_catoi(temp[j]);
		j++;
	}
	is_valid_color(game, flag);
	free_split(temp);
}

void	check_imgs_data(t_game *game, char *line, int *i)
{
	if (ft_strncmp(line + *i, "NO ", 3) == 0)
		get_img_path(game, line, i, 0);
	else if (ft_strncmp(line + *i, "SO ", 3) == 0)
		get_img_path(game, line, i, 1);
	else if (ft_strncmp(line + *i, "WE ", 3) == 0)
		get_img_path(game, line, i, 2);
	else if (ft_strncmp(line + *i, "EA ", 3) == 0)
		get_img_path(game, line, i, 3);
	else if (ft_strncmp(line + *i, "F ", 2) == 0)
		get_img_color(game, line, i, FLOOR);
	else if (ft_strncmp(line + *i, "C ", 2) == 0)
		get_img_color(game, line, i, CEILING);
	else
		ft_error("Error\nInvalid imgs\n", game);
}

int check_imgs(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return (FALSE);
	else if (ft_strchr("NSWEFC", line[i]))
		check_imgs_data(game, line, &i);
	else if (ft_isdigit(line[i]))
		return (TRUE);
	else
		ft_error("Error\nInvalid imgs\n", game);
	return (FALSE);
}

void	parse_token(t_game *game)
{
	int i;

	while (1)
	{
		game->map->line = get_next_line(game->map->fd);
		if (!game->map->line)
			ft_error("Error\nFailed to read file\n", game);
		if (check_imgs(game, game->map->line) == TRUE)
			break ;
		free(game->map->line);
	}
	i = 0;
	while (i < 4)
	{
		if (!game->imgs[i].path)
			ft_error("Error\nFailed to get imgs address\n", game);
		i++;
	}
}

static int	count_height(t_game *game)
{
	int		i;
	int		fd;
	int		height;
	char	*line;

	fd = open(game->map->path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFailed to open file\n", game);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i = 0;
		while (line[i] == ' ')
			++i;
		if (ft_isdigit(line[i]))
			height++;
		if (height > 0 && ft_isdigit(line[i]) == 0)
			ft_error("Error\nInvalid map character\n", game);
		free(line);
	}
	if (close(fd) == -1)
		ft_error("Error\nFailed to close file\n", game);
	return (height);
}

void init_map_two(t_game *game)
{
	game->map->height = count_height(game);
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

void	parse_player(t_game *game, char c, int height, int width)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	game->player.x = width + 0.5;
	game->player.y = height + 0.5;
	game->player.plane_x = game->player.dir_y * (-0.66);
	game->player.plane_y = game->player.dir_x * 0.66;
}

static void parse_map_line(t_game *game, int height)
{
	int	i;

	i = -1;
	while (game->map->line[++i] && game->map->line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEW", game->map->line[i]))
			ft_error("Error\nInvalid map\n", game);
		else if (ft_strchr("NSEW", game->map->line[i]))
		{
			if (game->map->player_cnt > 0)
				ft_error("Error\nMultiple players\n", game);
			game->map->player_cnt++;
			game->map->map[height][i] = '0';
			parse_player(game, game->map->line[i], height, i); // 수정 필요
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
	height = 0;
	while (game->map->line)
	{
		width = 0;
		while (game->map->line[width] && game->map->line[width] != '\n')
			++width;
		if (ft_isempty(game->map->line))
			ft_error("Error\nInvalid map\n", game);
		game->map->width[height] = width;
		game->map->map[height] = malloc(sizeof(char) * (width + 1));
		parse_map_line(game, height);
		free(game->map->line);
		game->map->line = get_next_line(game->map->fd);
		height++;
	}
	game->map->map[height] = NULL;
}

// static void	get_img(t_game *game)
// {
// 	int		i;

// 	i = -1;
// 	while (++i < 4)
// 		init_imgs(game, i);
// }

// static void	init_imgs(t_game *game, int i)
// {
// 	int	size;

// 	size = 64;
// 	game->imgs[i].ptr = mlx_xpm_file_to_image(game->, game->imgs[i].path, \
// 									&size, &size);
// 	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].ptr, &game->imgs[i].bpp, \
// 								&game->imgs[i].size_l, &game->imgs[i].endian);
// }

void	parse(t_game *game)
{
	game->map->fd = open(game->map->path, O_RDONLY);
	if (game->map->fd == -1)
		ft_error("Error\nFailed to open file\n", game);
	parse_token(game);
	parse_map(game);
	check_map(game);
	//get_img(game);
	if (close(game->map->fd) == -1)
		ft_error("Error\nFailed to close file\n", game);
}
