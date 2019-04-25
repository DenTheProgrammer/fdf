/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:21:42 by ashari            #+#    #+#             */
/*   Updated: 2019/04/25 17:47:02 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

static void		build_the_line_01(int x, int y, t_fdf *map)
{
	int			sign_a;
	int			sign_b;
	int			f;

	f = 0;
	sign_a = ((map->y2 - map->y1) < 0) ? -1 : 1;
	sign_b = ((map->x1 - map->x2) < 0) ? -1 : 1;
	while (x != map->x2 && y != map->y2)
	{
		if ((f = f + (map->x1 - map->x2) * sign_b) > 0)
		{
			f = f - (map->y2 - map->y1) * sign_a;
			x -= sign_b;
		}
		y += sign_a;
		mlx_pixel_put(map->mlx_ptr,
					map->win_ptr, x, map->win_size - y, map->color);
	}
}

static void		build_the_line_00(int x, int y, t_fdf *map)
{
	int			sign_a;
	int			sign_b;
	int			f;

	f = 0;
	sign_a = ((map->y2 - map->y1) < 0) ? -1 : 1;
	sign_b = ((map->x1 - map->x2) < 0) ? -1 : 1;
	while (x != map->x2 && y != map->y2)
	{
		if ((f = f + (map->y2 - map->y1) * sign_a) > 0)
		{
			f = f - (map->x1 - map->x2) * sign_b;
			y += sign_a;
		}
		x = x - sign_b;
		mlx_pixel_put(map->mlx_ptr,
					map->win_ptr, x, map->win_size - y, map->color);
	}
}

int				ft_brezen(t_fdf *map)
{
	int			x;
	int			y;

	x = map->x1;
	y = map->y1;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, map->win_size - y, map->color);
	if (ft_abs(map->y2 - map->y1) < ft_abs(map->x1 - map->x2))
		build_the_line_00(x, y, map);
	else
		build_the_line_01(x, y, map);
	return (0);
}