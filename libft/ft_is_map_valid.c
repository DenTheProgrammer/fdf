/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:55:25 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 12:07:45 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_is_map_valid(char *buff, int res1)
{
	int			i;
	int			res;
	int			count;

	i = -1;
	count = 0;
	while (buff[++i])
	{
		if ((buff[i] == '.' || buff[i] == '#')
		|| (buff[i] == '\n' && (i % 10 == 9 || i % 10 == 4 || i == 20)))
		{
			if (buff[i] == '#')
			{
				if (count == 0)
					res = i;
				count++;
			}
		}
		else
			return (-1);
	}
	if (count != 4 || i != res1)
		return (-1);
	return (res);
}
