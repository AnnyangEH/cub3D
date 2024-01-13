/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:15:04 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/13 19:42:10 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (FAILURE);
	while (i < n && (s1[i] || s2[i]))
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	if (!s1)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	int		i;
	int		s_len;
	char	*new;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s) - start;
	if (s_len < len)
		len = s_len;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
