/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:43:08 by ashari            #+#    #+#             */
/*   Updated: 2019/04/26 21:35:05 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define X1 100
#define Y1 170

#define X2 50
#define Y2 160

int			main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	x1 = (X1 + Y1) * cos(0.523599) + 250;
	y1 = (X1 - Y1) * sin(0.523599) - 0 + 250;
	x2 = (X2 + Y2) * cos(0.523599) + 250;
	y2 = (X2 - Y2) * sin(0.523599) - (150) + 250;
	if (!(mlx_ptr = mlx_init()))
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello");
	mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, X1, Y1, 0xFF00);
	mlx_pixel_put(mlx_ptr, win_ptr, X2, Y2, 0xFF00);
	mlx_loop(mlx_ptr);
	return (0);
}
