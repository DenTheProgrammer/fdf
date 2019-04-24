/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:02:37 by ashari            #+#    #+#             */
/*   Updated: 2019/04/24 23:04:40 by ashari           ###   ########.fr       */
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
    if (key == 53)
        exit (EXIT_SUCCESS);
    if (key == 25)
        mlx_pixel_put(window->mlx_ptr, window->win_ptr, 250, 400, 0xFFFFFF);
    return (0);
}

int     main()
{
    t_list  *window;

    if (!(window = (t_list *)malloc(sizeof(t_list))))
        return (0);
    window->next = NULL;
    if (!(window->mlx_ptr = mlx_init()))
        return (0);
    window->win_ptr = mlx_new_window(window->mlx_ptr, 500, 500, "Hello, Window!");
    mlx_pixel_put(window->mlx_ptr, window->win_ptr, 250, 300, 0xFFFFFF);
    mlx_hook(window->win_ptr, 2, 0,  deal_key, (void *)window);
    mlx_loop(window->mlx_ptr);
    return (0);
}