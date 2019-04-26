/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:25:07 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:18:01 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		n1;
	char	*src1;

	i = 0;
	j = 0;
	n1 = (int)n;
	src1 = (char *)s2;
	while (s1[i])
		i++;
	while (src1[j] && j < n1)
	{
		s1[i] = src1[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
