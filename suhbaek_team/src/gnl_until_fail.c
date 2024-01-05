/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_until_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhbaek <suhbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:35:19 by seungjki          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:45 by suhbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fd_returner(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nOpen() has failed\n", 25);
		return (fd);
	}
	return (fd);
}

int	check_line_numb(int *fd, int *idx1, char *argv)
{
	int		idx;
	char	*str;

	idx = 0;
	while (1)
	{
		str = get_next_line(*fd, idx1);
		if (*idx1 == -1)
			return (0);
		if (str == NULL)
			break ;
		free(str);
		idx ++;
	}
	*fd = fd_returner(argv);
	if (*fd == -1)
		return (0);
	return (idx);
}

char	**gnl_until_you_fail(char *argv)
{
	int		line_numb;
	int		fd;
	int		idx1;
	char	**answer;

	fd = fd_returner(argv);
	if (fd == -1)
		return (NULL);
	line_numb = check_line_numb(&fd, &idx1, argv);
	if (line_numb == 0)
		return (NULL);
	answer = malloc(sizeof(char *) * (line_numb + 1));
	if (answer == NULL)
		return (NULL);
	idx1 = 0;
	while (idx1 < line_numb)
	{
		answer[idx1] = get_next_line(fd, 0);
		if (answer[idx1] == NULL)
			return (free_all0(answer, idx1));
		idx1 ++;
	}
	answer[idx1] = NULL;
	return (answer);
}
