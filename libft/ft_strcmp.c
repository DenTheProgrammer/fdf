/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:57:34 by ashari            #+#    #+#             */
/*   Updated: 2019/04/06 20:06:20 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1_new;
	unsigned char	*s2_new;

	i = 0;
	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;
	while (s1_new[i] == s2_new[i] && s1_new[i] && s2_new[i])
		i++;
	return (s1_new[i] - s2_new[i]);
}
