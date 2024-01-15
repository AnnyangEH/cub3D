/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:51:37 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/15 14:53:51 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	sep_count(t_game *game, char *line, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	if (count != 2)
		ft_free("Error\nInvalid color type\n", game, -1);
}
