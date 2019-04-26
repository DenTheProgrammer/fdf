/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:08:24 by ashari            #+#    #+#             */
/*   Updated: 2019/04/07 13:28:40 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;

	if (!(new = (void *)malloc(size)))
		return (NULL);
	while (size-- > 0)
		new[size] = '\0';
	new[size] = '\0';
	return ((void *)new);
}
