/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:31:29 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 13:52:38 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		*ft_memalloc(size_t size)
{
	char	*new;

	if (!(new = (void *)malloc(size)))
		return (NULL);
	while (--size > 0)
		new[size] = '\0';
	new[size] = '\0';
	return ((void *)new);
}

char			*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
