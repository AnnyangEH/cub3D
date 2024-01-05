/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map_validity_turn_element.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:33:52 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	all_the_conditions(char **map, int idx, int idx1, char start_char)
{
	if (idx1 == 0)
		return (1);
	if (idx1 > 0)
		if (map[idx][idx1 - 1] == ' ')
			return (1);
	if (map[idx][idx1 + 1] == '\n' || map[idx][idx1 + 1] == ' '\
		|| map[idx][idx1 + 1] == '\0')
		return (1);
	if (map[idx + 1] == NULL)
		return (1);
	if (map[idx + 1][idx1] != '1' && map[idx + 1][idx1] != start_char)
		return (1);
	if (idx == 0)
		return (1);
	if (idx > 0)
		if (map[idx - 1][idx1] != '1' && map[idx - 1][idx1] != start_char)
			return (1);
	return (0);
}

int	check_maps_validity(char ***map, t_parsed_config *config)
{
	int	idx;
	int	idx1;
	int	limit_down;

	idx = 0;
	limit_down = 0;
	while ((*map)[limit_down])
		limit_down ++;
	while ((*map)[idx])
	{
		idx1 = 0;
		while ((*map)[idx][idx1])
		{
			if ((*map)[idx][idx1] == config->start_char)
			{
				if (all_the_conditions(*map, idx, idx1, config->start_char))
					return (free_fake_map(map, limit_down));
			}
			idx1 ++;
		}
		idx ++;
	}
	free_fake_map(map, limit_down);
	return (0);
}

int	flood_fill(char **map, char start_char, int idx, int idx1)
{
	if (map[idx][idx1] == start_char)
		return (0);
	if (map[idx + 1] != NULL)
		if (start_char == map[idx + 1][idx1])
			map[idx][idx1] = start_char;
	if (idx > 0)
		if (start_char == map[idx - 1][idx1])
			map[idx][idx1] = start_char;
	if (map[idx][idx1 + 1] != '\n' && map[idx][idx1 + 1] != '\0')
		if (map[idx][idx1 + 1] == start_char)
			map[idx][idx1] = start_char;
	if (idx1 > 0)
		if (map[idx][idx1 - 1] == start_char)
			map[idx][idx1] = start_char;
	if (map[idx][idx1] == start_char)
		return (1);
	else
		return (0);
}

void	turn_element_of_fake_map(char start_char, char **fake_map)
{
	int	idx;
	int	idx1;
	int	flag;

	while (1)
	{
		idx = 0;
		flag = 0;
		while (fake_map[idx])
		{
			idx1 = 0;
			while (fake_map[idx][idx1])
			{
				if (fake_map[idx][idx1] == '0')
					flag = flag + flood_fill(fake_map, start_char, idx, idx1);
				idx1 ++;
			}
			idx ++;
		}
		if (flag == 0)
			return ;
	}
}
