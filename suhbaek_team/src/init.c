/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:07:34 by apple             #+#    #+#             */
/*   Updated: 2024/01/05 14:06:31 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_dir(t_player_config *player)
{
	if (player->state == 'N' || player->state == 'S')
	{
		player->dir_y = 0;
		player->plane_x = 0;
		if (player->state == 'N')
		{
			player->dir_x = -1;
			player->plane_y = 0.66;
		}
		else
		{
			player->dir_x = 1;
			player->plane_y = -0.66;
		}
	}
	else if (player->state == 'E' || player->state == 'W')
	{
		player->dir_x = 0;
		player->plane_y = 0;
		if (player->state == 'E')
		{
			player->dir_y = 1;
			player->plane_x = 0.66;
		}
		else
		{
			player->dir_y = -1;
			player->plane_x = -0.66;
		}
	}
}

void	init_map(t_parsed_config config)
{
	t_map	*map;

}
void	init_player(t_parsed_config config)
{
	t_player_config	*player;

	player = malloc (sizeof(t_player_config));
	player->state = config.start_char;
	player->pos_x = config.start[0];
	player->pos_y = config.start[1];
	init_dir(player);
}

void	init_start(t_parsed_config *config)
{
	init_player(*config);
	init_map(*config);
}
