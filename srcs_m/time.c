#include "../inc/cub3D.h"

long long	get_time(void)
{
	struct timeval	time;
	long long	curr_time;

	gettimeofday(&time, NULL);
	curr_time = (time.tv_sec * 1000) + time.tv_usec / 1000;
	return (curr_time);
}
