#include "../inc/cub3D.h"

int	ft_error(int error)
{
	if (error == USAGE_ERROR)
		perror("Error\nInvalid argument count.");
	else if (error == OPEN_ERROR)
		perror("Error\nFailed to open the file");
	else if (error == READ_ERROR)
		perror("Error\nFailed to read the map from the file.");
	else if (error == CLOSE_ERROR)
		perror("Error\nFailed to close the file descriptor.");
	else if (error == MALLOC_ERROR)
		perror("Error\nFailed to allocate memory.");
	else if (error == MAP_ERROR)
		perror("Error\nInvalid map.");
	else if (error == FORMAT_ERROR)
		perror("Error\nInvalid file format.");
	else if (error == RESOLUTION_ERROR)
		perror("Error\nInvalid resolution.");
	else if (error == TEXTURE_ERROR)
		perror("Error\nInvalid texture.");
	else if (error == COLOR_ERROR)
		perror("Error\nInvalid color.");
	return (error);
}
