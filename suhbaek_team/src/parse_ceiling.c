/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:28:19 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	nbr_put_in(char *str)
{
	int	idx;
	int	digit;
	int	answer;

	idx = 0;
	digit = 10;
	answer = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		if (idx == 3 || answer > 255)
			return (-1);
		answer = digit * answer + str[idx] - '0';
		idx ++;
	}
	return (answer);
}

int	check_char_ceiling(t_map_config u_c, t_parsed_config *c, int *flag, int idx)
{
	if (u_c.ceiling[idx] != ' ' && u_c.ceiling[idx] != '\n' && \
		(u_c.ceiling[idx] < '0' || u_c.ceiling[idx] > '9') && \
		u_c.ceiling[idx] != ',')
		return (1);
	if (c->ceiling[0] == -1 && u_c.ceiling[idx] == ',')
		return (1);
	else if (u_c.ceiling[idx] == ',' && *flag == 1)
		return (1);
	else if (u_c.ceiling[idx] == ',' && *flag == 0)
		*flag = 1;
	return (0);
}

int	check_str_rest(char *str, int idx)
{
	while (str[idx])
	{
		if (str[idx] != '\n' && str[idx] != ' ')
			return (1);
		idx ++;
	}
	return (0);
}

int	check_ceiling(t_map_config u_c, t_parsed_config *config)
{
	int	idx;
	int	idx1;
	int	flag;

	idx = 2;
	idx1 = 0;
	flag = 0;
	while (idx1 < 3 && u_c.ceiling[idx])
	{
		if (check_char_ceiling(u_c, config, &flag, idx))
			return (1);
		if (u_c.ceiling[idx] >= '0' && u_c.ceiling[idx] <= '9')
		{
			flag = 0;
			config->ceiling[idx1] = nbr_put_in(u_c.ceiling + idx);
			if (config->ceiling[idx1] < 0)
				return (1);
			while (u_c.ceiling[idx] >= '0' && u_c.ceiling[idx] <= '9')
				idx ++;
			idx --;
			idx1 ++;
		}
		idx ++;
	}
	return (check_str_rest(u_c.ceiling, idx));
}
