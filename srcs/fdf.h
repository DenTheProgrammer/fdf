/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:25:28 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 16:35:57 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
	int				size;
	int				*data;
	int				endian;
}					t_img;

typedef	struct		s_coord
{
	int				start_x;
	int				start_y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_coord;

typedef	struct		s_window
{
	int				map_sizex;
	int				map_sizey;
	int				wight;
	int				hight;
	void			*mlx_ptr;
	void			*win_ptr;
	t_dot			**map;
	t_img			img;
	t_coord			crd;
}					t_window;

int				ft_brezen(t_window *w);
int				ft_abs(int n);
void			window_size(t_window *w);
void			print_map(t_window *w);
void			start_coordinate(t_window *w);
t_dot**			read_map_from_file(char *filename, t_window *window);

#endif
