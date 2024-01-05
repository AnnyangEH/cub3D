/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:33:52 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/05 13:58:57 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map_and_give_map(t_map_config u_c, t_parsed_config *c)
{
	char	**fake_map;
	int		flag;
	int		flag1;

	flag = 0;
	flag1 = 0;
	if (check_the_map_char(u_c.map, c))
		return (1);
	if (give_clean_map(u_c.map, c))
		return (1);
	if (check_the_map_spaces(c->map))
		return (1);
	fake_map = make_fake_map(c->map, &flag, &flag1);
	if (flag1 == 1)
		return (free_fake_map(&fake_map, flag));
	else if (fake_map != NULL && flag == 0)
	{
		free(fake_map);
		return (1);
	}
	turn_element_of_fake_map(c->start_char, fake_map);
	if (check_maps_validity(&fake_map, c))
		return (1);
	return (0);
}

void	initialize(t_parsed_config *config)
{
	config->north = NULL;
	config->south = NULL;
	config->west = NULL;
	config->east = NULL;
	config->floor[0] = -1;
	config->ceiling[0] = -1;
	config->map = NULL;
	config->start_char = 0;
	config->start[0] = 0;
	config->start[1] = 0;
}

t_game	map_checker(t_map_config unparsed_config)
{
	t_game	game;

	initialize(&game.config);
	if (check_nswe(unparsed_config, &config))
	{
		free_all_config(&config);
		return (config);
	}
	if (check_floor(unparsed_config, &config) \
		|| check_ceiling(unparsed_config, &config))
	{
		free_all_config(&config);
		return (config);
	}
	if (check_map_and_give_map(unparsed_config, &config))
	{
		free_all_config(&config);
		return (config);
	}
	return (game.config);
}
