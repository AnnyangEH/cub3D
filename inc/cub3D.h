/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:06:23 by suhbaek           #+#    #+#             */
/*   Updated: 2024/01/16 15:32:00 by eunhcho          ###   ########.fr       */
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

int			ft_strlen(char *s);
int			ft_strncmp(char *s1, char *s2, int n);
int			ft_strchr(char *s, int c);
int			ft_iswhitespace(char c);
int			ft_isempty(char *line);
int			ft_isdigit(int c);
int			ft_catoi(const char *str);
int			press_key(int key, t_game *game);
int			exit_hook(t_game *game);
int			create_trgb(int t, int r, int g, int b);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, int len);
void		ft_memset(void *b, int c, size_t len);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_init(int ac, char **av, t_game *game);
void		init_ray(t_ray *ray, t_game *game, int x);
void		cal_step_and_sidedist(t_ray *ray, t_game *game);
void		perform_dda(t_ray *ray, t_game *game);
void		cal_perpwalldist(t_ray *ray, t_game *game);
void		cal_line_height(t_ray *ray);
void		parse(t_game *game);
void		parse_token(t_game *game);
void		parse_map(t_game *game);
void		free_split(char **split);
void		check_map(t_game *game);
void		close_win(t_game *game);
void		move_up_down(t_game *game, int key);
void		move_side(t_game *game, int key);
void		rotate(t_player *player, int direction);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);
long long	get_time(void);
int			exec(t_game *game);
void		set_nsew(t_game *game, t_ray *ray);
void		set_wall(t_game *game, t_ray *ray);
void		draw(t_game *game, t_ray *ray, int x, int y);
void		ft_free_exit(char *str);
void		ft_free(char *str, t_game *game, int i);
void		sep_count(t_game *game, char *line, char c);
void		get_img(t_game *game);
void		set_color(t_game *game);
void		init_mlx(t_game *game);
#endif
