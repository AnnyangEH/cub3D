/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hysung <hysung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:11:04 by hysung            #+#    #+#             */
/*   Updated: 2022/12/27 18:15:12 by hysung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, t_mem *info)
{
	char	*have_n;

	have_n = ft_memchr(info->buff, '\n', info->size);
	while (!have_n && info->rd > 0)
	{
		info->buff = ft_realloc(info->buff, info->size + BUFFER_SIZE);
		if (!info->buff)
			return (0);
		info->rd = read(fd, &info->buff[info->size], BUFFER_SIZE);
		if (info->rd > 0)
			have_n = ft_memchr(&info->buff[info->size], '\n', info->rd);
		info->size += info->rd;
	}
	return (have_n);
}

static char	*free_set(t_mem *info)
{
	free(info->buff);
	info->buff = 0;
	return (0);
}

static char	*cut_line(t_mem *info, char *have_n)
{
	int		ct;
	char	*line;

	if (!have_n)
		return (free_set(info));
	ct = have_n - info->buff + 1;
	line = (char *)malloc(ct + 1);
	if (!line)
		return (free_set(info));
	line = ft_memmove(line, info->buff, ct);
	line[ct] = 0;
	if (info->size - ct > 0)
		info->buff = ft_memmove(info->buff, have_n + 1, info->size - ct);
	else
		free_set(info);
	info->size -= ct;
	return (line);
}

static void	first_read(int fd, t_mem *info)
{
	info->buff = (char *)malloc(BUFFER_SIZE);
	info->rd = read(fd, info->buff, BUFFER_SIZE);
	if (info->rd <= 0)
	{
		if (info->buff)
			free_set(info);
		return ;
	}
	info->size = info->rd;
}

char	*get_next_line(int fd)
{
	static t_mem	info;
	char			*have_n;

	if (!info.buff)
		first_read(fd, &info);
	if (info.rd <= 0)
	{
		info.buff = 0;
		return (0);
	}
	have_n = read_line(fd, &info);
	if (!have_n && !info.rd)
	{
		info.buff[info.size] = 0;
		return (info.buff);
	}
	return (cut_line(&info, have_n));
}
