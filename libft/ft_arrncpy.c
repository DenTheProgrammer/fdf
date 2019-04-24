/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:59:59 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 13:54:11 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_arrncpy(long long *dst, long long *src, int i, int n)
{
	while (src[i] && n--)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
