/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:10:12 by ashari            #+#    #+#             */
/*   Updated: 2019/04/27 23:16:36 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

/*
*	Тут старые структуры, да и вообще это нужно переписать
*/

int		find_max_z(t_window *window, int numb)
{
	int		max;

	max = window->points[numb]->z;
	while (--numb)
		if (dot[numb].z > max)
			max = dot[numb].z;
	return (max);
}

int		find_max_y(t_dot *dot, int numb)
{
	int		max;

	max = dot[numb].y;
	while (--numb)
		if (dot[numb].y > max)
			max = dot[numb].y;
	return (max);
}

void	start_coordinate(t_dot *dot, t_window *window)
{
	window->start_x = 250;
	window->start_y = 250;
}
