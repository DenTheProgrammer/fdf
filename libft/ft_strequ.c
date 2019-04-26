/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:04:16 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 17:55:34 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*s1_new;
	unsigned char	*s2_new;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2) || !s1 || !s2)
		return (0);
	s1_new = (unsigned char	*)s1;
	s2_new = (unsigned char	*)s2;
	while (*s1_new && *s2_new)
	{
		if (*s1_new != *s2_new)
			return (0);
		s1_new++;
		s2_new++;
	}
	return (1);
}
