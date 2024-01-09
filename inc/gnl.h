/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:48:45 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/07 22:18:30 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_info {
	char	*buf;
	char	*save;
	char	*line;
	char	*ret;
	int		fd;
	int		idx;
}				t_info;

char	*get_next_line(int fd);

#endif