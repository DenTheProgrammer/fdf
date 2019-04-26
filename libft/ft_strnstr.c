/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:31:29 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:18:32 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s_haystack;
	char	*s_needle;
	int		temp;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && (len-- > 0))
		if (*haystack == *needle)
		{
			s_haystack = (char *)haystack;
			s_needle = (char *)needle;
			temp = len + 1;
			while ((*haystack == *needle && (temp > 0)) || !(*needle))
			{
				if (!(*needle++))
					return (s_haystack);
				haystack++;
				temp--;
			}
			haystack = s_haystack + 1;
			needle = s_needle;
		}
		else
			haystack++;
	return (NULL);
}
