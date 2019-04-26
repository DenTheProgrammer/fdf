/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:13:09 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 20:05:45 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strcpy(char *dst, const char *src)
{
	int				i;
	unsigned char	*src1;

	i = 0;
	src1 = (unsigned char *)src;
	while (src1[i])
	{
		dst[i] = src1[i];
		i++;
	}
	dst[i] = src1[i];
	return (dst);
}
