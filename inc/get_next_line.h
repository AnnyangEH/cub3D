/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:07:50 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 17:08:40 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buffer
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_fdlist
{
	t_buffer		*buflist;
	int				fdnumber;
	size_t			strlen;
	struct s_fdlist	*next;
}	t_fdlist;

ssize_t	ft_strchrindex(char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_gnlfree_all(t_fdlist *firlist, char *str_rtn);
void	*ft_gnlfree_use(t_fdlist *firlist, t_fdlist *uselist, char *str_rtn);
char	*get_next_line(int fd);

#endif