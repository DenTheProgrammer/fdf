/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:21:42 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 17:14:26 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		build_the_line_01(int x, int y, t_window *w)
{
	int			sign_a;
	int			sign_b;
	int			f;

	f = 0;
	sign_a = ((w->crd.y2 - w->crd.y1) < 0) ? -1 : 1;
	sign_b = ((w->crd.x1 - w->crd.x2) < 0) ? -1 : 1;
	while (x != w->crd.x2 || y != w->crd.y2)
	{
		if ((f = f + (w->crd.x1 - w->crd.x2) * sign_b) > 0)
		{
			f = f - (w->crd.y2 - w->crd.y1) * sign_a;
			x -= sign_b;
		}
		y += sign_a;
		w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
	}
}

static void		build_the_line_00(int x, int y, t_window *w)
{
	int			sign_a;
	int			sign_b;
	int			f;

	f = 0;
	sign_a = ((w->crd.y2 - w->crd.y1) < 0) ? -1 : 1;
	sign_b = ((w->crd.x1 - w->crd.x2) < 0) ? -1 : 1;
	while (x != w->crd.x2 || y != w->crd.y2)
	{
		if ((f = f + (w->crd.y2 - w->crd.y1) * sign_a) > 0)
		{
			f = f - (w->crd.x1 - w->crd.x2) * sign_b;
			y += sign_a;
		}
		x = x - sign_b;
		w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
	}
}

static void		build_y_line(int x, int y, t_window *w)
{
	int			sign_y;

	sign_y = ((w->crd.y2 - w->crd.y1) < 0) ? 1 : -1;
	while (y != w->crd.y2)
	{
		w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
		y += sign_y;
	}
	w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
}

static void		build_x_line(int x, int y, t_window *w)
{
	int			sign_x;

	sign_x = ((w->crd.x2 - w->crd.x1) > 0) ? 1 : -1;
	while (x != w->crd.x2)
	{
		w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
		x += sign_x;
	}
	w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
}

int				ft_brezen(t_window *w)
{
	int			x;
	int			y;

	x = w->crd.x1;
	y = w->crd.y1;
	w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
	if (w->crd.x1 == w->crd.x2)
		build_y_line(x, y, w);
	else if (w->crd.y1 == w->crd.y2)
		build_x_line(x, y, w);
	if (ft_abs(w->crd.y2 - w->crd.y1) < ft_abs(w->crd.x1 - w->crd.x2))
		build_the_line_00(x, y, w);
	else
		build_the_line_01(x, y, w);
	return (0);
}
