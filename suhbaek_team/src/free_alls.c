/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 06:31:37 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_map(t_map_config *map_config)
{
	int	idx;

	idx = 0;
	while (map_config->map[idx])
	{
		free(map_config->map[idx]);
		map_config->map[idx] = NULL;
		idx ++;
	}
	free(map_config->map);
	return (1);
}

void	free_all1(char ***str)
{
	int	idx;

	idx = 0;
	while ((*str)[idx])
	{
		free((*str)[idx]);
		idx ++;
	}
}

char	**free_all0(char **answer, int idx1)
{
	int	idx;

	idx = 0;
	while (idx < idx1)
	{
		free(answer[idx]);
		idx ++;
	}
	free(answer);
	return (NULL);
}

void	free_all_config(t_parsed_config *config)
{
	int	idx;

	idx = 0;
	if (config->north != NULL)
		free(config->north);
	config->north = NULL;
	if (config->south != NULL)
		free(config->south);
	config->south = NULL;
	if (config->east != NULL)
		free(config->east);
	config->east = NULL;
	if (config->west != NULL)
		free(config->west);
	config->west = NULL;
	if (config->map == NULL)
		return ;
	while (config->map[idx])
	{
		free(config->map[idx]);
		idx ++;
	}
	free(config->map);
}

t_map_config	free_all(t_map_config map_config)
{
	if (map_config.north != NULL)
		free(map_config.north);
	map_config.north = NULL;
	if (map_config.south != NULL)
		free(map_config.south);
	map_config.south = NULL;
	if (map_config.east != NULL)
		free(map_config.east);
	map_config.east = NULL;
	if (map_config.west != NULL)
		free(map_config.west);
	map_config.west = NULL;
	if (map_config.ceiling != NULL)
		free(map_config.ceiling);
	map_config.ceiling = NULL;
	if (map_config.floor != NULL)
		free(map_config.floor);
	map_config.floor = NULL;
	return (map_config);
}
