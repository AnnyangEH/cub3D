#include "../inc/cub3D.h"

int	ft_error(int error, char *str)
{
	if (error == USAGE_ERROR)
		ft_putstr_fd("Error\nInvalid argument count.", 2);
	else if (error == OPEN_ERROR)
		ft_putstr_fd("Error\nFailed to open the file", 2);
	else if (error == READ_ERROR)
		ft_putstr_fd("Error\nFailed to read the map from the file.", 2);
	else if (error == CLOSE_ERROR)
		ft_putstr_fd("Error\nFailed to close the file descriptor.", 2);
	else if (error == EMPTY_ERROR)
		ft_putstr_fd("Error\nThis file empty", 2);
	else if (error == MAP_EX_ERROR)
		ft_putstr_fd("Error\nInvalid file extension.", 2);
	else
		exit(error);
}
