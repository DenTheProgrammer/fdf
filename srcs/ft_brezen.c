/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:21:42 by ashari            #+#    #+#             */
/*   Updated: 2019/04/27 23:16:41 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
*	Алгоритм, который рисует линии (x1 y1 x2 y2)
*	Есть проблема с прямой линией (fix_needed)
*/

static int		ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

static void		build_the_line_01(int x, int y, t_window *w)
{
	int			sign_a;
	int			sign_b;
	int			f;

	f = 0;
	sign_a = ((w->y2 - w->y1) < 0) ? -1 : 1;
	sign_b = ((w->x1 - w->x2) < 0) ? -1 : 1;
	while (x != w->x2 && y != w->y2)
	{
		if ((f = f + (w->x1 - w->x2) * sign_b) > 0)
		{
			f = f - (w->y2 - w->y1) * sign_a;
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
	sign_a = ((w->y2 - w->y1) < 0) ? -1 : 1;
	sign_b = ((w->x1 - w->x2) < 0) ? -1 : 1;
	while (x != w->x2 && y != w->y2)
	{
		if ((f = f + (w->y2 - w->y1) * sign_a) > 0)
		{
			f = f - (w->x1 - w->x2) * sign_b;
			y += sign_a;
		}
		x = x - sign_b;
		w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
	}
}

int				ft_brezen(t_window *w)
{
	int			x;
	int			y;

	x = w->x1;
	y = w->y1;
	w->img.data[x * 4 + 4 * w->wight * y] = 0xFFFFFF;
	if (ft_abs(w->y2 - w->y1) < ft_abs(w->x1 - w->x2))
		build_the_line_00(x, y, w);
	else
		build_the_line_01(x, y, w);
	return (0);
}
