/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:20:56 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 12:00:17 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_n;
	unsigned char	*src_n;
	int				i;

	i = 0;
	dst_n = (unsigned char *)dst;
	src_n = (unsigned char *)src;
	if (src_n < dst_n)
	{
		i = (int)len;
		while (i-- > 0)
			dst_n[i] = src_n[i];
	}
	else
		while (i < (int)len)
		{
			dst_n[i] = src_n[i];
			i++;
		}
	return (dst);
}
