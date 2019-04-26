/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:21:35 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 21:23:40 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(s1 = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = f(s[i]);
		i++;
	}
	while (s1[i])
	{
		s1[i] = '\0';
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
