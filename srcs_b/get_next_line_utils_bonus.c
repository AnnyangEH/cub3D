/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:10:01 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 18:13:38 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

ssize_t	ft_strchrindex(char *s, int c)
{
	char	temp;
	int		i;

	temp = (char)c;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == temp)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		*temp = 0;
		i++;
		temp++;
	}
}

void	*ft_gnlfree_all(t_fdlist *firlist, char *str_rtn)
{
	t_fdlist	*templist;
	t_buffer	*temp;

	while (firlist->next)
	{
		templist = firlist->next;
		firlist->next = templist->next;
		while (templist->buflist)
		{
			temp = templist->buflist;
			templist->buflist = temp->next;
			free (temp);
		}
		free(templist);
	}
	return (str_rtn);
}

void	*ft_gnlfree_use(t_fdlist *firlist, t_fdlist *uselist, char *str_rtn)
{
	t_fdlist	*templist;
	t_buffer	*temp;

	while (uselist->buflist)
	{
		temp = uselist->buflist;
		uselist->buflist = temp->next;
		free(temp);
	}
	templist = firlist;
	while (templist->next != uselist)
		templist = templist->next;
	templist->next = uselist->next;
	free(uselist);
	return (str_rtn);
}