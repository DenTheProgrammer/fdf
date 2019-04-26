/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:15:00 by ashari            #+#    #+#             */
/*   Updated: 2019/04/26 20:21:30 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include <math.h>

int			put_coordinate(char **map_rd, int start_x, int start_y, t_fdf *map)
{
	int		x;
	int		y;

	start_x = 250;
	start_y = 250;
	while (map_rd[y])
	{
		x = 0;
		while (map_rd[x] )
		{
			map->x1 = (x + y) * cos(30);
			map->y1 = (x - y) * cos(30) - map_rd[y][x];
			map->x2 = (++x + y) * cos(30);
			map->y2 = (x - y) * cos(30) - map_rd[y][x];
			mlx_hook(map->win_ptr, 2, 0, ft_brezen, (void *)map);
		}
		y++;
	}
}
