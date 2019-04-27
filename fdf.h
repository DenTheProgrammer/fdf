/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:25:28 by ashari            #+#    #+#             */
/*   Updated: 2019/04/27 23:16:44 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef	struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot;

typedef	struct		s_image
{
	void			*img_ptr;
	int				bpp;
	int				*data;
	int				endian;
}					t_img;

typedef	struct		s_window
{
	int				wight;
	int				start_x;
	int				start_y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_dot			**p;
	t_img			img;
}					t_window;

int				ft_brezen(t_window *w);

#endif
