/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:33:55 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 12:20:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	s1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	while (i < len)
	{
		s1[i] = c1;
		i++;
	}
	return (s1);
}
