/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysung <hysung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:11:44 by hysung            #+#    #+#             */
/*   Updated: 2022/12/24 00:30:53 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;
	size_t			i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	dtemp = (unsigned char *)dst;
	stemp = (unsigned char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			dtemp[i] = stemp[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dtemp[len] = stemp[len];
	}
	return (dtemp);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
	}
	return (0);
}

void	*ft_realloc(char *s, unsigned int size)
{
	char				*news;
	unsigned int		i;

	i = 0;
	news = (char *)malloc(size);
	if (!news)
	{
		free(s);
		return (0);
	}
	news = ft_memmove(news, s, size - BUFFER_SIZE);
	free(s);
	return (news);
}
