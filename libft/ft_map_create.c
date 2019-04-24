/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:00:45 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/22 12:07:38 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_map_create(char *map, int coord, int h, int w)
{
	char	res;
	int		i_w;

	res = 0;
	while (h--)
	{
		i_w = w;
		while (i_w--)
			if (map[coord++] == '#')
				res = (res << 1) | 1;
			else
				res <<= 1;
		coord = coord + 5 - w;
	}
	return (res);
}
