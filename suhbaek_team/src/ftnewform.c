/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnewform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:32:39 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mymemset(t_map_config *map_config)
{
	map_config->north = NULL;
	map_config->south = NULL;
	map_config->west = NULL;
	map_config->east = NULL;
	map_config->floor = NULL;
	map_config->ceiling = NULL;
	map_config->map = NULL;
}

int	mystrdup(const char *s1, char **s2)
{
	int	idx;

	if (*s2 != NULL)
		return (1);
	idx = 0;
	while (s1[idx])
		idx ++;
	*s2 = (char *)malloc(sizeof(char) * (idx + 1));
	if (*s2 == NULL)
		return (1);
	while (idx >= 0)
	{
		(*s2)[idx] = s1[idx];
		idx --;
	}
	return (0);
}

int	mystrdup1(const char *s1, char **s2)
{
	int	idx;

	idx = 0;
	while (s1[idx])
		idx ++;
	*s2 = (char *)malloc(sizeof(char) * (idx + 1));
	if (*s2 == NULL)
		return (1);
	while (idx >= 0)
	{
		(*s2)[idx] = s1[idx];
		idx --;
	}
	return (0);
}

int	strdup_until_you_fail(t_map_config *map_config, char **map)
{
	int	idx;

	idx = check_nbr_one(map[0]);
	if (idx == 0)
		return (0);
	idx = 0;
	while (map[idx])
		idx ++;
	map_config->map = malloc(sizeof(char *) * (idx + 1));
	if (map_config->map == NULL)
		return (1);
	idx = 0;
	while (map[idx])
	{
		if (mystrdup1(map[idx], &map_config->map[idx]))
			return (free_map(map_config));
		idx ++;
	}
	map_config->map[idx] = NULL;
	return (1);
}

int	check_nbr_one(char *str)
{
	int	idx;

	idx = 0;
	if (str == NULL)
		return (2);
	while (str[idx])
	{
		if (str[idx] == '1')
			return (1);
		idx ++;
	}
	return (0);
}
