/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:03:46 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/12 17:08:21 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		curr_time;

	gettimeofday(&time, NULL);
	curr_time = (time.tv_sec * 1000) + time.tv_usec / 1000;
	return (curr_time);
}
