/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:25:28 by ashari            #+#    #+#             */
/*   Updated: 2019/04/26 15:44:08 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		fdf
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				color;
	int				size;
	void			*mlx_ptr;
	void			*win_ptr;
	struct fdf		*next;
}					t_fdf;

int				ft_brezen(int key, t_fdf *map);

#endif
