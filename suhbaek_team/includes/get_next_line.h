/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:13 by seungjki          #+#    #+#             */
/*   Updated: 2023/11/05 22:35:38 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct s_gnl
{
	char	*str;
	char	buff[101];
	int		endl;
	int		size;
	char	*ret;
}	t_gnl;

int		ft_strlen(char *str);
int		indexof(char *str, char c);
char	*get_next_line(int fd, int *idx);

#endif
