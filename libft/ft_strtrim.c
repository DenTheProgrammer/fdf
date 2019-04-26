/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:12:45 by ashari            #+#    #+#             */
/*   Updated: 2019/04/08 22:04:16 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spl(int len, char const *s)
{
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		ss;
	int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	len = spl(len, s);
	ss = len;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		len--;
		i++;
	}
	len = len <= 0 ? 0 : len;
	if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (i <= ss)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
