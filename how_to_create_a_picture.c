/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_create_a_picture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:02:55 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 17:39:15 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

/*
*	Это прикольные карты (скидывала скрины)
*/

int			main()
{
	int		size_line;
	int		bpp;
	int		x;
	int		y;
	int		endian;
	int		*new;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;

	size_line = 3200;
	bpp = 32;
	x = 0;
	y = 0;
	int color = 0x0000FF;
	if (!(mlx_ptr = mlx_init()))
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Eaaaasy");
	// img_ptr = mlx_new_image(mlx_ptr, 800, 600);
	// new = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	// while (y < 60)
	// {
	// 	x = 0;
	// 	while (x < 80)
	// 	{
	// 		color += 100;
	// 		if (x % 4 == 2)
	// 			new[y + (int)sqrt(x)] = color;
	// 		else
	// 			new[(int)sqrt(y * 800 + x * y)] = color + 10000000;
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
