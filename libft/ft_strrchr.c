/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:23:28 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 21:18:45 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	unsigned char	*s_new;
	int				len;

	s_new = (unsigned char *)s;
	len = ft_strlen(s);
	while (s_new[len] != (unsigned char)c && (len > 0))
		len--;
	if (s_new[len] == (unsigned char)c)
		return ((char *)&s_new[len]);
	return (NULL);
}
