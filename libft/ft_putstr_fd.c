/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:46:34 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 17:21:56 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_fd(char const *s, int fd)
{
	unsigned char	*s1;

	if (s == NULL)
		return ;
	s1 = (unsigned char	*)s;
	while (*s1)
	{
		ft_putchar_fd(*s1, fd);
		s1++;
	}
}
