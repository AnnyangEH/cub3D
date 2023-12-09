#include "../inc/cub3D.h"

void	ft_error_exit(char *str, int error)
{
	perror(str);
	exit(error);
}
