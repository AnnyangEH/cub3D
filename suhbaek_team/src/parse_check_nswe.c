/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_nswe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:54:24 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	word_check(char *str)
{
	int	idx;
	int	wc;
	int	flag;

	idx = 0;
	flag = 0;
	wc = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			break ;
		if (str[idx] != ' ' && flag == 0)
		{
			flag = 1;
			wc ++;
		}
		if (flag == 1 && str[idx] == ' ')
			flag = 0;
		idx ++;
	}
	return (wc);
}

int	give_path(char *str, char **config_str)
{
	int	idx;
	int	idx1;

	idx = 2;
	if (str[2] != ' ')
		return (1);
	while (str[idx] == ' ')
		idx ++;
	idx1 = 0;
	while (str[idx + idx1] != ' ' && str[idx + idx1] != '\n')
		idx1 ++;
	*config_str = malloc(sizeof(char) * (idx1 + 1));
	if (*config_str == NULL)
		return (1);
	idx1 = 0;
	while (str[idx + idx1] != ' ' && str[idx + idx1] != '\n')
	{
		(*config_str)[idx1] = str[idx + idx1];
		idx1 ++;
	}
	(*config_str)[idx1] = '\0';
	return (0);
}

int	check_nswe(t_map_config unparsed_config, t_parsed_config *config)
{
	if (word_check(unparsed_config.north) != 2 || \
		word_check(unparsed_config.south) != 2 || \
		word_check(unparsed_config.west) != 2 || \
		word_check(unparsed_config.east) != 2)
		return (1);
	if (give_path(unparsed_config.north, &config->north) || \
		give_path(unparsed_config.south, &config->south) || \
		give_path(unparsed_config.west, &config->west) || \
		give_path(unparsed_config.east, &config->east))
		return (1);
	return (0);
}
