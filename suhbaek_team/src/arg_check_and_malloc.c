/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_and_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:55:44 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	how_many_words(char *str)
{
	int	idx;
	int	flag;
	int	words;

	idx = 0;
	flag = 0;
	words = 0;
	while (str[idx])
	{
		if (flag != 1 && str[idx] != ' ' && str[idx] != '\n')
			words ++;
		if (str[idx] != ' ' && str[idx] != '\n')
			flag = 1;
		else
			flag = 0;
		idx ++;
	}
	return (words);
}

int	is_it_nswefc(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (0);
	else if (str[0] == 'S' && str[1] == 'O')
		return (1);
	else if (str[0] == 'W' && str[1] == 'E')
		return (2);
	else if (str[0] == 'E' && str[1] == 'A')
		return (3);
	else if (str[0] == 'F' && str[1] == ' ')
		return (4);
	else if (str[0] == 'C' && str[1] == ' ')
		return (5);
	return (6);
}

int	dupstr_for_ext(char *str, t_map_config *map_config, int flag)
{
	if (flag == 0)
		return (mystrdup(str, &map_config->north));
	else if (flag == 1)
		return (mystrdup(str, &map_config->south));
	else if (flag == 2)
		return (mystrdup(str, &map_config->west));
	else if (flag == 3)
		return (mystrdup(str, &map_config->east));
	else if (flag == 4)
		return (mystrdup(str, &map_config->floor));
	else if (flag == 5)
		return (mystrdup(str, &map_config->ceiling));
	return (1);
}

int	find_out_extention(char *str, t_map_config *map_config)
{
	int	flag;

	flag = 0;
	flag = is_it_nswefc(str);
	if (flag >= 0 && flag <= 3)
	{
		if (how_many_words(str) != 2)
			return (1);
		else
			return (dupstr_for_ext(str, map_config, flag));
	}
	else if (flag == 4 || flag == 5)
		return (dupstr_for_ext(str, map_config, flag));
	return (1);
}

t_map_config	argument_checker(char **cub3d_map_config)
{
	t_map_config		map_config;
	int					idx;

	mymemset(&map_config);
	idx = 0;
	while (cub3d_map_config[idx])
	{
		if (map_config.north != NULL && map_config.south != NULL && \
			map_config.east != NULL && map_config.west != NULL && \
			map_config.floor != NULL && map_config.ceiling != NULL)
			break ;
		if (cub3d_map_config[idx][0] != '\n')
			if (find_out_extention(cub3d_map_config[idx], &map_config))
				return (free_all(map_config));
		idx ++;
	}
	while (cub3d_map_config[idx])
	{
		if (strdup_until_you_fail(&map_config, cub3d_map_config + idx))
			break ;
		idx ++;
	}
	return (map_config);
}
