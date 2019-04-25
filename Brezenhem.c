/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brezenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:39:58 by ashari            #+#    #+#             */
/*   Updated: 2019/04/25 12:03:22 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct algor
{
    int         x1;
    int         x2;
    int         y1;
    int         y2;
    void        *mlx_ptr;
    void        *win_ptr;
    struct  algor  *next;
}               t_list;

int     ft_abs(int n)
{
    if (n < 0)
        return (n * (-1));
    return (n);
}

void        ft_brezen(t_list *map)
{
    int     f;
    int     x;
    int     y;
    int     sign_a;
    int     sign_b;

    if ((map->y2 - map->y1) < 0)
        sign_a = -1;
    else
        sign_a = 0;
    if ((map->x1 - map->x2) < 0)
        sign_b = -1;
    else
        sign_b = 0;
    f = 0;
    x = map->x1;
    y = map->y1;
    mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
    if (ft_abs(map->y2 - map->y1) < ft_abs(map->x1 - map->x2))
        while (x != map->x2 || y != map->y2)
        {
            if ((f = f + (map->y2 - map->y1) * sign_a) > 0)
            {
                f = f - (map->x1 - map->x2) * sign_b;
                y += sign_a;
            }
            x = x - sign_b;
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
        }
    else
        while (x != map->x2 || y != map->y2)
        {
            if ((f = f + (map->y2 - map->y1) * sign_a) > 0)
            {
                f = f - (map->y2 - map->y1) * sign_a;
                x -= sign_b;
            }
            y += sign_a;
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
        }   
}