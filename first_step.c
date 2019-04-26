/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:02:37 by ashari            #+#    #+#             */
/*   Updated: 2019/04/25 19:51:57 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct first_step
{
    void                *mlx_ptr;
    void                *win_ptr;
    struct  first_step  *next;
}               t_list;


void      ft_putchar(char c)
{
    write(1, &c, 1);
}

int     deal_key(int key, t_list *window)
{
    int     x;
    int     y;

    x = 499;
    y = 200;
    if (key == 53)
        exit (EXIT_SUCCESS);
    
    return (0);
}

int     main()
{
    t_list  *window;
    int     x;
    int     y;

    x = 250;
    y = 400;
    if (!(window = (t_list *)malloc(sizeof(t_list))))
        return (0);
    window->next = NULL;
    if (!(window->mlx_ptr = mlx_init()))
        return (0);
    window->win_ptr = mlx_new_window(window->mlx_ptr, 500, 500, "Hello, Window!");
    while (x > 100)
    {
        mlx_pixel_put(window->mlx_ptr, window->win_ptr, x, y, 0xFFFFFF);
        x -= 10;
    }
    mlx_hook(window->win_ptr, 2, 0,  deal_key, (void *)window);
    mlx_loop(window->mlx_ptr); //бесконечный цикл ожидающий нажатия
    return (0);
}
