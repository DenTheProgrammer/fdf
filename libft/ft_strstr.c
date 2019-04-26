/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:41:42 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:18:56 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*s_haystack;
	unsigned char	*s_needle;
	int				i;
	int				j;
	int				h;

	s_haystack = (unsigned char	*)haystack;
	s_needle = (unsigned char	*)needle;
	i = 0;
	if (!s_needle[i])
		return ((char *)s_haystack);
	h = 0;
	while (s_haystack[i])
	{
		if (s_haystack[i] == s_needle[0])
		{
			j = i;
			while (s_haystack[j++] == s_needle[h++])
				if (!s_needle[h])
					return ((char *)(s_haystack + i));
			h = 0;
		}
		i++;
	}
	return (NULL);
}
