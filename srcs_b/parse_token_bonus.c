/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:34:18 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/12 18:41:13 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

void	get_img_path(t_game *game, char *line, int *i, int flag)
{
	(*i) += 3;
	while (ft_iswhitespace(line[*i]) && line[*i])
		(*i)++;
	if (line[*i] == '\n')
		return ;
	game->imgs[flag].cnt++;
	if (game->imgs[flag].cnt > 1)
		ft_error("Error\nDup imgs\n", game);
	game->imgs[flag].path = ft_strdup(line + *i);
	if (!game->imgs[flag].path)
		ft_error("Error\nFailed to allocate imgs path\n", game);
	if (game->imgs[flag].path[ft_strlen(game->imgs[flag].path) - 1] == '\n')
		game->imgs[flag].path[ft_strlen(game->imgs[flag].path) - 1] = '\0';
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
		return ;
	temp = ft_split(line + *i, ',');
	if (!temp)
		ft_error("Error\nFailed to split color string\n", game);
	while (temp[j] && j < 3)
	{
		game->map->color[flag][j] = ft_catoi(temp[j]);
		if ((ft_catoi(temp[j]) == -1) || (ft_catoi(temp[j]) > 255 \
		|| ft_catoi(temp[j]) < 0))
			ft_error("Error\nInvalid color value\n", game);
		j++;
	}
	if (temp[j])
		ft_error("Error\nInvalid color count it must be three\n", game);
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
	else if (ft_strncmp(line + *i, "DOOR ", 5) == 0)
		get_img_path(game, line, i, 4);
	else if (ft_strncmp(line + *i, "M1 ", 3) == 0)
		get_img_path(game, line, i, 5);
	else if (ft_strncmp(line + *i, "M2 ", 3) == 0)
		get_img_path(game, line, i, 6);
	else if (ft_strncmp(line + *i, "M3 ", 3) == 0)
		get_img_path(game, line, i, 7);
	else if (ft_strncmp(line + *i, "M4 ", 3) == 0)
		get_img_path(game, line, i, 8);
	else if (ft_strncmp(line + *i, "F ", 2) == 0)
		get_img_color(game, line, i, FLOOR);
	else if (ft_strncmp(line + *i, "C ", 2) == 0)
		get_img_color(game, line, i, CEILING);
	else
		ft_error("Error\nInvalid imgs\n", game);
}

int	check_imgs(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(line[i]) && line[i])
		i++;
	if (line[i] == '\n')
		return (FALSE);
	else if (ft_strchr("NSWEFCDM", line[i]))
		check_imgs_data(game, line, &i);
	else if (ft_isdigit(line[i]))
		return (TRUE);
	else
		ft_error("Error\nInvalid imgs\n", game);
	return (FALSE);
}

void	parse_token(t_game *game)
{
	int	i;

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
	while (i < 9)
	{
		if (!game->imgs[i].path)
			ft_error("Error\nOne or more imgs are missing\n", game);
		i++;
	}
}
