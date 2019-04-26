/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:47:55 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 12:03:53 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_n;
	unsigned char	*dst_n;
	unsigned char	c1;
	int				i;
	int				n1;

	src_n = (unsigned char *)src;
	dst_n = (unsigned char *)dst;
	c1 = (unsigned char)c;
	n1 = (int)n;
	i = 0;
	while (i < n1)
	{
		dst_n[i] = src_n[i];
		if (src_n[i] == c1)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
