/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:39:59 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 11:55:24 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned char	*s1;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (!(s1 = ft_memalloc(len + 1)))
		return (NULL);
	if (len == 0)
		return ((char *)s1);
	i = 0;
	while (i < len)
	{
		s1[i] = s[start];
		start++;
		i++;
	}
	s1[i] = '\0';
	return ((char *)s1);
}
