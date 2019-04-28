/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:10:12 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 18:04:50 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

//static int		max_z(t_dot **p, int x, int y)
//{
//	int		x_iter;
//	int		y_iter;
//	int		z_max;
//
//	z_max = p[0][0].z;
//	y_iter = 0;
//	while (y_iter < y)
//	{
//		x_iter = 0;
//		while (x_iter < x)
//		{
//			if (p[y_iter][x_iter].z > z_max)
//				z_max = p[y_iter][x_iter].z;
//			x_iter++;
//		}
//		y_iter++;
//	}
//	return (z_max);
//}

void			start_coordinate(t_window *w)
{
	w->crd.start_x = w->wight / 2;
	// w->crd.start_y = max_z(w->map, w->map_sizex, w->map_sizey);
	// w->crd.start_y += w->crd.start_y * 0.3;
	w->crd.start_y = w->hight / 2;
}
