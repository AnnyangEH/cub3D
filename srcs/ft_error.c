#include "../inc/cub3D.h"

int	ft_error(int error)
{
	if (error == USAGE_ERROR)
		ft_putstr_fd("Error\nInvalid argument count.", 2);
	else if (error == OPEN_ERROR)
		ft_putstr_fd("Error\nFailed to open the file", 2);
	else if (error == READ_ERROR)
		ft_putstr_fd("Error\nFailed to read the map from the file.", 2);
	else if (error == CLOSE_ERROR)
		ft_putstr_fd("Error\nFailed to close the file descriptor.", 2);
	else if (error == MALLOC_ERROR)
		ft_putstr_fd("Error\nFailed to allocate memory.", 2);
	else if (error == MAP_ERROR)
		ft_putstr_fd("Error\nInvalid map characters.", 2);
	else if (error == FORMAT_ERROR)
		ft_putstr_fd("Error\nInvalid file format.", 2);
	else if (error == RESOLUTION_ERROR)
		ft_putstr_fd("Error\nInvalid resolution.", 2);
	else if (error == TEXTURE_ERROR)
		ft_putstr_fd("Error\nInvalid texture.", 2);
	else if (error == COLOR_ERROR)
		ft_putstr_fd("Error\nInvalid color.", 2);
	else if (error == EXTENSION_ERROR)
		ft_putstr_fd("Error\nInvalid file extension.", 2);
	return (error);
}
