/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:45:44 by ashari            #+#    #+#             */
/*   Updated: 2019/04/09 15:31:14 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = (f)(lst);
	newlist = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = (f)(lst)))
		{
			free(list->next);
			list->next = NULL;
			return (NULL);
		}
		list = list->next;
	}
	return (newlist);
}
