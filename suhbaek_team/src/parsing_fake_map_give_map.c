/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fake_map_give_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:32:08 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	give_clean_map(char **map, t_parsed_config *config)
{
	int	idx;
	int	temp;

	idx = 0;
	while (map[idx])
		idx ++;
	while (idx -- > 0)
		if (map[idx] != NULL)
			if (!space_only(map[idx]))
				break ;
	idx ++;
	config->map = malloc(sizeof(char *) * (idx + 1));
	if (config->map == NULL)
		return (1);
	temp = idx;
	idx = 0;
	while (idx < temp)
	{
		if (mystrdup1(map[idx], &config->map[idx]))
			return (1);
		idx ++;
	}
	config->map[idx] = NULL;
	return (0);
}

char	**make_fake_map(char **map, int *flag, int *flag1)
{
	char	**fake_map;
	int		idx;
	int		idx1;

	idx = 0;
	while (map[idx])
		idx ++;
	fake_map = malloc(sizeof(char *) * (idx + 1));
	if (fake_map == NULL)
		return (NULL);
	idx1 = 0;
	while (idx1 < idx)
	{
		if (mystrdup1(map[idx1], &fake_map[idx1]))
		{
			*flag = idx1;
			*flag1 = 1;
			return (fake_map);
		}
		else
			*flag = *flag + 1;
		idx1 ++;
	}
	fake_map[idx1] = NULL;
	return (fake_map);
}

int	free_fake_map(char ***fake_map, int idx1)
{
	int	idx;

	idx = 0;
	while (idx < idx1)
	{
		free((*fake_map)[idx]);
		idx ++;
	}
	free(*fake_map);
	return (1);
}
