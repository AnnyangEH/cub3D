/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:38:19 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/05 14:59:59 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
#include "../mlx/mlx.h"

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_map_config
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	**map;
}	t_map_config;

typedef struct s_parsed_config
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	start_char;
	int		floor[3];
	int		ceiling[3];
	double 	start[2];
	int		size[2]; // not sure if I need this
	char	**map;
}	t_parsed_config;

typedef struct s_player_config
{
	char	state; // player state
	double	pos_x; // player x
	double	pos_y; // player y
	double	dir_x; // player direction x
	double	dir_y; // player direction y
	double	plane_x; // player plane x
	double	plane_y; // player plane y
}	t_player_config;

typedef struct s_img
{
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	t_img	*set;
	void	*img;
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	
	char	**map;
}	t_map;


int				arg_name_check(char *str);

int				check_nbr_one(char *str);
int				mystrdup(const char *s1, char **s2);
int				mystrdup1(const char *s1, char **s2);
int				strdup_until_you_fail(t_map_config *map_config, char **map);
int				check_nswe(t_map_config unparsed_config, \
				t_parsed_config *config);
int				free_map(t_map_config *map_config);
int				check_ceiling(t_map_config unparsed_config, \
				t_parsed_config *config);
int				check_floor(t_map_config unparsed_config, \
				t_parsed_config *config);
int				nbr_put_in(char *str);
int				check_str_rest(char *str, int idx);
int				check_the_map_char(char **map, t_parsed_config *config);
int				check_the_map_spaces(char **map);
int				space_only(char *map_line);
int				free_fake_map(char ***fake_map, int idx1);
int				give_clean_map(char **map, t_parsed_config *config);
int				check_maps_validity(char ***map, t_parsed_config *config);

char			**gnl_until_you_fail(char *argv);
char			**free_all0(char **answer, int idx1);
char			**make_fake_map(char **map, int *flag, int *flag1);

void			mymemset(t_map_config *map_config);
void			free_all1(char ***str);
void			free_all_config(t_parsed_config *config);
void			turn_element_of_fake_map(char start_char, char **fake_map);
void			turn_element_of_fake_map(char start_char, char **fake_map);


t_map_config	free_all(t_map_config map_config);
t_map_config	argument_checker(char **cub3d_map_config);
t_parsed_config	map_checker(t_map_config unparsed_config);

void		init_start(t_parsed_config *config);
void	print(char **str);

#endif
