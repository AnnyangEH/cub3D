/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:15:39 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/10 20:19:54 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (FALSE);
		s++;
	}
	return (TRUE);
}

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*ptr++ = (unsigned char)c;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
