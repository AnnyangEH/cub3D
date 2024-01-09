#include "../inc/cub3D.h"

void check_cell(t_game *game, int x, int y, char **map)
{
	while (y < game->map->height) // 모서리 검사
	{
		x = 0;
		while (x < game->map->width[y])
		{
			if (y == 0 || y == game->map->height - 1)
			{
				if (map[y][x] == '0')
					ft_error("Error\nInvalid map\n", game);
			}
			else if (x == 0 || x == game->map->width[y] - 1)
				if (map[y][x] == '0')
					ft_error("Error\nInvalid map\n", game);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < game->map->height) // 내부 0 상하좌우 검사
	{
		x = 0;
		while (x < game->map->width[y])
		{
			if (map[y][x] == '0')
			{
				if (y - 1 >= 0 && y + 1 <= game->map->height - 1 && x - 1 >= 0 && x + 1 <= game->map->width[y])
				{
					if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' ||
						map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
							ft_error("Error\nInvalid map\n", game);
				}
			}
			x++;
		}
		y++;
	}
}

void check_map(t_game *game)
{
	char	**map;

	map = game->map->map;
	check_cell(game, 0, 0, map);
}