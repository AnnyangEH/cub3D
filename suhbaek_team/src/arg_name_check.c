/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_name_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:03:06 by seungjki          #+#    #+#             */
/*   Updated: 2023/11/09 05:14:25 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arg_name_check(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	if (idx < 5)
		return (0);
	if (str[idx - 4] != '.' || str[idx - 3] != 'c' || \
		str[idx - 2] != 'u' || str[idx - 1] != 'b')
		return (0);
	return (1);
}
