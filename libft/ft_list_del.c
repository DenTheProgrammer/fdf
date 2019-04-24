/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:14:47 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/22 13:08:00 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_list_del(t_lst **beg)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	if (beg == NULL)
		return ;
	tmp = *beg;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_list_delone(&tmp);
		tmp = tmp2;
	}
	beg = NULL;
}
