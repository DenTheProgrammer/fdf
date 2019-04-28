/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:32:37 by ashari            #+#    #+#             */
/*   Updated: 2019/04/28 16:34:17 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_arrlen(char **arr)
{
	int len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

// void			printmap(t_dot **map)
// {
// 	int x,y;
// 	y = 0;
// 	while (y < 4)
// 	{
// 		x = 0;
// 		while (x < 4)
// 		{
// 			printf("%d ", map[y][x].z);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }

static void			ft_lstpush(t_list **list, t_list *node)
{
	t_list *tmp;

	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_dot**			read_map_from_file(char *filename, t_window *window)
{
	int fd;
	int linescount;
	char *line;
	t_list *lines;
	t_dot **dots;

	lines = NULL;
	linescount = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		linescount++;
		ft_lstpush(&lines, ft_lstnew(ft_strdup(line), 42));//pushback can be slow
	}
	window->map_sizey = linescount;
	dots = (t_dot**)malloc(sizeof(t_dot*) * (linescount + 1));
	dots[linescount] = NULL;


	size_t len;
	int x;
	int y = 0;
	len = 0;
	while (lines)
	{
		char **splitted_line = ft_strsplit(lines->content, ' ');
		len = ft_arrlen(splitted_line);
		dots[y] = (t_dot*)malloc(sizeof(t_dot) * (len + 1));
		dots[len] = NULL;
		x = 0;
		while (splitted_line[x])
		{
			dots[y][x].x = x;
			dots[y][x].y = y;
			dots[y][x].z = ft_atoi(splitted_line[x]);
			x++;
		}
		lines = lines->next;
		y++;
	}
	window->map_sizex = len;
	return (dots);
}

// int main() {
// 	t_dot **map = read_map_from_file("/Users/mdebbi/Desktop/fdfread/map.txt");
// 	printmap(map);
// 	return 0;
// }
