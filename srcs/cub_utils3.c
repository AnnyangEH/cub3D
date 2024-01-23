/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:20:08 by eunhcho           #+#    #+#             */
/*   Updated: 2024/01/23 15:30:01 by eunhcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_isint(long long n)
{
	return (n >= -2147483648 && n <= 2147483647);
}

int	ft_catoi(const char *str)
{
	long long	next;
	long long	temp;
	int			sign;

	sign = 1;
	temp = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		next = temp * 10 + sign * (*str - '0');
		if (!ft_isint(next))
			return (-1);
		temp = next;
		str++;
	}
	if (*str && (*str != '\n' && ft_isdigit(*str) == FALSE))
		return (-1);
	return ((int)temp);
}

int	ft_isempty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_iswhitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new)
		return (0);
	new[s1_len + s2_len] = 0;
	while (s2_len--)
		new[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		new[s1_len] = s1[s1_len];
	return (new);
}
