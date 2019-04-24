/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:33:23 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/22 12:07:32 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_lst			*ft_list_pushback(t_lst **beg, char *map)
{
	t_lst		*tmp;

	if (beg != NULL)
	{
		if (*beg != NULL)
		{
			tmp = *beg;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_list_new(map);
			if (tmp->next)
				tmp->next->next = NULL;
			return (tmp->next);
		}
		else
			*beg = ft_list_new(map);
		return (*beg);
	}
	return (NULL);
}
