/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:00:07 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 13:41:20 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*new_s1;
	char	*tmp;

	if (!(new_s1 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = new_s1;
	while (*s1 && (int)n--)
	{
		*new_s1 = *s1;
		new_s1++;
		s1++;
	}
	*new_s1 = '\0';
	return (tmp);
}
