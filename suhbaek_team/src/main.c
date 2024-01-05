/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:03:37 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/05 13:59:12 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_argument(int argc, char **argv, t_map_config *map_config)
{
	char	**cub3d_map_config;

	if (argc != 2 || arg_name_check(argv[1]) == 0)
	{
		write(2, "Error\nArgument(s) is not valid\n", 32);
		return (1);
	}
	cub3d_map_config = gnl_until_you_fail(argv[1]);
	if (cub3d_map_config == NULL)
	{
		write(2, "Error\nGnl_until_you_fail has reallllly failed\n", 47);
		return (1);
	}
	*map_config = argument_checker(cub3d_map_config);
	free_all1(&cub3d_map_config);
	if (map_config->north == NULL)
	{
		write(2, "Error\nArgument(s) config is not valid\n", 39);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map_config	map_config;
	t_parsed_config	config;
	t_img			img;
	t_mlx			mlx;

	if (check_argument(argc, argv, &map_config))
		return (1);
	config = map_checker(map_config);
	free_all(map_config);
	free_map(&map_config);
	if (config.north == NULL)
	{
		write(2, "Error\nMap is not valid\n", 24);
		return (1);
	}	
	init_start(&config);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "cub3d");
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(mlx.img, &img.bpp, &img.line, &img.endian);
	draw_start(&config, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
