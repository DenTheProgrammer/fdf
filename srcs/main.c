/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:10:56 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 15:50:50 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int	cleaner(t_window *w)
{
	free(w);
	w = NULL;
	return (0);
}

int			main(int ac, char **av)
{
	t_window	*w;

	w = (t_window *)malloc(sizeof(t_window));
	if (!(w->mlx_ptr = mlx_init()))
		return (cleaner(w));
	w->map = read_map_from_file(av[1], w);
	window_size(w);
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->wight, w->hight, "FdF");
	w->img.img_ptr = mlx_new_image(w->mlx_ptr, w->wight, w->hight);
	w->img.data = (int *)mlx_get_data_addr(w->img.img_ptr, w->img.bpp,
	w->img.size, w->img.endian);
	print_map(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr,
	w->wight, w->hight);
	mlx_loop(w->mlx_ptr);
	return (0);
}
