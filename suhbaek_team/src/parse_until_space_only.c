/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_until_space_only.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:09:05 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	conditions(char map_cha)
{
	if (map_cha != '\n' && map_cha != '1'\
		&& map_cha != '0' && map_cha != ' '\
		&& map_cha != 'N' && map_cha != 'S'\
		&& map_cha != 'E' && map_cha != 'E')
		return (1);
	return (0);
}

int	check_player_numb(int player_numb)
{
	if (player_numb == 1)
		return (0);
	return (1);
}

int	check_the_map_char(char **map, t_parsed_config *config)
{
	int	idx;
	int	idx1;
	int	count_player;

	idx = 0;
	count_player = 0;
	while (map[idx])
	{
		idx1 = 0;
		while (map[idx][idx1])
		{
			if (conditions(map[idx][idx1]))
				return (1);
			if (map[idx][idx1] == 'N' || map[idx][idx1] == 'S'\
				|| map[idx][idx1] == 'W' || map[idx][idx1] == 'E')
			{
				config->start_char = map[idx][idx1];
				config->start[0] = idx + 0.1;
				config->start[1] = idx1 + 0.1;
				count_player++;
			}
			idx1++;
		}
		idx++;
	}
	config->size[0] = idx;
	config->size[1] = idx1;
	return (check_player_numb(count_player));
}

int	check_the_map_spaces(char **map)
{
	int	idx;
	int	idx1;
	int	flag;

	idx = 0;
	while (map[idx])
	{
		flag = 0;
		idx1 = 0;
		while (map[idx][idx1])
		{
			if (map[idx][idx1] != ' ' && map[idx][idx1] != '\n')
				flag ++;
			idx1 ++;
		}
		if (flag == 0)
			return (1);
		idx ++;
	}
	return (0);
}

int	space_only(char *map_line)
{
	int	idx;

	idx = 0;
	while (map_line[idx])
	{
		if (map_line[idx] != '\n' && map_line[idx] != ' ')
			return (0);
		idx++;
	}
	return (1);
}
