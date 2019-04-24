/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:57:19 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/22 12:07:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_nul(t_lst *tetr)
{
	char	tmp;
	int		res;

	res = 0;
	tmp = tetr->map;
	while (tmp)
	{
		res++;
		tmp >>= 1;
	}
	return (tetr->w * tetr->h - res);
}

t_lst		*ft_list_new(char *map)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->map = ft_map_create(map, ft_find_coordinate(map, &(new->h), &(new->w)),
							new->h, new->w);
	new->nul = ft_nul(new);
	new->next = NULL;
	ft_strdel(&map);
	return (new);
}
