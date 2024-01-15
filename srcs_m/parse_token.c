/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:34:18 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 16:07:24 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_img_path(t_game *game, char *line, int *i, int flag)
{
	(*i) += 3;
	while (ft_iswhitespace(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == '\n')
		ft_free("Error\nMissing img path\n", game, -1);
	if (game->imgs[flag].path)
		free(game->imgs[flag].path);
	game->imgs[flag].path = ft_strdup(line + *i);
	if (!game->imgs[flag].path)
		ft_free("Error\nEmpty img path\n", game, -1);
	if (game->imgs[flag].path[ft_strlen(game->imgs[flag].path) - 1] == '\n')
		game->imgs[flag].path[ft_strlen(game->imgs[flag].path) - 1] = '\0';
	if (open(game->imgs[flag].path, O_RDONLY) == -1)
		ft_free("Error\nWrong img path\n", game, -1);
}

void	get_img_color(t_game *game, char *line, int *i, int flag)
{
	int		j;
	char	**temp;

	j = 0;
	(*i)++;
	while (ft_iswhitespace(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == '\n')
		ft_free("Error\nMissing color value\n", game, -1);
	sep_count(game, line, ',');
	temp = ft_split(line + *i, ',');
	if (!temp)
		ft_free("Error\nFailed to split color string\n", game, -1);
	while (temp[j] && j < 3)
	{
		game->map->color[flag][j] = ft_catoi(temp[j]);
		if ((ft_catoi(temp[j]) > 255 || ft_catoi(temp[j]) < 0))
			ft_free("Error\nInvalid color value\n", game, -1);
		j++;
	}
	if (temp[j] || j != 3)
		ft_free("Error\nInvalid color count it must be three\n", game, -1);
	free_split(temp);
}

void	check_imgs_data(t_game *game, char *line, int *i)
{
	if (ft_strncmp(line + *i, "NO ", 3) == 0)
		get_img_path(game, line, i, NO);
	else if (ft_strncmp(line + *i, "SO ", 3) == 0)
		get_img_path(game, line, i, SO);
	else if (ft_strncmp(line + *i, "WE ", 3) == 0)
		get_img_path(game, line, i, WE);
	else if (ft_strncmp(line + *i, "EA ", 3) == 0)
		get_img_path(game, line, i, EA);
	else if (ft_strncmp(line + *i, "F ", 2) == 0)
		get_img_color(game, line, i, FLOOR);
	else if (ft_strncmp(line + *i, "C ", 2) == 0)
		get_img_color(game, line, i, CEILING);
	else
		ft_free("Error\nInvalid imgs format\n", game, -1);
}

int	check_imgs(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return (2);
	else if (ft_strchr("NSWEFC", line[i]))
		check_imgs_data(game, line, &i);
	else if (ft_isdigit(line[i]))
		return (1);
	else
		ft_free("Error\nInvalid imgs filename\n", game, -1);
	return (0);
}

void	parse_token(t_game *game)
{
	int	i;

	while (1)
	{
		game->map->line = get_next_line(game->map->fd);
		if (!game->map->line)
			ft_free("Error\nFailed to read file\n", game, -1);
		if (check_imgs(game, game->map->line) == 2)
		{
			free(game->map->line);
			continue ;
		}
		else if (check_imgs(game, game->map->line) == 1)
			break ;
		free(game->map->line);
	}
	i = 0;
	while (i < 4)
	{
		if (!game->imgs[i].path)
			ft_free("Error\nOne or more imgs adress is missing\n", game, -1);
		i++;
	}
}
