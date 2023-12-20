#include "../inc/cub3D.h"

void	check_map(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width[i])
		{
			if (game->map->map[i][j] == '0')
			{
				if (i == 0 || i == game->map->height - 1 || j == 0 || j == game->map->width[i] - 1)
					ft_error("Error\nInvalid map\n", game);
				if (game->map->map[i - 1][j] == ' ' || game->map->map[i + 1][j] == ' ' || game->map->map[i][j - 1] == ' ' || game->map->map[i][j + 1] == ' ')
					ft_error("Error\nInvalid map\n", game);
			}
			else if (game->map->map[i][j] != ' ' && game->map->map[i][j] != '1')
				ft_error("Error\nInvalid map\n", game);
		}
	}
}