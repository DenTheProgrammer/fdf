/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:22:10 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:18:22 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*src1;

	i = 0;
	src1 = (unsigned char *)src;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	else if ((unsigned int)ft_strlen(src) < n)
		dest[i] = '\0';
	return (dest);
}
