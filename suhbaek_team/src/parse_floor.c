/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:33:53 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_char_floor(t_map_config u_c, t_parsed_config *c, int *flag, int idx)
{
	if (u_c.floor[idx] != ' ' && u_c.floor[idx] != '\n' && \
		(u_c.floor[idx] < '0' || u_c.floor[idx] > '9') && \
		u_c.floor[idx] != ',')
		return (1);
	if (c->floor[0] == -1 && u_c.floor[idx] == ',')
		return (1);
	else if (u_c.floor[idx] == ',' && *flag == 1)
		return (1);
	else if (u_c.floor[idx] == ',' && *flag == 0)
		*flag = 1;
	return (0);
}

int	check_floor(t_map_config u_c, t_parsed_config *config)
{
	int	idx;
	int	idx1;
	int	flag;

	idx = 2;
	idx1 = 0;
	flag = 0;
	while (idx1 < 3 && u_c.floor[idx])
	{
		if (check_char_floor(u_c, config, &flag, idx))
			return (1);
		if (u_c.floor[idx] >= '0' && u_c.floor[idx] <= '9')
		{
			flag = 0;
			config->floor[idx1] = nbr_put_in(u_c.floor + idx);
			if (config->floor[idx1] < 0)
				return (1);
			while (u_c.floor[idx] >= '0' && u_c.floor[idx] <= '9')
				idx ++;
			idx --;
			idx1 ++;
		}
		idx ++;
	}
	return (check_str_rest(u_c.floor, idx));
}
