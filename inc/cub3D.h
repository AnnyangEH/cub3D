/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:06:23 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/13 13:14:06 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "struct.h"
# include "gnl.h"
# include "../mlx/mlx.h"

# include "time.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include "math.h"
# include <sys/time.h>

int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, int len);
void	ft_memset(void *b, int c, size_t len);
int		ft_strchr(char *s, int c);
int		ft_iswhitespace(char c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_catoi(const char *str);
int		ft_isempty(char *line);
void	*ft_memcpy(void *dest, const void *src, size_t n);

//init functions
void	ft_init(int ac, char **av, t_game *game);
void	init_ray(t_ray *ray, t_game *game, int x);

//error handling function
void	ft_error(char *str, t_game *game);
void	ft_error_exit(char *str, t_game *game);
void	free_game_one(t_game *game);

void	cal_step_and_sidedist(t_ray *ray, t_game *game);
void	perform_dda(t_ray *ray, t_game *game);
void	cal_perpwalldist(t_ray *ray, t_game *game);
void	cal_line_height(t_ray *ray);

//parsing functions
void	parse(t_game *game);
void	parse_token(t_game *game);
void	parse_map(t_game *game);
void	free_split(char **split);

//checking functions
void	check_map(t_game *game);

//hook
int		press_key(int key, t_game *game);
void	set_hook(t_game *game);
void	close_win(t_game *game);
int		exit_hook(t_game *game);
void	move_up_down(t_game *game, int key);
void	move_side(t_game *game, int key);
void	rotate(t_player *player, int direction);

//mlx
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

//time
long long	get_time(void);

//exec
int		exec(t_game *game);
void	set_nsew(t_game *game, t_ray *ray);
void	set_wall(t_game *game, t_ray *ray);
void	draw(t_game *game, t_ray *ray, int x, int y);

#endif
