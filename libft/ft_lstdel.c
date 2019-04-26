/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:20:54 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 22:30:36 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nextl;
	t_list	*newl;

	if (alst && del != NULL)
	{
		newl = *alst;
		while (newl)
		{
			nextl = newl->next;
			(del)(newl->content, newl->content_size);
			free(newl);
			newl = nextl;
		}
		*alst = NULL;
	}
}
