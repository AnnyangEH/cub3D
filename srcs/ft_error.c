#include "../inc/cub3D.h"

void	ft_error_exit(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	if (game)
		free(game);
	exit(FAILURE);
}

void	ft_error(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	free_game(game);
	exit(FAILURE);
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	if (game->map->line)
		free(game->map->line);
	if (game->map->path)
		free(game->map->path);
	if (game->map->width)
		free(game->map->width);
	if (game->token->addr)
	{
		while (++i < 4)
			if (game->token[i].addr)
				free(game->token[i].addr);
	}
	if (game->map->map)
	{
		i = -1;
		while (++i < game->map->height)
			if (game->map->map[i])
				free(game->map->map[i]);
		free(game->map->map);
	}
	if (game->map)
		free(game->map);
	if (game)
		free(game);
	// if (game->img.img)
	// 	mlx_destroy_image(game->mlx, game->img.img);
	// if (game->win)
	// 	mlx_destroy_window(game->mlx, game->win);
	// if (game->mlx)
	// 	free(game->mlx); 
}
