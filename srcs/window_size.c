/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:55:19 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 17:20:09 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int		max_min_z(t_window *w)
{
	int		x;
	int		y;
	int		wight;
	int		z_max;
	int		z_min;

	z_max = w->map[0][0].z;
	z_min = w->map[0][0].z;
	y = w->map_sizey;
	wight = w->map_sizex;
	while (--y >= 0)
	{
		x = wight;
		while (--x >= 0)
		{
			if (w->map[y][x].z > z_max)
				z_max = w->map[y][x].z;
			if (w->map[y][x].z < z_min)
				z_min = w->map[y][x].z;
		}
	}
	return ((abs(z_max) + abs(z_min)));
}

void	window_size(t_window *w)
{
	int		x;
	int		y;
	int		wight;

	y = w->map_sizey;
	wight = w->map_sizex;
	w->wight = 0;
	w->hight = 10;
	while (y)
	{
		x = wight;
		while (x--)
			w->wight++;
		y--;
		w->wight++;
	}
	w->hight += max_min_z(w) * 1.3;
	//w->img.bpp = 10;
	//w->img.size = w->wight * w->hight;
}
