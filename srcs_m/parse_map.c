/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:45:49 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 18:12:22 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	count_height(t_game *game, int fd, int height)
{
	int		i;
	char	*line;

	fd = open(game->map->path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFailed to open file\n", game);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i = 0;
		while (line[i] == ' ')
			++i;
		if (line[i] == ' ' || line[i] == '\n' || ft_isdigit(line[i]))
			++height;
		free(line);
	}
	if (close(fd) == -1)
		ft_error("Error\nFailed to close file\n", game);
	return (height);
}

void	init_map_two(t_game *game)
{
	game->map->height = count_height(game, 0, 0);
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
	game->map->player_cnt++;
	game->map->map[height][width] = '0';
	game->player.x = width + 0.5;
	game->player.y = height + 0.5;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	if (c == 'N')
		game->player.dir_y = -1.0;
	else if (c == 'S')
		game->player.dir_y = 1.0;
	else if (c == 'W')
		game->player.dir_x = -1.0;
	else if (c == 'E')
		game->player.dir_x = 1.0;
	game->player.plane_y = game->player.dir_x * 0.66;
	game->player.plane_x = game->player.dir_y * (-0.66);
}

static void	parse_map_line(t_game *game, int height)
{
	int	i;

	i = -1;
	while (game->map->line[++i] && game->map->line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEW", game->map->line[i]))
			ft_error("Error\nInvalid map character\n", game);
		else if (ft_strchr("NSEW", game->map->line[i]))
			parse_player(game, game->map->line[i], height, i);
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
			ft_error("Error\nInvalid map - empty line\n", game);
		game->map->width[height] = width;
		game->map->map[height] = malloc(sizeof(char) * (width + 1));
		parse_map_line(game, height);
		free(game->map->line);
		game->map->line = get_next_line(game->map->fd);
		height++;
	}
	game->map->map[height] = NULL;
}
