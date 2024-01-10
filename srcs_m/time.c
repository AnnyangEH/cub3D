/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysung <hysung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:28:47 by hysung            #+#    #+#             */
/*   Updated: 2024/01/10 21:29:28 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		curr_time;

	gettimeofday(&time, NULL);
	curr_time = (time.tv_sec * 1000) + time.tv_usec / 1000;
	return (curr_time);
}
