/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:47:19 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 11:54:14 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*numb1;
	char	numb[11];
	int		znak;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	znak = n < 0 ? -1 : 1;
	i = 0;
	j = 0;
	while (znak * n > 9)
	{
		numb[i++] = '0' + znak * (n % 10);
		n /= 10;
	}
	numb[i++] = '0' + znak * n;
	if (znak == -1)
		numb[i++] = '-';
	if (!(numb1 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	numb1[i] = '\0';
	while (i--)
		numb1[i] = numb[j++];
	return (numb1);
}
