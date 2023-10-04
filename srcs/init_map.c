#include "../inc/cub3D.h"

int		init_game(t_game *game, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (OPEN_ERROR);
	while (get_next_line(fd, &line))
	{
		free(line);
	}
	free(line);
	if (close(fd) < 0)
		return (CLOSE_ERROR);
	return (0);
}
