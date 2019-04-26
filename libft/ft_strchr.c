/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:21:31 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:16:51 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (*s1 != (char)c)
	{
		if (*s1 == '\0')
			return (NULL);
		s1++;
	}
	return ((char *)s1);
}
