/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:38:56 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 15:51:22 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_map(t_window *w)
{
	int		x;
	int		y;

	y = 0;
	w->crd.x1 = w->crd.start_x;
	w->crd.x2 = w->crd.start_x;
	w->crd.y1 = w->crd.start_y;
	w->crd.y2 = w->crd.start_y;
	while (y < w->map_sizey)
	{
		x = 0;
		while (x < w->map_sizex)
		{
			w->crd.x1 = (w->map[y][x].x + w->map[y][x].y) * cos(0.523599);
			w->crd.y1 = (w->map[y][x].x - w->map[y][x].y) * cos(0.523599)
			- w->map[y][x].z;
			w->crd.x2 = (w->map[y][x + 1].x + w->map[y][x + 1].y)
			* cos(0.523599);
			w->crd.y2 = (w->map[y][x + 1].x - w->map[y][x + 1].y)
			* cos(0.523599) - w->map[y][x + 1].z;
			ft_brezen(w);
			x++;
		}
		y++;
	}
}


