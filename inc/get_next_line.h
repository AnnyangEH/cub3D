/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:48:45 by eunhcho           #+#    #+#             */
/*   Updated: 2023/12/01 20:53:07 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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