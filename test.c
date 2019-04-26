/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:40:42 by ashari            #+#    #+#             */
/*   Updated: 2019/04/26 22:47:34 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

static void		build_the_line_01(int x, int y, t_window *map)
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
					map->win_ptr, x, map->size - y, 0xFFFFFF);
	}
}

static void		build_the_line_00(int x, int y, t_window *map)
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
					map->win_ptr, x, map->size - y, 0xFFFFFF);
	}
}

int				ft_brezen(int key, t_window *map)
{
	int			x;
	int			y;

	x = map->x1;
	y = map->y1;
	if (key == 53)
		exit(EXIT_SUCCESS);
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, map->size - y, 0xFFFFFF);
	if (ft_abs(map->y2 - map->y1) < ft_abs(map->x1 - map->x2))
		build_the_line_00(x, y, map);
	else
		build_the_line_01(x, y, map);
	return (0);
}

int main()
{
	t_window *window = malloc(sizeof(t_window));

	window->size = 500;
	window->pix_size = 10;
	window->start_x = 250;
	window->start_y = 250;

	window->points = malloc(sizeof(t_dot*) * 4);

	int i = 0;
	while (i < 4)
		window->points[i++] = malloc(sizeof(t_dot));



	window->points[0]->x = 0;
	window->points[0]->y = 0;
	window->points[0]->z = 1 * window->pix_size;

	window->points[1]->x = 1 * window->pix_size;
	window->points[1]->y = 0;
	window->points[1]->z = 10 * window->pix_size;

	window->points[2]->x = 0;
	window->points[2]->y = 1 * window->pix_size;
	window->points[2]->z = 7 * window->pix_size;

	window->points[3]->x = 1 * window->pix_size;
	window->points[3]->y = 1 * window->pix_size;
	window->points[3]->z = 2 * window->pix_size;

	window->x1 = (window->points[0]->x + window->points[0]->y) * cos(0.523599) + window->size;
	window->y1 = (window->points[0]->x - window->points[0]->y) * cos(0.523599) - window->points[0]->z + window->size;
	window->x1 = (window->points[1]->x + window->points[1]->y) * cos(0.523599) + window->size;
	window->y1 = (window->points[1]->x - window->points[1]->y) * cos(0.523599) - window->points[1]->z + window->size;

	if (!(window->mlx_ptr = (t_window *)malloc(sizeof(t_window))))
		return (0);
	if (!(window->mlx_ptr = mlx_init()))
		return (0);
	window->win_ptr = mlx_new_window(window->mlx_ptr,
	window->size, window->size, "Hello, Window!");
	mlx_hook(window->win_ptr, 2, 0, ft_brezen, (void *)window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
