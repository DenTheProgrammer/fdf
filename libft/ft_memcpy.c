/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:35:52 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:16:10 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_n;
	unsigned char	*src_n;

	i = 0;
	dst_n = (unsigned char *)dst;
	src_n = (unsigned char *)src;
	while (i < n)
	{
		dst_n[i] = src_n[i];
		i++;
	}
	return (dst);
}
