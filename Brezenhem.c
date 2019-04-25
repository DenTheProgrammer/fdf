/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brezenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:39:58 by ashari            #+#    #+#             */
/*   Updated: 2019/04/25 17:09:00 by ashari           ###   ########.fr       */
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

static int     ft_abs(int n)
{
    if (n < 0)
        return (n * (-1));
    return (n);
}

static int        ft_brezen(int key, t_list *map)
{
    int     f;
    int     x;
    int     y;
    int     sign_a;
    int     sign_b;

    sign_a = ((map->y2 - map->y1) < 0) ? -1 : 1;
    sign_b = ((map->x1 - map->x2) < 0) ? -1 : 1;
    f = 0;
    x = map->x1;
    y = map->y1;
    if (key == 53)
        exit (EXIT_SUCCESS);
    mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
    if (ft_abs(map->y2 - map->y1) < ft_abs(map->x1 - map->x2))
        while (x != map->x2 && y != map->y2)
        {
            write (1, 'g', 1);
            if ((f = f + (map->y2 - map->y1) * sign_a) > 0)
            {
                f = f - (map->x1 - map->x2) * sign_b;
                y += sign_a; 
            }
            x = x - sign_b;
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
        }
    else
        while (x != map->x2 && y != map->y2)
        {
            write (1, 'a', 1);
            if ((f = f + (map->x1 - map->x2) * sign_b) > 0)
            {
                f = f - (map->y2 - map->y1) * sign_a;
                x -= sign_b;
            }
            y += sign_a;
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
        } 
    return (0);
}

int     main()
{
    t_list  *window;

    if (!(window = (t_list *)malloc(sizeof(t_list))))
        return (0);
    window->next = NULL;
    window->x1 = 1;
    window->x2 = 60;
    window->y1 = 1;
    window->y2 = 100;
    if (!(window->mlx_ptr = mlx_init()))
        return (0);
    window->win_ptr = mlx_new_window(window->mlx_ptr, 500, 500, "Hello, Window!");
    mlx_hook(window->win_ptr, 2, 0,  ft_brezen, (void *)window);
    mlx_loop(window->mlx_ptr);
    return (0);
}